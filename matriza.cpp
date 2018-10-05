#include "matriza.h"

using namespace std;

Matriza::Matriza() {

}

Matriza::Matriza(double** Mat, int y, int x) {
    Matrix = new double*[y];
    srand(time(NULL));
    for (int j = 0; j < y; j++) {
        Matrix[j] = new double[x];
        for (int i = 0; i < x; i++) {
            if (Mat) Matrix[j][i] = Mat[j][i];
            else Matrix[j][i] = rand() % 9 * 1.0 + 1;
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
    cout << endl;
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++)
            cout << right << setw(8) << Matrix[i][j] << " ";
        cout << endl;
    }
}

void Matriza::Inversion() {
    //Create unitary matrix
    double** E = new double*[y];
    for (int i = 0; i < y; i++) {
        E[i] = new double[x];
        for (int j = 0; j < x; j++)
            if (i == j) E[i][j] = 1;
            else E[i][j] = 0;
    }

    //Invers with Gaus
    for (int i = 0; i < x; i++) {
        //_Check if first elem == 0
        if (Matrix[i][i] == 0) {
            int n;
            for (int k = 0; k < x; k++) {
                if (i+1 > y) n = i - 1;
                else n = i + 1;
                Matrix[i][k] += Matrix[n][k] * 2;
                E[i][k] += E[n][k] * 2;
            }
        }

        //_Make elem of main diagonal == 1
        for (int k = 0; k < x; k++) {
            if (k != i)
                Matrix[i][k] /= Matrix[i][i];
            E[i][k] /= Matrix[i][i];
        }
        Matrix[i][i] /= Matrix[i][i];

        //_Make all elements of the column except main diagonal == 0
        for (int j = 0; j < y; j++) {
            if (i != j) {
                for (int k = 0; k < y; k++) {
                    if (k != i)
                        Matrix[j][k] += Matrix[i][k] * Matrix[j][i] * -1;
                    E[j][k] += E[i][k] * Matrix[j][i] * -1;
                }

                Matrix[j][i] += Matrix[i][i] * Matrix[j][i] * -1;
            }
        }
    }

    Matrix = E;
}

void Matriza::Mult(double** Mat, int k) {
    double** E = new double*[y];
    for (int i = 0; i < y; i++)
        E[i] = new double[k];

    double sum;
    for (int i = 0; i < y; i++)
        for (int j = 0; j < k; j++) {
            sum = 0;
            for (int f = 0; f < x; f++) {
                sum += Matrix[i][f] * Mat[f][j];
            }
            E[i][j] = sum;
        }
    x = k;
    Matrix = E;
}











