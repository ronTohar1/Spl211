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
    (*visitedVertices)[rootLabel]=true;
    myTree->createChildrenTree(visitedVertices,g,type);


}

void Tree::createChildrenTree(std::vector<bool>* visitedVertices,const Graph &g,TreeType type) {
    queue<int> neighboursOfRoot=g.getNeighbors(this->node);
    queue<int> notVisitedNeighbours;
    //taking all of the unvisited neighbours of the root node.
    while(!neighboursOfRoot.empty()){
        int neighbour=neighboursOfRoot.front();
        neighboursOfRoot.pop();
        if(!(*visitedVertices)[neighbour])
            notVisitedNeighbours.push(neighbour);
    }
    //Going through all of the neighbours that were not visited yet and adding them to this tree's children vector.
    while(!notVisitedNeighbours.empty()) {
        const int vertex = notVisitedNeighbours.front();
        notVisitedNeighbours.pop();
        (*visitedVertices)[vertex] = true;
        const Tree &childTreeRef=getNewTree(type, vertex);
        this->addChild(childTreeRef);

    }
    //Creating children tree to each one of this tree's children.
    for (int i = 0; i < this->children.size(); ++i) {
        Tree* childTree=this->children[i];
        childTree->createChildrenTree(visitedVertices,g,type);
    }
}

const Tree& Tree::getNewTree(TreeType type,int rootLabel) {
    if(type==Cycle)
        return *(new CycleTree(rootLabel,Session.currCycle));
    else if(type==MaxRank)
        return *(new MaxRankTree(rootLabel));
    else
        return *(new RootTree(rootLabel));

}

void Tree::addChild(const Tree &child) {
    const Tree* childTree=&child;
    int nodeToInsert=child.node;
    int indexToInsert=0;
    while(this->children[indexToInsert]->node>nodeToInsert){
        indexToInsert++;
    }
    //why do we get *const* reference if we need to insert a *not const* pointer??
    this->children.push_back(const_cast<Tree *&&>(childTree));
    for (int i = this->children.size()-1; i >indexToInsert; --i) {
        Tree* temp=this->children[i];
        this->children[i]=this->children[i-1];
        this->children[i-1]=temp;
    }

}

int Tree::getRank() const {
    return children.size();
}

int Tree::getRoot() const {return this->node;}

const vector<Tree*> Tree::getChildren() const {return this->children;}
