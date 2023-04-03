class Pack
{
    private:
        typedef struct dimensions
        {
            float x, y, z; //populate dividing dimensions by 2
        };
        typedef struct centerCoords
        {
            float cX, cY, cZ;
        };

        float weight; //[kg]
        int density; //[Kg/m3]

    public:
        Pacco(float X, float Y, float Z, float CX, float CY, float CZ){
            x=X; y=Y; z=Z; cX=CX; cY=CY; cZ=CZ;
        }
        
        void set_CenterCoords(float x, float y, float z);
        void set_Dims(float x, float y, float z);

        dimensions get_Dims(); //define what type to pass back for 3 dimensions
        void change_Orientation(int a); //change orientation by setting number here (0, 1 or 2), but multiplies x "1" or "-1"

    
};