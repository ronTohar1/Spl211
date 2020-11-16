//
// Created by spl211 on 09/11/2020.
//

#include "../include/Tree.h"

RootTree::RootTree(int rootLabel):Tree(rootLabel) {
}

int RootTree::traceTree() {
        return this->getRoot();
}

RootTree * RootTree::clone() const {
    return new RootTree(*this);
}