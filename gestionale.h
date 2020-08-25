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
#include <QAction>
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
    void setModel(std::shared_ptr<EmployeesManagement> model_);
    void updateList() const;
    bool disableSaveEnableImport();
    void showLiquidation(QString nome, float quota_liquidazione);

private:
    std::shared_ptr<EmployeesManagement> model;
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
    QComboBox* Dipendenti;
    QCheckBox* c_nome;
    QCheckBox* c_cognome;
    QCheckBox* c_sesso;
    QCheckBox* c_dataNascita;
    QCheckBox* c_cf;
    QCheckBox* DataA;
    QCheckBox* DataFineContratto;
    QCheckBox* StipendioBase;
    QCheckBox* OreLavoro;
    QAction* a_import;
    QAction* a_export;
    QAction* a_exit;
    QAction* a_open;
    QCheckBox* produttivo;
    QCheckBox* bonus_stipendio;
    QCheckBox* grado_esperienza;
    QCheckBox* numero_righe_totali;
    QCheckBox* linguaggio;
    QCheckBox* percentuale_ripristino;
    QCheckBox* numero_criticita_risolte;
    QCheckBox* ore_straordinari;




    void addTitleSinistro();
	void addBoxDestro();
	void addBoxSinistro();
	void addComboBox();
	void addFirstBox();
	void addBoxPersona();
	void addBoxLavoro();
    void addBoxSpecifico();
	void addAzioni();
    void addMenu();

	void setStyle();
signals:
    void employeeListElementDoubleClickedEvent(Employee*);
    void modifyEmployeeEvent(Employee*);
    void deleteEmployeeEvent(Employee *);
    void insertEmployeeEvent();
    void importFileRequestEvent();
    void exportToFileRequestEvent();
    void exitApplicationEvent();
public slots:
    void deleteButtonClicked();
    void insertButtonClicked();
    void modifyButtonClicked();
    void employeeListElementDoubleClicked(EmployeeListElement* e);
    void importFile();
    void exportToFile();
    void exitApplication();
    void changeSelectedElementComboBox(const QString& selected);
};

#endif // GESTIONALE_H
