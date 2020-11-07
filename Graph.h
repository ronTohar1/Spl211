#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>

class Graph{
public:
    Graph(std::vector<std::vector<int>> matrix);
    
    void infectNode(int nodeInd);
    bool isInfected(int nodeInd);
    int getNodeToSpreadTo(int fromNodeInd);
    bool isCarrier(int nodeInd);
    void setCarrier(int newCarrierNodeInd);
    //Methods added for Tree class
    std::queue<int>* getNeighbors(int NodeInd) const;//Returns the neighbours of a node sorted by their Index.
    int getNumOfNodes() const;


private:
    std::vector<std::vector<int>> edges;
    int numOfNodes;
    std::vector<int> nodesInfection;
};

#endif
