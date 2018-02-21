#include "Actor.h"
#include "StudentWorld.h"

// Students:  Add code to this file, Actor.h, StudentWorld.h, and StudentWorld.cpp

// NachenBalster functions

void NachenBlaster::doSomething(){
    if(!isAlive()) return;
    int ch;

    if(getWorld()->getKey(ch))
    {
        // User hit a key during this tick!
        switch(ch){
            case KEY_PRESS_LEFT:
                if(getX()-6 < 0) return;
                    else moveTo(getX()-6, getY());
            break;
            
            case KEY_PRESS_RIGHT:
                if(getX() + 6 >= VIEW_WIDTH) return;
                    else moveTo(getX()+6, getY());
            break;
            
            case KEY_PRESS_UP:
                if(getY()+ 6 >= VIEW_HEIGHT) return;
                    else moveTo(getX(), getY()+6);
            break;
            
            case KEY_PRESS_DOWN:
                if(getY()-6 < 0) return;
                    else moveTo(getX(), getY()-6);
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