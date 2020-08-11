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
//    auto dym= DynamicArray<Employee*>{
//            new DBDev(
//                Persona{"Alberto", "Sinigaglia", "ASDGEIWIJFIK", Data::oggi()},
//                DatiLavoratore{Data::oggi(), Data::oggi(), 10, 10.},
//                DatiDeveloping(Conv::Linguaggio::PYTHON, 0, 0, 0, 0),
//                DatiLatoServer{0,0,0,0},
//                DatiDatabase{0,0,0}
//            ),
//            new DBDev(
//                Persona{"Riccardo", "Calcagno", "ASDGEIWIJFIK", Data::oggi()},
//                DatiLavoratore{Data::oggi(), Data::oggi(), 10, 10.},
//                DatiDeveloping(Conv::Linguaggio::PYTHON, 0, 0, 0, 0),
//                DatiLatoServer{0,0,0,0},
//                DatiDatabase{0,0,0}
//            ),
//            new DBDev(
//                Persona{"Sara", "Privitera", "ASDGEIWIJFIK", Data::oggi()},
//                DatiLavoratore{Data::oggi(), Data::oggi(), 10, 10.},
//                DatiDeveloping(Conv::Linguaggio::PYTHON, 0, 0, 0, 0),
//                DatiLatoServer{0,0,0,0},
//                DatiDatabase{0,0,0}
//            )
//    };

    return a.exec();
}
