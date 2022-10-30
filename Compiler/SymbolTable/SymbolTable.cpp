//
// Created by Emanuel on 30.10.2022.
//

#include "SymbolTable.h"
#include <stack>

int SymbolTable::getPositionOfElementInorder(const std::string &element) const {
    std::stack<Node<std::string>*> stk;
    auto current = tree_root;
    int position = 0;

    while (current != nil || !stk.empty())
    {
        while (current != nil)
        {
            stk.push(current);
            current = current->getLeftChild();
        }

        current = stk.top();
        stk.pop();

        if (current->getKey() == element) {
            return position;
        }

        position++;
        current = current->getRightChild();
    }

    return -1;
}

int SymbolTable::retrievePosition(const std::string &element) {
    if (search(element) == nil) {
        insert(element);
    }

    return getPositionOfElementInorder(element);
}
