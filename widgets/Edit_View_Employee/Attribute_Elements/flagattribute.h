#ifndef FLAGATTRIBUTE_H
#define FLAGATTRIBUTE_H

#include <QWidget>

#include"widgets/Edit_View_Employee/abstattribute.h"

class FlagAttribute : public AbstAttribute{
Q_OBJECT

public:
    explicit FlagAttribute(QString nome, bool valore, bool editable=false,  QWidget *parent = nullptr);


private:


signals:

    void isModify();

};

#endif // FLAGATTRIBUTE_H
