#ifndef DATIINTERFACCIAUTENTEELEMENT_H
#define DATIINTERFACCIAUTENTEELEMENT_H

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

class DatiInterfacciaUtenteElement: public AbstSectionElement
{
public:
    DatiInterfacciaUtenteElement(const DatiInterfacceUtente& dati_, bool editable=false, QWidget *parent = 0);

    AbstDataSection* getData() const;


private:
    static QString nome_campi[4];
    static QString descrizione_campi[4];

    //  LISTA DI QWIDGET che mostrano i valori dei campi
    FlagAttribute* query_predefinite_widget;
    FlagAttribute* stile_minimalista_widget;
    LineEditAttribute* num_medio_percorsi_widget;
    LineEditAttribute* lunghezza_massima_percorso_widget;

    void addCampi(const DatiInterfacceUtente& dati, bool editable);
};

#endif // DATIINTERFACCIAUTENTEELEMENT_H
