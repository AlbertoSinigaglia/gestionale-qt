#ifndef DATIFULLSTACKELEMENT_H
#define DATIFULLSTACKELEMENT_H
#include"models/support/TipiRaggruppamento.h"
#include"collections/DynamicArray.h"
#include <qwidget.h>
#include <iostream>
#include <QPushButton>
#include <QLabel>
#include "models/support/Data.h"

#include"widgets/Edit_View_Employee/abstsectionelement.h"

#include"widgets/Edit_View_Employee/Attribute_Elements/slideattribute.h"
#include"widgets/Edit_View_Employee/Attribute_Elements/flagattribute.h"
#include"widgets/Edit_View_Employee/Attribute_Elements/lineeditattribute.h"

class DatiFullstackElement: public AbstSectionElement
{
public:
    DatiFullstackElement(const DatiFullStack& dati_, bool editable=false, QWidget *parent = 0);

    AbstDataSection* getData() const;

private:


    //  LISTA DI QWIDGET che mostrano i valori dei campi

    FlagAttribute* separa_interfacce_widget;
    SlideAttribute* perc_lavoro_back_widget;


    static QString nome_campi[2];
    static QString descrizione_campi[2];


    void addCampi(const DatiFullStack& dati, bool editable);
};

#endif // DATIFULLSTACKELEMENT_H
