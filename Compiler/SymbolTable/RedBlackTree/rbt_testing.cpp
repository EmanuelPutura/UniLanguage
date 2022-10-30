//
// Created by Emanuel on 21.08.2021.
//

#include "rbt_testing.h"
#include "RedBlackTree.h"

#include <iostream>
#include <sstream>
#include <cassert>

void testRedBlackTree() {
    RedBlackTree<int, Node<int>> t1;

    t1.insert(6);
    assert(t1.size() == 1);
    assert(t1.maximum() == 6);
    assert(t1.minimum() == 6);

    t1.insert(4);
    t1.insert(7);

    auto root = t1.root();
    assert(root->getKey() == 6);
    assert(root->getLeftChild()->getKey() == 4);
    assert(root->getRightChild()->getKey() == 7);

    assert(!root->getLeftChild()->getColor() && !root->getRightChild()->getColor());
    t1.insert(7);
    assert(root->getLeftChild()->getColor() && root->getRightChild()->getColor());  // red uncle case

    t1.insert(10);  // black uncle, right-right case
    assert(t1.size() == 5);

    t1.insert(3);
    assert(t1.size() == 6);
    assert(t1.minimum() == 3);
    assert(t1.maximum() == 10);

    root = t1.root();
    assert(root->getKey() == 6 && root->getColor());
    assert(root->getLeftChild()->getKey() == 4 && root->getLeftChild()->getColor());
    assert(root->getLeftChild()->getLeftChild()->getKey() == 3 && !root->getLeftChild()->getLeftChild()->getColor());
    assert(root->getRightChild()->getKey() == 7 && root->getRightChild()->getColor());
    assert(root->getRightChild()->getLeftChild()->getKey() == 7 && !root->getRightChild()->getLeftChild()->getColor());
    assert(root->getRightChild()->getRightChild()->getKey() == 10 && !root->getRightChild()->getRightChild()->getColor());

    std::stringstream stream;
    t1.inorderTraversal(stream);
    assert(stream.str() == "3 4 6 7 7 10 ");

    t1.remove(7);
    assert(t1.size() == 5);

    stream.str("");
    t1.inorderTraversal(stream);
    assert(stream.str() == "3 4 6 7 10 ");

    t1.remove(3);
    assert(t1.size() == 4);

    stream.str("");
    t1.inorderTraversal(stream);
    assert(stream.str() == "4 6 7 10 ");

    t1.remove(10);
    assert(t1.size() == 3);

    stream.str("");
    t1.inorderTraversal(stream);
    assert(stream.str() == "4 6 7 ");

    try {
        t1.remove(10);
        assert(false);
    }
    catch (const RedBlackTreeException& exception) {
        assert(exception.message() == "The key to be removed was not found.");
    }

    t1.remove(6);
    assert(t1.size() == 2);

    stream.str("");
    t1.inorderTraversal(stream);
    assert(stream.str() == "4 7 ");

    t1.remove(4);
    assert(t1.size() == 1);

    stream.str("");
    t1.inorderTraversal(stream);
    assert(stream.str() == "7 ");
    assert(t1.root()->getKey() == 7);

    t1.remove(7);
    assert(t1.size() == 0);

    stream.str("");
    t1.inorderTraversal(stream);
    assert(stream.str() == "");

    std::cout << "...testing red black tree data structure\n";
}
