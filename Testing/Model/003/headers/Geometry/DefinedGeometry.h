//Document: DefinedGeomety.h
//
//Description: user-defined geometric abstracions

#include "..\..\headers\Geometry\Cell.h"

//dimensione dei Pacchi
typedef struct dimensions_t     
        {   
            float x, y, z;
        }; 

//piani dello spazio 3D
typedef struct plane_t   
        {   
            int maxX, maxY;
            Cell** cell;
        };

//singola cella dello spazio
typedef struct cell_t
        {   
            float centerX, centerY; 
            bool isFree;
            Pack * pack = nullptr;
        };

//coordinate dello spazio 3D
typedef struct coords_t
        {
            float x, y, z;
        };
