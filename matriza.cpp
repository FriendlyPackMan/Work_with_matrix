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









Matriza::Matriza(double** Mat, double* annex, int y, int x) {
	Matrix = new double*[y];
	srand(time(NULL));
	for (int j = 0; j < y; j++) {
		Matrix[j] = new double[x];
		for (int i = 0; i < x; i++) {
			if (Mat) Matrix[j][i] = Mat[j][i];
			else Matrix[j][i] = rand() % 9 * 1.0 + 1;
		}
	}

	this.annex = new double[y];
	for (int i = 0; i < y; i++) {
		if(annex) this.annex[i] = annex[i];
		else annex[i] = rand() % 9 * 1.0 + 1;
	}

	this->x = x;
	this->y = y;
}

Matriza Matriza::newMatrix(double** mat, int x, int y = x) {
	double** newMat = new double*[y];
	for (int j = 0; j < y; j++) {
		newMat[j] = new double[x];
	}
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			newMat[i][j] = mat[i][j];
		}
	}
	Matriza newMatrix = new Matriza(newMat)
		return newMatrix;
}

double Matriza::determinant(int x) {
	if (x == 0) return 1.0;
	double rez = 0;
	for (int i = 0; i < x; i++) {
		Matrix newMat = newMatrix(mat, x - 1);
		rez += pow(-1, (x + 1) + (y + 1)) * Matrix[0][i] * newMat.determinant(x - 1);
	}
	return rez;
}

double Matriza::Crammer_Method() {
	for (int i = 0; i < x; i++) {
		double** newMatrix = new double*[y];
		for (int j = 0; j < x; j++) {
			newMat[j] = new double[x];
		}
		for (int j = 0; j < y; j++) {
			for (int k = 0; k < x; k++) {
				if (k != i) {
					newMat[j][k] = Matrix[j][k];
				}
				else newMat[j][k] = annex[j];
			}
		}
		Matrix newMatrix = new Matrix(newMat);
		cout << "x1 = " << this.determinant() / newMatrix.determinant() << endl;
	}
}

/*
*
	!!!!!! ÍÀÑÒÓÏÍÓ ÔÓÍÊÖ²Þ ÇÀÁÎÐÎÍÅÍÎ ÄÈÂÈÒÈÑß ËÞÄßÌ Ç² ÑËÀÁÊÎÞ ÏÑÈÕ²ÊÎÞ !!!!!!
*
*/
double Matriza::Invers_Method() {
	double** inverse = new double*[y];
	for (int i = 0; i < y; i++) {
		inverse[i] = new double[x];
	}
	double det = this.determinant();
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			int ix = iy = 0;
			double** temp = new double[x - 1];
			for (int k = 0; k < x - 1; k++) {
				temp[k] = new double[x - 1];
			}

			for (int ii = 0; ii < x; ii++) {
				if (ii != i) {
					for (int jj = 0; jj < x; jj++) {
						if (jj != j) {
							temp[iy][ix] = Matrix[i][j];
						}
					}
					iy++;
					ix = 0;
				}
			}

			Matriza addit = new Matriza(temp, y - 1, x - 1);
			inverse[j][i] = pow(-1, (i + 1)*(j + 1)) * addit.determinant / det;
		}
	}
// ïîìíîæèòè íà annex (ðîçâÿçêè)
// ïîâåðíóòè ðåçóëüòàò 
}
