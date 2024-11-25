#pragma once

#include <algorithm>

template<class T>
class AVL {
public:
    struct Node {
        Node* left;
        Node* right;
        T value;
        int height;

        Node(T v) : left(nullptr), right(nullptr), value(v), height(1) {}
    };

    AVL() : root(nullptr), node_count(0) {}

    ~AVL() {
        clear();
    }

    const Node* getRootNode() const {
        return root;
    }

    bool insert(T item) {
        if (contains(item)) return false;
        root = insertNode(root, item);
        node_count++;
        return true;
    }

    bool remove(T item) {
        if (!contains(item)) return false;
        root = removeNode(root, item);
        node_count--;
        return true;
    }

    bool contains(T item) const {
        return findNode(root, item) != nullptr;
    }

    void clear() {
        clearTree(root);
        root = nullptr;
        node_count = 0;
    }

    int size() const {
        return node_count;
    }

private:
    Node* root;
    int node_count;

    int getHeight(Node* node) {
        return node ? node->height : 0;
    }

    int getBalanceFactor(Node* node) {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    void updateHeight(Node* node) {
        if (node) {
            node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
        }
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    Node* rebalance(Node* node) {
        updateHeight(node);

        int balance = getBalanceFactor(node);

        if (balance > 1) {
            if (getBalanceFactor(node->left) < 0)
                node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balance < -1) {
            if (getBalanceFactor(node->right) > 0)
                node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    Node* insertNode(Node* node, T item) {
        if (!node) return new Node(item);

        if (item < node->value)
            node->left = insertNode(node->left, item);
        else
            node->right = insertNode(node->right, item);

        return rebalance(node);
    }

    Node* findMin(Node* node) {
        while (node->left) node = node->left;
        return node;
    }

    Node* removeNode(Node* node, T item) {
        if (!node) return node;

        if (item < node->value) {
            node->left = removeNode(node->left, item);
        } else if (item > node->value) {
            node->right = removeNode(node->right, item);
        } else {
            if (!node->left || !node->right) {
                Node* temp = node->left ? node->left : node->right;
                delete node;
                return temp;
            } else {
                Node* temp = findMin(node->right);
                node->value = temp->value;
                node->right = removeNode(node->right, temp->value);
            }
        }

        return rebalance(node);
    }

    Node* findNode(Node* node, T item) const {
        if (!node) return nullptr;
        if (item < node->value) return findNode(node->left, item);
        if (item > node->value) return findNode(node->right, item);
        return node;
    }

    void clearTree(Node* node) {
        if (node) {
            clearTree(node->left);
            clearTree(node->right);
            delete node;
        }
    }
};
