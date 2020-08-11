#ifndef GESTIONALE_H
#define GESTIONALE_H

#include <QWidget>

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QCheckBox>
#include <QMenuBar>
#include <QMenu>
#include <QTableView>
#include <QGroupBox>
#include <QComboBox>
#include <QFile>
#include <QScrollArea>
#include <QListWidget>
#include "gestionalebutton.h"
#include "widgets/employeelistelement.h"
#include <vector>
#include "models/headers/Employee.h"
#include "widgets/employeeslist.h"
#include "collections/DynamicArray.h"
#include<QDebug>
#include "employeesmanagement.h"
class Gestionale : public QWidget{
	Q_OBJECT

public:
	Gestionale(QWidget *parent = nullptr);
    ~Gestionale();
    void setModel(EmployeesManagement* model_){
        model = model_;
    }
    void updateList() const{
        if(model){
            this->employeesList->setEmployees(*(model->getEmployees().get()));
        }
    }

private:
    EmployeesManagement* model;
	QHBoxLayout* mainLayout;
	//Layout Sinistro con tutti i suoi componenti
    QVBoxLayout* layoutFrameFiltri;
	QGroupBox* Visualizzare;
	QVBoxLayout* LayoutVisualizzare;
	//Layout Destro con tutti i suoi componenti
	QHBoxLayout* Left;
	QVBoxLayout* layoutVisualizza;


    EmployeesList* employeesList;
    QPushButton* modifica;
    QPushButton* inserisci;
    QPushButton* elimina;
    QCheckBox* c_nome;
    QCheckBox* c_cognome;
    QCheckBox* c_sesso;
    QCheckBox* c_dataNascita;
    QCheckBox* c_cf;
    QCheckBox* DataA;
    QCheckBox* DataFineContratto;
    QCheckBox* StipendioBase;
    QCheckBox* OreLavoro;

    void addTitleSinistro();
	void addBoxDestro();
	void addBoxSinistro();
	void addComboBox();
	void addFirstBox();
	void addBoxPersona();
	void addBoxLavoro();
	void addAzioni();

	void setStyle();
signals:
    void employeeListElementDoubleClickedEvent(Employee*);
    void modifyEmployeeEvent(Employee*);
    void deleteEmployeeEvent(Employee *);
    void insertEmployeeEvent();
public slots:
    void deleteButtonClicked(){
        auto e = employeesList->getCurrent();
        if(e){
            QMessageBox msgBox(this);
            msgBox.setText(QString("Stai per eliminare ") + QString(e->getNome().c_str()) + QString(" ") + QString(e->getCognome().c_str()));
            msgBox.setInformativeText("Sicuro di voler procedere?");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::No);
            int resp = msgBox.exec();
            if(resp == QMessageBox::Yes)
                emit deleteEmployeeEvent(employeesList->getCurrent());
        } else {
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Nessun dipendente selezionato", "Nessun dipendente selezionato, vuoi crearne uno?",QMessageBox::Yes|QMessageBox::No);
            if(reply == QMessageBox::Yes) this->insertButtonClicked() ;
        }
    }
    void insertButtonClicked(){
        emit insertEmployeeEvent();
    }
    void modifyButtonClicked(){
        emit modifyEmployeeEvent(employeesList->getCurrent());
    }
    void employeeListElementDoubleClicked(EmployeeListElement* e){
        emit employeeListElementDoubleClickedEvent(e->getEmployee());
    }
};

#endif // GESTIONALE_H
