//
// Created by Emanuel on 12.12.2022.
//

#include "RecursiveParser.h"
#include "LanguageSymbol/NonTerminalSymbol/NonTerminalSymbol.h"
#include "LanguageSymbol/TerminalSymbol/TerminalSymbol.h"

RecursiveParser::RecursiveParser(const std::string& grammarFilePath) : state(NORMAL), inputIndex(0) {
    grammar.parse(grammarFilePath);
}

std::pair<bool, std::string> firstSource(const Grammar& grammar, const std::string& destination) {
    for (const auto& production : grammar.getProductions()) {
        for (const auto& dest : production.second.getDestinationsRaw()) {
            if (dest.find(destination) != std::string::npos) {
                return std::make_pair(true, production.first);
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

void RecursiveParser::expand() {
    if (inputStack.top()->isTerminalSymbol()) {
        // TODO: handle this case
        return;
    }

    auto top = std::move(inputStack.top());
    inputStack.pop();

    auto allDestinations = grammar.getDestinationsForSource(top->getSymbol());
    if (allDestinations.empty()) {
        // TODO: handle this case
        return;
    }

    auto firstDestination = allDestinations.front();
    for (size_t i = firstDestination.size() - 1; i >= 0; --i) {
        if (grammar.getTerminals().contains(firstDestination[i])) {
            inputStack.push(std::make_unique<TerminalSymbol>(firstDestination[i]));
        }
        else {
            inputStack.push(std::make_unique<NonTerminalSymbol>(firstDestination[i]));
        }
    }

    workingStack.push(std::move(top));
}

void RecursiveParser::advance() {
    if (!inputStack.top()->isTerminalSymbol() || inputStack.top()->getProductionIndex() != inputIndex) {
        // TODO: handle this case
        return;
    }

    inputIndex++;
    workingStack.push(std::move(inputStack.top()));
    inputStack.pop();
}

void RecursiveParser::momentaryInsuccess() {
    if (!inputStack.top()->isTerminalSymbol() || inputStack.top()->getProductionIndex() == inputIndex) {
        // TODO: handle this case
        return;
    }

    state = BACK;
}
