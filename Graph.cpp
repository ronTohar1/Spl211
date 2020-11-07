
#include "Graph.h";

void Graph::infectNode(int nodeInd) {
    nodesInfection[nodeInd] = 2;
}

int Graph::getNodeToSpreadTo(int fromNodeInd) {
    for (int nodeInd = 0; nodeInd < numOfNodes; nodeInd++){
        if (edges[fromNodeInd][nodeInd] == 1 && !isCarrier(nodeInd))
            return nodeInd;
    }
    return -1; // in case there is no Node to spread to
}

bool Graph::isCarrier(int nodeInd) {
    return nodesInfection[nodeInd] >= 1;
}

void Graph::setCarrier(int newCarrierNodeInd) {
    // Assuming that the node is not infected
    nodesInfection[newCarrierNodeInd] = 1;
}
