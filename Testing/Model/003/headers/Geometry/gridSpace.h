class gridSpace
{
    private:
        plane_t xyPlane;
        plane_t xzPlane;
        plane_t yzPlane;

    public:
        gridSpace(int x, int y, int z);        
        ~gridSpace();

        void set_occupiedCells(float c1, float c2, float dim1, float dim2); 

        //bool isFree(float c1, float c2, float dim1, float dim2);
};

