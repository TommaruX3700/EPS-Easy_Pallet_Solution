//Document: Cell.h
//
//Description: Single cell class declaration

#include "..\3D_Objects\Pack.h"

class Cell //punto della griglia
{
    private:
        cell_t cell;

    public:
        Cell();
        Cell(float dim1, float dim2);
};