//
// Created by Emanuel on 12.12.2022.
//

#include <iostream>
#include <string_view>
#include "RecursiveParser.h"
#include "LanguageSymbol/NonTerminalSymbol/NonTerminalSymbol.h"
#include "LanguageSymbol/TerminalSymbol/TerminalSymbol.h"

RecursiveParser::RecursiveParser(const std::string &grammarFilePath) : state(NORMAL), inputIndex(0) {
    grammar.parse(grammarFilePath);
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
    auto workingStackHead = std::move(workingStack.top());
    workingStack.pop();

    if (checkNextProductionIndex(workingStackHead->getProductionIndex(), workingStackHead->getSymbol())) {
        state = RecursiveParserState::NORMAL;
        insertNextProduction(workingStackHead->getProductionIndex() + 1, workingStackHead->getSymbol());
        workingStack.push(std::make_unique<NonTerminalSymbol>(workingStackHead->getSymbol(),
                                                              workingStackHead->getProductionIndex() + 1));
    } else if (inputIndex == 0 && workingStackHead->getSymbol() == grammar.getStartingSymbol()) {
        state = RecursiveParserState::ERROR;
    } else {
        state = RecursiveParserState::BACK;
        inputStack.push(std::move(std::make_unique<NonTerminalSymbol>(workingStackHead->getSymbol(), 1)));
    }
}

bool RecursiveParser::checkNextProductionIndex(int productionIndex, const std::string &src) {
    auto destinations = grammar.getDestinationsForSource(src);

    if (productionIndex > destinations.size()) {
        inputStack.pop();
        return false;
    }

    for (auto el: destinations[productionIndex - 1]) {
        inputStack.pop();
    }

    if (productionIndex == destinations.size()) {
        return false;
    }

    return true;
}

void RecursiveParser::insertNextProduction(int productionIndex, const std::string &src) {
    auto destinations = grammar.getDestinationsForSource(src);

    for (int i = destinations[productionIndex - 1].size() - 1; i >= 0; --i) {
        if (grammar.getTerminals().contains(destinations[productionIndex - 1][i])) {
            inputStack.push(std::make_unique<TerminalSymbol>(destinations[productionIndex - 1][i], 1));
        } else {
            inputStack.push(std::make_unique<NonTerminalSymbol>(destinations[productionIndex - 1][i], 1));
        }
    }
}

void RecursiveParser::expand() {
    auto top = std::move(inputStack.top());
    inputStack.pop();

    auto allDestinations = grammar.getDestinationsForSource(top->getSymbol());

    auto firstDestination = allDestinations.front();
    for (int i = firstDestination.size() - 1; i >= 0; --i) {
        if (grammar.getTerminals().contains(firstDestination[i])) {
            inputStack.push(std::make_unique<TerminalSymbol>(firstDestination[i], 1));
        } else {
            inputStack.push(std::make_unique<NonTerminalSymbol>(firstDestination[i], 1));
        }
    }

    workingStack.push(std::move(top));
}

void RecursiveParser::advance() {
    inputIndex++;
    workingStack.push(std::move(inputStack.top()));
    inputStack.pop();
}

void RecursiveParser::momentaryInsuccess() {
    state = BACK;
}

void traverseStack(std::stack<std::unique_ptr<ParserLanguageSymbol>> &stack) {
    if (stack.empty()) {
        return;
    }

    auto t = std::move(stack.top());
    std::cout << t->getSymbol() << " ";
    stack.pop();
    traverseStack(stack);
    stack.push(std::move(t));
}

bool RecursiveParser::parse(const std::vector<std::string> &inputSequence) {
    state = RecursiveParserState::NORMAL;
    inputIndex = 0;
    workingStack = std::stack<std::unique_ptr<ParserLanguageSymbol>>();
    inputStack = std::stack<std::unique_ptr<ParserLanguageSymbol>>();
    inputStack.push(std::make_unique<NonTerminalSymbol>(grammar.getStartingSymbol(), 1));
    int index = 0;

    while (state != RecursiveParserState::FINAL && state != RecursiveParserState::ERROR) {
        index += 1;
//        if (index > 1) {
//            std::cout << "Index: " << index << '\n';
//            std::cout << "Working stack: ";
//            traverseStack(workingStack);
//
//            std::cout << "\nInput stack: ";
//            traverseStack(inputStack);
//            std::cout << "\n\n";
//        }

        if (state == RecursiveParserState::NORMAL) {
            if (inputIndex == inputSequence.size() && inputStack.empty()) {
                success();
            } else {
                if (!inputStack.empty() && !inputStack.top()->isTerminalSymbol()) {
                    expand();
                } else {
                    if (inputIndex < inputSequence.size() && !inputStack.empty() &&
                        inputStack.top()->getSymbol() == inputSequence[inputIndex]) {
                        advance();
                    } else {
                        momentaryInsuccess();
                    }
                }
            }
        } else {
            if (workingStack.top()->isTerminalSymbol()) {
                back();
            } else {
                anotherTry();
            }
        }
    }

    if (state == RecursiveParserState::ERROR) {
        return false;
    } else {
        return true;
    }
}


