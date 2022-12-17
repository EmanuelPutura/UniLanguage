//
// Created by Emanuel on 12.12.2022.
//

#ifndef COMPILER_RECURSIVEPARSER_H
#define COMPILER_RECURSIVEPARSER_H

#include "LanguageSymbol/LanguageSymbol.h"
#include "../Grammar/Grammar.h"

#include <stack>
#include <memory>

enum RecursiveParserState {
    NORMAL,
    BACK,
    FINAL,
    ERROR
};

class RecursiveParser {
private:
    RecursiveParserState state;
    int inputIndex;
    Grammar grammar;

    std::stack<std::unique_ptr<LanguageSymbol>> workingStack;
    std::stack<std::unique_ptr<LanguageSymbol>> inputStack;
public:
    RecursiveParser();
private:
    void expand();

    void advance();

    void momentaryInsuccess();

    void back();

    void anotherTry();

    void success();
};


#endif //COMPILER_RECURSIVEPARSER_H
