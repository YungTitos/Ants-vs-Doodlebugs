#ifndef WORLD_H
#define WORLD_H

#include <iostream>

using namespace std;

const int WORLD_SIZE = 20;

class World {
public:
    char grid[WORLD_SIZE][WORLD_SIZE];
    World();
    void printWorld();
    bool isInside(int x, int y);
    void setValue(int x, int y, char value);
};

#endif // WORLD_H