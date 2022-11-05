//
// Created by Emanuel on 30.10.2022.
//

#include "SymbolTable.h"

int SymbolTable::retrievePosition(const std::string &element) {
    auto node = search(SymbolTableEntry(element));

    if (node == nil) {
        insert(SymbolTableEntry(element, ++currentIndex));
        return currentIndex;
    }

    return node->getKey().index;
}
