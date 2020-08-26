#ifndef DATIRIPRISTINOSICUREZZAELEMENT_H
#define DATIRIPRISTINOSICUREZZAELEMENT_H

#include"models/support/TipiRaggruppamento.h"
#include"collections/DynamicArray.h"
#include <qwidget.h>
#include <iostream>
#include <QPushButton>
#include <QLabel>
#include "models/support/Data.h"
#include"widgets/Edit_View_Employee/abstsectionelement.h"
#include"widgets/Edit_View_Employee/Attribute_Elements/lineeditattribute.h"

class DatiRipristinoSicurezzaElement: public AbstSectionElement{
public:
    DatiRipristinoSicurezzaElement(const DatiRipristinoSicurezza& dati_, bool editable=false, QWidget *parent = 0);
    AbstDataSection* getData() const;

private:
    static QString nome_campi[2];
    static QString descrizione_campi[2];

    //  LISTA DI QWIDGET che mostrano i valori dei campi
    LineEditAttribute* num_problemi_irrsolti_widget;
    LineEditAttribute* num_criticita_risolte_widget;

    void addCampi(const DatiRipristinoSicurezza& dati, bool editable);
};

#endif // DATIRIPRISTINOSICUREZZAELEMENT_H
