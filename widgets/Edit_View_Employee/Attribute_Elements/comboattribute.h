#ifndef COMBOATTRIBUTE_H
#define COMBOATTRIBUTE_H

#include"widgets/Edit_View_Employee/abstattribute.h"
#include"collections/DynamicArray.h"
#include <QComboBox>

class ComboAttribute: public AbstAttribute{
    Q_OBJECT

public:
    explicit ComboAttribute(QString nome,const DynamicArray<QString>& opzioni, int index_valore_inizio, bool editable=false,  QWidget *parent = nullptr);

private:
    DynamicArray<QString> opzioni;
    QComboBox* setter_combo;

private slots:
    void setValue(int i);

};

#endif // COMBOATTRIBUTE_H
