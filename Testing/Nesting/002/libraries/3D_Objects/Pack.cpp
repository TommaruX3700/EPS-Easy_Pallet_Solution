/*
Declare here all the 3D objects used inside the project.
*/

#include ".\Pack.h"
#include ".\Objects_includes.h"

void Pack::set_CenterCoords(int x, int y, int z){ //sets center coords
    centerCoords.x = x;
    centerCoords.y = y;
    centerCoords.z = z;

}

void Pack::set_Dims(int x, int y, int z){ //set ddimensions divided by 2 (in order to refer at them by center)
    dimsFromCentrer.x = x/2;
    dimsFromCentrer.y = y/2;
    dimsFromCentrer.z = z/2;

}

dimensions Pack::getDims(){

    return temp;
}

void Pack::changeOrientation(int a){

}