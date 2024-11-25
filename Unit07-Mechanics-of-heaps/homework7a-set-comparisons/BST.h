#pragma once

#include <iostream>

template<class T>
class BST {
public:
    struct Node {
        Node* left;
        Node* right;
        T value;

        Node(T v) : left(nullptr), right(nullptr), value(v) {}
    };

    BST() : root(nullptr), treeSize(0) {}

    ~BST() {
        clear();
    }

    const Node* getRootNode() const {
        return root;
    }

    bool insert(T item) {
        if (!root) {
            root = new Node(item);
            treeSize++;
            return true;
        }
        return insertHelper(root, item);
    }

    bool remove(T item) {
        bool removed = false;
        root = removeHelper(root, item, removed);
        if (removed) treeSize--;
        return removed;
    }

    bool contains(T item) const {
        return containsHelper(root, item);
    }

    void clear() {
        clearHelper(root);
        root = nullptr;
        treeSize = 0;
    }

    int size() const {
        return treeSize;
    }

private:
    Node* root;
    int treeSize;

    bool insertHelper(Node* node, T item) {
        if (item == node->value) {
            return false; // Duplicate item
        }
        if (item < node->value) {
            if (node->left) {
                return insertHelper(node->left, item);
            } else {
                node->left = new Node(item);
                treeSize++;
                return true;
            }
        } else {
            if (node->right) {
                return insertHelper(node->right, item);
            } else {
                node->right = new Node(item);
                treeSize++;
                return true;
            }
        }
    }

    Node* removeHelper(Node* node, T item, bool& removed) {
        if (!node) {
            removed = false;
            return nullptr;
        }

        if (item < node->value) {
            node->left = removeHelper(node->left, item, removed);
        } else if (item > node->value) {
            node->right = removeHelper(node->right, item, removed);
        } else {
            removed = true;
            if (!node->left && !node->right) {
                delete node;
                return nullptr;
            }
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* iop = findInOrderPredecessor(node->left);
            node->value = iop->value;
            node->left = removeHelper(node->left, iop->value, removed);
        }
        return node;
    }

    bool containsHelper(Node* node, T item) const {
        if (!node) return false;
        if (item == node->value) return true;
        if (item < node->value) return containsHelper(node->left, item);
        return containsHelper(node->right, item);
    }

    void clearHelper(Node* node) {
        if (!node) return;
        clearHelper(node->left);
        clearHelper(node->right);
        delete node;
    }

    Node* findInOrderPredecessor(Node* node) {
        while (node->right) {
            node = node->right;
        }
        return node;
    }
};


