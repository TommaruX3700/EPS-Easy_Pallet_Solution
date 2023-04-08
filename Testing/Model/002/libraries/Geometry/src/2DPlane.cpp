/*
Declare here all the Geometry entities in used by the project.
*/

#include ".\Grid.h"
#include ".\Geom_includes.h"

XYplane :: XYplane(int dim1, int dim2)
{
    max_X = dim1;
    max_Y = dim2;
    cella = new Cella*[max_X];
    for(int i = 0; i < max_X; i++){
        cella[i] = new Cella[max_Y];
        for(int j = 0; j < max_Y; j++){
            cella[i][j] = Cella(i, j);
            }
        }
}

XYplane :: ~pianoXY()
{
    for(int i = 0; i < max_X; i++){
            delete[] cella[i];
        }
    delete[] cella;
}

