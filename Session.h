#ifndef SESSION_H_
#define SESSION_H_

#include <vector>
#include <string>
#include <queue>
#include "Graph.h"
#include <map>
#include "json.hpp"

class Agent;

enum TreeType{
  Cycle,
  MaxRank,
  Root
};

class Session{
public:
    Session(const std::string& path);
    
    void simulate();
    void addAgent(const Agent& agent);
    void setGraph(const Graph& graph);
    
    void enqueueInfected(int);
    int dequeueInfected();
    TreeType getTreeType() const;

    int getNodeToSpreadTo(int nodeFromInd) const;
    void updateInfected(int newInfectedNodeInd);
    void addCarrier(int nodeInd);
    void isolateNode(int nodeInd);

    Const Graph* getGraph() const;

private:
    Graph g;
    TreeType treeType;
    std::vector<Agent*> agents;
    std::queue<int> infectionQueue;

    bool terminationConditionsSatisfied() const;
    void addAgents(const nlohmann::json& jsonSessionData);
    void addAgent(const nlohmann::json& jsonAgentData);
    void setTreeType(const std::string &stringTreeType);
    static nlohmann::json* getJsonDataFromFile(const std::string& path);

    void writeOutput() const;
};

#endif
