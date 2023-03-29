#ifndef QSP_H
#define QSP_H

#include <vector>
#include <string>
#include "pacco.h"

using namespace std;

int partition(vector<Pacco2D>& pacchi, int low, int high) {
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

void quickSort(vector<Pacco2D>& pacchi, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(pacchi, low, high);
        quickSort(pacchi, low, pivotIndex);
        quickSort(pacchi, pivotIndex + 1, high);
    }
}

void swap(Pacco2D& a, Pacco2D& b){
    Pacco2D c=a;
    a=b;
    b=c;
}

#endif