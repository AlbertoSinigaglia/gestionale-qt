#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QMessageBox>
#include <gestionale.h>
#include<QFileDialog>
#include<QDebug>
#include <algorithm>
#include <QShortcut>

#include "CSV/CSVWriter.h"
#include "models/support/Convenzioni.h"
#include"employeesmanagement.h"
#include "models/headers/Employee.h"
#include"editviewemployee.h"
#include"widgets/typecreation.h"

class Controller : public QObject
{
    Q_OBJECT
    std::shared_ptr<Gestionale> view;
    std::shared_ptr<EmployeesManagement> model;

    EditViewEmployee* edit_view;
    Employee* considered_employee;

    bool updateModel(bool want_to_export = false);
    QString getFilePath(const QString info) const;
public:
    explicit Controller(QObject *parent = nullptr, Gestionale* view_ = new Gestionale);

public slots:
    void deleteEmployee(Employee * e);
    void insertNewEmployee();
    void openEmployeeInfo(Employee* e);
    void modifyButtonClicked(Employee * e);
    void importFile();
    void exportToFile();
    void exitApplication();

    void SaveChanges(AbstDataSection* data_);
    void SaveEditView();
    void ExitEditView();
    void setTypeInsert(QString q);

private:
    void OpenEditView(Employee* considerato, EditViewEmployee::Utilizzo stato_utilizzo);

signals:
    void exitEvent();
};

#endif // CONTROLLER_H
