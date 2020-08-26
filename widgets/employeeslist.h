#ifndef EMPLOYEESLIST_H
#define EMPLOYEESLIST_H

#include <qwidget.h>
#include <QHBoxLayout>
#include <QPushButton>
#include <QFrame>
#include <QLabel>
#include <QFile>
#include <QStyleOption>
#include <QPainter>
#include <QMessageBox>
#include "widgets/employeelistelement.h"
#include "models/headers/Employee.h"
#include "collections/DynamicArray.h"
#include "widgets/tableheader.h"
#include <algorithm>

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
    void orderBy(EmployeeListElement::FIELDS field){
        std::sort(children.begin(), children.end(), [&](auto &f, auto& s){ return f->lessThan(*s, field);});
        std::vector<Employee*> v;
        std::transform(children.begin(), children.end(), std::back_inserter(v), [](auto&el){ return el->getEmployee();});
        setEmployees(DynamicArray<Employee*>(v.begin(), v.end()));
    }
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
