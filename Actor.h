#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
#include "GameConstants.h"
// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp


/*
Required Classes:

• The NachenBlaster
• Aliens: Smallgons, Smoregons, Snagglegons
• Stars
• Projectiles: Cabbages, Turnips, Flatulence Torpedoes
• Explosions
• Goodies: Repair Goodies, Extra Life Goodies, Flatulence Torpedo Goodies
*/

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

    bool checkInBound();

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

class Alien : public Actor{
    public:
};

class Star : public Actor{
    public:
     Star(StudentWorld* world, int startX, int startY, double size)
     : Actor(world, IID_STAR, startX, startY, 0, size, 3){}

    private:
        virtual void doSomething();

};

class Projectiles : public Actor{
    public:
    Projectiles(StudentWorld* world, int imageID, int startX, int startY, int dir)
    :Actor(world, imageID, startX, startY, dir, 0.5, 1){

    }
};

class Cabbage : public Projectiles{
    public: 
    Cabbage(StudentWorld* world, int startX, int startY)
    : Projectiles(world, IID_CABBAGE, startX, startY, 0){}

    virtual void doSomething();

    private:
};




#endif // ACTOR_H_
