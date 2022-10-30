//
// Created by Emanuel on 30.10.2022.
//

#ifndef COMPILER_SYMBOLTABLE_H
#define COMPILER_SYMBOLTABLE_H

#include <string>
#include "RedBlackTree/RedBlackTree.h"

class SymbolTable : public RedBlackTree<std::string, Node<std::string>> {
public:
    int retrievePosition(const std::string& element);
private:
    int getPositionOfElementInorder(const std::string& element) const;
};


#endif //COMPILER_SYMBOLTABLE_H
