#include "Session.h"
#include <vector>
#include "Agent.h"


void Session::simulate(){
    int cyclesStartingNumOfAgents;
    while (!terminationConditionsSatisfied()){
        cyclesStartingNumOfAgents = agents.size();
        for (int i = 0; i < cyclesStartingNumOfAgents; i++) {
            agents[i]->act(*this);
        }
    }
};

void Session::addAgent(const Agent &agent) {
    Agent *a= agent.clone();
    agents.push_back(a);
}

void Session::setGraph(const Graph &graph) {
    g = graph;
}

void Session::enqueueInfected(int nodeInd) {
    infectionQueue.push(nodeInd);
}

int Session::dequeueInfected() {
    int infectedNodeInd = infectionQueue.front();
    infectionQueue.pop();
    return infectedNodeInd;
}

TreeType Session::getTreeType() const {
    return treeType;
}

int Session::getNodeToSpreadTo(int nodeFromInd) const {
    return g.getNodeToSpreadTo(nodeFromInd);
};

void Session::addCarrier(int nodeInd) {
    g.setCarrier(nodeInd);
}

void Session::updateInfected(int newInfectedNodeInd) {
    g.infectNode(newInfectedNodeInd);
    enqueueInfected(newInfectedNodeInd);
}

bool Session::terminationConditionsSatisfied() const {
    // TODO: implement
}

//
// Created by spl211 on 05/11/2020.
//
