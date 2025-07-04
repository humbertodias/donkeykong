/*
 * DonkeyKong
 * CFire.h
 * This file contains the interface for CFire class, inheriting from CEntity.
 */

#ifndef CFIRE_H
#define CFIRE_H

#include "CEntity.h"
#include "CMario.h"
#include "Define.h"

#include <iostream>
using namespace std;

enum fireState {       // values for state private data member
    FIRE_WALKING = 0,  // state when fire is moving horizontally along platform
    FIRE_SEARCHING,    // state when the fire follows Mario up a platform
    FIRE_CLIMBING      // state when fire collides with Mario and ends his worthless
                       // life.
};

class CFire : public CEntity {
   public:
    CFire();

    virtual void OnLoop();
    virtual void OnRender(SDL_Surface* Surf_Display);

    virtual int identifyType();

    void set_clips();

    int  getState();
    void setState(fireState);

    int wheresMarioX(CMario&);
    int IsDiffLevel(CMario&);

    void reset();

    void setXinit(int);
    void setYinit(int);

   private:
    fireState state;  // defined by enum fireState above
    int       xinit;  // position fire starts, used for reset() function
    int       yinit;

    SDL_Rect clips[3];
};

#endif
