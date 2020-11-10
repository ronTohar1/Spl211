//
// Created by spl211 on 09/11/2020.
//

#include "Tree.h"
#include "vector"
using namespace std;

CycleTree::CycleTree(int rootLabel, int currCycle):Tree(rootLabel),currCycle(currCycle) {}

int CycleTree::traceTree() {
        vector<Tree*> children=this->getChildren();
        bool flag=false;
    for (int i = 0; i < currCycle && !flag; ++i) {
        if(this->getRank()>0) {
            children=(*(children[0])).getChildren();
        }
        else
        {
            flag=true;
        }
    }
    return this->getRoot();
}