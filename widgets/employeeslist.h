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
    auto getNewLayout(){
        auto layout = new QVBoxLayout(this);
        layout->setContentsMargins(0,0,0,0);
        layout->setSpacing(0);
        layout->setAlignment(Qt::AlignTop);
        return layout;
    }
public:
    EmployeesList( QWidget *parent = 0): QFrame( parent )
    {
        this->setLayout(getNewLayout());
        this->setObjectName("frame-right");
        this->setContentsMargins(0,0,0,0);
        this->setStyleSheet("background-color:white;");

    }
    void setEmployees(const DynamicArray<Employee*>& empl){
        for(auto c: children)
            delete c;
        children.erase(children.begin(), children.end());
        for (auto e : empl) {
            auto el = new EmployeeListElement(e, this);
            children.push_back(el);
            this->layout()->addWidget(el);
            connect(this,SIGNAL(changeListAttributeVisibilityEvent(int, int)), el, SLOT(changeVisibility(int, int)));
            connect(el, SIGNAL(clicked(EmployeeListElement *)), this,SLOT(childPressedEvent(EmployeeListElement*)));
            connect(el, SIGNAL(doubleClicked(EmployeeListElement *)), this,SLOT(childClickedEvent(EmployeeListElement*)));
        }
    }
    Employee * getCurrent() const{
        return current ? current->getEmployee() : nullptr;
    }
    ~EmployeesList() {}
signals:
    void changeListAttributeVisibilityEvent(int, int);
    void ListElementDoubleClicked(EmployeeListElement*);
public slots:
    void changeListAttributeVisibility(int props, int visibility){
        emit changeListAttributeVisibilityEvent(props, visibility);
    }
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
