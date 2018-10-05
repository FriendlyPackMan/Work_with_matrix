#include <QCoreApplication>
#include <iostream>
#include <ctime>

#include "matriza.h"

using namespace std;

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    /*Matriza temp(nullptr, 2, 2);
    Matriza temp2(temp.getMatrix(), temp.getY(), temp.getX());

    temp.Display();
    temp.Inversion();
    temp.Display();

    temp2.Mult(temp.getMatrix(), temp.getY(), temp.getX());
    temp2.Display();*/

    Matriza temp(nullptr, 1, 2);
    Matriza temp2(nullptr, 2, 3);
    temp.Display();
    temp2.Display();

    temp.Mult(temp2.getMatrix(), temp2.getX());
    temp.Display();

    return a.exec();
}
