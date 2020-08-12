#ifndef EMPLOYEESMANAGEMENT_H
#define EMPLOYEESMANAGEMENT_H
#include "collections/DynamicArray.h"
#include <QString>
#include "models/headers/Employee.h"
#include"CSV/CSVReader.h"
#include <QFileDialog>
#include"CSV/CSVWriter.h"
class EmployeesManagement
{
    std::shared_ptr<DynamicArray<Employee*>> employees;
    QString source;
public:
    EmployeesManagement(const QString& source_);
    void save(const QString& source_);
     std::shared_ptr<DynamicArray<Employee*>> getEmployees() const;
    QString getOriginalSource() const;
};

#endif // EMPLOYEESMANAGEMENT_H
