//
// Created by spl211 on 09/11/2020.
//

#include "../include/Tree.h"
#include "vector"
using namespace std;

MaxRankTree::MaxRankTree(int rootLabel):Tree(rootLabel) {}

int MaxRankTree::traceTree() {
    int maxRankVertex= this->maxRankTreeTrace();
    return maxRankVertex;
}



int MaxRankTree::getMaxRankNode() {
     queue<const Tree*>* treeQueue=getTreeQueue();

     const Tree* maxTree=treeQueue->front();
     treeQueue->pop();
     int maxNodeIndex=maxTree->getRoot();
     int maxNodeRank=maxTree->getRank();

     //Finding the max Ranked node.
     while(!treeQueue->empty()){
         maxTree=treeQueue->front();
         treeQueue->pop();
         if(maxNodeRank<maxTree->getRank()){
             maxNodeIndex=maxTree->getRoot();
             maxNodeRank=maxTree->getRank();
         }
     }
     delete treeQueue;
     return maxNodeIndex;
}



int MaxRankTree::maxRankTreeTrace() {
    int nodeIndex=getMaxRankNode();
    return nodeIndex;
}

//Returns a queue ordered by an InOrder traversal of the tre.
 std::queue<const Tree*>* MaxRankTree::getTreeQueue() {
    queue<const Tree*>* tree= new queue<const Tree*>();
    queue<const Tree*> tempNodes;
    tempNodes.push(this);
    addChildrenToQueue(tempNodes,*tree);
    return tree;

}

void MaxRankTree::addChildrenToQueue(std::queue<const Tree *> &tempQueue,std::queue<const Tree *> &treeQueue) {
    while(!tempQueue.empty()){
        const Tree* nextTree=tempQueue.front();
        tempQueue.pop();
        treeQueue.push(nextTree);
        //Adding the tree neighbours to the queue.
        const vector<Tree*> children=nextTree->getChildren();
        for (int i = 0; i < children.size(); ++i) {
            tempQueue.push(children[i]);
        }
    }

}

MaxRankTree * MaxRankTree::clone() const {
    return new MaxRankTree(*this);
}

