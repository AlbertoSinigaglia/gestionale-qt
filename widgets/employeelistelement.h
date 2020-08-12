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
public:
    enum{
        Name = 1<<0,
        Surname = 1<<1,
        CF = 1<<2,
        DateOfBirth = 1<<3,
        DateOfEmployment = 1<<4,
        DateEndOfContract = 1<<5,
        Salary = 1<<6,
        WeeklyHours = 1<<7

    };
    EmployeeListElement(Employee *e, QWidget *parent = 0);
    ~EmployeeListElement();
    // from https://doc.qt.io/archives/qt-5.6/qobject.html#no-copy-constructor-or-assignment-operator
    EmployeeListElement(const EmployeeListElement& e) = delete;
    EmployeeListElement& operator= (const EmployeeListElement& e) = delete;

    void updateStatus(bool new_status);
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
