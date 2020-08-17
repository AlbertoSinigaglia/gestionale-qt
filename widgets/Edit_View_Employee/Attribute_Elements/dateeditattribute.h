#ifndef DATEEDITATTRIBUTE_H
#define DATEEDITATTRIBUTE_H

#include <QWidget>
#include"models/support/Data.h"
#include<QDateEdit>

#include"widgets/Edit_View_Employee/abstattribute.h"

class DateEditAttribute : public AbstAttribute
{
    Q_OBJECT
public:
    explicit DateEditAttribute(QString nome, Data valore_, bool editable, QWidget *parent = nullptr);

private:
    QDateEdit* setter_data;

signals:

    void isModify();

};

#endif // DATEEDITATTRIBUTE_H
