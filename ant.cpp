#ifndef ANT_CPP
#define ANT_CPP

#include "ant.h"
#include <iostream>
#include <random>

using namespace std;

Ant::Ant() : breedCounter(0) {
    setX(rand() % 20);
    setY(rand() % 20);
    setID('O');
}

Ant::Ant(int x, int y) : Organism(x, y, 'O'), breedCounter(0) {}

void Ant::move(World& world) {
    int direction = rand() % 4;
    int newX = getX(), newY = getY();

    switch (direction) {
        case 0: newY -= 1; break; 
        case 1: newY += 1; break; 
        case 2: newX -= 1; break; 
        case 3: newX += 1; break; 
    }

    if (world.isInside(newX, newY) && world.grid[newX][newY] == '-' && !hasNeighborDoodlebug(world, newX, newY)) {
        world.setValue(getX(), getY(), '-');
        setX(newX);
        setY(newY);
        world.setValue(newX, newY, 'O');
    }

    breedCounter++;
}

bool Ant::hasNeighborDoodlebug(World& world, int x, int y) {
    if (world.isInside(x, y - 1) && world.grid[x][y - 1] == 'X') {
        return true;
    }
    if (world.isInside(x, y + 1) && world.grid[x][y + 1] == 'X') {
        return true;
    }
    if (world.isInside(x - 1, y) && world.grid[x - 1][y] == 'X') {
        return true;
    }
    if (world.isInside(x + 1, y) && world.grid[x + 1][y] == 'X') {
        return true;
    }
    return false;
}

void Ant::breed(World& world) {
    if (breedCounter >= 3) {
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
            Ant newAnt(newX, newY);
            world.setValue(newX, newY, 'O');
        }
    }
}

void Ant::die(World& world) {
    world.setValue(getX(), getY(), '-');
}

#endif // ANT_CPP