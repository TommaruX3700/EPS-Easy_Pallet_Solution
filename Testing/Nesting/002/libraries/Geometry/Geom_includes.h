class General_Geometry
{
    private:
        typedef struct versor
            {
                int vX, vY, vZ;
            };
        
        versor vers[6];
    
    public:
        versor* GenerateVersors();
        General_Geometry(){
            GenerateVersors();
        }
      
}