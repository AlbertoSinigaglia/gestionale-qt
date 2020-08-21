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
class DatiRipristinoSicurezzaElement: public AbstSectionElement
{
public:
    DatiRipristinoSicurezzaElement(const DatiRipristinoSicurezza& dati_, bool editable=false, QWidget *parent = 0);

    AbstDataSection* getData() const;


private:


    //  LISTA DI QWIDGET che mostrano i valori dei campi

    LineEditAttribute* num_problemi_irrisolti_widget;
    LineEditAttribute* num_criticita_risolte_widget;

    static QString nome_campi[4];
    static QString descrizione_campi[4];


    void addCampi(const DatiRipristinoSicurezza& dati, bool editable);
    // Il metodo (X il COSTRUTTORE) + stabilisce le connessioni

};

#endif // DATIRIPRISTINOSICUREZZAELEMENT_H
