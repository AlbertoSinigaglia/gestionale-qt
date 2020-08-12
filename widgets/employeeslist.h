#ifndef EMPLOYEESLIST_H
#define EMPLOYEESLIST_H


#include <qwidget.h>
#include <QHBoxLayout>
#include <QPushButton>
#include <QFrame>
#include <QLabel>
#include <QFile>
#include <QDebug>
#include <QStyleOption>
#include <QPainter>
#include <QMessageBox>
#include <QDebug>
#include "widgets/employeelistelement.h"
#include "models/headers/Employee.h"
#include "collections/DynamicArray.h"

class EmployeesList : public QFrame
{
    Q_OBJECT
    EmployeeListElement* current = nullptr;
    std::vector<EmployeeListElement*> children;
    QVBoxLayout* getNewLayout();
public:
    EmployeesList( QWidget *parent = 0);
    ~EmployeesList() {}
    // from https://doc.qt.io/archives/qt-5.6/qobject.html#no-copy-constructor-or-assignment-operator
    EmployeesList(const EmployeesList& e) = delete;
    EmployeesList& operator= (const EmployeesList& e) = delete;

    void setEmployees(const DynamicArray<Employee*>& empl);
    Employee * getCurrent() const;
signals:
    void changeListAttributeVisibilityEvent(int, int);
    void ListElementDoubleClicked(EmployeeListElement*);
public slots:
    void changeListAttributeVisibility(int props, int visibility);
    void childPressedEvent(EmployeeListElement* e);
    void childClickedEvent(EmployeeListElement* e);

};

#endif // EMPLOYEELIST_H
