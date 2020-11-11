//
// Created by spl211 on 09/11/2020.
//

#include "Tree.h"
#include "vector"
using namespace std;

MaxRankTree::MaxRankTree(int rootLabel):Tree(rootLabel) {}

int MaxRankTree::traceTree() {

    int maxRankVertex= this->maxRankTreeTrace();
    return maxRankVertex;
}



int MaxRankTree::getMaxRankNode() {
    vector<int> &ranks=getRanks();
    vector<Tree*> children=this->getChildren();
    int highestRankNode=children[0]->getRoot();

    if(this->getRank()==0)
        return highestRankNode;

    int highestRankChild=this->getMaxRankChild();
    if(ranks[highestRankChild]>ranks[highestRankNode])
        return highestRankChild;

    return highestRankNode;
}

int MaxRankTree::getMaxRankChild() {
    vector<int> &ranks=getRanks();
    vector<Tree*> children=this->getChildren();
    int highestRankChild=(children[0])->traceTree();

    int highestRankNode=highestRankChild;

    for (int i = 1; i < children.size(); ++i) {

        int currHighestRank=children[i]->getRoot();

        if(ranks[currHighestRank]>ranks[highestRankNode])
            highestRankNode = currHighestRank;

    }

    return highestRankNode;
}

int MaxRankTree::maxRankTreeTrace() {
    int nodeIndex=getMaxRankNode();
    return nodeIndex;
}

MaxRankTree * MaxRankTree::clone() const {
    return new MaxRankTree(*this);
}

