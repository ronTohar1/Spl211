
#include <vector>
#include "Session.h"
#include "Agent.h"

Virus::Virus(int nodeInd):nodeInd(nodeInd), infectedNode(false) {

}

Virus * Virus::clone() const {
    return new Virus(nodeInd);
}

void Virus::act(Session &session) {
    // first infecting our Node, if haven't yet:
    if(!infectedNode){
        session.updateInfected(nodeInd); // update session that our Node is infected
        infectedNode = true;
    }
    // then spread to another node:
    int nodeToSpreadTo = session.getNodeToSpreadTo(nodeInd);
    if (nodeToSpreadTo != -1) { // if -1 then there is no Node to spread to
        session.addAgent(Virus(nodeToSpreadTo));
        session.addCarrier(nodeToSpreadTo);
    }
}
