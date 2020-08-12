#include "employeesmanagement.h"

EmployeesManagement::EmployeesManagement():
    employees(std::make_shared<DynamicArray<Employee*>>()),
    source(){}
bool EmployeesManagement::import(const QString& path){
    try {
        *employees = CSVReader::parse(path);
        source = path;
        return true;
    } catch (std::invalid_argument& e) {
        qDebug() << "Attenzione eccezione: " << e.what();
        return false;
    } catch (illformed_file_exception& e) {
        qDebug() << "Attenzione eccezione: "<< e.what();
        return false;
    }
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
