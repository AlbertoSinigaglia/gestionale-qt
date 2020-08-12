#include "gestionale.h"
#include "collections/DynamicArray.h"
#include <QApplication>
#include "controller.h"
#include <QDebug>
#include "CSV/CSVWriter.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller w;
    QObject::connect(&w, &Controller::exitEvent, &a, &QApplication::quit);
    return a.exec();
}
