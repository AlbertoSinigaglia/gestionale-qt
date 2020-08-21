#ifndef DATILATOSERVERELEMENT_H
#define DATILATOSERVERELEMENT_H
#include"models/support/TipiRaggruppamento.h"
#include"collections/DynamicArray.h"
#include <qwidget.h>
#include <iostream>
#include <QPushButton>
#include <QLabel>
#include "models/support/Data.h"

#include"widgets/Edit_View_Employee/abstsectionelement.h"

#include"widgets/Edit_View_Employee/Attribute_Elements/comboattribute.h"
#include"widgets/Edit_View_Employee/Attribute_Elements/flagattribute.h"
#include"widgets/Edit_View_Employee/Attribute_Elements/slideattribute.h"
#include"widgets/Edit_View_Employee/Attribute_Elements/lineeditattribute.h"

class DatiLatoServerElement: public AbstSectionElement
{
public:
    DatiLatoServerElement(const DatiLatoServer& dati_, bool editable=false, QWidget *parent = 0);

    AbstDataSection* getData() const;


private:


    //  LISTA DI QWIDGET che mostrano i valori dei campi

    FlagAttribute* orientato_ortogonalita_widget;
    FlagAttribute* prove_correttezza_widget;
    LineEditAttribute* livello_astrazione_widget;
    SlideAttribute* perc_capo_progetto_widget;


    static QString nome_campi[4];
    static QString descrizione_campi[4];


    void addCampi(const DatiLatoServer& dati, bool editable);
    // Il metodo (X il COSTRUTTORE) + stabilisce le connessioni
};

#endif // DATILATOSERVERELEMENT_H
