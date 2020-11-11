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
    const Graph &g = session.getGraph();
    int numOfNodes = g.getNumOfNodes();

    vector<bool> visitedNodes(numOfNodes, false);
    queue<Tree *> trees;

    Tree *rootTree = getNewTree(session, rootLabel);
    trees.push(rootTree);
    visitedNodes[rootLabel] = true;
    while (!trees.empty()){
        popTreeBFS(trees, visitedNodes, g, session);
    }
    return rootTree;
}

void Tree::popTreeBFS(std::queue<Tree *> &trees, std::vector<bool> &visitedNodes, const Graph &g,
                      const Session &session) {
    Tree *tree = trees.front();
    trees.pop();
    // Tree *currentSonTree;
    int numOfNodes = g.getNumOfNodes();
    for (int otherNode = 0; otherNode < numOfNodes; otherNode++){
        if (g.edgeExists(tree->node, otherNode) && !visitedNodes[otherNode]){
            // currentSonTree = getNewTree(session, otherNode);
            tree->addChild(*getNewTree(session, otherNode));
            // trees.push(currentSonTree);
            visitedNodes[otherNode] = true;
        }
    }
    for (Tree *currentSon : tree->children){
        trees.push(currentSon);
    }
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


