#include <vector>
#include <string>
#include "../../3D_Objects/headers/Pack.h"

using namespace std;

int partition(vector<Pack>& pacchi, int low, int high) {
    double pivot = max(pacchi[low].get_Dims()->x, max(pacchi[low].get_Dims()->y, pacchi[low].get_Dims()->z));
    int i = low - 1, j = high + 1;
    while (true) {
        do {
            i++;
        } while (max(pacchi[i].get_Dims()->x, max(pacchi[i].get_Dims()->y, pacchi[i].get_Dims()->z)) > pivot);
        do {
            j--;
        } while (max(pacchi[j].get_Dims()->x, max(pacchi[j].get_Dims()->y, pacchi[j].get_Dims()->z)) < pivot);
        if (i >= j) {
            return j;
        }
        swap(pacchi[i], pacchi[j]);
    }
}

void quickSort(vector<Pack>& pacchi, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(pacchi, low, high);
        quickSort(pacchi, low, pivotIndex);
        quickSort(pacchi, pivotIndex + 1, high);
    }
}

void swap(Pack& a, Pack& b){
    Pack c=a;
    a=b;
    b=c;
}
