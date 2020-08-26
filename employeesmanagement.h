#ifndef EMPLOYEESMANAGEMENT_H
#define EMPLOYEESMANAGEMENT_H

#include "collections/DynamicArray.h"
#include <QString>
#include"CSV/CSVReader.h"
#include <QFileDialog>
#include"CSV/CSVWriter.h"
#include"models/headers/GUIDev.h"
#include"models/headers/DBDev.h"
#include"models/headers/FullStack.h"
#include"models/headers/ITSecurityDev.h"
#include"models/headers/Tecnico.h"

class EmployeesManagement{
    // contenitore dei dipendenti
    std::shared_ptr<DynamicArray<Employee*>> employees;
    // instanza del singleton
    static std::shared_ptr<EmployeesManagement> instance;
    // path del primo file importato (che nella vista corrisponde al "apri")
    QString source;

    /**
     * @brief Costruttore della classe
     * @param source_ : path da cui ricostruire i dipendenti
     */
    EmployeesManagement();

public:
    EmployeesManagement(const EmployeesManagement &) = delete;
    EmployeesManagement& operator= (const EmployeesManagement &) = delete;
    ~EmployeesManagement() = default;

    /**
     * @brief getter per singleton
     * @return puntatore all'istanza
     */
    static std::shared_ptr<EmployeesManagement> getInstance();

    /**
     * @brief Aggiunge un impiegato al vettore di impiegati del database
     * @param puntatore all'impiegato da aggiungere
     */
    void addEmployee(Employee* e);

    /**
     * @brief rimuove l'impiegato dal database
     * @param il puntatore all'impiegato da rimuovere
     */
    void deleteEmployee(Employee* e);

    /**
     * @brief importa dipendenti da file
     * @param path path del file da cui importare
     * @return
     *      true: è riuscito a importare i dipendenti
     *      false: altrimenti
     */
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

    /**
     * @brief Viene ustato per aggiornare i campi dati di tutti gli impiegati nel dataBase sulla
     * base del cambio del mese
     */
    void updateMonthAll();

    /**
     * @brief serializza i dati dell'impiegato in un insieme di macro raggruppamenti ordinato
     * @return l'insieme delle tipi raggruppamento
     */
    static DynamicArray<AbstDataSection*> serializeEmployee(Employee* e);
};

#endif // EMPLOYEESMANAGEMENT_H
