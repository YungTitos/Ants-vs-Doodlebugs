#ifndef ORGANISM_H
#define ORGANISM_H

#include <iostream>
#include "world.h"

using namespace std;

class Organism
{
    private:
        int x_pos,y_pos;
        char id;
    public:
        Organism();
        Organism(int x, int y, char ID);
        virtual void move(World& world) = 0;
        virtual void breed(World& world) = 0;
        virtual void die(World& world) = 0;
        void setX(int x);
        void setY(int y);
        void setID(char ID);
        int getX();
        int getY();
        char getID();
};

#endif // ORGANISM_H