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
    EmployeesManagement(const QString& source_): source(source_){
         employees = std::make_shared<DynamicArray<Employee*>>(CSVReader::parse(source));
    }
    void save(const QString& source_){
        CSVWriter::write(source_, *employees);
    }
     std::shared_ptr<DynamicArray<Employee*>> getEmployees() const{
        return employees;
    }
    QString getOriginalSource() const{
        return source;
    }
};

#endif // EMPLOYEESMANAGEMENT_H
