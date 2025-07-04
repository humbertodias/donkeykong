/*
 * DonkeyKong
 * Ladder.h
 * This file contains the interface for the Ladder class, inheriting from
 * StaticObj.
 */

#ifndef LADDER_H
#define LADDER_H

#include "StaticObj.h"

class Ladder : public StaticObj {
   public:
    Ladder(int = 0, int = 0, int = 0, int = 0);
    virtual void IsCollision(CMario&);
    virtual void entityIsCollision(CEntity&);

   private:
};

#endif
