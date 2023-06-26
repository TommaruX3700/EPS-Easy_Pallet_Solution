#include <iostream>
#include <vector>

#include "headers\Geometry\GridSpace.h"

#include "headers\3D_Objects\Pack.h"
#include "headers\3D_Objects\Pallet.h"
#include "headers\3D_Objects\PalletGroup.h"

#include "headers\Operations\nestingSort.h"

GridSpace grid = GridSpace(10, 10, 10);

std::vector<Pack> input; //input, pacchi ordinati
std::vector<Pack> packsToNest; 
std::vector<Pack> outputNOTNested;

Pallet pallet;

int main()
{
    //TODO: add application loop + error codes

    try
    {    
        double areaPallet = pallet.get_Dims().x * pallet.get_Dims().y;
        //nestingSort

    
    }
    catch(const std::exception& e)
    {
        std::cerr << "main :: nestingSort :: exception caught: " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "main :: nestingSort :: unknown exception caught, exiting..." << std::endl;
        return 0;
    }
    

   
   return 0;
}