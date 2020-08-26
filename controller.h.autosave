#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QMessageBox>
#include <gestionale.h>
#include<QFileDialog>
#include <algorithm>
#include <QShortcut>
#include <QTimer>
#include "CSV/CSVWriter.h"
#include "models/support/Convenzioni.h"
#include"employeesmanagement.h"
#include "models/headers/Employee.h"
#include"editviewemployee.h"
#include"widgets/typecreation.h"

class Controller : public QObject{
    Q_OBJECT

// -----------------------------------------
//               MAIN CONTROL
// -----------------------------------------

public:
    explicit Controller(QObject *parent = nullptr, Gestionale* view_ = new Gestionale);

private:
    /* Il timer si occupa di gestire il cambiamento del mese, un evento
     * che deve portare alla modifica di determinati campi in ogni
     * impiegato del contenitore del modello
     */
    void InizializeTimer();
    QTimer *timer;
    QDate prev_date;

private slots:
    void updateTime();

public slots:
    void exitApplication();

signals:
    void exitEvent();

// -----------------------------------------
//       RIGUARDO a: VISTA PRINCIPALE
// -----------------------------------------

private:
    std::shared_ptr<Gestionale> view;
    std::shared_ptr<EmployeesManagement> model;
    bool updateModel(bool want_to_export = false);
    QString getFilePath(const QString info) const;

public slots:
    void deleteEmployee(Employee * e);
    void importFile();
    void exportToFile();

// -----------------------------------------
//          RIGUARDO a: EDIT / VIEW
// -----------------------------------------

private:
    EditViewEmployee* edit_view;

    /**
     * @brief l'impiegato considerato è necessario per identificare quale
     * impiegato si sta visualizzando , modificando o creando. Nel caso della
     * creazione è utile per mantenere separato dal contenitore il nuovo impiegato
     * fino alla ultima modifica
     */
    Employee* considered_employee;

    /**
     * @brief si occua di aprire l'EditView con il cambio di contesto
     */
    void OpenEditView(Employee* considerato, EditViewEmployee::Utilizzo stato_utilizzo);

public slots:
    /**
     * @brief si occupa di generare una vista che mostri in sola lettura i dati
     * relativi all'impiegato <e>
     */     // VISUALIZZA
    void ViewEmployeeInfo(Employee* e);

    /**
     * @brief si occupa di generare una vista che mostri in lettura e in scrittura
     * i dati relativi all'impiegato <e>
     */     // MODIFICA
    void EditEmployeeInfo(Employee * e);

    /**
     * @brief genera un dialog di tipo <TypeCreation> con la quale scegliere
     * il tipo di impiegato da inserire
     */
    void chooseNewEmployee();

    /**
     * @brief si occupa di creare un impiegato temporaneo di tipo espresso da <q>
     * e grazie a questo creare una vista che mostri in lettura e scrittura i suoi
     * dati
     */      // CREAZIONE
    void createEmployeeInfo(QString q);

    /**
     * @brief Si occupa di salvare i dati aggiornati contenuti nella sezione <data_>
     * negli appropriati campi dell'impiegato considerato
     */
    void SaveChanges(AbstDataSection* data_);

    /**
     * @brief gestisce l'uscita dell'editView e il commit delle info modificate
     * (DA NOTARE che il commit derivante da una vista di creazione corrisponde
     * anche all'aggiunta del temporaneo <considered_employee> aggiornato al modello)
     */
    void SaveEditView();

    /** @brief gestisce l'uscita diretta della EditView senza salvataggio, comprese
     * le dovute procedure di abortimento della procedura scelta
     */
    void ExitEditView();
};

#endif // CONTROLLER_H
