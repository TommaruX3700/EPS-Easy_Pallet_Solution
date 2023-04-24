#ifndef PACK_H  //"header guards", they prevents C++ header files from beign included multiple times
#define PACK_H

class Pack
{
    private:

        struct dimensions_t     //custom type "dimensions"
        {
            float x, y, z;
        }; 
        struct centerCoords_t   //custom type "centerCoords"
        {
            float cX, cY, cZ;
        };

        float weight;   //Unit: [kg]
        float density;  //Unit: [kg/m^3]

        dimensions_t dims;      //Note: those are the current dimensions effected by current orientation
        dimensions_t old_dims;  //Note: this old structure is use to preserve the original orientation of the pack
        centerCoords_t center;

        int packID;
        bool rotatable;
        bool palletizable;
        
        int packPalletIndex;    //TODO: this contains the Index of where it is inside a Vector (evaluate if usefull or not)

    public:

//CONSTRUCTORS
        Pack(){}                                                                        //generic constructor
        Pack(float X, float Y, float Z, float WGHT, int n_collo, bool ruotabile);       //specific constructor
        ~Pack();                                                                        //TODO: implement distructor

//SET-METHODS
        void set_dims(float x, float y, float z);       //dimensions are set with real values
        void set_centerCoords(float x, float y, float z); 
        void set_weight(float kg);
        void set_orientation(int a);                    //a = orientation (0~5, with 0 as standard orientation)
        void set_isRotatable(bool is_rotatable);
        void set_packID(int n_collo);
        
        dimensions_t* get_Dims();                       //outs a pointer to an out stucture (with correct dimensions)

//GET-METHODS
        int get_PackID();

};


#endif
