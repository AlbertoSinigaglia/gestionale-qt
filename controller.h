#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <model.h>
#include <gestionale.h>
#include "models/headers/Employee.h"
class Controller : public QObject
{
    Q_OBJECT
    Gestionale* view;
    std::vector<Employee*> getEmployee() const{

    }
public:
    explicit Controller(QObject *parent = nullptr, Gestionale* view_ = new Gestionale): QObject(parent), view(view_){

    }

signals:

};

#endif // CONTROLLER_H
