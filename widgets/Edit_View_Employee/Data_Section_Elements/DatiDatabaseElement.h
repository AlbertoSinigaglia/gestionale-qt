#ifndef DATIDATABASEELEMENT_H
#define DATIDATABASEELEMENT_H

#include"TipiRaggruppamento.h"
#include"collections/DynamicArray.h"
#include <qwidget.h>
#include <iostream>
#include <QPushButton>
#include <QLabel>
#include "models/support/Data.h"
#include"widgets/Edit_View_Employee/abstsectionelement.h"
#include"widgets/Edit_View_Employee/Attribute_Elements/slideattribute.h"
#include"widgets/Edit_View_Employee/Attribute_Elements/dateeditattribute.h"
#include"widgets/Edit_View_Employee/Attribute_Elements/lineeditattribute.h"

class DatiDatabaseElement: public AbstSectionElement{
public:
    DatiDatabaseElement(const DatiDatabase& dati_, bool editable=false, QWidget *parent = 0);
    AbstDataSection* getData() const;

private:
    static QString nome_campi[3];
    static QString descrizione_campi[3];

    //  LISTA DI QWIDGET che mostrano i valori dei campi
    LineEditAttribute* num_attributi_ridondanti_per_entita_widget;
    LineEditAttribute* speed_up_indicizzazioni_widget;
    SlideAttribute*  perc_entita_forma_normale_widget;

    void addCampi(const DatiDatabase& dati, bool editable);
};

#endif // DATIDATABASEELEMENT_H


