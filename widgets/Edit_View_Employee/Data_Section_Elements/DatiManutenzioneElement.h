#ifndef DATIMANUTENZIONEELEMENT_H
#define DATIMANUTENZIONEELEMENT_H

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
class DatiManutenzioneElement: public AbstSectionElement
{
public:
    DatiManutenzioneElement(const DatiManutenzione& dati_, bool editable=false, QWidget *parent = 0);

    AbstDataSection* getData() const;

private:
    LineEditAttribute* n_riparazioni_mese_widget;
    SlideAttribute* perc_riparazioni_inefficaci_widget;
    SlideAttribute* perc_ripristino_medio_widget;

    static QString nome_campi[4];
    static QString descrizione_campi[4];


    void addCampi(const DatiManutenzione& dati, bool editable);
};

#endif // DATIMANUTENZIONEELEMENT_H
