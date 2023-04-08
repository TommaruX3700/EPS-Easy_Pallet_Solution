#include <iostream>
#include <vector>
#include "..\headers\Pack.h"

class Pallet
{
    private:
        float Xmax, Ymax, Zmax;     //Note: those are the max dimensions of the Pallet

        std :: vector<Pack> pallet;    

    public:
        Pallet();       //constructor
        ~Pallet();

        void add_Pack(Pack* a, int index = NULL);    //Note: the "index" is a default value.
        void remove_Pack(int index = NULL);

        int pack_Count();
};

