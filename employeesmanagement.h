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
    /**
     * @brief Costruttore della classe
     * @param source_ : path da cui ricostruire i dipendenti
     */
    EmployeesManagement();
    bool import(const QString& path);
    /**
     * @brief salva sul path fornito una serializzazione della collezione dei dipendenti corrente
     * @param source_
     */
    void save(const QString& source_);
    /**
      * @brief getter per la collezione corrente di dipedenti
      * @return collezione corrente dei dipendenti
      */
     std::shared_ptr<DynamicArray<Employee*>> getEmployees() const;
     /**
     * @brief getter per il path del file che è stato usato alla creazione dell'oggetto
     * @return path file originale
     */
    QString getOriginalSource() const;
};

#endif // EMPLOYEESMANAGEMENT_H
