#include "Session.h"
#include <vector>
#include "Agent.h"
#include "json.hpp"
#include <fstream>


Session::Session(const std::string &path) {
    nlohmann::json jsonSessionData = getJsonDataFromFile(path);
    setGraph(Graph(jsonSessionData["Graph"]));
//    agents = jsonSessionData["Agents"];

}

void Session::simulate(){
    int cyclesStartingNumOfAgents;
    while (!terminationConditionsSatisfied()){
        cyclesStartingNumOfAgents = agents.size();
        for (int i = 0; i < cyclesStartingNumOfAgents; i++) {
            agents[i]->act(*this);
        }
    }
};



nlohmann::json Session::getJsonDataFromFile(const std::string &path) {
    std::ifstream fileData(path);
    nlohmann::json jsonData;
    jsonData << fileData;
    return jsonData;
}

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

void Session::isolateNode(int nodeInd) {
    g.isolateNode(nodeInd);
}

bool Session::terminationConditionsSatisfied() const {
    return !g.areThereActiveConnectedComponents();
}
