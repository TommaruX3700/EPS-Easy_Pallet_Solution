#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
#include <windows.h>
#include <chrono>

using namespace std;

class Cella{
    public:
    bool libera;
};

int main(){


    auto start = chrono::high_resolution_clock::now();


    Cella*** cella = new Cella**[120];
    for (int i = 0; i < 120; i++) {
        cella[i] = new Cella*[80];
        for (int j = 0; j < 80; j++) {
            cella[i][j] = new Cella[230];
        }
    }


    cout<<"Griglia di celle inizializzata con successo"<<endl;

    for(int i=0; i<120; i++){
       for(int j=0; j<80; j++){
            for(int k=0; k<230; k++){
                cella[i][j][k].libera = true;
            }
        }
    }

    cout<<cella[119][79][229].libera<<endl;
    
    cout<<"Reso le celle libere con successo"<<endl;

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cout << "Tempo di esecuzione: " << duration.count() << " millisecondi" << endl;

    return 0;
}
