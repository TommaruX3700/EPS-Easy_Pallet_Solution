/*
Declare here all the 3D objects used inside the project.
*/

#include ".\Geometry.h"

class Pacco
{
private:
    struct centerCoords
    {
        int x, y, z; //coordinates (divide cms by 10)

    };
    struct dimsFromCentrer
    {
        int x, y, z; //populate dividing dimensions by 2

    };
    
    float weight; //[kg]
    int density; //[Kg/m3]

public:
    void setCenterCoords(int x, int y, int z);
    void setDims(int x, int y, int z);
    int* getDims(); //define what type to pass back for 3 dimensions

};

void Pacco::setCenterCoords(int x, int y, int z){ //sets center coords
    centerCoords.x = x;
    centerCoords.y = y;
    centerCoords.z = z;

}

void Pacco::setDims(int x, int y, int z){ //set ddimensions divided by 2 (in order to refer at them by center)
    dimsFromCentrer.x = x/2;
    dimsFromCentrer.y = y/2;
    dimsFromCentrer.z = z/2;

}



