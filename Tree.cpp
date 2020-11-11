//
// Created by spl211 on 07/11/2020.
//

#include "Tree.h"
#include "Graph.h"
#include "vector"
#include "Session.h"
using namespace std;

Tree::Tree(int rootLabel):node(rootLabel),numOfNodes(0), ranks(new std::vector<int>()) {}


Tree* Tree::createTree(const Session &session, int rootLabel) {
    //Using bfs algorithm to create a tree
    const Graph &g = session.getGraph();
    TreeType type = session.getTreeType();//Need to initialize children somehow...? or no need ?
    Tree *myTree = &(getNewTree(session, rootLabel));
    int numOfNodes = g.getNumOfNodes();
    myTree->numOfNodes = numOfNodes;

    vector<bool> *visitedVertices = new vector<bool>();
    for (int i = 0; i < numOfNodes; ++i) {
        visitedVertices->push_back(false);
    }
    (*visitedVertices)[rootLabel] = true;
    myTree->createChildrenTree(visitedVertices, g, session);

    //Setting the ranks vector .

    for (int i = 0; i < myTree->numOfNodes; ++i) {
        myTree->getRanks().push_back(0);
    }
    myTree->setRanks((myTree->ranks),myTree);


    delete visitedVertices;
    return myTree;

}

void Tree::setRanks(vector<int>* ranks,Tree* tree){
    (*ranks)[tree->getRoot()]=(tree->getRank());
    vector<Tree*> children=tree->getChildren();
    for (int i = 0; i < children.size(); ++i) {
        setRanks(ranks,children[i]);
    }
}

void Tree::createChildrenTree(std::vector<bool>* visitedVertices,const Graph &g,Session session) {
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
        Tree &childTreeRef=getNewTree(session, vertex);
        this->addChild(childTreeRef);

    }
    //Creating children tree to each one of this tree's children.
    for (int i = 0; i < this->children.size(); ++i) {
        Tree* childTree=this->children[i];
        childTree->createChildrenTree(visitedVertices,g,session);
    }

    delete neighboursOfRoot;
}

 Tree& Tree::getNewTree(const Session session,int rootLabel) {
    TreeType type=session.getTreeType();
    if(type==Cycle)
        return *(new CycleTree(rootLabel,session.getCurrCycle()));
    else if(type==MaxRank)
        return *(new MaxRankTree(rootLabel));
    else
        return *(new RootTree(rootLabel));

}

//Adding in a sorted way. not needed if we recieve the nodes by order. need to check
void Tree::addChild(const Tree &child) {
    const Tree* childTree=&child;
    int nodeToInsert=child.node;
    int indexToInsert=0;
    while(indexToInsert < this->children.size() && this->children[indexToInsert]->node>nodeToInsert){
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
    return (getRanks())[this->node];
}

int Tree::getRoot() const {return this->node;}

const vector<Tree*> Tree::getChildren() const {return this->children;}

Tree::~Tree() {

    delete ranks;
    for (int i = 0; i < children.size(); ++i) {
        delete(children[i]);
    }

}

std::vector<int> &Tree::getRanks() const {
    return *ranks;
}
