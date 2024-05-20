#ifndef SIMULATION_CPP
#define SIMULATION_CPP

#include <iostream>
#include "simulation.h"

using namespace std;

Simulation::Simulation() : steps(0) {
    for (int i = 0; i < 100; ++i) {
        Ant ant;
        prey.push_back(ant);
        world.setValue(ant.getX(), ant.getY(), 'O');
    }
    for (int i = 0; i < 5; ++i) {
        Doodlebug doodlebug;
        predator.push_back(doodlebug);
        world.setValue(doodlebug.getX(), doodlebug.getY(), 'X');
    }
}

void Simulation::step() {
    moveDoodlebugs();
    moveAnts();
    breedDoodlebugs();
    breedAnts();
    starveDoodlebugs();
    steps++;
}

void Simulation::moveDoodlebugs() {
    for (Doodlebug& doodlebug : predator) {
        doodlebug.move(world);
    }
}

void Simulation::moveAnts() {
    for (Ant& ant : prey) {
        ant.move(world);
    }
}

void Simulation::breedDoodlebugs() {
    vector<Doodlebug> newDoodlebugs;
    for (Doodlebug& doodlebug : predator) {
        doodlebug.breed(world);
        newDoodlebugs.push_back(doodlebug);
    }
    predator.insert(predator.end(), newDoodlebugs.begin(), newDoodlebugs.end());
}

void Simulation::breedAnts() {
    vector<Ant> newAnts;
    for (Ant& ant : prey) {
        ant.breed(world);
        newAnts.push_back(ant);
    }
    prey.insert(prey.end(), newAnts.begin(), newAnts.end());
}

void Simulation::starveDoodlebugs() {
    vector<Doodlebug> remainingDoodlebugs;
    for (Doodlebug& doodlebug : predator) {
        doodlebug.die(world);
        if (world.grid[doodlebug.getX()][doodlebug.getY()] == 'X') {
            remainingDoodlebugs.push_back(doodlebug);
        }
    }
    predator = remainingDoodlebugs;
}

void Simulation::printWorld() {
    for (int i = 0; i < WORLD_SIZE; ++i) {
        for (int j = 0; j < WORLD_SIZE; ++j) {
            cout << world.grid[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "Time step: " << steps << endl;
}

void Simulation::clickSystem() {
    cout << "Starting Simulation. Press Enter for next step." << endl;
    while (true) {
        char enterKey;
        cin.get(enterKey);
        if (enterKey == '\n') {
            step(); 
            printWorld(); 
        } else {
            break; 
        }
    }
}

#endif // SIMULATION_CPP