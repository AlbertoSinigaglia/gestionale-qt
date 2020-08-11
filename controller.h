#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "CSV/CSVWriter.h"
#include "models/support/Convenzioni.h"
#include <QObject>
#include <QMessageBox>
#include <gestionale.h>
#include "models/headers/Employee.h"
#include "models/headers/DBDev.h"
#include<QFileDialog>
#include<QDebug>
#include"employeesmanagement.h"
#include <algorithm>
class Controller : public QObject
{
    Q_OBJECT
    Gestionale* view;
    EmployeesManagement* model;
    void update(bool want_to_export = false){
        QString path =
                want_to_export ?
                QFileDialog::getOpenFileName(view,"Salvataggio Dipendenti", "", "Files (*.qcsv)"):
                model->getOriginalSource();
        model->save(path);
    }
    QString getFilePath(const QString info) const{
        return QFileDialog::getOpenFileName(view,info, "", "Files (*.qcsv)");
    }
public:
    explicit Controller(QObject *parent = nullptr, Gestionale* view_ = new Gestionale): QObject(parent), view(view_){
        view->show();
        model = new EmployeesManagement(getFilePath("Carica Dipendenti"));
        view->setEmployees(model->getEmployees());
        connect(view, SIGNAL(modifyEmployeeEvent(Employee*)), this, SLOT(modifyButtonClicked(Employee *)));
        connect(view, SIGNAL(insertEmployeeEvent()), this, SLOT(insertNewEmployee()));
        connect(view, SIGNAL(deleteEmployeeEvent(Employee *)), this, SLOT(deleteEmployee(Employee *)));
        connect(view, SIGNAL(employeeListElementDoubleClickedEvent(Employee*)), this, SLOT(openEmployeeInfo(Employee*)));
    }

public slots:
    void deleteEmployee(Employee * e){
        if(e){
            auto employees = model->getEmployees();
            for(auto it = employees.begin(); it != employees.end(); ++it){
                if(*it == e){
                    employees
                }
            }
            qDebug() << empl.size();
        }
    }
    void insertNewEmployee(){
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
            if(reply == QMessageBox::Yes) this->insertNewEmployee() ;
        }
    }

};

#endif // CONTROLLER_H
