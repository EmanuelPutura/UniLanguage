//
// Created by Emanuel on 12.12.2022.
//

#include "RecursiveParser.h"
#include "LanguageSymbol/NonTerminalSymbol/NonTerminalSymbol.h"

#include <algorithm>

std::pair<bool, std::string> firstSource(const Grammar& grammar, const std::string& destination) {
    for (const auto& production : grammar.getProductions()) {
        for (const auto& dest : production.getDestinationsRaw()) {
            if (dest.find(destination) != std::string::npos) {
                return std::make_pair(true, production.getSource());
            }
        }
    }

    return std::make_pair(false, "");
}

void RecursiveParser::success() {
    state = RecursiveParserState::FINAL;
}

void RecursiveParser::back() {
    inputIndex -= 1;

    inputStack.push(std::move(workingStack.top()));
    workingStack.pop();
}

void RecursiveParser::anotherTry() {
    auto inputStackHead = std::move(inputStack.top());
    inputStack.pop();

    workingStack.pop();

    auto firstSrc = firstSource(grammar, inputStackHead->getSymbol());

    if (firstSrc.first) {
        inputStack.push(std::make_unique<NonTerminalSymbol>(firstSrc.second));
    }
    else {
        state = RecursiveParserState::ERROR;
    }
}
