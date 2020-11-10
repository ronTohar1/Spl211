
#include "Graph.h";


Graph::Graph(std::vector<std::vector<int>> matrix) : edges(matrix), numOfNodes(matrix.size()),
        nodesInfection(std::vector<int>(matrix.size(), 0)) {

}

Graph::Graph() : numOfNodes(0) {

}

void Graph::infectNode(int nodeInd) {
    nodesInfection[nodeInd] = 2;
}

bool Graph::isInfected(int nodeInd) {
    return isInfected(nodeInd);
}

bool Graph::isInfected(int nodeInd) const {
    return nodesInfection[nodeInd] == 2;
}

int Graph::getNodeToSpreadTo(int fromNodeInd) const {
    for (int nodeInd = 0; nodeInd < numOfNodes; nodeInd++){
        if (edgeExists(fromNodeInd, nodeInd) == 1 && !isCarrier(nodeInd))
            return nodeInd;
    }
    return -1; // in case there is no Node to spread to
}

bool Graph::isCarrier(int nodeInd) const {
    return nodesInfection[nodeInd] >= 1;
}

void Graph::setCarrier(int newCarrierNodeInd) {
    // Assuming that the node is not infected
    nodesInfection[newCarrierNodeInd] = 1;
}

bool Graph::areThereActiveConnectedComponents() const {
    std::vector<bool> visitedNodes(numOfNodes, false);
    for (int nodeInd = 0; nodeInd < numOfNodes; nodeInd++){
        if (isCarrier(nodeInd)){
            if (visitNode(nodeInd, visitedNodes))
                return true;
        }
    }
    return true;
}

bool Graph::visitNode(int nodeInd, std::vector<bool>& visitedNodes) const {
    visitedNodes[nodeInd] = true;
    if (!isInfected(nodeInd))
        return true;
    for (int otherNodeInd = 0; otherNodeInd < numOfNodes; otherNodeInd++){
        if (edgeExists(nodeInd, otherNodeInd) && !visitedNodes[otherNodeInd]){
            if (!visitNode(otherNodeInd, visitedNodes))
                return true;
        }
    }
    return false;
}

bool Graph::edgeExists(int nodeInd1, int nodeInd2) const {
    return  edges[nodeInd1][nodeInd2] == 1;
}

void Graph::isolateNode(int nodeInd) {
    for (int otherNodeInd = 0; otherNodeInd < numOfNodes; otherNodeInd++){
        if (edgeExists(nodeInd, otherNodeInd))
            removeEdge(nodeInd, otherNodeInd);
    }
}

void Graph::removeEdge(int nodeInd1, int nodeInd2) {
    removeDirectedEdge(nodeInd1, nodeInd2);
    removeDirectedEdge(nodeInd2, nodeInd1);
}

void Graph::removeDirectedEdge(int nodeIndFrom, int nodeIndTo) {
    edges[nodeIndFrom][nodeIndTo] = 0;
}

const std::vector<std::vector<int>> &Graph::getEdges() const {
    return edges;
}

std::vector<int> *Graph::getAllInfected() const {
    std::vector<int> *infectedNodes = new std::vector<int>();
    for (int nodeInd = 0; nodeInd < numOfNodes; nodeInd++) {
        if (isInfected(nodeInd))
            infectedNodes->push_back(nodeInd);
    }
    return infectedNodes;
}

std::queue<int>* Graph::getNeighbors(int NodeInd) const {
     std::queue<int>* neighbours= new std::queue<int>();
    for (int i = 0; i < numOfNodes; ++i) {
        if(NodeInd!=i)
            if(edgeExists(NodeInd,i))
                neighbours->push(i);
    }
    return neighbours;
}

int Graph::getNumOfNodes() const {
    return numOfNodes;
}

//void Graph::initCarriers(std::vector<int> carriers) {
//    std::vector<bool> inExistingConnectedComponent(carriers.size(), false);
//    for (int carrier : carriers){
//        if (!inExistingConnectedComponent[carrier]){
//
//            activeConnectedComponents.push_back(std::vector<int>());
//        }
//    }
//}
