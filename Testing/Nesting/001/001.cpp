#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
#include <windows.h>

using namespace std;

class Pacco2D{
    public:
    float x, y;
    float peso;
    float cX, cY;
};

int partition(Pacco2D pacchi[], int low, int high) {
    int pivot = std::max(pacchi[low].x, pacchi[low].y);
    int i = low - 1, j = high + 1;
    while (true) {
        do {
            i++;
        } while (std::max(pacchi[i].x, pacchi[i].y) > pivot);
        do {
            j--;
        } while (std::max(pacchi[j].x, pacchi[j].y) < pivot);
        if (i >= j) {
            return j;
        }
        std::swap(pacchi[i], pacchi[j]);
    }
}

void quickSort(Pacco2D pacchi[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(pacchi, low, high);
        quickSort(pacchi, low, pivotIndex);
        quickSort(pacchi, pivotIndex + 1, high);
    }
}
    

void swap(int a, int b){
    int c=a;
    a=b;
    b=c;
}


void posizionamento(Pacco2D pacchi[], float pallet_ratio){
    //Definisco il centro del primo pacco
    pacchi[0].cX=0;
    pacchi[0].cY=0;
    if((pacchi[0].y/pacchi[0].x)>pallet_ratio){
        //Metto il pacco iniziale con il lato orizzontale come quello più lungo. Questo è il primo layer
        swap(pacchi[0].x, pacchi[0].y);
    }

    //Metto il secondo pacco nel layer superiore, centrato con quello iniziale
    pacchi[1].cX=0;
    pacchi[1].cY=(pacchi[0].y/2)+(pacchi[1].y/2);

    
    if(pacchi[1].x+pacchi[2].x<=pacchi[0].x){
        //Se la somma della lunghezza orizzontale del secondo pacco e del terzo pacco è inferiore o uguale a quella del primo, metto il terzo nel secondo layer, affiancato al secondo
        pacchi[2].cX=(pacchi[1].x/2)+(pacchi[2].x/2);
        pacchi[2].cY=(pacchi[0].y/2)+(pacchi[2].y/2);
        //Successivamente centro gli ultimi 2 pacchi in modo che il lato orizzontale del blocco creato (secondo+terzo pacco) del secondo layer sia centrato con il primo pacco
        pacchi[1].cX=pacchi[1].cX-(pacchi[2].cX/2);
        pacchi[2].cX=pacchi[2].cX-(pacchi[2].cX/2);
    } else {
        //Altrimenti metto il terzo pacco centrato nel layer terzo layer, quello appoggiato al lato inferiore del primo pacco
        pacchi[2].cX=0;
        pacchi[2].cY=-(pacchi[0].y/2)-(pacchi[2].y/2);
    }
    
}

