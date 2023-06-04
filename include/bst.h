// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <algorithm>
template<typename T>
class BST {
private:
    struct Node {
        T value;
        Node* left, * right;
        int count;
        explicit Node(T value) : value(value), count(1), left(nullptr), right(nullptr) {}
    };

public:
    Node* roottree;
    BST() : roottree(nullptr) {}
    int search(T value) {
        return searchNode(roottree, value);
    }
    int depth() {
        return getDepth(roottree) - 1;
    }
    int searchNode(Node* roottree, T value) {
        if (!roottree)
            return 0;
        if (value == roottree->value)
            return roottree->count;
        if (value < roottree->value)
            return searchNode(roottree->left, value);
        else
            return searchNode(roottree->right, value);
    }
    void add(T value) {
        roottree = insertWord(roottree, value);
    }
    int getDepth(Node* root) {
        if (root)
            return std::max(getDepth(root->left), 1 + getDepth(root->right));
        else
            return 0;
    }
    Node* insertWord(Node* pointer, T word) {
        if (pointer == nullptr) {
            pointer = new Node(word);
        }
        else if (pointer->value < word) {
            pointer->right = insertWord(pointer->right, word);
        }
        else if (pointer->value > word) {
            pointer->left = insertWord(pointer->left, word);
        }
        else if (pointer->value == word) {
            pointer->count++;
        }
        return pointer;
    }
};
#endif  // INCLUDE_BST_H_
