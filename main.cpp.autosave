#include "gestionale.h"
#include "collections/DynamicArray.h"
#include <QApplication>
#include "controller.h"
#include "CSV/CSVWriter.h"


int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":resources/logo.ico"));
    a.setApplicationName("MyGestionale");
    Controller w;
    QObject::connect(&w, &Controller::exitEvent, &a, &QApplication::quit);
    return a.exec();
}
