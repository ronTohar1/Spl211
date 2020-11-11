//
// Created by spl211 on 07/11/2020.
//

#include "Tree.h"
#include "Graph.h"
#include "vector"
#include "Session.h"
using namespace std;

Tree::Tree(int rootLabel):node(rootLabel),numOfNodes(0) {}


Tree* Tree::createTree(const Session &session, int rootLabel) {
    //Using bfs algorithm to create a tree
    const Graph &g = session.getGraph();
    Tree *myTree = getNewTree(session, rootLabel);
    int numOfNodes = g.getNumOfNodes();
    myTree->numOfNodes = numOfNodes;

    vector<bool> *visitedVertices = new vector<bool>();
    for (int i = 0; i < numOfNodes; ++i) {
        visitedVertices->push_back(false);
    }
    (*visitedVertices)[rootLabel] = true;
    myTree->createChildrenTree(visitedVertices, g, session);


    delete visitedVertices;
    return myTree;

}

void Tree::createChildrenTree(std::vector<bool>* visitedVertices,const Graph &g,const Session &session) {
    queue<int>* neighboursOfRoot=g.getNeighbors(this->node);
    queue<int> notVisitedNeighbours;

    //taking all of the unvisited neighbours of the root node.
    while(!neighboursOfRoot->empty()){
        int neighbour=neighboursOfRoot->front();
        neighboursOfRoot->pop();
        if(!(*visitedVertices)[neighbour])
            notVisitedNeighbours.push(neighbour);
    }

    //Going through all of the neighbours that were not visited yet and adding them to this tree's children vector.
    while(!notVisitedNeighbours.empty()) {
        const int vertex = notVisitedNeighbours.front();
        notVisitedNeighbours.pop();
        (*visitedVertices)[vertex] = true;
        Tree *childTreeRef=getNewTree(session, vertex);
        this->addChild(*childTreeRef);
    }

    //Creating children tree to each one of this tree's children.
    for (int i = 0; i < this->children.size(); ++i) {
        Tree* childTree=this->children[i];
        childTree->createChildrenTree(visitedVertices,g,session);
    }

    delete neighboursOfRoot;
}



 Tree* Tree::getNewTree(const Session &session,int rootLabel) {
    TreeType type=session.getTreeType();
    if(type==Cycle)
        return (new CycleTree(rootLabel,session.getCurrCycle()));
    else if(type==MaxRank)
        return (new MaxRankTree(rootLabel));
    else
        return (new RootTree(rootLabel));

}

//Adding a child to the children array. adding it to the last place.
//Assuming the rootLabel of the input tree is bigger than all of the other children.
void Tree::addChild(const Tree &child) {
    Tree* childTree=child.clone();
    this->children.push_back(childTree);
}

int Tree::getRank() const {
    return children.size();
}

int Tree::getRoot() const {return this->node;}

const vector<Tree*> Tree::getChildren() const {return this->children;}

Tree::~Tree() {

    for (int i = 0; i < children.size(); ++i) {
        delete(children[i]);
    }

}


