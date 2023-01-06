//
// Created by Emanuel on 12.12.2022.
//

#include <iostream>
#include <string_view>
#include "RecursiveParser.h"
#include "LanguageSymbol/NonTerminalSymbol/NonTerminalSymbol.h"
#include "LanguageSymbol/TerminalSymbol/TerminalSymbol.h"

namespace {
    std::stack<std::unique_ptr<ParserLanguageSymbol>> reverseStack(std::stack<std::unique_ptr<ParserLanguageSymbol>>& stack) {
        std::stack<std::unique_ptr<ParserLanguageSymbol>> result;

        while (!stack.empty()) {
            result.push(std::move(stack.top()));
            stack.pop();
        }

        return result;
    }
} // anonymous namespace

RecursiveParserLogicError::RecursiveParserLogicError(const std::string &message) : logic_error(message) {}

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

ParserOutput RecursiveParser::parse(const std::vector<std::string> &inputSequence) {
    state = RecursiveParserState::NORMAL;
    inputIndex = 0;
    workingStack = std::stack<std::unique_ptr<ParserLanguageSymbol>>();
    inputStack = std::stack<std::unique_ptr<ParserLanguageSymbol>>();
    inputStack.push(std::make_unique<NonTerminalSymbol>(grammar.getStartingSymbol(), 1));
    int index = 0;

    while (state != RecursiveParserState::FINAL && state != RecursiveParserState::ERROR) {
        index += 1;

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
        auto parsingOutput = ParserOutput();
        parsingOutput.setInvalidInput();

        return parsingOutput;
    } else {
        auto parsingTree = createParserTree();
        return ParserOutput(parsingTree);
    }
}

ParserTree RecursiveParser::createParserTree() {
    ParserTree tree;
    std::stack<std::shared_ptr<ParserTreeNode>> processingStack;
    auto revWorkingStack = reverseStack(workingStack);

    tree.root = std::make_shared<ParserTreeNode>();
    tree.root->symbol = revWorkingStack.top()->getSymbol();
    processingStack.push(tree.root);

    while (!revWorkingStack.empty()) {
        if (processingStack.empty() || revWorkingStack.top()->getSymbol() != processingStack.top()->symbol) {
            throw RecursiveParserLogicError("Error while building the parsing tree.");
        }

        auto node = processingStack.top();
        processingStack.pop();

        auto parserSymbol = std::move(revWorkingStack.top());
        revWorkingStack.pop();

        if (!parserSymbol->isTerminalSymbol()) {
            auto allRightHandSides = grammar.getDestinationsForSource(parserSymbol->getSymbol());

            if (allRightHandSides.size() < parserSymbol->getProductionIndex()) {
                throw RecursiveParserLogicError("Error while building the parsing tree.");
            }

            auto currentRightHandSide = allRightHandSides[parserSymbol->getProductionIndex() - 1];
            int prevNoOfChildren = node->children.size();

            for (int i = 0; i < currentRightHandSide.size(); ++i) {
                node->children.push_back(std::make_shared<ParserTreeNode>());
            }

            for (int i = currentRightHandSide.size() - 1; i >= 0; --i) {
                node->children[prevNoOfChildren + i]->symbol = currentRightHandSide[i];
                processingStack.push(node->children[prevNoOfChildren + i]);
            }
        }
    }

    return tree;
}
