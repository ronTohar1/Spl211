//
// Created by spl211 on 10/11/2020.
//
#include "Tree.h"
#include "Agent.h"


ContactTracer::ContactTracer() : Agent() {

}

ContactTracer * ContactTracer::clone() const {

    return new ContactTracer();

}

void ContactTracer::act(Session &session) {

    int infectedNode=session.dequeueInfected();
    if(infectedNode!=-1){
        Tree* tree= Tree::createTree(session,infectedNode);
        int nodeToIsolate=tree->traceTree();
        session.isolateNode(nodeToIsolate);
    }
}
