// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

#include  "bst.h"


BST<std::string> makeTree(const char* filename) {
    std::string word;
    BST<std::string> tree;
    std::ifstream file(filename);
    if (file) {
        while (!file.eof()) {
            char s = tolower(file.get());
            if (!isalpha(s)) {
                if (!word.empty()) {
                    tree.add(word);
                }
                word.clear();
            }
            else {
                word += s;
            }
        }
    }
    else {
        std::cout << "Error!" << std::endl;
    }
    file.close();
    return tree;
}
