#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include <string>
#include <vector>


// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp
class Actor;
class StudentWorld : public GameWorld
{
public:
    StudentWorld(std::string assetDir);
    virtual ~StudentWorld();
    virtual int init();
    virtual int move();
    virtual void cleanUp();

    void createNewObject(Actor* x) {m_actors.push_back(x);};

private:
    
    std::vector<Actor*> m_actors;
    int num_alien_needed;
    int num_alien_killed;
};

#endif // STUDENTWORLD_H_
