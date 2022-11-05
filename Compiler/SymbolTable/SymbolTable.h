//
// Created by Emanuel on 30.10.2022.
//

#ifndef COMPILER_SYMBOLTABLE_H
#define COMPILER_SYMBOLTABLE_H

#include <string>
#include "RedBlackTree/RedBlackTree.h"

struct SymbolTableEntry {
    std::string symbol;
    size_t index;

    SymbolTableEntry() : symbol(""), index(-1) {}

    SymbolTableEntry(const std::string& symbol) : symbol(symbol), index(-1) {}

    SymbolTableEntry(const std::string& symbol, size_t index) : symbol(symbol), index(index) {}

    friend bool operator< (const SymbolTableEntry& e1, const SymbolTableEntry& e2) {
        return e1.symbol < e2.symbol;
    }

    friend bool operator== (const SymbolTableEntry& e1, const SymbolTableEntry& e2) {
        return e1.symbol == e2.symbol;
    }

    friend bool operator!= (const SymbolTableEntry& e1, const SymbolTableEntry& e2) {
        return e1.symbol != e2.symbol;
    }
};

class SymbolTable : public RedBlackTree<SymbolTableEntry, Node<SymbolTableEntry>> {
private:
    size_t currentIndex;
public:
    SymbolTable() : currentIndex(0), RedBlackTree<SymbolTableEntry, Node<SymbolTableEntry>>() {}

    int retrievePosition(const std::string& element);
};


#endif //COMPILER_SYMBOLTABLE_H
