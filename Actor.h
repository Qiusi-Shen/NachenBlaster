#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
#include "GameConstants.h"
// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp

class StudentWorld;

// create an actor class as a basic of all the objects
class Actor : public GraphObject{
    public: 
    Actor(StudentWorld* world, int imageID, double startX, double startY, int dir = 0, double size = 1.0, int depth = 0)
    :GraphObject(imageID, startX, startY, dir, size, depth), m_world(world), m_lifes(true){}

    virtual ~Actor(){};
    virtual void doSomething() = 0;
    bool isAlive(){return m_lifes!=0;}
    void setLifes(int life){ m_lifes = life; }

    StudentWorld* getWorld(){return m_world;}
    private:
    StudentWorld* m_world;
    bool m_lifes;
};

class NachenBlaster : public Actor{
    public:
    NachenBlaster(StudentWorld* world)
    : Actor(world, IID_NACHENBLASTER, 0, 128, 0, 1.0, 0){
        m_hitPoint = 50;
        m_cabbageEnergyPoint = 30;
        m_torpedoes = 0;
    }
    virtual void doSomething();
    virtual ~NachenBlaster(){};
    private:
    int m_hitPoint;
    int m_cabbageEnergyPoint;
    int m_torpedoes;
};

class Star : public Actor{
    public:
     Star(StudentWorld* world, int startX, int startY, double size)
     : Actor(world, IID_STAR, startX, startY, 0, size, 3){}

    private:
        virtual void doSomething();

};

#endif // ACTOR_H_
