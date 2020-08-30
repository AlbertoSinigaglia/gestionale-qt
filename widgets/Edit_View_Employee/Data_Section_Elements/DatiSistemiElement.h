#ifndef DATISISTEMIELEMENT_H
#define DATISISTEMIELEMENT_H

#include"TipiRaggruppamento.h"
#include"collections/DynamicArray.h"
#include <qwidget.h>
#include <iostream>
#include <QPushButton>
#include <QLabel>
#include "models/support/Data.h"
#include"widgets/Edit_View_Employee/abstsectionelement.h"
#include"widgets/Edit_View_Employee/Attribute_Elements/lineeditattribute.h"

class DatiSistemiElement: public AbstSectionElement{
public:
    DatiSistemiElement(const DatiSistemi& dati_, bool editable=false, QWidget *parent = 0);
    AbstDataSection* getData() const;

private:
    static QString nome_campi[4];
    static QString descrizione_campi[4];

    //  LISTA DI QWIDGET che mostrano i valori dei campi
    LineEditAttribute* num_sistemi_gestiti_widget;
    LineEditAttribute* num_sistemi_malfunzionanti_widget;
    LineEditAttribute* num_sistemi_gestiti_totale_widget;
    LineEditAttribute* nuovi_gestiti_widget;

    void addCampi(const DatiSistemi& dati, bool editable);
};

#endif // DATISISTEMIELEMENT_H
