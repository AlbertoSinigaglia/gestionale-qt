#ifndef DATILAVORATOREELEMENT_H
#define DATILAVORATOREELEMENT_H

#include"models/support/TipiRaggruppamento.h"
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


    //  LISTA DI QWIDGET che mostrano i valori dei campi
    QLabel* data_assunzione_label;
    QLabel* fine_contratto_label;
    QLabel* ore_lavoro_sett_label;
    QLabel* quota_aggiuntiva_label;


    const std::string nome_campi[4] = {"data di assunzione", "data di fine contratto", "ore di lavoro settimanali", "quota aggiuntiva"};
    const std::string descrizione_campi[4];


    void addCampi(const DatiLavoratore& dati, bool editable);
    // Il metodo (X il COSTRUTTORE) + stabilisce le connessioni

};



#endif // DATILAVORATOREELEMENT_H
