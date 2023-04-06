#include <vector>
#include <string>
#include "../../3D_Objects/headers/Pack.h"

using namespace std;

int partition(vector<Pacco>& pacchi, int low, int high) {
    double pivot = max(pacchi[low].x, max(pacchi[low].y, pacchi[low].z));
    int i = low - 1, j = high + 1;
    while (true) {
        do {
            i++;
        } while (max(pacchi[i].x, max(pacchi[i].y, pacchi[i].z)) > pivot);
        do {
            j--;
        } while (max(pacchi[j].x, max(pacchi[j].y, pacchi[j].z)) < pivot);
        if (i >= j) {
            return j;
        }
        swap(pacchi[i], pacchi[j]);
    }
}

void quickSort(vector<Pacco>& pacchi, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(pacchi, low, high);
        quickSort(pacchi, low, pivotIndex);
        quickSort(pacchi, pivotIndex + 1, high);
    }
}

void swap(Pacco& a, Pacco& b){
    Pacco c=a;
    a=b;
    b=c;
}
