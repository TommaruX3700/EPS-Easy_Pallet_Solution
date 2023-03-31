// TESTING GENERICO SULLA GESTIONE DELLO SPAZIO 3D A "PROIEZIONE SUI PIANI". INVECE DI GESTIRE
// UNA GRIGLIA DI PUNTATORI O CELLE ENORME DI 120x80x230, CIOÈ 2.2 MILIONI DI ELEMENTI, 
// GENERO LE LORO PROIEZIONI SUI PIANI XY, XZ, YZ, RIDUCENDO DI MOLTO IL NUMERO DI PUNTI 
// CHE L'ALGORITMO DOVRÀ ANALIZZARE (120x80+120x230+80x230 CIOÈ SOLI 55600 ELEMENTI) 


#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
#include <windows.h>

using namespace std;

// Semplificazione dell'oggetto pacco

class Pacco{
    public:
    float x, y, z;
    float cX, cY, cZ;

    Pacco(float X, float Y, float Z, float CX, float CY, float CZ){
        x=X; y=Y; z=Z; cX=CX; cY=CY; cZ=CZ;
    }

};

//Definisco la cella unitaria 2D

class Cella {
public:
    float c1, c2;
    bool libera;

    Cella() : c1(0.0), c2(0.0), libera(true) {}

    Cella(float dim1, float dim2) {
        c1 = dim1 + 0.5;
        c2 = dim2 + 0.5;
        libera = true;
    }
};


//Definisco una classe virtuale che rappresenta il generico piano 2D

class Piano2D{
public:
    virtual void occupaCelle(float c1, float c2, float dim1, float dim2) = 0;
    virtual bool isFree(float c1, float c2, float dim1, float dim2) = 0;
};


// Definisco il piano XY

class pianoXY : public Piano2D{
public:
    int max_X;
    int max_Y;
    Cella** cella;

    pianoXY(int dim1, int dim2){
        max_X = dim1;
        max_Y = dim2;
        cella = new Cella*[max_X];
        for(int i = 0; i < max_X; i++){
            cella[i] = new Cella[max_Y];
            for(int j = 0; j < max_Y; j++){
                cella[i][j] = Cella(i, j);
            }
        }
    }

    ~pianoXY(){
        for(int i = 0; i < max_X; i++){
            delete[] cella[i];
        }
        delete[] cella;
    }

    bool isFree(float c1, float c2, float dim1, float dim2){
        // implementazione della funzione
        return true;
    }

    // Metodo che occupa le celle in base al pacco messo
    void occupaCelle(float c1, float c2, float dim1, float dim2){
        for(float i=(-dim1)/2; i<=dim1/2; i+=1){
            for(float j=(-dim2)/2; j<=dim2/2; j+=1){
                cella[int(c1+i)][int(c2+j)].libera=false;              
            }
        }
        //cout<<dim1<<" "<<dim2<<" CELLE OCCUPATE: ["<<c1-dim1/2<<"]["<<c2-dim2/2<<"] - ["<<c1+dim2/2<<"]["<<c2+dim2/2<<"]"<<endl;
    }

};

//Definisco il piano XZ

class pianoXZ : public Piano2D{
public:
    int max_X;
    int max_Z;
    Cella** cella;

    pianoXZ(int dim1, int dim2){
        max_X = dim1;
        max_Z = dim2;
        cella = new Cella*[max_X];
        for(int i = 0; i < max_X; i++){
            cella[i] = new Cella[max_Z];
            for(int j = 0; j < max_Z; j++){
                cella[i][j] = Cella(i, j);
            }
        }
    }

    ~pianoXZ(){
        for(int i = 0; i < max_X; i++){
            delete[] cella[i];
        }
        delete[] cella;
    }

    bool isFree(float c1, float c2, float dim1, float dim2){
        // implementazione della funzione
        return true;
    }

    // Metodo che occupa le celle in base al pacco messo
    void occupaCelle(float c1, float c2, float dim1, float dim2){
        for(float i=(-dim1)/2; i<=dim1/2; i+=1){
            for(float j=(-dim2)/2; j<=dim2/2; j+=1){
                cella[int(c1+i)][int(c2+j)].libera=false;                
            }
        }
        //cout<<dim1<<" "<<dim2<<" CELLE OCCUPATE: ["<<c1-dim1/2<<"]["<<c2-dim2/2<<"] - ["<<c1+dim1/2<<"]["<<c2+dim2/2<<"]"<<endl;
    }
};

//Definisco il piano YZ

class pianoYZ : public Piano2D{
public:
    int max_Y;
    int max_Z;
    Cella** cella;

    
    pianoYZ(int dim1, int dim2){
        max_Y = dim1;
        max_Z = dim2;
        cella = new Cella*[max_Y];
        for(int i = 0; i < max_Y; i++){
            cella[i] = new Cella[max_Z];
            for(int j = 0; j < max_Z; j++){
                cella[i][j] = Cella(i, j);
            }
        }
    }

    ~pianoYZ(){
        for(int i = 0; i < max_Y; i++){
            delete[] cella[i];
        }
        delete[] cella;
    }

    bool isFree(float c1, float c2, float dim1, float dim2){
        // implementazione della funzione
        return true;
    }


    // Metodo che occupa le celle in base al pacco messo
    void occupaCelle(float c1, float c2, float dim1, float dim2){
        for(float i=(-dim1)/2; i<=dim1/2; i+=1){
            for(float j=(-dim2)/2; j<=dim2/2; j+=1){
                cella[int(c1+i)][int(c2+j)].libera=false;
            }
        }
        //cout<<dim1<<" "<<dim2<<" CELLE OCCUPATE: ["<<c1-dim1/2<<"]["<<c2-dim2/2<<"] - ["<<c1+dim1/2<<"]["<<c2+dim2/2<<"]"<<endl;
    }
};

int main(){

    int max_X=120;
    int max_Y=80;
    int max_Z=230;

    //Genero i piani delle dimensioni del pallet

    pianoXY XY(120, 80);
    pianoXZ XZ(120, 230);
    pianoYZ YZ(80, 230);

    //Controllo che l'occupazione di una cella
    cout<<"Libera = "<<XY.cella[50][25].libera<<" "<<XZ.cella[50][30].libera<<" "<<YZ.cella[25][30].libera<<endl;

    //Creo e piazzo un pacco centrandolo nella cella precedente
    Pacco pacco_test=Pacco(49, 49, 49, 50.5, 25.5, 30.5);
    XY.occupaCelle(pacco_test.cX, pacco_test.cY, pacco_test.x, pacco_test.y);
    XZ.occupaCelle(pacco_test.cX, pacco_test.cZ, pacco_test.x, pacco_test.z);
    YZ.occupaCelle(pacco_test.cY, pacco_test.cZ, pacco_test.y, pacco_test.z);


    //Controllo se la cella centrale del pacco è occupata
    cout<<"Libera = "<<XY.cella[50][25].libera<<" "<<XZ.cella[50][30].libera<<" "<<YZ.cella[25][30].libera<<endl;

    return 0;
}