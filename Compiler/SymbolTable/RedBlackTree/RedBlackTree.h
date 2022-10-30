//
// Created by Emanuel on 21.08.2021.
//

#ifndef CORMENBOOK_REDBLACKTREE_H
#define CORMENBOOK_REDBLACKTREE_H

#include <iostream>
#include <exception>
#include <string>

#include "Node.h"

class RedBlackTreeException : public std::exception {
private:
    std::string error_message;
public:
    RedBlackTreeException(const std::string& error_message);
    const std::string& message() const;
};

/*
 * Class Node from RedBlackTree class template must provide public access to at least the following fields: key, left, right, parent, color
 */
template <class K, class Node>
class RedBlackTree {
protected:
    Node *tree_root;
    Node *nil;

    int nodes_number;
public:
    RedBlackTree();
    ~RedBlackTree();

    void inorderTraversal(std::ostream& os) const;
    virtual void insert(const K& key);
    virtual void remove(const K& key);

    Node* search(const K& key) const;
    const K& minimum() const;
    const K& maximum() const;

    int size() const;
    Node* root() const;
protected:
    virtual void initNode(Node* &node, const K& key) const;
    void recursiveInorderTraversal(Node *subtree_root, std::ostream& os) const;
    void deleteRecursively(Node *subtree_root);

    virtual void leftRotate(Node *subtree_root);
    virtual void rightRotate(Node *subtree_root);
    void transplant(Node *initial_node, Node *new_node);

    Node* subtree_minimum(Node *root) const;
    Node* subtree_maximum(Node *root) const;

    virtual void insertFixup(Node *node);
    virtual void deleteFixup(Node *node);
};

/*
 *  ============================ Implementation ============================
 */

template <class K, class Node>
RedBlackTree<K, Node>::RedBlackTree() : nil {new Node}, nodes_number {0} {
    nil->color = true;
    tree_root = nil;
}

template <class K, class Node>
void RedBlackTree<K, Node>::initNode(Node* &node, const K& key) const {
    node = new Node;
    node->key = key;
    node->parent = nil;
    node->right = nil;
    node->left = nil;
    node->color = true;
}

template <class K, class Node>
void RedBlackTree<K, Node>::leftRotate(Node *subtree_root) {
    auto new_root = subtree_root->right;
    if (new_root == nil)
        return;

    subtree_root->right = new_root->left;
    new_root->left->parent = subtree_root;
    new_root->parent = subtree_root->parent;

    if (subtree_root->parent == nil)
        tree_root = new_root;
    if (new_root->parent->right == subtree_root)
        new_root->parent->right = new_root;
    else if (new_root->parent->left == subtree_root)
        new_root->parent->left = new_root;

    subtree_root->parent = new_root;
    new_root->left = subtree_root;
}

template <class K, class Node>
void RedBlackTree<K, Node>::rightRotate(Node *subtree_root) {
    auto new_root = subtree_root->left;
    if (new_root == nil)
        return;

    subtree_root->left = new_root->right;
    new_root->right->parent = subtree_root;
    new_root->parent = subtree_root->parent;

    if (subtree_root->parent == nil)
        tree_root = new_root;
    if (new_root->parent->right == subtree_root)
        new_root->parent->right = new_root;
    else if (new_root->parent->left == subtree_root)
        new_root->parent->left = new_root;

    subtree_root->parent = new_root;
    new_root->right = subtree_root;
}

template<class K, class Node>
void RedBlackTree<K, Node>::inorderTraversal(std::ostream &os) const {
    recursiveInorderTraversal(tree_root, os);
}

template <class K, class Node>
void RedBlackTree<K, Node>::recursiveInorderTraversal(Node *subtree_root, std::ostream& os) const {
    if (subtree_root != nil) {
        recursiveInorderTraversal(subtree_root->left, os);
        os << subtree_root->key << ' ';
        recursiveInorderTraversal(subtree_root->right, os);
    }
}

template <class K, class Node>
void RedBlackTree<K, Node>::insert(const K &key) {
    auto previous_node = nil, current = tree_root;
    while (current != nil) {
        previous_node = current;

        if (key < current->key)
            current = current->left;
        else
            current = current->right;
    }

    initNode(current, key);
    current->parent = previous_node;
    current->color = false;

    if (previous_node == nil)
        tree_root = current;
    else if (key < previous_node->key)
        previous_node->left = current;
    else previous_node->right = current;

    insertFixup(current);
    nodes_number++;
}

template <class K, class Node>
void RedBlackTree<K, Node>::insertFixup(Node *node) {
    while (!node->parent->color) {  // while the color of the node's parent is red
        if (node->parent == node->parent->parent->left) {
            auto uncle_node = node->parent->parent->right;
            if (!uncle_node->color) {  // if the color of the uncle node is red, just change the colors of the uncle and of the parent to black, the grandfather's color to red and continue
                node->parent->color = true;
                uncle_node->color = true;
                node->parent->parent->color = false;
                node = node->parent->parent;
            } else {
                if (node == node->parent->right) {
                    node = node->parent;
                    leftRotate(node);
                }

                node->parent->color = true;
                node->parent->parent->color = false;
                rightRotate(node->parent->parent);
            }
        }
        else {
            auto uncle_node = node->parent->parent->left;
            if (!uncle_node->color) {  // if the color of the uncle node is red, just change the colors of the uncle and of the parent to black, the grandfather's color to red and continue
                node->parent->color = true;
                uncle_node->color = true;
                node->parent->parent->color = false;
                node = node->parent->parent;
            }
            else {
                if (node == node->parent->left) {
                    node = node->parent;
                    rightRotate(node);
                }

                node->parent->color = true;
                node->parent->parent->color = false;
                leftRotate(node->parent->parent);
            }
        }
    }

    tree_root->color = true;
}

