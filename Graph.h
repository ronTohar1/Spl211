#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>

class Graph{
public:
    Graph(std::vector<std::vector<int>> matrix);
    Graph();
    
    void infectNode(int nodeInd);
    bool isInfected(int nodeInd);

    int getNodeToSpreadTo(int fromNodeInd) const;
    bool isCarrier(int nodeInd) const;
    void setCarrier(int newCarrierNodeInd);
//    void initCarriers(std::vector<int> carriers);
    bool areThereActiveConnectedComponents() const;
    bool isInfected(int nodeInd) const;
    void isolateNode(int nodeInd);
    void removeEdge(int nodeInd1, int nodeInd2);
    const std::vector<std::vector<int>> &getEdges() const;
    std::vector<int> *getAllInfected() const;

private:
    std::vector<std::vector<int>> edges;
    int numOfNodes;
    std::vector<int> nodesInfection;
//    std::vector<std::vector<int>> activeConnectedComponents;
//    std::vector<int> activeConnectedComponentsNumOfInfected;

    bool visitNode(int nodeInd, std::vector<bool>& visitedNodes) const;
    bool edgeExists(int nodeInd1, int nodeInd2) const;
    void removeDirectedEdge(int nodeIndFrom, int nodeIndTo);
};

#endif
