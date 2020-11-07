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

void Session::enqueueInfected(int nodeInd) {
    infectionQueue.push(nodeInd);
}

int Session::dequeueInfected() {


}

int Session::getNodeToSpreadTo(int nodeFromInd) {
    return g.getNodeToSpreadTo(nodeFromInd);
};

void Session::addCarrier(int nodeInd) {
    g.setCarrier(nodeInd);
}

void Session::updateInfected(int newInfectedNodeInd) {
    g.infectNode(newInfectedNodeInd);
    enqueueInfected(newInfectedNodeInd);
}

bool Session::terminationConditionsSatisfied(){
    // TODO: implement
}

//
// Created by spl211 on 05/11/2020.
//
