#include <QCoreApplication>
#include <iostream>
#include <ctime>

#include "matriza.h"

using namespace std;

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    Matriza temp(nullptr, 5, 5);
    temp.Display();

    Matriza temp2(nullptr, 5, 5);
    temp2.Display();

    return a.exec();
}
