#ifndef ORGANISM_CPP
#define ORGANISM_CPP

#include <iostream>
#include <random>
#include "organism.h"

using namespace std;

Organism::Organism() {
    x_pos = rand() % 20;
    y_pos = rand() % 20;
    id = (rand() % 2 == 0) ? 'O' : 'X'; // It was shown in class, not my problem !
}

Organism::Organism(int x, int y, char ID) {
    x_pos = x;
    y_pos = y;
    id = ID;
}

void Organism::setX(int x) {
    x_pos = x;
}

void Organism::setY(int y) {
    y_pos = y;
}

void Organism::setID(char ID) {
    id = ID;
}

int Organism::getX() {
    return x_pos;
}

int Organism::getY() {
    return y_pos;
}

char Organism::getID() {
    return id;
}

#endif // ORGANISM_CPP