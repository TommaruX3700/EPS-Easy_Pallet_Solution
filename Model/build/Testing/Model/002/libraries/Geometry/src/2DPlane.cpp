#include "..\headers\2DPlane.h"
#include "..\headers\Cell.h"

virtual void 2DPlane :: set_occupiedCells(float c1, float c2, float dim1, float dim2){
    for(float i=(-dim1)/2; i<=dim1/2; i+=1){
            for(float j=(-dim2)/2; j<=dim2/2; j+=1){
                cell[int(c1+i)][int(c2+j)].isFree=false;
            }
        }
}

// Tom: Is this method to develop in order to handle area occupation?
//
// 2DPlane :: isFree(float c1, float c2, float dim1, float dim2){
//     return true;
// }

XYplane :: XYplane(int dim1, int dim2)
{
    max_X = dim1;
    max_Y = dim2;
    cell = new Cell*[max_X];
    for(int i = 0; i < max_X; i++){
        cell[i] = new Cell[max_Y];
        for(int j = 0; j < max_Y; j++){
            cell[i][j] = Cell(i, j);
            }
        }
}

XYplane :: ~XYplane()
{
    for(int i = 0; i < max_X; i++){
            delete[] cell[i];
        }
    delete[] cell;
}


XZplane :: XZplane(int dim1, int dim2)
{
    max_X = dim1;
    max_Y = dim2;
    cell = new Cell*[max_X];
    for(int i = 0; i < max_X; i++){
        cell[i] = new Cell[max_Y];
        for(int j = 0; j < max_Y; j++){
            cell[i][j] = Cell(i, j);
            }
        }
}

XZplane :: ~XZplane()
{
    for(int i = 0; i < max_X; i++){
            delete[] cell[i];
        }
    delete[] cell;
}


YZplane :: YZplane(int dim1, int dim2)
{
    max_X = dim1;
    max_Y = dim2;
    cell = new Cell*[max_X];
    for(int i = 0; i < max_X; i++){
        cell[i] = new Cell[max_Y];
        for(int j = 0; j < max_Y; j++){
            cell[i][j] = Cell(i, j);
            }
        }
}

YZplane :: ~YZplane()
{
    for(int i = 0; i < max_X; i++){
            delete[] cell[i];
        }
    delete[] cell;
}

