//
// Created by spl211 on 07/11/2020.
//

#include "../include/Tree.h"
#include "../include/Graph.h"
#include "vector"
#include "../include/Session.h"
using namespace std;

Tree::Tree(int rootLabel):node(rootLabel),children() {}

//Assignment operator
Tree &Tree::operator=(const Tree &tree) {
    if(this!=&tree) {
        //Deleting all of my children.
        deleteChildren();
        //Copying the tree's node and it's children.
        this->node=tree.node;
        copyChildren(tree);
    }
    return *this;

}

//Move Assignment operator
Tree &Tree::operator=(Tree &&tree) {
    if(this!=&tree){
        this->node=tree.node;
        //Deleting all of my children.
        deleteChildren();
        this->children=tree.children;//Moving the children
        tree.children.clear();//Clearing the other tree children so this tree's children won't be deleted.
    }
    return *this;

}

//Move Constructor
Tree::Tree(Tree &&tree):node(tree.node), children(std::move(tree.children)) {
}

//Copy Constructor
Tree::Tree(const Tree &tree):node(tree.node),children() {
    copyChildren(tree);
}

//Destructor
Tree::~Tree() {

    for (unsigned i = 0; i < children.size(); ++i) {
        if(children[i]){
            delete(children[i]);
            children[i]=nullptr;
        }
    }

}

Tree* Tree::createTree(const Session &session, int rootLabel) {
    //Using bfs algorithm to create a tree
    const Graph &g = session.getGraph();
    int numOfNodes = g.getNumOfNodes();

    vector<bool> visitedNodes(numOfNodes, false);
    queue<Tree *> trees;

    Tree *rootTree = getNewTree(session, rootLabel);
    trees.push(rootTree);
    visitedNodes[rootLabel] = true;

    //Implementing the BFS algorithm
    while (!trees.empty()){
        popTreeBFS(trees, visitedNodes, g, session);
    }

    return rootTree;
}

//BFS algorithm
void Tree::popTreeBFS(std::queue<Tree *> &trees, std::vector<bool> &visitedNodes, const Graph &g,
                      const Session &session) {

    Tree *tree = trees.front();
    trees.pop();
    int numOfNodes = g.getNumOfNodes();

    //Adding each not visited neighbour to the children vector.
    for (int otherNode = 0; otherNode < numOfNodes; otherNode++){
        if (g.edgeExists(tree->node, otherNode) && !visitedNodes[otherNode]){

            Tree * treeToAdd=getNewTree(session, otherNode);
            tree->addChild(treeToAdd);//Adding the new tree directly without cloning.
            visitedNodes[otherNode] = true;
        }
    }

    //Adding the children to the queueu in order to implement the BFS algorithm.
    for (Tree *currentSon : tree->children){
        trees.push(currentSon);
    }
}


//Method returns a new tree according to the Tree type in the session.
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
//Overloading addChild-> adding a tree directly to the children vector without cloning.
void Tree::addChild( Tree *child) {
    this->children.push_back(child);
}

int Tree::getRank() const {
    return children.size();
}

int Tree::getRoot() const {return this->node;}

const vector<Tree*> Tree::getChildren() const {return this->children;}

//Deep copying the children of the other tree.
void Tree::copyChildren(const Tree &other) {
    if(this!=&other){
        for (unsigned i = 0;i < other.children.size(); ++i) {
            addChild(*other.children[i]);
        }
    }
}

//Deletes all of the children of the tree.
void Tree::deleteChildren() {

    for (unsigned i = 0; i < children.size(); ++i) {

        if (children[i]) {
            delete children[i];
            children[i] = nullptr;
        }
        children.clear();
    }
}








