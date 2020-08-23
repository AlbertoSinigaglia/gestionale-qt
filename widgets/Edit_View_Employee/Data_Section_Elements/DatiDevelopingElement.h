#ifndef DATIDEVELOPINGELEMENT_H
#define DATIDEVELOPINGELEMENT_H

#include"models/support/TipiRaggruppamento.h"
#include"collections/DynamicArray.h"
#include <qwidget.h>
#include <iostream>
#include "models/support/Data.h"

#include"widgets/Edit_View_Employee/abstsectionelement.h"

#include"widgets/Edit_View_Employee/Attribute_Elements/slideattribute.h"
#include"widgets/Edit_View_Employee/Attribute_Elements/lineeditattribute.h"
#include"widgets/Edit_View_Employee/Attribute_Elements/comboattribute.h"

class DatiDevelopingElement: public AbstSectionElement
{
public:
    DatiDevelopingElement(const DatiDeveloping& dati_, bool editable=false, QWidget *parent = 0);

    AbstDataSection* getData() const;

private:


    //  LISTA DI QWIDGET che mostrano i valori dei campi
    ComboAttribute* linguaggio_widget;
    LineEditAttribute* n_righe_totali_widget;
    LineEditAttribute* n_righe_mese_widget;
    LineEditAttribute* n_progetti_conclusi_mese_widget;
    SlideAttribute*  perc_ore_programmazione_widget;

    static QString nome_campi[5];

    static DynamicArray<QString> opzioni_linguaggio;


    void addCampi(const DatiDeveloping& dati, bool editable);
    // Il metodo (X il COSTRUTTORE) + stabilisce le connessioni
};

#endif // DATIDEVELOPINGELEMENT_H
