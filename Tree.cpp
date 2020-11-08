//
// Created by spl211 on 07/11/2020.
//

#include "Tree.h"
#include "Graph.h"
#include "vector"
#include "Session.h"
using namespace std;

Tree::Tree(int rootLabel):node(rootLabel) {}


Tree* Tree::createTree(const Session &session, int rootLabel) {
        //Using bfs algorithm to create a tree
        Const Graph* g=session.getGraph();
        int numOfNodes=g->getNumOfNodes();
        bool visitedVertices[numOfNodes];
    for (int i = 0; i < numOfNodes; ++i) {
        visitedVertices[i]=false;
    }
    int currNode=rootLabel;
    queue<int>* neighbours1=new queue<int>();
    queue<int>* neighbours2=new queue<int>();
    neighbours1->push(currNode);
    while(!neighbours1->empty() && !neighbours2->empty())
    {
        vector<Tree*> *nextLevelNeighbours= new vector<Tree*>();
        while(!neighbours->empty()) {
            const int nextNeighbour = neighbours->front();
            neighbours->pop();
            if(!visitedVertices[nextNeighbour]) {
                nextLevelNeighbours->push_back(nextNeighbour);
                visitedVertices[nextNeighbour]=true;
            }
        }

    }

}

void

void Tree::addChild(const Tree &child) {

}

