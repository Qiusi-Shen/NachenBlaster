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

class Star : public Actor{
    public:
     Star(StudentWorld* world, int startX, int startY, double size)
     : Actor(world, IID_STAR, startX, startY, 0, size, 3){}

    private:
        virtual void doSomething();

};

#endif // ACTOR_H_
