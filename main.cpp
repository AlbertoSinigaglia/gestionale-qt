#include "gestionale.h"
#include "collections/DynamicArray.h"
#include <QApplication>
#include "controller.h"
#include "CSV/CSVWriter.h"
#include "collections/DynamicArray.h"
#include<QTranslator>
#include<QLibraryInfo>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    QTranslator qtTranslator;
    QLocale qloc(QLocale("it_IT"));
    QLocale::setDefault(qloc);
    if (qtTranslator.load(qloc ,QString("qt"), QString("_"),QLibraryInfo::location(QLibraryInfo::TranslationsPath))){
        a.installTranslator(&qtTranslator);
    }

    QTranslator qtBaseTranslator;
    if (qtBaseTranslator.load("qtbase_" + QLocale::system().name(),QLibraryInfo::location(QLibraryInfo::TranslationsPath))){
        a.installTranslator(&qtBaseTranslator);
    }
    a.setWindowIcon(QIcon(":resources/logo.ico"));
    a.setApplicationName("MyGestionale");
    Controller w;
    QObject::connect(&w, &Controller::exitEvent, &a, &QApplication::quit);
    return a.exec();
}
