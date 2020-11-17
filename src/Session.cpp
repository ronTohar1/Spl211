#include "../include/Session.h"
#include <vector>
#include "../include/Agent.h"
#include "../json.hpp"
#include <fstream>


Session::Session(const std::string &path) : g(), treeType(), agents(), infectionQueue(), currCycle(0) {
    nlohmann::json* jsonSessionData = getJsonDataFromFile(path);
    setGraph(Graph((*jsonSessionData)["graph"]));
    addAgents((*jsonSessionData)["agents"]);
    setTreeType((*jsonSessionData)["tree"]);
    // safe delete of jsonSessionData:
    if (jsonSessionData != nullptr){
        delete jsonSessionData;
        jsonSessionData = nullptr;
    }
}

// a private method that returns a pointer to a json data object with the data of the file in the given path
nlohmann::json* Session::getJsonDataFromFile(const std::string &path) {
    std::ifstream fileData(path); // reads the data from the file
    nlohmann::json* jsonData = new nlohmann::json();
    (*jsonData) << fileData; // saving the data in the json object
    return jsonData;
}

void Session::setGraph(const Graph &graph) {
    g = graph; // using the copy assignment operator
}

// adds the agents in the json data object to this Session
void Session::addAgents(const nlohmann::json &jsonSessionData) {
    for (const nlohmann::json &jsonAgentData : jsonSessionData){
        addAgent(jsonAgentData); // this private method creates and adds the new Agent to agents
    }
}

// creates a new Agent according to the given json data, and adds it to this Session
void Session::addAgent(const nlohmann::json &jsonAgentData) {
    Agent *newAgent; // the pointer to the new Agent
    if (jsonAgentData[0] == "V"){ // create a Virus
        newAgent = new Virus(jsonAgentData[1]);
        g.setCarrier(jsonAgentData[1]); // updating the graph that the node carries a virus
    }
    else if (jsonAgentData[0] == "C"){ // create a ContactTracer
        newAgent = new ContactTracer();
    }
    agents.push_back(newAgent); // adding the new Agent pointer to the last position in agents
}

// sets the TreeType of this graph according to the given string type
void Session::setTreeType(const std::string &stringTreeType) {
    if (stringTreeType == "C")
        treeType = Cycle;
    else if (stringTreeType == "M")
        treeType = MaxRank;
    else if (stringTreeType == "R")
        treeType = Root;
}

void Session::simulate(){
    int cyclesStartingNumOfAgents;
    while (!terminationConditionsSatisfied()){
        cyclesStartingNumOfAgents = agents.size(); // so only the agents that existed before this cycle will act
        for (int i = 0; i < cyclesStartingNumOfAgents; i++) {
            agents[i]->act(*this);
        }
        currCycle = currCycle + 1;
    }
    writeOutput(); // write the simulation's output to the output file of this Session
};

bool Session::terminationConditionsSatisfied() const {
    return !g.areThereActiveConnectedComponents();
}

// Writes the state of this Session to its output file
void Session::writeOutput() const {
    // creating the necessary objects for writing the output:
    std::ofstream outputFile("output.json");
    nlohmann::json jsonOutput;
    // saving the data of this Session in the json object:
    jsonOutput["graph"] = g.getEdges();
    std::vector<int> *infectedNodes = g.getAllInfected();
    jsonOutput["infected"] = *infectedNodes;
    // writing the json object to the json file:
    outputFile << jsonOutput;
    // safe delete of the used memory:
    if (infectedNodes != nullptr){
        delete infectedNodes;
        infectedNodes = nullptr;
    }
}

void Session::addAgent(const Agent &agent) {
    Agent *a= agent.clone();
    agents.push_back(a);
}

void Session::enqueueInfected(int nodeInd) {
    infectionQueue.push(nodeInd); // adds the infected node to the end of the queue
}

int Session::dequeueInfected() {
    int infectedNodeInd = infectionQueue.front(); // saving the value before removing it from the queue
    infectionQueue.pop(); // removing the value from the queue
    return infectedNodeInd;
}

TreeType Session::getTreeType() const {
    return treeType;
}

// this method updates this Session to have the given node infected, by updating the graph and enqueuing the node to
// the infection queue
void Session::updateInfected(int newInfectedNodeInd) {
    g.infectNode(newInfectedNodeInd);
    enqueueInfected(newInfectedNodeInd);
}

// setting the given node to be a carrier in the graph
void Session::addCarrier(int nodeInd) {
    g.setCarrier(nodeInd); // updating the graph that this node is a carrier
}

// returns a node for the virus to spread to from the given node, or -1 if there is no node to spread to
int Session::getNodeToSpreadTo(int nodeFromInd) const {
    return g.getNodeToSpreadTo(nodeFromInd);
};

// isolates the given node in the graph
void Session::isolateNode(int nodeInd) {
    g.isolateNode(nodeInd);
}

bool Session::isInfectionQueueEmpty() const {
    return infectionQueue.empty();
}

const Graph &Session::getGraph() const {
    return this->g;
}

int Session::getCurrCycle() const {
    return currCycle;
}

// rule of 5

Session::Session(const Session &other) : g(other.g), treeType(other.treeType), agents(),
                                         infectionQueue(other.infectionQueue), currCycle(other.currCycle) {
    copyAgents(other);
}

Session & Session::operator=(const Session &other){
    if (this != &other){
        g = other.g;
        treeType = other.treeType;
        deleteAgents();
        agents.clear();
        copyAgents(other);
        infectionQueue = other.infectionQueue;
        currCycle = other.currCycle;
    }
    return *this;
}
Session::~Session() {
    deleteAgents();
}

Session::Session(const Session &&other) : g(std::move(other.g)), treeType(std::move(other.treeType)),
                                          agents(std::move(other.agents)),
                                          infectionQueue(std::move(other.infectionQueue)),
                                          currCycle(std::move(other.currCycle)) {

}

void Session::copyAgents(const Session &other) {
    for (Agent *agent : other.agents)
        agents.push_back(agent->clone());
}

void Session::deleteAgents() {
    for (Agent *agent : agents){
        if (agent != nullptr){
            delete agent;
            agent = nullptr;
        }
    }
}