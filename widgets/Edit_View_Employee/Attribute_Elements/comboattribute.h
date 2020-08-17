#ifndef COMBOATTRIBUTE_H
#define COMBOATTRIBUTE_H

#include"widgets/Edit_View_Employee/abstattribute.h"
#include"collections/DynamicArray.h"

class ComboAttribute: public AbstAttribute
{
    Q_OBJECT

    public:
        explicit ComboAttribute(QString nome, DynamicArray<QString> opzioni, int index_valore_inizio, bool editable=false,  QWidget *parent = nullptr);


    private:


    signals:

        void isModify();
};

#endif // COMBOATTRIBUTE_H
