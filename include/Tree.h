#ifndef TREE_H_
#define TREE_H_

#include <vector>
#include "Session.h"
class Session;

class Tree{
public:
    Tree(int rootLabel);//Constructor
    //Rule of 5 implementation --------------------------------
    Tree(Tree &&tree);//Move Copy Constructor
    Tree(const Tree &tree);//Copy  Constructor
     Tree& operator=(const Tree& tree);//Assignment Operator
    Tree& operator=(Tree &&tree);//Move Assignment Operator
    virtual ~Tree();//Destructor
    //---------------------------------------------------------
    void addChild(const Tree& child);
    const std::vector<Tree*> getChildren() const;
    int getRoot() const;
    int getRank() const;
    static Tree* createTree(const Session& session, int rootLabel);
    virtual Tree * clone() const = 0;
    virtual int traceTree()=0;


private:
    int node;
    std::vector<Tree*> children;

    void addChild( Tree* child);
    void copyChildren(const Tree& other);
    void deleteChildren();
    static Tree* getNewTree(const Session &session,int rootLabel);
    static void popTreeBFS(std::queue<Tree *> &trees, std::vector<bool> &visitedNodes, const Graph &g,
    const Session &session);
};

class CycleTree: public Tree{
public:
    CycleTree(int rootLabel, int currCycle);
    virtual int traceTree();
    virtual CycleTree * clone() const;
private:
    int currCycle;
};

class MaxRankTree: public Tree{
public:
    MaxRankTree(int rootLabel);
    virtual int traceTree();
    virtual MaxRankTree * clone() const;
private:
    int maxRankTreeTrace();
    int getMaxRankNode();
    void addChildrenToQueue(std::queue<const Tree *> &tempQueue,std::queue<const Tree*> &treeQueue);
    std::queue<const Tree*>* getTreeQueue();

};

class RootTree: public Tree{
public:
    RootTree(int rootLabel);
    virtual int traceTree();
    virtual RootTree * clone() const;
};

#endif
