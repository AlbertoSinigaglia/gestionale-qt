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
class Gestionale : public QWidget{
	Q_OBJECT

public:
	Gestionale(QWidget *parent = nullptr);
	~Gestionale();
    void setEmployees(const DynamicArray<Employee*>& empl){
        this->employeesList->addEmployees(empl);
    }

private:
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
    QCheckBox* c_eta;
    QCheckBox* c_cf;

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
        emit deleteEmployeeEvent(employeesList->getCurrent());
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
