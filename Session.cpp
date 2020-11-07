#include "Session.h"
#include <vector>
#include "Agent.h"


void Session::simulate(){
    int cyclesStartingNumOfAgents;
    while (!TerminationConditionsSatisfied()){
        cyclesStartingNumOfAgents = agents.size();
        for (int i = 0; i < cyclesStartingNumOfAgents; ++i) {
            agents[i]->act(*this);
        }
    }
};

void Session::addAgent(const Agent &agent) {
    Agent *a= agent.clone();
    agents.push_back(a);
}

void Session::enqueueInfected(int nodeInd) {
    if(!g.isInfected(nodeInd)) // Virus is not infected
    {
        g.infectNode(nodeInd);
        infectionQueue.push(nodeInd);
    }
}

int Session::dequeueInfected() {


}

bool Session::TerminationConditionsSatisfied(){
    // TODO: implement
};
//
// Created by spl211 on 05/11/2020.
//
