#ifndef FLAGATTRIBUTE_H
#define FLAGATTRIBUTE_H

#include <QWidget>
#include <QCheckBox>

#include"widgets/Edit_View_Employee/abstattribute.h"

class FlagAttribute : public AbstAttribute{
Q_OBJECT

public:
    explicit FlagAttribute(QString nome, bool valore, bool editable=false,  QWidget *parent = nullptr);

    QCheckBox* setter_bool;


private slots:

    void setValue(int v);


signals:

    void isModify();

};

#endif // FLAGATTRIBUTE_H
