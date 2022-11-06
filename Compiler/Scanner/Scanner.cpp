//
// Created by Emanuel on 05.11.2022.
//

#include "Scanner.h"

#include <sstream>
#include <fstream>
#include <regex>

LexicalError::LexicalError(const std::string& token, int line) : token(token), line(line) {}

std::string LexicalError::getMessage() const {
    return "Lexical Error: token '" + token + "' cannot be classified, line " + std::to_string(line) + "\n";
}

Scanner::Scanner(const std::string &inputFilePath, const std::string &tokensFilePath) : inputFilePath(inputFilePath), isLexicallyCorrect(true),
    pif(ProgramInternalForm("../Files/Output/PIF.out")), symbolTable(SymbolTable("../Files/Output/ST.out")) {
    std::ifstream fin (tokensFilePath);
    std::string currentSection = "KEYWORDS";
    std::string token;

    while (fin >> token) {
        if (token == "KEYWORDS" || token == "OPERATORS" || token == "SEPARATORS") {
            currentSection = token;
            continue;
        }

        if (currentSection == "KEYWORDS") {
            keywords.insert(token);
        }
        else if (currentSection == "OPERATORS") {
            operators.insert(token);
        }
        else if (currentSection == "SEPARATORS") {
            separators.insert(token);
        }
    }

    fin.close();
}

void Scanner::scanTokens() {
    std::ifstream fin(inputFilePath);
    std::string separatorsRegex = buildOrRegex(separators);
    std::string line;
    std::string word;

    int lineNumber = 1;

    while (std::getline(fin, line)) {
        std::istringstream iss (line);

        while (iss >> word) {
            std::smatch sm;
            while (std::regex_search(word, sm, std::regex(separatorsRegex))) {
                int splitPos = sm.position();

                auto currentStr = word.substr(0, splitPos);
                splitByOperators(currentStr, lineNumber);

                currentStr = word.substr(splitPos, sm.length());
                splitByOperators(currentStr, lineNumber);

                word = word.substr(splitPos + sm.length());
            }

            splitByOperators(word, lineNumber);
        }

        lineNumber++;
    }

    fin.close();
}

void Scanner::scan() {
    scanTokens();

    if (isLexicallyCorrect) {
        std::cout << "The program is lexically correct!\n";
    }

    pif.getPifInFile();
    symbolTable.getSymbolTableInFile();
}

std::string Scanner::buildOrRegex(const std::unordered_set<std::string> &elements) const {
    std::string resultRegex;

    for (const auto& element : elements) {
        std::string finalElement;
        for (int i = 0; i < element.length(); ++i) {
            finalElement += "\\";
            finalElement += element[i];
        }

        resultRegex += finalElement + "|";
    }

    resultRegex.pop_back();
    return resultRegex;
}

void Scanner::splitByOperators(std::string currentStr, int lineNumber) {
    if (currentStr == "") {
        return;
    }

    std::unordered_set<std::string> multipleCharsOperators;
    std::unordered_set<std::string> singleCharOperators;

    for (const auto& op : operators) {
        if (op.length() > 1) {
            multipleCharsOperators.insert(op);
        }
        else {
            singleCharOperators.insert(op);
        }
    }

    std::smatch sm;
    std::string multipleCharsOperatorRegex = buildOrRegex(multipleCharsOperators);
    std::string singleCharsOperatorRegex = buildOrRegex(singleCharOperators);

    splitByOperatorsRecursively(multipleCharsOperatorRegex, singleCharsOperatorRegex, currentStr, lineNumber);
}

void Scanner::splitByOperatorsRecursively(const std::string &multipleCharsOperatorsRegex, const std::string &singleCharOperatorsRegex,
                                          std::string currentStr, int lineNumber, bool isMultipleCharsStep) {
    if (currentStr == "") {
        return;
    }

    std::smatch sm;
    std::string operatorsRegex = isMultipleCharsStep ? multipleCharsOperatorsRegex : singleCharOperatorsRegex;

    while (std::regex_search(currentStr, sm, std::regex(operatorsRegex))) {
        int splitPos = sm.position();

        if (isMultipleCharsStep) {
            splitByOperatorsRecursively(multipleCharsOperatorsRegex, singleCharOperatorsRegex, currentStr.substr(0, splitPos), lineNumber, false);
            handleToken(currentStr.substr(splitPos, sm.length()), lineNumber);
        }
        else {
            handleToken(currentStr.substr(0, splitPos), lineNumber);
            handleToken(currentStr.substr(splitPos, sm.length()), lineNumber);
        }

        currentStr = currentStr.substr(splitPos + sm.length());
    }

    if (isMultipleCharsStep) {
        splitByOperatorsRecursively(multipleCharsOperatorsRegex, singleCharOperatorsRegex, currentStr, lineNumber, false);
    }
    else {
        handleToken(currentStr, lineNumber);
    }
}

void Scanner::handleToken(std::string token, int lineNumber) {
    if (token == "") {
        return;
    }

    // handle the token
    TokenType tokenType;
    try {
        tokenType = identifyToken(token, lineNumber);
    }
    catch (const LexicalError& error) {
        std::cout << error.getMessage();
        isLexicallyCorrect = false;
        return;
    }

    if (tokenType == KEYWORD || tokenType == SEPARATOR || tokenType == OPERATOR) {
        pif.push(token, -1);
    }
    else {
        int index = symbolTable.retrievePosition(token);
        pif.push(token, index);
    }
}

TokenType Scanner::identifyToken(const std::string &token, int lineNumber) const {
    if (keywords.find(token) != keywords.end()) {
        return KEYWORD;
    }

    if (operators.find(token) != operators.end()) {
        return OPERATOR;
    }

    if (separators.find(token) != separators.end()) {
        return SEPARATOR;
    }

    std::regex identifierRegex ("^([a-zA-Z])[a-zA-Z0-9]*$");
    if (std::regex_match(token, identifierRegex)) {
        return IDENTIFIER;
    }

    std::regex negativeIntegerConstRegex ("^\\-[1-9][0-9]*$");
    std::regex positiveIntegerConstRegex ("^\\+[1-9][0-9]*$");
    std::regex integerConstRegex ("^[1-9][0-9]*|0$");

    std::regex characterConstRegex("^\'[a-zA-Z0-9]?\'$");
    std::regex stringConstRegex("^\"[a-zA-Z0-9]*\"$");

    if (std::regex_match(token, negativeIntegerConstRegex) || std::regex_match(token, positiveIntegerConstRegex) || std::regex_match(token, integerConstRegex) ||
            std::regex_match(token, characterConstRegex) || std::regex_match(token, stringConstRegex)) {
        return CONSTANT;
    }

    throw LexicalError(token, lineNumber);
}
