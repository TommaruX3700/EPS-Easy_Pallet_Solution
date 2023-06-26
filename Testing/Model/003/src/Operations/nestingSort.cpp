//functions for the nestingSort

#include "..\..\headers\Operations\nestingSort.h"

void nesting(Pack * input)
{
        static double tempAreaPacco = 0;
        static int index = 0;
        do{
            packToCheck = input(index)
            tempAreaPacco = packToCheck.dimX*packToCheck.dimY
            if(areaPallet - tempAreaPacco){
                packsToNest.append(packToCheck)
                areaPallet -= tempAreaPacco
                index++
            } else {
                outputNOTNested.append(packToCheck)
                index++
            }
        } while (index < packsToNest.size())
}

