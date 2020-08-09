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
class Gestionale : public QWidget{
	Q_OBJECT

public:
	Gestionale(QWidget *parent = nullptr);
	~Gestionale();
    void setEmployees(const std::vector<Employee*>& empl){
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
    void modifyEmployeeEvent(Employee*);
public slots:
    void modifyButtonClicked(){
        qDebug() << "modifica cliccato";
        emit modifyEmployeeEvent(employeesList->getCurrent());
    }
};

#endif // GESTIONALE_H
