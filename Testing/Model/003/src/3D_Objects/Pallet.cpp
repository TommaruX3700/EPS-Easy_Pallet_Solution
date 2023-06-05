#include "..\..\headers\3D_Objects\Pallet.h"

Pallet :: Pallet(float x, float y, float z)
{   
    set_Dims(x, y, z);
    this->pallet.clear();
}

Pallet :: ~Pallet()
{
    this->pallet.clear();
}

void Pallet :: set_Dims(float x, float y, float z)
{
    this->dims.Xmax = x;
    this->dims.Ymax = y;
    this->dims.Zmax = z;
}

Pallet :: palletDims_t Pallet :: get_Dims()
{
    palletDims_t out;
    out.Xmax = this->dims.Xmax;
    out.Ymax = this->dims.Ymax;
    out.Zmax = this->dims.Zmax;
    return out;
}

void Pallet :: add_Pack(Pack* a, int index = NULL)
{
    (index == NULL) ? (this->pallet.push_back(a)) : (this->pallet.insert(this->pallet.begin() + index, a));
}

void Pallet :: remove_Pack(int index)
{
    (index < 0) ? (this->pallet.erase(this->pallet.end())) : (this->pallet.erase(this->pallet.begin() + index));    
}

int Pallet :: pack_Count()
{
    return this->pallet.size();
}