#ifndef DATILATOCLIENTELEMENT_H
#define DATILATOCLIENTELEMENT_H
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
#include"widgets/Edit_View_Employee/Attribute_Elements/comboattribute.h"

class DatiLatoClientElement: public AbstSectionElement
{
public:
    DatiLatoClientElement(const DatiLatoClient& dati_, bool editable=false, QWidget *parent = 0);

    AbstDataSection* getData() const;



private:


    //  LISTA DI QWIDGET che mostrano i valori dei campi

    FlagAttribute* orientato_professionalita_widget;
    ComboAttribute* libreria_widget;
    SlideAttribute* perc_codice_perfezionato_widget;


    static QString nome_campi[3];
    static QString descrizione_campi[3];

    static DynamicArray<QString> opzioni_libreria;


    void addCampi(const DatiLatoClient& dati, bool editable);
    // Il metodo (X il COSTRUTTORE) + stabilisce le connessioni
};

#endif // DATILATOCLIENTELEMENT_H
