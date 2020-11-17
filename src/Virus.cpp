
#include <vector>
#include "../include/Session.h"
#include "../include/Agent.h"

Virus::Virus(int nodeInd):nodeInd(nodeInd), infectedNode(false) {

}

Virus * Virus::clone() const {
    return new Virus(*this); // using the copy constructor
}

void Virus::act(Session &session) {
    // first infecting our Node, if haven't yet:
    if(!infectedNode){
        session.updateInfected(nodeInd); // update session that our Node is infected
        infectedNode = true;
    }
    // then spread to another node if there is a node to spread to:
    int nodeToSpreadTo = session.getNodeToSpreadTo(nodeInd);
    if (nodeToSpreadTo != -1) { // if -1 then there is no node to spread to
        session.addAgent(Virus(nodeToSpreadTo));
        session.addCarrier(nodeToSpreadTo); // updating the Session that the node is a new carrier
    }
}


