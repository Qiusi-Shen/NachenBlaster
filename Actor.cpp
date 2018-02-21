#include "Actor.h"
#include "StudentWorld.h"

// Students:  Add code to this file, Actor.h, StudentWorld.h, and StudentWorld.cpp

// NachenBalster functions

bool Actor::checkInBound(){
    int x = getX(), y = getY();
    if( x < 0 || y < 0 || x >= VIEW_WIDTH || y >= VIEW_HEIGHT){
        setLifes(0);
        return true;
    }
    return false;
}

void NachenBlaster::doSomething(){
    if(!isAlive()) return;
    int ch;
    int x = getX(), y = getY();
    if(getWorld()->getKey(ch))
    {
        // User hit a key during this tick!
        switch(ch){
            case KEY_PRESS_LEFT:
                if(x-6 < 0) return;
                    else moveTo(x-6, y);
            break;
            
            case KEY_PRESS_RIGHT:
                if(x + 6 >= VIEW_WIDTH) return;
                    else moveTo(x+6, y);
            break;
            
            case KEY_PRESS_UP:
                if(y+ 6 >= VIEW_HEIGHT) return;
                    else moveTo(x, y+6);
            break;
            
            case KEY_PRESS_DOWN:
                if(y-6 < 0) return;
                    else moveTo(x, y-6);
            break;

            case KEY_PRESS_SPACE:
                m_cabbageEnergyPoint-=5;
                getWorld()->playSound(SOUND_PLAYER_SHOOT);
                Cabbage* c = new Cabbage(getWorld(), x+12, y);
                getWorld()->createNewObject(c);
            break;

            case KEY_PRESS_TAB:
                m_torpedoes--;
                getWorld()->playSound(SOUND_TORPEDO);
                Torpedoes* t = new Torpedoes(getWorld(), x+12, y);
                getWorld()->createNewObject(t);
            break;
            
        }
    }

    if(m_cabbageEnergyPoint < 30)
        m_cabbageEnergyPoint++;
}


// star functions
void Star::doSomething(){
    if(getX()<1){
        setLifes(0);
    }
    else{
        moveTo(getX()-1, getY());
    }
}

// cabbage functions

void Cabbage::doSomething(){
    
    // check cabbage is alive
    if(!isAlive()) return;

    // check if it is in bound
    if(checkInBound()) return;

    // check if it is collision

    moveTo(getX()+8, getY());
    setDirection(getDirection() + 20);

}

// Torpedoes functions

void Torpedoes::doSomething(){

    // check torpedoes is alive
    if(!isAlive()) return;

    // check if is in bound
    if(checkInBound()) return;

    moveTo(getX()+8, getY());
}