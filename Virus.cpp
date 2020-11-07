
#include <vector>
#include "Session.h"
#include "Agent.h"

Virus::Virus(int nodeInd):nodeInd(nodeInd) {

}

Virus * Virus::clone() const {
    return new Virus(nodeInd);
}

void Virus::act(Session &session) {
    session.enqueueInfected(nodeInd);

}
