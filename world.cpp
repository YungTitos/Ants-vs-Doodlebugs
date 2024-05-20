#ifndef WORLD_CPP
#define WORLD_CPP

#include <iostream>
#include "world.h"

using namespace std;

World::World() {
        for (int i = 0; i < WORLD_SIZE; ++i) {
            for (int j = 0; j < WORLD_SIZE; ++j) {
                grid[i][j] = '-';
            }
        }
}

void World::printWorld() {
        for (int i = 0; i < WORLD_SIZE; ++i) {
            for (int j = 0; j < WORLD_SIZE; ++j) {
                cout << grid[i][j] << ' ';
            }
            cout << endl;
        }
}

bool World::isInside(int x, int y) {
        return x >= 0 && x < WORLD_SIZE && y >= 0 && y < WORLD_SIZE;
}

void World::setValue(int x, int y, char value) {
        grid[x][y] = value;
}

#endif // WORLD_CPP