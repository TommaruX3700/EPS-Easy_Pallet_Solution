class Cell //punto della griglia
{
    private:
        float c1, c2;
        bool libera; 

    public:
        Cella() : c1(0.0), c2(0.0), libera(true) {}
        Cella(float dim1, float dim2) {
            c1 = dim1 + 0.5;
            c2 = dim2 + 0.5;
            libera = true;
        }
};