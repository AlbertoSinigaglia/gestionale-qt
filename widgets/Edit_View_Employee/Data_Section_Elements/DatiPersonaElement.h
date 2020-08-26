#ifndef DATIPERSONAELEMENT_H
#define DATIPERSONAELEMENT_H

#include"models/support/TipiRaggruppamento.h"
#include"collections/DynamicArray.h"
#include <qwidget.h>
#include <iostream>
#include <QPushButton>
#include <QLabel>
#include "models/support/Data.h"
#include"widgets/Edit_View_Employee/abstsectionelement.h"
#include"widgets/Edit_View_Employee/Attribute_Elements/dateeditattribute.h"
#include"widgets/Edit_View_Employee/Attribute_Elements/lineeditattribute.h"

class DatiPersonaElement : public AbstSectionElement{
public:
    DatiPersonaElement(const DatiPersona& dati_, bool editable=false, QWidget *parent = 0);
    AbstDataSection* getData() const;

private:
    static QString nome_campi[4];
    static QString descrizione_campi[4];

    LineEditAttribute* nome_widget;
    LineEditAttribute* cognome_widget;
    LineEditAttribute* cf_widget;
    DateEditAttribute* dataNascita_widget;

    void addCampi(const DatiPersona& dati, bool editable);
};

#endif // DATIPERSONAELEMENT_H









