#ifndef ANT_H
#define ANT_H

#include <iostream>
#include "organism.h"
#include "world.h"

class Ant : public Organism {
    private:
        int breedCounter;
    public:
        Ant();
        Ant(int x, int y);
        bool hasNeighborDoodlebug(World& world, int x, int y);
        void move(World& world);
        void breed(World& world);
        void die(World& world);
};

#endif