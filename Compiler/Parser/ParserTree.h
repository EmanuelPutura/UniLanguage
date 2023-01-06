//
// Created by Emanuel on 06.01.2023.
//

#ifndef COMPILER_PARSERTREE_H
#define COMPILER_PARSERTREE_H

#include <memory>

struct ParserTreeNode {
    std::string symbol;
    std::vector<std::shared_ptr<ParserTreeNode>> children;
};

struct ParserTree {
    std::shared_ptr<ParserTreeNode> root;
};

#endif //COMPILER_PARSERTREE_H
