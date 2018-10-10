#include <QCoreApplication>
#include <iostream>
#include <ctime>

#include "matriza.h"

using namespace std;

int main(int argc, char *argv[]) {
    //QCoreApplication a(argc, argv);

    /*Matriza temp(nullptr, 2, 2);
    Matriza temp2(temp.getMatrix(), temp.getY(), temp.getX());

    temp.Display();
    temp.Inversion();
    temp.Display();

    temp2.Mult(temp.getMatrix(), temp.getY(), temp.getX());
    temp2.Display();*/
	double** matrix = new double*[3];
	for (int i = 0; i < 3; i++) {
		matrix[i] = new matrix[3];
	}
	a[0][0] = 2.0;
	a[0][1] = 1.0;
	a[0][2] = 1.0;
	a[1][0] = 1.0;
	a[1][1] = -1.0;
	a[1][2] = 0.0;
	a[2][0] = 3.0;
	a[2][1] = -1.0;
	a[2][2] = 2.0;
	double* annex = new double[3];
	annex[0] = 2.0;
	annex[1] = -2.0;
	annex[2] = 2.0;

	Matriza Matrix(matrix, annex, 3);
	Matrix.Crammer();

    /*Matriza temp(nullptr, 1, 2);
    Matriza temp2(nullptr, 2, 3);
    temp.Display();
    temp2.Display();

    temp.Mult(temp2.getMatrix(), temp2.getX());
    temp.Display();
	*/
	return 0;//a.exec();
}
