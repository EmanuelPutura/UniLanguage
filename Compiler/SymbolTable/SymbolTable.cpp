//
// Created by Emanuel on 30.10.2022.
//

#include "SymbolTable.h"

#include <fstream>

int SymbolTable::retrievePosition(const std::string &element) {
    auto node = search(SymbolTableEntry(element));

    if (node == nil) {
        insert(SymbolTableEntry(element, ++currentIndex));
        return currentIndex;
    }

    return node->getKey().index;
}

void SymbolTable::getSymbolTableInFile() const {
    std::ofstream fout (outFilePath);

    fout << "Data Structure: Balanced binary search tree, implemented using a red-black tree\n";
    fout << *this << '\n';

    fout.close();
}

std::ostream &operator<<(std::ostream &out, const SymbolTable &st) {
    st.recursiveInorderTraversal(st.tree_root, out);
    return out;
}
