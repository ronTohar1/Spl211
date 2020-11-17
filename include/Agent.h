#ifndef AGENT_H_
#define AGENT_H_

#include <vector>
#include "Session.h"

class Agent{
public:
    Agent();

    virtual Agent * clone() const=0;
    virtual void act(Session& session)=0;
    virtual ~Agent()=default;

};

class ContactTracer: public Agent{
public:
    ContactTracer();

    ContactTracer * clone() const;
    virtual void act(Session& session);
    virtual ~ContactTracer();
};


class Virus: public Agent{
public:
    Virus(int nodeInd);

    Virus * clone() const;
    virtual void act(Session& session);
    virtual ~Virus();
private:
    const int nodeInd;
    bool infectedNode; // true iff this Virus already infected its node
};

#endif
