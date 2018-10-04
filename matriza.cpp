#include "matriza.h"

using namespace std;

Matriza::Matriza() {

}

Matriza::Matriza(double** Mat, int y, int x) {
    Matrix = new double*[y];
    for (int j = 0; j < y; j++) {
        Matrix[j] = new double[x];
        for (int i = 0; i < x; i++) {
            if (Mat) Matrix[j][i] = Mat[j][i];
            else Matrix[j][i] = rand() % 100 * 1.0 - 50;
        }
    }

    this->x = x;
    this->y = y;
}

Matriza::~Matriza() {
    for (int j = 0; j < y; j++)
        delete[] Matrix[j];
    delete[] Matrix;
}

void Matriza::Display() {
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++)
            cout << right << setw(3) << Matrix[i][j] << " ";
        cout << endl;
    }
}
