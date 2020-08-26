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
#include "widgets/employeelistelement.h"
#include "models/headers/Employee.h"
#include "collections/DynamicArray.h"
#include "widgets/tableheader.h"

class EmployeesList : public QFrame{
    Q_OBJECT
    EmployeeListElement* current = nullptr;
    std::vector<EmployeeListElement*> children;
    QVBoxLayout* getNewLayout();
    TableHeader* header;

public:
    /**
     * source: https://doc.qt.io/archives/qt-5.6/qobject.html#no-copy-constructor-or-assignment-operator
     */
    EmployeesList(const EmployeesList& e) = delete;
    EmployeesList& operator= (const EmployeesList& e) = delete;
    EmployeesList( QWidget *parent = 0);

    template<class T> void filter();
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

template<class T> void EmployeesList::filter(){
    if(current && !dynamic_cast<T*>(current->getEmployee())) {
        current->updateStatus(false);
        current = nullptr;
    }
    for(auto &e:children){
        if(dynamic_cast<T*>(e->getEmployee()))
            e->show();
        else
            e->hide();
    }
}

#endif // EMPLOYEELIST_H
