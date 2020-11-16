//
// Created by spl211 on 09/11/2020.
//

#include "../include/Tree.h"
#include "vector"
using namespace std;

CycleTree::CycleTree(int rootLabel, int currCycle):Tree(rootLabel),currCycle(currCycle) {}

int CycleTree::traceTree() {

    Tree *currentTree = this;
    for (int i = 0; i < currCycle && currentTree->getRank() > 0; ++i) {
        currentTree = currentTree->getChildren()[0];
    }
    return currentTree->getRoot();
}

CycleTree * CycleTree::clone() const {
    return new CycleTree(*this);
}