#ifndef DOODLEBUG_H
#define DOODLEBUG_H

#include <iostream>
#include "organism.h"

using namespace std;

class Doodlebug : public Organism {
    private:
        int starveCounter,breedCounter;
    public:
        Doodlebug();
        Doodlebug(int x, int y);
        void move(World& world);
        void breed(World& world);
        void die(World& world);
};



#endif
