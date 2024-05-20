#ifndef DOODLEBUGS_CPP
#define DOODLEBUGS_CPP

#include <iostream>
#include <random>
#include "doodlebug.h"

using namespace std;

Doodlebug::Doodlebug() : starveCounter(0), breedCounter(0) {
    setX(rand() % 20);
    setY(rand() % 20);
    setID('X');
}

Doodlebug::Doodlebug(int x, int y) : Organism(x, y, 'X'), starveCounter(0), breedCounter(0) {}

void Doodlebug::move(World& world) {
    int direction = rand() % 4;
    int newX = getX(), newY = getY();

    switch (direction) {
        case 0: newY -= 1; break; 
        case 1: newY += 1; break; 
        case 2: newX -= 1; break;
        case 3: newX += 1; break;
    }

    if (world.isInside(newX, newY)) {
        if (world.grid[newX][newY] == 'O') {
            starveCounter = 0;
        } else if (world.grid[newX][newY] == '-') {
            starveCounter++;
        } else {
            return;
        }
        world.setValue(getX(), getY(), '-');
        setX(newX);
        setY(newY);
        world.setValue(newX, newY, 'X');
    }
    breedCounter++;
}

void Doodlebug::breed(World& world) {
    if (breedCounter >= 8) {
        breedCounter = 0;
        int direction = rand() % 4;
        int newX = getX(), newY = getY();

        switch (direction) {
            case 0: newY -= 1; break; 
            case 1: newY += 1; break; 
            case 2: newX -= 1; break; 
            case 3: newX += 1; break; 
        }

        if (world.isInside(newX, newY) && world.grid[newX][newY] == '-') {
            Doodlebug newDoodlebug(newX, newY);
            world.setValue(newX, newY, 'X');
        }
    }
}

void Doodlebug::die(World& world) {
    if (starveCounter >= 3) {
        world.setValue(getX(), getY(), '-');
    }
}


#endif // DOODLEBUGS_CPP