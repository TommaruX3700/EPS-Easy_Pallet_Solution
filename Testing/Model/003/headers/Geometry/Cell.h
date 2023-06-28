// Document: Cell.h
//
// Description: Single cell class declaration

#ifndef CELL_H
#define CELL_H

#include "DefinedGeometry.h"

// struct cell_t;

class Pack;

struct cell_t
{
    float centerX, centerY;
    bool isFree;
    Pack *pack = nullptr;
};

class Cell // punto della griglia
{
private:
    cell_t cell;

public:
    Cell();
    Cell(float dim1, float dim2);
};

#endif