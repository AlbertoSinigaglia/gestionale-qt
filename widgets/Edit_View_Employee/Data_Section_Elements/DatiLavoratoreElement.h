#ifndef DATILAVORATOREELEMENT_H
#define DATILAVORATOREELEMENT_H

#include"TipiRaggruppamento.h"
#include"collections/DynamicArray.h"
#include <qwidget.h>
#include <iostream>
#include <QPushButton>
#include <QLabel>
#include "models/support/Data.h"
#include"widgets/Edit_View_Employee/abstsectionelement.h"

class DatiLavoratoreElement: public AbstSectionElement{
public:
    DatiLavoratoreElement(const DatiLavoratore& dati_, bool editable=false, QWidget *parent = 0);
    AbstDataSection* getData() const;

private:
    static QString nome_campi[4];
    static QString descrizione_campi[4];

    //  LISTA DI QWIDGET che mostrano i valori dei campi
    DateEditAttribute* data_assunzione_widget;
    DateEditAttribute* fine_contratto_widget;
    SlideAttribute* ore_lavoro_sett_widget;
    LineEditAttribute* quota_aggiuntiva_widget;

    void addCampi(const DatiLavoratore& dati, bool editable);
};

#endif //DATILAVORATOREELEMENT_H
