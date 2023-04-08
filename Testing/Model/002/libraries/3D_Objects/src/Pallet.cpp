#include "..\headers\Pallet.h"

Pallet :: Pallet()
{
    pallet.clear();
}

Pallet :: ~Pallet()
{
    pallet.clear();
}

void Pallet :: add_Pack(Pack* a, int index = NULL)
{
    (index == NULL) ? (pallet.push_back(a)) : (pallet.insert(index, a))
}

void Pallet :: remove_Pack(int index = NULL)
{
    pallet.erase(index);
}

int Pallet :: pack_Count()
{
    return pallet.size();
}