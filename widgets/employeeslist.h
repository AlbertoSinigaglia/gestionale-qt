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

class EmployeesList : public QFrame
{
    Q_OBJECT
    EmployeeListElement* current = nullptr;
    std::vector<EmployeeListElement*> children;
public:
    EmployeesList( QWidget *parent = 0): QFrame( parent )
    {
        auto layout = new QVBoxLayout(this);
        layout->setAlignment(Qt::AlignTop);
        this->setObjectName("frame-right");
        this->setContentsMargins(0,0,0,0);
        this->layout()->setContentsMargins(0,0,0,0);
        this->layout()->setSpacing(0);

    }
    void addEmployees(const std::vector<Employee*> empl){
        for (auto e : empl) {
            auto el = new EmployeeListElement(e, this);
            children.push_back(el);
            this->layout()->addWidget(el);
            connect(el, SIGNAL(clicked(EmployeeListElement *)), this,SLOT(childPressedEvent(EmployeeListElement*)));
            connect(el, SIGNAL(doubleClicked(EmployeeListElement *)), this,SLOT(childClickedEvent(EmployeeListElement*)));
        }
    }
    Employee * getCurrent() const{
        return current ? current->getEmployee() : nullptr;
    }
    ~EmployeesList() {}
signals:
    void ListElementDoubleClicked(EmployeeListElement*);
public slots:
    void childPressedEvent(EmployeeListElement* e){
        if(e != current){
            current = e;
            for(auto& e : children)
                if(current != e)
                    e->updateStatus(false);
            current->updateStatus(true);
        } else {
            current->updateStatus(false);
            current = nullptr;
        }
        // do something
    }
    void childClickedEvent(EmployeeListElement* e){
        // do something
        emit ListElementDoubleClicked(e);
    }
};

#endif // EMPLOYEELIST_H
