#ifndef PACK_H //header guards, prevents C++ header files from beign included multiple times
#define PACK_H

class Pack
{
    private:

        struct dimensions_t //defines type "dimensions"
        {
            float x, y, z;
        }; 
        struct centerCoords_t //defines type "centerCoords"
        {
            float cX, cY, cZ;
        };

        float weight; //Unit: [kg]
        float density; //Unit: [kg/m^3]

        dimensions_t dims;
        centerCoords_t center;

        int packID;
        bool rotatable;
        bool palletizable;

    public:

//CONSTRUCTORS
        Pack(){}                                                                        //generic constructor
        Pack(float X, float Y, float Z, float WGHT, int n_collo, bool ruotabile) {}     //specific constructor

//SET-METHODS
        void set_dims(float x, float y, float z) {}
        void set_centerCoords(float x, float y, float z); //check implementation
        void set_weight(float kg) {}
        void set_orientation(int a); //TOM: end implementation
        void set_isRotatable(bool is_rotatable) {}
        void set_packID(int n_collo) {}
        dimensions_t* get_Dims() {} //outs a pointer to an out stucture (with correct dimensions)

//GET-METHODS
        int get_PackID() {}

};


#endif
