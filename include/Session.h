#ifndef SESSION_H_
#define SESSION_H_

#include <vector>
#include <string>
#include <queue>
#include "Graph.h"
#include <map>
#include "../json.hpp"

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

    void updateInfected(int newInfectedNodeInd);
    void addCarrier(int nodeInd);
    int getNodeToSpreadTo(int nodeFromInd) const;
    void isolateNode(int nodeInd);
    bool isInfectionQueueEmpty() const;

    const Graph& getGraph() const;
    int getCurrCycle() const;

    // rule of 5 - because the Session class manages memory on the heap
    Session(const Session &other);
    Session & operator=(const Session &other);
    virtual ~Session();
    Session(Session &&other);
    Session & operator=(Session &&other);

private:
    Graph g;
    TreeType treeType;
    std::vector<Agent*> agents;
    std::queue<int> infectionQueue; // a queue of the new infected nodes, ordered by their infection time
    int currCycle; // the current cycle of the session, starts from 0

    const std::string OUTPUT_FILE = "./output.json";

    static nlohmann::json* getJsonDataFromFile(const std::string &path);
    void addAgents(const nlohmann::json &jsonSessionData);
    void addAgent(const nlohmann::json &jsonAgentData);
    void setTreeType(const std::string &stringTreeType);

    bool terminationConditionsSatisfied() const;

    void writeOutput() const;

    void deleteAgents();
    void copyAgents(const Session &other);
};

#endif
