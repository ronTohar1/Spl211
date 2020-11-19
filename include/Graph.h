#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>

class Graph{
public:
    Graph(std::vector<std::vector<int>> matrix);
    Graph(); // creates a graph without any nodes or edges
    
    void infectNode(int nodeInd);
    bool isInfected(int nodeInd) const;

    bool isCarrier(int nodeInd) const;
    const std::vector<std::vector<int>> &getEdges() const;
    std::vector<int> *getAllInfected() const;
    int getNumOfNodes() const;
    bool edgeExists(int nodeInd1, int nodeInd2) const;
    void setCarrier(int newCarrierNodeInd);

    int getNodeToSpreadTo(int fromNodeInd) const; // returns a node a for a Virus to spread to from the given node, or
    // -1 if there isn't a node to spread to
    void isolateNode(int nodeInd); // removes all edges that include the given node from the Graph

    bool areThereActiveConnectedComponents() const; // returns true iff at least one connected component exists and
    // has no Virus in it, or that all its nodes are infected

private:
    std::vector<std::vector<int>> edges;
    int numOfNodes;
    std::vector<int> nodesInfection; // a vector that includes for every node in the Graph if it doesn't have a virus,
    // has a virus but not infected, or infected.

    // static const ints for the state of the nodes in the Graph (defined in the Graph.cpp file):
    static const int NON_CARRIER;
    static const int CARRIER;
    static const int INFECTED;

    void removeEdge(int nodeInd1, int nodeInd2);
    void removeDirectedEdge(int nodeIndFrom, int nodeIndTo);
    bool visitNodeDFS(int nodeInd, std::vector<bool>& visitedNodes) const; // used in the DFS algorithm that is used to
    // check if there are active connected components in the Graph (for more information check the
    // areThereActiveConnectedComponents method).
};

#endif
