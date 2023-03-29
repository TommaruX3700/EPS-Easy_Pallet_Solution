#ifndef PACCO_H
#define PACCO_H

#include <string>



class Pacco2D{
    public:
    int n_collo;
    double x, y, z;
    double peso;
    std::string pallettizzabile;
    bool ruotabile;
};

#endif