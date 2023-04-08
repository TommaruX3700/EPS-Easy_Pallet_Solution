class 2DPlane
{
    private:
        
    public:
        virtual void occupaCelle(float c1, float c2, float dim1, float dim2) = 0;
        virtual bool isFree(float c1, float c2, float dim1, float dim2) = 0;
};

class XYplane : public 2DPlane
{
    private:
        int max_X;
        int max_Y;
        Cella** cella;

    public:
        XYplane(int dim1, int dim2);
        ~pianoXY();
        
};