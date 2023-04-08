/*
Declare here all the 3D objects used inside the project.
*/

#include ".\Pack.h"
#include ".\Objects_includes.h"

Pack :: Pack(float X, float Y, float Z, float WGHT, int n_collo, bool ruotabile){
    set_Dims(X, Y, Z);
    set_weight(WGHT);
    set_PackID(n_collo);
    is_Rotatable(ruotabile);
}

void Pack :: set_dims(float x, float y, float z){
    this->dims.x = x;
    this->dims.y = y;
    this->dims.z = z;
}

void Pack :: set_centerCoords(float x, float y, float z){ 
    center.cX = x;
    center.cY = y;
    center.cZ = z;
}

void Pack :: set_weight(float kg){
    this->weight = kg;
    this->density = this->weight/((this->get_Dims()->x)*(this->get_Dims()->y)*(this->get_Dims()->z))
}

void Pack::set_orientation(int a){
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

void Pack :: set_isRotatable(bool is_rotatable){
    this->rotatable = is_rotatable;
}

void Pack :: set_packID(int n_collo){
    this->packID = n_collo;
}

dimensions_t* Pack :: get_Dims(){
    return &this->dims;     
}

int Pack :: get_PackID(){
    return this->packID;
}