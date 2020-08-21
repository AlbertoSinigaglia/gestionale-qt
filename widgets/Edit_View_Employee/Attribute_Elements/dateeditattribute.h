#ifndef DATEEDITATTRIBUTE_H
#define DATEEDITATTRIBUTE_H

#include <QWidget>
#include"models/support/Data.h"
#include<QCalendarWidget>
#include<QDate>

#include"widgets/Edit_View_Employee/abstattribute.h"

class DateEditAttribute : public AbstAttribute
{
    Q_OBJECT
public:
    explicit DateEditAttribute(QString nome, const Data& valore_, bool editable, QWidget *parent = nullptr);

private:
    QCalendarWidget* setter_data;

    void setValue(Data d);

private slots:

    void catchValue();

signals:

    void isModify();

};

#endif // DATEEDITATTRIBUTE_H
