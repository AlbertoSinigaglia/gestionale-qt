#ifndef EMPLOYEELISTELEMENT_H
#define EMPLOYEELISTELEMENT_H


#include <qwidget.h>
#include <QHBoxLayout>
#include <QPushButton>
#include <QFrame>
#include <QLabel>
#include <QFile>
#include <QStyleOption>
#include <QPainter>
#include "models/headers/Employee.h"
#include <QDebug>
#include <QPaintEvent>
#include <QMouseEvent>
class EmployeeListElement : public QWidget{
    Q_OBJECT
    Employee* e_;
    QLabel* name;
    QLabel* surname;
    QLabel* date_of_birth;
    QLabel* cf;

    QLabel* date_of_empl;
    QLabel* date_end_of_contract;
    QLabel* salary;
    QLabel* weekly_hours;
    QLabel* produttivo;

    QLabel* bonus_stipendio;
    QLabel* grado_esperienza;
    QLabel* numero_righe_totali;
    QLabel* linguaggio;
    QLabel* percentuale_ripristino;
    QLabel* numero_criticita_risolte;
    QLabel* ore_straordinari;
public:
    enum{
        Name                    = 1<<0,
        Surname                 = 1<<1,
        CF                      = 1<<2,
        DateOfBirth             = 1<<3,
        DateOfEmployment        = 1<<4,
        DateEndOfContract       = 1<<5,
        Salary                  = 1<<6,
        WeeklyHours             = 1<<7,
        Produttivo              = 1<<8,
        BonusStipendio          = 1<<9,
        GradoEsperienza         = 1<<10,

        NumeroRigheTotali       = 1<<11,    // software
        Linguaggio              = 1<<12,    // software
        PercentualeRipristino   = 1<<13,    // manutentore
        NumeroCriticitaRisolte  = 1<<14,    // security
        OreStraordinari         = 1<<15     // tecnico
    };
    EmployeeListElement(Employee *e, QWidget *parent = 0);
    ~EmployeeListElement();
    // da: https://doc.qt.io/archives/qt-5.6/qobject.html#no-copy-constructor-or-assignment-operator
    EmployeeListElement(const EmployeeListElement& e) = delete;
    EmployeeListElement& operator= (const EmployeeListElement& e) = delete;

    /**
     * @brief imposta lo stato di questo elemento (se selezionato o no)
     * @param lo stato che deve assumere questo elemento
     */
    void updateStatus(bool new_status);
    /**
     * @brief getter per il dipendente che questo elemento gestisce
     * @return l'employee gestito
     */
    Employee* getEmployee() const;


signals:
    void clicked(EmployeeListElement*);
    void doubleClicked(EmployeeListElement *);
public slots:
    void changeVisibility(int prop, int visibility);
private:
    void updateVisibility(QLabel* EmployeeListElement::* elem, int visibility);
    void setStyle();
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent *e) override;
    void mouseDoubleClickEvent( QMouseEvent * e ) override;
};

#endif // EMPLOYEELISTELEMENT_H
