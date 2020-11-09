//
// Created by spl211 on 09/11/2020.
//

#include "Tree.h"
#include "vector"
using namespace std;

MaxRankTree::MaxRankTree(int rootLabel):Tree(rootLabel) {}

int MaxRankTree::traceTree() {
    return (*getMaxRankNode())[1];
}



vector<int>* MaxRankTree::getMaxRankNode() {
    vector<Tree*> children=this->getChildren();
    vector<int>* highestRankNode;
    highestRankNode->push_back(this->getRank());
    highestRankNode->push_back(this->getRoot());
    if(this->getRank()==0)
        return highestRankNode;
    vector<int>* highestRankChild=this->getMaxRankChild();
    if((*highestRankChild)[0]>(*highestRankNode)[0])
        return highestRankChild;
    return highestRankNode;
}

std::vector<int>* MaxRankTree::getMaxRankChild() {

    vector<Tree*> children=this->getChildren();
    vector<int>* highestRankNode=((MaxRankTree*)children[0])->getMaxRankNode();
    for (int i = 1; i < children.size(); ++i) {
        vector<int>* currHighestRank=((MaxRankTree*)children[i])->getMaxRankNode();
        if((*currHighestRank)[0]>(*highestRankNode)[0])
            highestRankNode=currHighestRank;
    }

    return highestRankNode;
}