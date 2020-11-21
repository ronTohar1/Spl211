
#include "../include/Graph.h"

// const ints for the state of the nodes in the Graph. The values are sorted by the infection severity:
const int Graph::NON_CARRIER = 0;
const int Graph::CARRIER = 1;
const int Graph::INFECTED = 2;

Graph::Graph(std::vector<std::vector<int>> matrix) : edges(matrix), numOfNodes(matrix.size()),
        nodesInfection(std::vector<int>(matrix.size(), NON_CARRIER)) {

}

// an empty constructor that creates a Graph without any nodes or edges
Graph::Graph() : edges(), numOfNodes(0), nodesInfection() {

}

void Graph::infectNode(int nodeInd) {
    nodesInfection[nodeInd] = INFECTED;
}

bool Graph::isInfected(int nodeInd) const {
    return nodesInfection[nodeInd] == INFECTED;
}

bool Graph::isCarrier(int nodeInd) const {
    return nodesInfection[nodeInd] >= CARRIER; // more than carrier means infected and carrier - the values are sorted
    // by the infection severity
}

const std::vector<std::vector<int>> &Graph::getEdges() const {
    return edges;
}

std::vector<int> *Graph::getAllInfected() const {
    // create and return a vector of all infected nodes in this Graph:
    std::vector<int> *infectedNodes = new std::vector<int>();
    for (int nodeInd = 0; nodeInd < numOfNodes; nodeInd++) {
        if (isInfected(nodeInd))
            infectedNodes->push_back(nodeInd);
    }
    return infectedNodes;
}

int Graph::getNumOfNodes() const {
    return numOfNodes;
}

bool Graph::edgeExists(int nodeInd1, int nodeInd2) const {
    return  edges[nodeInd1][nodeInd2] == 1;
}

void Graph::setCarrier(int newCarrierNodeInd) {
    // Assuming that the node is not infected
    nodesInfection[newCarrierNodeInd] = CARRIER;
}

// returns a node a for a Virus to spread to from the given node, or
// -1 if there isn't a node to spread to
int Graph::getNodeToSpreadTo(int fromNodeInd) const {
    // iterating over the nodes in increasing order, so the first node we can spread to will be with the smallest index:
    for (int nodeInd = 0; nodeInd < numOfNodes; nodeInd++){
        // if the current node is a neighbor of the given node and is not a carrier, return it:
        if (edgeExists(fromNodeInd, nodeInd) && !isCarrier(nodeInd))
            return nodeInd;
    }
    return -1; // in case there is no Node to spread to
}

// removes all edges that include the given node from the Graph
void Graph::isolateNode(int nodeInd) {
    // remove all existing edges that include the given node (the graph is not directed so these are the edges that
    // start from this node):
    for (int otherNodeInd = 0; otherNodeInd < numOfNodes; otherNodeInd++){
        if (edgeExists(nodeInd, otherNodeInd))
            removeEdge(nodeInd, otherNodeInd);
    }
}

// returns true iff at least one connected component exists and has no Virus in it, or that all its nodes are infected
bool Graph::areThereActiveConnectedComponents() const {
    // we will use a DFS algorithm, but only on the connected components that include a carrier in them, by visiting
    // a first connected component's node only iff it is a carrier. These way we will surly avoid connected components
    // without any carriers in them. In the remaining connected components all we will check is if they are fully
    // infected or not:
    std::vector<bool> visitedNodes(numOfNodes, false); // so we don't visit a node twice
    for (int nodeInd = 0; nodeInd < numOfNodes; nodeInd++){
        if (isCarrier(nodeInd)){ // as described, starting only from nodes that are carriers
            // the visit returns true iff the node is part of an active connected component. because it is the first
            // node of its connected component:
            if (visitNodeDFS(nodeInd, visitedNodes))
                return true;
        }
    }
    return false;
}

// used in the DFS algorithm that is used to check if there are active connected components in the Graph (for more
// information check the areThereActiveConnectedComponents method).
bool Graph::visitNodeDFS(int nodeInd, std::vector<bool>& visitedNodes) const {
    visitedNodes[nodeInd] = true;
    if (!isInfected(nodeInd)) // if not infected, then its connected component is not fully infected
        return true;
    // visiting every neighbor of the node which hasn't been visited:
    for (int otherNodeInd = 0; otherNodeInd < numOfNodes; otherNodeInd++){
        if (edgeExists(nodeInd, otherNodeInd) && !visitedNodes[otherNodeInd]){
            if (visitNodeDFS(otherNodeInd, visitedNodes)) // if true, then its part of an active connected component
                return true;
        }
    }
    return false;
}

void Graph::removeEdge(int nodeInd1, int nodeInd2) {
    // removing the directed edges in both directions:
    removeDirectedEdge(nodeInd1, nodeInd2);
    removeDirectedEdge(nodeInd2, nodeInd1);
}

void Graph::removeDirectedEdge(int nodeIndFrom, int nodeIndTo) {
    edges[nodeIndFrom][nodeIndTo] = 0;
}