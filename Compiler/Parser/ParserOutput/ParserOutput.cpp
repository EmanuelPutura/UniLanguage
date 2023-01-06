//
// Created by Emanuel on 06.01.2023.
//

#include "ParserOutput.h"

#include <unordered_map>
#include <queue>

int ParsingTableRow::currentRowIndex = 0;

ParsingTableRow::ParsingTableRow(const std::string &symbol, int parentIndex) :
    index(currentRowIndex++),
    symbol(symbol),
    parentIndex(parentIndex),
    rightSiblingIndex(-1) {
}

ParserOutput::ParserOutput(const ParserTree &parserTree) {
    loadFromParserTree(parserTree);
}

void ParserOutput::loadFromParserTree(const ParserTree &parserTree) {
    table.clear();

    // BFS
    std::queue<std::tuple<std::shared_ptr<ParserTreeNode>, int, int>> queue;
    std::unordered_map<int, int> tableIndexToDepth;

    queue.push({parserTree.root, -1, 0});

    while (!queue.empty()) {
        auto front = queue.front();
        auto node = std::get<0>(front);
        auto parentIndex = std::get<1>(front);
        auto depth = std::get<2>(front);

        queue.pop();

        // update the table
        auto row = ParsingTableRow(node->symbol, parentIndex);
        tableIndexToDepth[row.index] = depth;

        if (row.index && tableIndexToDepth[table.back().index] == depth) {
            table.back().rightSiblingIndex = row.index;
        }

        table.push_back(row);

        for (int i = 0; i < node->children.size(); ++i) {
            queue.push({node->children[i], row.index, depth + 1});
        }
    }
}

std::ostream &operator<<(std::ostream &out, const ParserOutput &parserOutput) {
    out << std::setw(15) << "Index";
    out << std::setw(20) << "Symbol";
    out << std::setw(25) << "Parent Index";
    out << std::setw(30) << "Right Sibling Index" << '\n';

    for (const auto& row : parserOutput.table) {
        out << std::setw(15) << row.index;
        out << std::setw(20) << row.symbol;
        out << std::setw(25) << row.parentIndex;
        out << std::setw(30) << row.rightSiblingIndex << '\n';
    }

    return out;
}

void ParserOutput::setInvalidInput() {
    isValidInput = false;
}

bool ParserOutput::getIsValidInput() const {
    return isValidInput;
}
