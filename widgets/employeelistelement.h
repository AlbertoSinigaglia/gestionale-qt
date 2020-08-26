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
    enum FIELDS{
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

    /**
     * source: https://doc.qt.io/archives/qt-5.6/qobject.html#no-copy-constructor-or-assignment-operator
     */
    EmployeeListElement(const EmployeeListElement& e) = delete;
    EmployeeListElement& operator= (const EmployeeListElement& e) = delete;
    EmployeeListElement(Employee *e, QWidget *parent = 0);

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

    /**
     * @brief è un operator< con un parametro specifico per il confronto
     * @param o : oggetto con cui confrontare prop
     * @param prop : proprietà da confrontare
     * @return true sse this->prop < o->prop, false altrimenti (o se la proprietà specificata non è supportata)
     */
    bool lessThan(const EmployeeListElement& o, EmployeeListElement::FIELDS prop){
        if(prop & EmployeeListElement::Name)                    return name->text()                         < o.name->text();
        if(prop & EmployeeListElement::Surname)                 return surname->text()                      < o.surname->text();
        if(prop & EmployeeListElement::CF)                      return cf->text()                           < o.cf->text();
        if(prop & EmployeeListElement::DateOfBirth)             return date_of_birth->text()                < o.date_of_birth->text();
        if(prop & EmployeeListElement::DateOfEmployment)        return date_of_empl->text()                 < o.date_of_empl->text();
        if(prop & EmployeeListElement::DateEndOfContract)       return date_end_of_contract->text()         < o.date_end_of_contract->text();
        if(prop & EmployeeListElement::Salary)                  return salary->text()                       < o.salary->text();
        if(prop & EmployeeListElement::WeeklyHours)             return weekly_hours->text()                 < o.weekly_hours->text();
        if(prop & EmployeeListElement::Produttivo)              return static_cast<int>(e_->produttivo())   < static_cast<int>(o.e_->produttivo());
        if(prop & EmployeeListElement::BonusStipendio)          return bonus_stipendio->text()              < o.bonus_stipendio->text();
        if(prop & EmployeeListElement::GradoEsperienza)         return grado_esperienza->text()             < o.grado_esperienza->text();
        if(prop & EmployeeListElement::NumeroRigheTotali)       return numero_righe_totali->text()          < o.numero_righe_totali->text();
        if(prop & EmployeeListElement::Linguaggio)              return linguaggio->text()                   < o.linguaggio->text();
        if(prop & EmployeeListElement::PercentualeRipristino)   return percentuale_ripristino->text()       < o.percentuale_ripristino->text();
        if(prop & EmployeeListElement::NumeroRigheTotali)       return numero_righe_totali->text()          < o.numero_righe_totali->text();
        if(prop & EmployeeListElement::OreStraordinari)         return ore_straordinari->text()             < o.ore_straordinari->text();
        return false;
    }
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
