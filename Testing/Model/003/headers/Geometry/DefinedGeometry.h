//Document: DefinedGeomety.h
//
//Description: user-defined geometric abstracions
#pragma once
#ifndef GEOM_H  
#define GEOM_H

#include "Cell.h"
#include "..\3D_Objects\Pack.h"

//forward declarations (to avoid cirular dependencies)

//dimensione dei Pacchi


//piani dello spazio 3D
class Cell; 
struct plane_t    
        {   
            int maxX, maxY;
            Cell** cell;
        };

//singola cella dello spazio
class Pack;


//coordinate dello spazio 3D
struct coords_t
        {
            float x, y, z;
        };

#endif