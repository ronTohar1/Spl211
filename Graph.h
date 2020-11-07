#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>

class Graph{
public:
    Graph(std::vector<std::vector<int>> matrix);
    
    void infectNode(int nodeInd);
    bool isInfected(int nodeInd);
    int getNodeToSpreadTo(int fromNodeInd);
private:
    std::vector<std::vector<int>> edges;
    int numOfVeritces;
    std::vector<int> verticesInfections;
};

#endif
