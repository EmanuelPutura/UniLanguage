//
// Created by Emanuel on 21.08.2021.
//

#include "RedBlackTree.h"

RedBlackTreeException::RedBlackTreeException(const std::string &error_message) : error_message(error_message) {
}

const std::string &RedBlackTreeException::message() const {
    return error_message;
}
