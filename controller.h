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
#include <QShortcut>

#include"editviewemployee.h"

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
    void ExitEditView();

private:
    void OpenEditView(Employee* considerato, bool editable =false);

signals:
    void exitEvent();
};

#endif // CONTROLLER_H
