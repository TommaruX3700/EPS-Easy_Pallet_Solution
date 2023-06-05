//Our user-defined geometric abstracion

#include "..\..\headers\Geometry\Cell.h"

typedef struct dimensions_t     
        {
            float x, y, z;
        }; 

typedef struct plane_t   
        {
            int maxX, maxY;
            Cell** cell;
        };

typedef struct cell_t
        {
            float centerX, centerY; 
            bool isFree;
            Pack * pack = nullptr;
        };
