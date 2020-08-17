#ifndef LINEEDITATTRIBUTE_H
#define LINEEDITATTRIBUTE_H

#include <QWidget>
#include<QLineEdit>

#include"widgets/Edit_View_Employee/abstattribute.h"

/**
 * @brief La classe si occuperà di getire la modifica e la visualizzazione
 * di tutti i campi dati (sia integer che real) che assumono valori non limitati
 */


class LineEditAttribute : public AbstAttribute
{
    Q_OBJECT
public:
    explicit LineEditAttribute(QString nome, double valore_, bool editable=false,  QWidget *parent = nullptr);

private:
    QLineEdit* setter_num;

signals:

    void isModify();

};

#endif // LINEEDITATTRIBUTE_H
