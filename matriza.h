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
    void Inversion();
    double** getMatrix() const { return Matrix; }
    void Mult(double**, int, int);
    int getY() { return y; }
    int getX() { return x; }
private:
    double** Matrix;
    int y = 0, x = 0;
};

#endif // MATRIZA_H
