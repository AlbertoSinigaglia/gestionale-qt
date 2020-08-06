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
#include "widgets/employeelistelement.h"
#include "models/headers/Employee.h"

class EmployeesList : public QFrame
{
    Q_OBJECT
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
            this->layout()->addWidget(new EmployeeListElement(e, this));
        }
    }
    ~EmployeesList() {}
};

#endif // EMPLOYEELIST_H
