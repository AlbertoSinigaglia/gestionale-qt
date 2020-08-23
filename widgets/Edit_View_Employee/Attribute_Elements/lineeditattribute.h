#ifndef LINEEDITATTRIBUTE_H
#define LINEEDITATTRIBUTE_H

#include <QWidget>
#include<QLineEdit>
#include<math.h>
#include"widgets/Edit_View_Employee/abstattribute.h"

/**
 * @brief La classe si occuperà di getire la modifica e la visualizzazione
 * di tutti i campi dati (sia integer che real) che assumono valori non limitati
 * oltre che a campi dati esplicitamente string
 */


class LineEditAttribute : public AbstAttribute
{
    Q_OBJECT
public:
    enum TipoInserimento: short{
        STRING,
        INTEGER,
        REAL
    };

    explicit LineEditAttribute(QString nome, TipoInserimento tipo, QString valore_, bool editable=false,  QWidget *parent = nullptr);

    void setValMin(double min);
    void setValMax(double max);

private:
    QLineEdit* setter_str;
    TipoInserimento tipo;
    double val_min, val_max;

    bool verify(QString s);
    void setError();

    void setValue(QString q);

private slots:

    void catchValue(QString q);


};

#endif // LINEEDITATTRIBUTE_H
