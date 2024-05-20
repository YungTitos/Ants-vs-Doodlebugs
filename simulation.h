#ifndef SIMULATION_H
#define SIMULATION_H

#include "world.h"
#include "ant.h"
#include "doodlebug.h"
#include <vector>

class Simulation {
    private:
        World world;
        vector<Ant> prey;
        vector<Doodlebug> predator;
        int steps;
        void moveDoodlebugs();
        void moveAnts();
        void breedDoodlebugs();
        void breedAnts();
        void starveDoodlebugs();
    public:
        Simulation();
        void step();
        void printWorld();
        void clickSystem();

    
};

#endif // SIMULATION_H
