#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "models/support/Convenzioni.h"
#include <QObject>
#include <QMessageBox>
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
        view->show();
        /* ottiene employee da file */
        view->setEmployees(getEmployee());
        connect(view, SIGNAL(modifyEmployeeEvent(Employee*)), this, SLOT(modifyButtonClicked(Employee *)));
        connect(view, SIGNAL(insertEmployeeEvent()), this, SLOT(insertNewEmlployee()));
        connect(view, SIGNAL(deleteEmployeeEvent(Employee *)), this, SLOT(deleteEmployee(Employee *)));
        connect(view, SIGNAL(employeeListElementDoubleClickedEvent(Employee*)), this, SLOT(openEmployeeInfo(Employee*)));
    }

public slots:
    void deleteEmployee(Employee * e){
        if(e){
            QMessageBox msgBox(view);
            msgBox.setText(QString("Stai per eliminare ") + QString(e->getNome().c_str()) + QString(" ") + QString(e->getCognome().c_str()));
            msgBox.setInformativeText("Sicuro di voler procedere?");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::No);
            msgBox.exec();
        } else {
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(view, "Nessun dipendente selezionato", "Nessun dipendente selezionato, vuoi crearne uno?",QMessageBox::Yes|QMessageBox::No);
            if(reply == QMessageBox::Yes) this->insertNewEmlployee() ;
        }
    }
    void insertNewEmlployee(){
        QMessageBox::information(view, "inserimento dipendente", "Stai per inserire un nuovo dipendente");
    }
    void openEmployeeInfo(Employee* e){
        QMessageBox::information(view, "Info dipendente", QString("Stai modificando ") + QString(e->getNome().c_str()) + QString(" ") + QString(e->getCognome().c_str()));
    }
    void modifyButtonClicked(Employee * e){
        if(e){
            QMessageBox msgBox(view);
            msgBox.setText(QString("Stai modificando ") + QString(e->getNome().c_str()) + QString(" ") + QString(e->getCognome().c_str()));
            msgBox.setInformativeText("Vuoi che lo faccia esplodere?");
            msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
            msgBox.setDefaultButton(QMessageBox::Save);
            msgBox.exec();
        } else {
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(view, "Nessun dipendente selezionato", "Nessun dipendente selezionato, vuoi crearne uno?",QMessageBox::Yes|QMessageBox::No);
            if(reply == QMessageBox::Yes) this->insertNewEmlployee() ;
        }
    }

};

#endif // CONTROLLER_H
