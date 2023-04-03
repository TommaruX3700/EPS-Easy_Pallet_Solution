#include ".\Geom_includes.h"

General_Geometry::GenerateVersors(){
        vers[0].vX = 1;
        vers[0].vY = 1;
        vers[0].vZ = 1;
    
        vers[1].vX = -1;
        vers[1].vY = 1;
        vers[1].vZ = 1;
        
        vers[2].vX = 1;
        vers[2].vY = -1;
        vers[2].vZ = 1;        

        vers[3].vX = 1;
        vers[3].vY = 1;
        vers[3].vZ = -1;        

        vers[4].vX = -1;
        vers[4].vY = -1;
        vers[4].vZ = 1;        

        vers[5].vX = 1;
        vers[5].vY = -1;
        vers[5].vZ = -1;        
}
        