#include "gestionale.h"
#include "collections/DynamicArray.h"
#include <QApplication>
#include "controller.h"
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller w;
    return a.exec();
}