void posizionamento2(Pacco2D pacchi[], float pallet_ratio, int n_pacchi){

    //Definisco il centro del primo pacco
    pacchi[0].cX=0;
    pacchi[0].cY=0;
    if((pacchi[0].y/pacchi[0].x)>pallet_ratio){
        //Metto il pacco iniziale con il lato orizzontale come quello più lungo. Questo è il primo layer
        swap(pacchi[0].x, pacchi[0].y);
    }

    int somma_layer1=0;
    int somma_layer2=0;
    int n_layer1=0;
    int n_layer2=0;

    vector<Pacco2D> layer1;
    vector<Pacco2D> layer2;

    int i=1;

    while(((somma_layer1+pacchi[i].x)<=pacchi[0].x)&&(i<n_pacchi)){
        if (i % 2 == 1){
            layer1.insert(layer1.begin(), pacchi[i]);
            somma_layer1=somma_layer1+pacchi[i].x;
            n_layer1++;
        } else {
            layer1.insert(layer1.end(), pacchi[i]);
            somma_layer1=somma_layer1+pacchi[i].x;
            n_layer1++;
        }
        i++;
    }


    while(((somma_layer2+pacchi[i].x)<=pacchi[0].x)&&(i<n_pacchi)){
        if (i % 2 == 1){
            layer2.insert(layer2.begin(), pacchi[i]);
            somma_layer2=somma_layer2+pacchi[i].x;
            n_layer2++;
        } else {
            layer2.insert(layer2.end(), pacchi[i]);
            somma_layer2=somma_layer2+pacchi[i].x;
            n_layer2++;
        }
        i++;
    }

    cout<<endl<<n_layer1<<endl<<n_layer2<<endl;

    float offsetX=0;
    float offsetX_Gruppo=0;

    for(int j=0; j<n_layer1; j++){
        pacchi[j+1].x=layer1[j].x;
        pacchi[j+1].y=layer1[j].y;
        pacchi[j+1].peso=layer1[j].peso;
        if(j==0){
            pacchi[j+1].cX=0;
        } else {
            offsetX=offsetX+(pacchi[j+1].x/2)+(pacchi[j].x/2);
            pacchi[j+1].cX=offsetX;
        }   
        offsetX_Gruppo=offsetX_Gruppo+(pacchi[j+1].x/2);
    }

    for(int j=0; j<n_layer1; j++){
        pacchi[j+1].cY=(pacchi[j+1].y/2)+(pacchi[0].y/2);
        pacchi[j+1].cX=pacchi[j+1].cX-offsetX_Gruppo+(pacchi[1].x/2);
    }


    offsetX=0;
    offsetX_Gruppo=0;

    for(int j=0; j<n_layer2; j++){
        pacchi[j+1+n_layer1].x=layer2[j].x;
        pacchi[j+1+n_layer1].y=layer2[j].y;
        pacchi[j+1+n_layer1].peso=layer2[j].peso;
        if(j==0){
            pacchi[j+1+n_layer1].cX=0;
        } else {
            offsetX=offsetX+(pacchi[j+1+n_layer1].x/2)+(pacchi[j+n_layer1].x/2);
            cout<<endl<<offsetX<<endl;
            pacchi[j+1+n_layer1].cX=offsetX;
        }   
        offsetX_Gruppo=offsetX_Gruppo+(pacchi[j+1+n_layer1].x/2);
        cout<<endl<<offsetX<<endl;
    }

    for(int j=0; j<n_layer1; j++){
        pacchi[j+1+n_layer1].cY=-(pacchi[j+1+n_layer1].y/2)-(pacchi[0].y/2);
        pacchi[j+1+n_layer1].cX=pacchi[j+1+n_layer1].cX-offsetX_Gruppo+(pacchi[1+n_layer1].x/2);
    }
}




int main(){
    int n_pacchi=4;
    float larghezza_pallet=800.0;
    float lunghezza_pallet=1200.0;
    float pallet_ratio=larghezza_pallet/lunghezza_pallet;
    Pacco2D pacchi[n_pacchi];

    //Inserisco dimensioni pacchi (Peso per ora superfluo)
    for(int i=0; i<n_pacchi; i++){
        cout<<"Inserisci dimensioni e peso pacco "<<i+1<<":"<<endl;
        cout<<"x: ";
        cin>>pacchi[i].x;
        cout<<"y: ";
        cin>>pacchi[i].y;
        cout<<"peso: ";
        cin>>pacchi[i].peso;
    }

    

    int n = sizeof(pacchi) / sizeof(pacchi[0]);
    //Ordino i pacchi dal lato maggiore minimo al lato maggiore massimo
    quickSort(pacchi, 0, n - 1);

    for(int i=1; i<n_pacchi; i++){
        if(pacchi[i].x<pacchi[i].y){
            swap(pacchi[i].x,pacchi[i].y);
        }
    }

    //Eseguo il posizionamento dei pacchi secondo il mini prototipo di algoritmo
    posizionamento2(pacchi, pallet_ratio, n_pacchi);

    //Visualizzo in output il centro di ogni pacco per testare l'algoritmo
    for (int i = 0; i < n_pacchi; i++) {
        cout << "{" << pacchi[i].cX << ", " << pacchi[i].cY << "}" << endl;
    }

    return 0;
}