template <class K, class Node>
int RedBlackTree<K, Node>::size() const {
    return nodes_number;
}

template <class K, class Node>
Node* RedBlackTree<K, Node>::root() const{
    return tree_root;
}

template <class K, class Node>
RedBlackTree<K, Node>::~RedBlackTree() {
    deleteRecursively(tree_root);
    delete nil;
}

template <class K, class Node>
void RedBlackTree<K, Node>::deleteRecursively(Node *subtree_root) {
    if (subtree_root != nil) {
        deleteRecursively(subtree_root->left);
        deleteRecursively(subtree_root->right);
        delete subtree_root;
    }
}

template <class K, class Node>
void RedBlackTree<K, Node>::transplant(Node *initial_node, Node *new_node) {
    if (tree_root == initial_node)
        tree_root = new_node;
    else if (initial_node == initial_node->parent->right)
        initial_node->parent->right = new_node;
    else
        initial_node->parent->left = new_node;

    new_node->parent = initial_node->parent;
}

template <class K, class Node>
void RedBlackTree<K, Node>::remove(const K &key) {
    auto node = search(key);
    if (node == nil)
        throw RedBlackTreeException("The key to be removed was not found.");

    auto changing_node = node;  // if node has less than two children, than changing_node is node; else, it is the successor of node
    auto replace_node = nil;    // the node that replaces the deleted/moved one (i.e., changing_node)
    auto changing_node_original_color = changing_node->color;  // the original color of the changing node

    if (node->right == nil) {
        replace_node = node->left;
        transplant(node, node->left);
    }
    else if (node->left == nil) {
        replace_node = node->right;
        transplant(node, node->right);
    }
    else {
        changing_node = subtree_minimum(node->right);
        changing_node_original_color = changing_node->color;
        replace_node = changing_node->right;  // the minimum only has a right child

        transplant(changing_node, changing_node->right);
        changing_node->right = node->right;
        changing_node->right->parent = changing_node;
        transplant(node, changing_node);
        changing_node->left = node->left;
        changing_node->left->parent = changing_node;
        changing_node->color = node->color;
    }

    // only if the original color of changing_node was black
    if (changing_node_original_color)
        deleteFixup(replace_node);
    nodes_number--;
    delete node;
}

template <class K, class Node>
Node *RedBlackTree<K, Node>::search(const K& key) const {
    auto current = tree_root;
    while (current != nil && current->key != key) {
        if (key < current->key)
            current = current->left;
        else
            current = current->right;
    }
    return current;
}

template <class K, class Node>
const K& RedBlackTree<K, Node>::minimum() const {
    auto minimum = subtree_minimum(tree_root);
    return minimum->key;
}

template <class K, class Node>
const K& RedBlackTree<K, Node>::maximum() const {
    auto maximum = subtree_maximum(tree_root);
    return maximum->key;
}

template <class K, class Node>
Node* RedBlackTree<K, Node>::subtree_minimum(Node *root) const {
    auto previous = root;
    while (root != nil) {
        previous = root;
        root = root->left;
    }
    return previous;
}

template <class K, class Node>
Node* RedBlackTree<K, Node>::subtree_maximum(Node *root) const {
    auto previous = root;
    while (root != nil) {
        previous = root;
        root = root->right;
    }
    return previous;
}

template <class K, class Node>
void RedBlackTree<K, Node>::deleteFixup(Node *node) {
    while (node != tree_root && node->color) {
        if (node == node->parent->left) {
            auto sibling = node->parent->right;
            if (!sibling->color) {  // case 1 - sibling color is red
                sibling->color = true;
                node->parent->color = false;
                leftRotate(node->parent);
                sibling = node->parent->right;
            }
            if (sibling->left->color && sibling->right->color) {  // case 2 - sibling is black and both its children are black
                sibling->color = false;
                node = node->parent;
            }
            else if (sibling->right->color) {  // case 3 - sibling is black, its left child is red and its right child is black
                sibling->color = false;
                sibling->left->color = true;
                rightRotate(sibling);
                sibling = node->parent->right;
            }
            // case 4 - sibling is black and its right child is red
            sibling->color = node->parent->color;
            node->parent->color = true;
            sibling->right->color = true;
            leftRotate(node->parent);
            break;
        }
        else {
            auto sibling = node->parent->left;
            if (!sibling->color) {  // case 1 - sibling color is red
                sibling->color = true;
                node->parent->color = false;
                rightRotate(node->parent);
                sibling = node->parent->left;
            }
            if (sibling->left->color && sibling->right->color) {  // case 2 - sibling is black and both its children are black
                sibling->color = false;
                node = node->parent;
            }
            else {
                if (sibling->left->color) {  // case 3 - sibling is black, its right child is red and its left child is black
                    sibling->color = false;
                    sibling->left->color = true;
                    leftRotate(sibling);
                    sibling = node->parent->left;
                }
                // case 4 - sibling is black and its left child is red
                sibling->color = node->parent->color;
                node->parent->color = true;
                sibling->left->color = true;
                rightRotate(node->parent);
                break;
            }
        }
    }
    node->color = true;
}


#endif //CORMENBOOK_REDBLACKTREE_H
