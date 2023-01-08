//
// Created by Emanuel on 06.01.2023.
//

#ifndef COMPILER_PARSEROUTPUT_H
#define COMPILER_PARSEROUTPUT_H

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "../ParserTree.h"

class ParsingTableRow {
private:
    static int currentRowIndex;
public:
    int index;
    std::string symbol;
    int parentIndex;
    int rightSiblingIndex;
public:
    ParsingTableRow(const std::string& symbol, int parentIndex);
};

class ParserOutput {
private:
    std::vector<ParsingTableRow> table;
    bool isValidInput = true;
public:
    ParserOutput() = default;
    explicit ParserOutput(const ParserTree& parserTree);

    void loadFromParserTree(const ParserTree& parserTree);

    bool getIsValidInput() const;
    void setInvalidInput();

    friend std::ostream& operator<< (std::ostream& out, const ParserOutput& parserOutput);
};


#endif //COMPILER_PARSEROUTPUT_H
