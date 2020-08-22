#ifndef DATIRIPARAZIONESISTEMIELEMENT_H
#define DATIRIPARAZIONESISTEMIELEMENT_H


#include"models/support/TipiRaggruppamento.h"
#include"collections/DynamicArray.h"
#include <qwidget.h>
#include <iostream>
#include <QPushButton>
#include <QLabel>
#include "models/support/Data.h"

#include"widgets/Edit_View_Employee/abstsectionelement.h"

#include"widgets/Edit_View_Employee/Attribute_Elements/slideattribute.h"
#include"widgets/Edit_View_Employee/Attribute_Elements/lineeditattribute.h"


class DatiRiparazioneSistemiElement: public AbstSectionElement{

public:
    DatiRiparazioneSistemiElement(const DatiRiparazioneSistemi& dati_, bool editable=false, QWidget *parent = 0);

    AbstDataSection* getData() const;


private:


    //  LISTA DI QWIDGET che mostrano i valori dei campi

    LineEditAttribute* ore_stallo_mensili_widget;
    LineEditAttribute* ore_straordinari_widget;
    SlideAttribute* perc_riparazioni_sussistenti_widget;


    static QString nome_campi[3];
    static QString descrizione_campi[3];


    void addCampi(const DatiRiparazioneSistemi& dati, bool editable);
    // Il metodo (X il COSTRUTTORE) + stabilisce le connessioni

};

#endif // DATIRIPARAZIONESISTEMIELEMENT_H
