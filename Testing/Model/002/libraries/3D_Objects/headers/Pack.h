class Pack
{
    private:

        typedef struct dimensions_t //defines type "dimensions"
        {
            float x, y, z;
        }; 
        typedef struct centerCoords_t //defines type "centerCoords"
        {
            float cX, cY, cZ;
        };

        float weight; //[kg]
        float density; //[Kg/m3]

        dimensions_t dims;
        centerCoords_t center;

        int packID;
        bool rotatable;
        bool palletizable;

    public:

        Pack(float X, float Y, float Z, float WGHT, int n_collo, bool ruotabile){ //constructor
            set_Dims(X, Y, Z);
            set_weight(WGHT);
            set_PackID(n_collo);
            is_Rotatable(ruotabile);
        }

        void set_Dims(float x, float y, float z){
            this->dims.x = x;
            this->dims.y = y;
            this->dims.z = z;
        }

        void set_CenterCoords(float x, float y, float z);

        void set_weight(float kg){
            this->weight = kg;
        }

        void set_Orientation(int a); //change orientation by setting number here (0, 1 or 2), but multiplies x "1" or "-1"

        void is_Rotatable(bool is_rotatable){
            this->rotatable = is_rotatable;
        }

        void set_PackID(int n_collo){
            this->packID = n_collo;
        }

        dimensions_t* get_Dims(){
            return &this->dims;     //outs a pointer to an out stucture (with correct dimensions)
        }                           
};