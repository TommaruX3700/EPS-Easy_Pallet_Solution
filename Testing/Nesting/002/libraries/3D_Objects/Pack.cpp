/*
Declare here all the 3D objects used inside the project.
*/

#include ".\Geometry.h"

void Pack::setCenterCoords(int x, int y, int z){ //sets center coords
    centerCoords.x = x;
    centerCoords.y = y;
    centerCoords.z = z;

}

void Pack::setDims(int x, int y, int z){ //set ddimensions divided by 2 (in order to refer at them by center)
    dimsFromCentrer.x = x/2;
    dimsFromCentrer.y = y/2;
    dimsFromCentrer.z = z/2;

}

int* Pack::getDims(){
    int temp[3];
        temp[0] = x*2;
        temp[1] = y*2;
        temp[2] = z*2;

    return temp;
}
