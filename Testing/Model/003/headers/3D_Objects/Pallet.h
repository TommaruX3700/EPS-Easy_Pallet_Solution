// Document: Pallet.h
//
// Description: Pallet class declaration

#pragma once
#ifndef PALLET_H
#define PALLET_H

#include <iostream>
#include <vector>
#include ".\Pack.h"

class Pallet
{
private:
    std ::vector<Pack *> pallet; // contains pointers to the actual packs (already declared in memory)

    dimensions_t palletDims; // Note: those are the max dimensions of the Pallet

    float param_Efficency; // Note: 0 < "param_Efficency" < 1, rapresents how much space is actually occupied considering the whole volume.

public:
    Pallet() {}                        // Note: generic constructor
    Pallet(float x, float y, float z); // Note: specific constructor
    ~Pallet();

    void set_Dims(float x, float y, float z);
    dimensions_t get_Dims();

    void add_Pack(Pack *a, int index = NULL); // Note: the "index" is a default value.
    void remove_Pack(int index = -1);         // Note: if "index" not specified, removes the last one

    int pack_Count();
};

#endif