class 2DPlane
{
    public:
        virtual void set_occupiedCells(float c1, float c2, float dim1, float dim2) = 0;
        //virtual bool isFree(float c1, float c2, float dim1, float dim2) = 0;
};

class XYplane : public 2DPlane
{
    private:
        int max_X;
        int max_Y;
        Cell** cell;

    public:
        XYplane(int dim1, int dim2);
        ~XYplane();
        
};

class XZplane : public 2DPlane
{
    private:
        int max_X;
        int max_Y;
        Cell** cell;

    public:
        XZplane(int dim1, int dim2);
        ~XZplane();
};

class YZplane : public 2DPlane
{
    private:
        int max_X;
        int max_Y;
        Cell** cell;
        
    public:
        YZplane(int dim1, int dim2);
        ~YZplane();
};
