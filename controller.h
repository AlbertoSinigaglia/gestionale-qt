#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "models/support/Convenzioni.h"
#include <QObject>
#include <QMessageBox>
#include <model.h>
#include <gestionale.h>
#include "models/headers/Employee.h"
#include "models/headers/DBDev.h"
class Controller : public QObject
{
    Q_OBJECT
    Gestionale* view;

    std::vector<Employee*> getEmployee() const{
        return std::vector<Employee*>{
            new DBDev(
                Persona{"Alberto", "Sinigaglia", "ASDGEIWIJFIK", Data::oggi()},
                DatiLavoratore{Data::oggi(), Data::oggi(), 10, 10.},
                DatiDeveloping(Conv::Linguaggio::PYTHON, 0, 0, 0, 0),
                DatiLatoServer{0,0,0,0},
                DatiDatabase{0,0,0}
            ),
            new DBDev(
                Persona{"Riccardo", "Calcagno", "ASDGEIWIJFIK", Data::oggi()},
                DatiLavoratore{Data::oggi(), Data::oggi(), 10, 10.},
                DatiDeveloping(Conv::Linguaggio::PYTHON, 0, 0, 0, 0),
                DatiLatoServer{0,0,0,0},
                DatiDatabase{0,0,0}
            ),
            new DBDev(
                Persona{"Sara", "Privitera", "ASDGEIWIJFIK", Data::oggi()},
                DatiLavoratore{Data::oggi(), Data::oggi(), 10, 10.},
                DatiDeveloping(Conv::Linguaggio::PYTHON, 0, 0, 0, 0),
                DatiLatoServer{0,0,0,0},
                DatiDatabase{0,0,0}
            )
        };
    }
public:
    explicit Controller(QObject *parent = nullptr, Gestionale* view_ = new Gestionale): QObject(parent), view(view_){
        /* ottiene employee da file */
        view->show();
        auto emp = getEmployee();
        view->setEmployees(emp);
        connect(view, SIGNAL(modifyEmployeeEvent(Employee*)), this, SLOT(modifyButtonClicked(Employee *)));
    }

public slots:
    void modifyButtonClicked(Employee * e){
        if(e){
            QMessageBox msgBox;
            msgBox.setText(QString("Stai modificando ") + QString(e->getNome().c_str()) + QString(" ") + QString(e->getCognome().c_str()));
            msgBox.setInformativeText("Vuoi che lo faccia esplodere?");
            msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
            msgBox.setDefaultButton(QMessageBox::Save);
            msgBox.exec();
        } else {
            QMessageBox::StandardButton reply;
              reply = QMessageBox::question(view, "Nessun dipendente selezionato", "Nessun dipendente selezionato, vuoi crearne uno?",QMessageBox::Yes|QMessageBox::No);
              if (reply == QMessageBox::Yes) {
                qDebug() << "no was clicked";
              } else {
                qDebug() << "Yes was *not* clicked";
              }
        }
    }

};

#endif // CONTROLLER_H
