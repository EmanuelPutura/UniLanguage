//
// Created by Emanuel on 05.11.2022.
//

#ifndef COMPILER_SCANNER_H
#define COMPILER_SCANNER_H

#include "../ProgramInternalForm/ProgramInternalForm.h"
#include "../SymbolTable/SymbolTable.h"
#include "../FiniteAutomata/FiniteAutomata.h"

#include <unordered_set>

class LexicalError : public std::exception {
private:
    std::string token;
    int line;
public:
    LexicalError(const std::string& token, int line);
    std::string getMessage() const;
};

enum TokenType {
    IDENTIFIER,
    CONSTANT,
    KEYWORD,
    SEPARATOR,
    OPERATOR
};

class Scanner {
private:
    FiniteAutomata finiteAutomataIntegers;
    FiniteAutomata finiteAutomataIdentifiers;

    ProgramInternalForm pif;
    SymbolTable symbolTable;

    std::string inputFilePath;

    std::unordered_set<std::string> keywords;
    std::unordered_set<std::string> separators;
    std::unordered_set<std::string> operators;

    bool isLexicallyCorrect;
public:
    Scanner(const std::string& inputFilePath, const std::string& tokensFilePath);

    void scan();
private:
    void scanTokens();

    std::string buildOrRegex(const std::unordered_set<std::string>& elements) const;
    void splitByOperators(std::string currentStr, int lineNumber);
    void splitByOperatorsRecursively(const std::string& multipleCharsOperatorsRegex, const std::string& singleCharOperatorsRegex,
                 std::string currentStr, int lineNumber, bool isMultipleCharsStep = true);
    void handleToken(std::string token, int lineNumber);

    TokenType identifyToken(const std::string& token, int lineNumber) const;
};


#endif //COMPILER_SCANNER_H
