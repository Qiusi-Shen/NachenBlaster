#include "StudentWorld.h"
#include "GameConstants.h"
#include "Actor.h"
#include <string>
using namespace std;

GameWorld* createStudentWorld(string assetDir)
{
	return new StudentWorld(assetDir);
}

// Students:  Add code to this file, StudentWorld.h, Actor.h and Actor.cpp

StudentWorld::StudentWorld(string assetDir)
: GameWorld(assetDir)
{
}

StudentWorld::~StudentWorld(){
    cleanUp();
}

int StudentWorld::init()
{   
    // initialize the number of alien needed to finish this level 6 + 4 * N
    num_alien_needed = 6 + 4 * getLevel();
    num_alien_killed = 0;

    // Place NachenBlaster

    m_actors.push_back(new NachenBlaster(this));

    // Place 30 stars in the game
    for(int i =0; i < 30; i++){
        double startX = randInt(0, VIEW_WIDTH - 1);
        double startY = randInt(0, VIEW_HEIGHT - 1);
        double size = randInt (1,10) * 0.05;
        m_actors.push_back(new Star(this, startX, startY, size));

    }
    return GWSTATUS_CONTINUE_GAME;
}

int StudentWorld::move()
{
    // This code is here merely to allow the game to build, run, and terminate after you hit enter.
    // Notice that the return value GWSTATUS_PLAYER_DIED will cause our framework to end the current level.
    //decLives();
    //return GWSTATUS_PLAYER_DIED;

    // move each alive object
    for(int i = 0; i <  m_actors.size(); i++){
        if(m_actors[i]->isAlive()){
            m_actors[i]->doSomething();
        }
        
    }

    // Remove Dead Object
    vector<Actor*>::iterator it = m_actors.begin();

    for(;it!=m_actors.end();){
        if(!(*it)->isAlive()){
            delete *it;
            it = m_actors.erase(it);
        }
        else{
            it++;
        }
    }

    //create a random star at rate 1/15
    if(randInt(1,15) ==10){
        double startX = VIEW_WIDTH - 1;
        double startY = randInt(0, VIEW_HEIGHT - 1);
        double size = randInt (1,10) * 0.05;
        m_actors.push_back(new Star(this, startX, startY, size));
    }
    return GWSTATUS_CONTINUE_GAME;
}

void StudentWorld::cleanUp()
{
}

