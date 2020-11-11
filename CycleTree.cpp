//
// Created by spl211 on 09/11/2020.
//

#include "Tree.h"
#include "vector"
using namespace std;

CycleTree::CycleTree(int rootLabel, int currCycle):Tree(rootLabel),currCycle(currCycle) {}

int CycleTree::traceTree() {
        Tree *currTree=this;
        bool flag=false;

    for (int i = 0; i < currCycle && !flag; ++i) {
        if(currTree->getRank()>0) {
            currTree=(currTree->getChildren())[0];
        }
        else
        {
            flag=true;
        }
    }
    return currTree->getRoot();
}

CycleTree * CycleTree::clone() const {
    return new CycleTree(*this);
}