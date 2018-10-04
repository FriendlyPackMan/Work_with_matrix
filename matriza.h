#ifndef MATRIZA_H
#define MATRIZA_H

#include <iostream>
#include <ctime>
#include <iomanip>

class Matriza
{
public:
    Matriza();
    Matriza(double**, int, int);
    ~Matriza();
    void Display();
private:
    double** Matrix;
    int y = 0, x = 0;
};

#endif // MATRIZA_H
