#include "Session.h"
#include <vector>
#include "Agent.h"
#include "json.hpp"
#include <fstream>


Session::Session(const std::string &path) {
    nlohmann::json* jsonSessionData = getJsonDataFromFile(path);
    setGraph(Graph((*jsonSessionData)["graph"]));
    addAgents((*jsonSessionData)["agents"]);
    setTreeType((*jsonSessionData)["tree"]);
    delete jsonSessionData;
}

nlohmann::json* Session::getJsonDataFromFile(const std::string &path) {
    std::ifstream fileData(path);
    nlohmann::json* jsonData = new nlohmann::json();
    (*jsonData) << fileData;
    return jsonData;
}

void Session::addAgents(const nlohmann::json& jsonSessionData) {
    for (nlohmann::json jsonAgentData : jsonSessionData){
        addAgent(jsonAgentData);
    }
}

void Session::addAgent(const nlohmann::json &jsonAgentData) {
    Agent *newAgent;
    if (jsonAgentData[0] == "V"){
        newAgent = new Virus(jsonAgentData[1]);
        g.setCarrier(jsonAgentData[1]);
    }
    else if (jsonAgentData[0] == "C"){
        newAgent = new ContactTracer();
    }
    agents.push_back(newAgent);
}

void Session::simulate(){
    int cyclesStartingNumOfAgents;
    while (!terminationConditionsSatisfied()){
        cyclesStartingNumOfAgents = agents.size();
        for (int i = 0; i < cyclesStartingNumOfAgents; i++) {
            agents[i]->act(*this);
        }
    }
    writeOutput();
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

void Session::isolateNode(int nodeInd) {
    g.isolateNode(nodeInd);
}

bool Session::terminationConditionsSatisfied() const {
    return !g.areThereActiveConnectedComponents();
}

void Session::setTreeType(const std::string &stringTreeType) {
    if (stringTreeType == "C")
        treeType = Cycle;
    else if (stringTreeType == "M")
        treeType = MaxRank;
    else if (stringTreeType == "R")
        treeType = Root;
}

void Session::writeOutput() const {
    std::ofstream outputFile("../output.json");
    nlohmann::json jsonOutput;
    jsonOutput["graph"] = g.getEdges();
    std::vector<int> *infectedNodes = g.getAllInfected();
    jsonOutput["infected"] = *infectedNodes;
    outputFile << jsonOutput;
    delete infectedNodes;
}

const Graph &Session::getGraph() const {
    return this->g;
}
