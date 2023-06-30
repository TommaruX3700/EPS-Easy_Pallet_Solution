// Document: DefinedGeomety.h
//
// Description: user-defined geometric abstracions
// NB: forward declarations (to avoid cirular dependencies)

#pragma once
#ifndef GEOM_H
#define GEOM_H

#include "Cell.h"
#include "..\3D_Objects\Pack.h"

class definedGeometry
{
    private:
        /* data */

    public:
        definedGeometry();
        ~definedGeometry();
};

// Dimensione dei pacchi
class packDimensions : virtual definedGeometry 
{
    private:
        float x, y, z;

    public:
        packDimensions();
        ~packDimensions();
        
};

// Piani dello spazio 3D
class planeGraph : virtual definedGeometry
{
    private:
        int maxX, maxY;
        Cell** cell;

    public:
        planeGraph();
        ~planeGraph();

};

// Coordinate dello spazio 3D
class coordsGraph : virtual definedGeometry
{
    private:
        float x, y, z;
    
    public:
        coordsGraph();
        ~coordsGraph();

};


// struct cell_t;

class Pack;

struct cell_t
{
    float centerX, centerY;
    bool isFree;
    Pack *pack = nullptr;
};

struct dimensions_t
{
    float x, y, z;
};

class Cell;
struct plane_t
{
    int maxX, maxY;
    Cell **cell;
};

// singola cella dello spazio
class Pack;

struct coords_t
{
    float x, y, z;
};

#endif