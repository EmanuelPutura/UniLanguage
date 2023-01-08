//
// Created by Emanuel on 12.12.2022.
//

#ifndef COMPILER_RECURSIVEPARSER_H
#define COMPILER_RECURSIVEPARSER_H

#include "LanguageSymbol/ParserLanguageSymbol.h"
#include "../Grammar/Grammar.h"
#include "ParserTree.h"
#include "ParserOutput/ParserOutput.h"

#include <stack>
#include <memory>
#include <exception>


class RecursiveParserLogicError : public std::logic_error {
public:
    explicit RecursiveParserLogicError(const std::string& message);
};

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

    std::stack<std::unique_ptr<ParserLanguageSymbol>> workingStack;
    std::stack<std::unique_ptr<ParserLanguageSymbol>> inputStack;
public:
    explicit RecursiveParser(const std::string &grammarFilePath);

    ParserOutput parse(const std::vector<std::string> &inputSequence);
private:
    void expand();

    void advance();

    void momentaryInsuccess();

    void back();

    void anotherTry();

    void success();

    bool checkNextProductionIndex(int productionIndex, const std::string& src);

    void insertNextProduction(int productionIndex, const std::string& src);

    ParserTree createParserTree();
};


#endif //COMPILER_RECURSIVEPARSER_H
