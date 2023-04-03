/*
Declare here all the 3D objects used inside the project.
*/

#include ".\Pack.h"
#include ".\Objects_includes.h"
#include "..\Geometry\Geom_includes.h"

void Pack::set_Dims(float x, float y, float z){ //set ddimensions divided by 2 (in order to refer at them by center)
    dims.x = x/2;
    dims.y = y/2;
    dims.z = z/2;

}

void Pack::set_CenterCoords(float x, float y, float z){ //sets center coords    
    center.cX = x;
    center.cY = y;
    center.cZ = z;

}

void Pack::set_weight(float kg){
    weight = kg;
    density = weight/((get_Dims()->x)*(get_Dims()->y)*(get_Dims()->z))

}

dimensions* Pack::get_Dims(){
    dimensions out;
    out.x = out.x*2;
    out.y = out.y*2;
    out.z = out.z*2;
    return out*;
}

void Pack::set_Orientation(int a){
    switch (a)
    {
        case 0:
            dims.x
            break;
        
        case 1:

            break;
        
        case 2:
        
            break;

        default:
            break;
    }

}