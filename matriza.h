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
    void Mult(double**, int);
    double** getMatrix() const { return Matrix; }
    int getY() const { return y; }
    int getX() const { return x; }
private:
    double** Matrix;
    int y = 0, x = 0;
};

#endif // MATRIZA_H
