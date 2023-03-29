class Pack
{
private:
    struct centerCoords
    {
        int x, y, z; //coordinates (divide cms by 10)

    };
    struct dimsFromCentrer
    {
        int x, y, z; //populate dividing dimensions by 2

    };
    
    float weight; //[kg]
    int density; //[Kg/m3]

public:
    void setCenterCoords(int x, int y, int z);
    void setDims(int x, int y, int z);
    int* getDims(); //define what type to pass back for 3 dimensions

};