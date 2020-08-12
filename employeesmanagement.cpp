#include "employeesmanagement.h"

EmployeesManagement::EmployeesManagement(const QString& source_): source(source_){
     employees = std::make_shared<DynamicArray<Employee*>>(CSVReader::parse(source));
}
void EmployeesManagement::save(const QString& source_){
    CSVWriter::write(source_, *employees);
}
 std::shared_ptr<DynamicArray<Employee*>> EmployeesManagement::getEmployees() const{
    return employees;
}
QString EmployeesManagement::getOriginalSource() const{
    return source;
}
