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



vector<int>* MaxRankTree::getMaxRankNode() {
    vector<Tree*> children=this->getChildren();
    vector<int> *highestRankNode = new vector<int>();
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
    int highestRankChild=(children[0])->traceTree();

    vector<int>* highestRankNode=new vector<int>();
    highestRankNode->push_back(ranks.at(highestRankChild));
    highestRankNode->push_back(highestRankChild);

    for (int i = 1; i < children.size(); ++i) {

        vector<int>* currHighestRank=new vector<int>();
        int childHighestRank=(children[i])->traceTree();
        currHighestRank->push_back(ranks.at(childHighestRank));
        currHighestRank->push_back(childHighestRank);

        if((*currHighestRank)[0]>(*highestRankNode)[0])
            highestRankNode=currHighestRank;
    }

    return highestRankNode;
}

int MaxRankTree::maxRankTreeTrace() {
    vector<int>* x= getMaxRankNode();
    int nodeIndex=(*x)[1];
    delete x;
    return nodeIndex;
}


