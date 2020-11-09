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
        const Graph &g=session.getGraph();
        TreeType type=session.getTreeType();//Need to initialize children somehow...? or no need ?
        Tree* myTree=getNewTree(type,rootLabel);
        int numOfNodes=g.getNumOfNodes();
        vector<bool>* visitedVertices= new vector<bool>();
    for (int i = 0; i < numOfNodes; ++i) {
        visitedVertices->push_back(false);
    }
    visitedVertices->at(rootLabel)=true;
    myTree->createChildrenTree(visitedVertices,g,type);


}

void Tree::createChildrenTree(std::vector<bool>* visitedVertices,const Graph &g,TreeType type) {
    queue<int> neighboursOfRoot=g.getNeighbors(this->node);
    queue<int> notVisitedNeighbours;

    while(!neighboursOfRoot.empty()){
        int neighbour=neighboursOfRoot.front();
        neighboursOfRoot.pop();
        if(!visitedVertices->at(neighbour))
            notVisitedNeighbours.push(neighbour);
    }
    //Going through all of the neighbours that were not visited yet.
    while(!notVisitedNeighbours.empty()) {
        const int vertex = notVisitedNeighbours.front();
        notVisitedNeighbours.pop();
        visitedVertices->at(vertex) = true;
        Tree *childTree = getNewTree(type, vertex);
        this->children.push_back(childTree);

    }
    for (int i = 0; i < this->children.size(); ++i) {
        Tree* childTree=this->children[i];
        childTree->createChildrenTree(visitedVertices,g,type);
    }
}

Tree* Tree::getNewTree(TreeType type,int rootLabel) {


}

void Tree::addChild(const Tree &child) {

}

