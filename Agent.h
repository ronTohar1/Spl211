#ifndef AGENT_H_
#define AGENT_H_

#include <vector>
#include "Session.h"

class Agent{
public:
    Agent();

    virtual Agent * clone() const=0;
    virtual void act(Session& session)=0;
};

class ContactTracer: public Agent{
public:
    ContactTracer();

    ContactTracer * clone() const;
    virtual void act(Session& session);
};


class Virus: public Agent{
public:
    Virus(int nodeInd);

    Virus * clone() const;
    virtual void act(Session& session);
private:
    const int nodeInd;
};

#endif
