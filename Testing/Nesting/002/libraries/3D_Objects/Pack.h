class Pack
{
    private:
        typedef struct dimensions //defines type "dimensions"
        {
            float x, y, z; //divided by 2
        }; 
        typedef struct centerCoords //defines type "centerCoords"
        {
            float cX, cY, cZ;
        };

        float weight; //[kg]
        float density; //[Kg/m3]

        dimensions dims;
        centerCoords center;

    public:
        void set_Dims(float x, float y, float z);
        void set_CenterCoords(float x, float y, float z);
        void set_weight(float kg);
        void set_Orientation(int a); //change orientation by setting number here (0, 1 or 2), but multiplies x "1" or "-1"

        dimensions* get_Dims(); //outs a pointer to an out stucture (with correct dimensions)

        Pacco(float X, float Y, float Z, float CX, float CY, float CZ, float WGHT){ //constructor
            set_Dims(X, Y, Z);
            set_CenterCoords(CX, CY, CZ);
            set_weight(WGHT);
        }

};