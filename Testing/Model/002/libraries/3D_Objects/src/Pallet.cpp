#include "..\headers\Pallet.h"

Pallet :: Pallet(float x, float y, float z)
{   
    set_Dims(x, y, z);
    pallet.clear();
}

Pallet :: ~Pallet()
{
    pallet.clear();
}

void Pallet :: set_Dims(float x, float y, float z)
{
    this->dims.Xmax = x;
    this->dims.Ymax = y;
    this->dims.Zmax = z;
}

palletDims_t Pallet :: get_Dims()
{
    palletDims_t out;
    out.Xmax = this->dims.Xmax;
    out.Ymax = this->dims.Ymax
    out.Zmax = this->dims.Zmax
    return out;
}

void Pallet :: add_Pack(Pack* a, int index = NULL)
{
    (index == NULL) ? (pallet.push_back(a)) : (pallet.insert(index, a))
}

void Pallet :: remove_Pack(int index = pallet.size())
{
    pallet.erase(index);
}

int Pallet :: pack_Count()
{
    return pallet.size();
}