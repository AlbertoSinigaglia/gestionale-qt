#include "DatiRiparazioneSistemiElement.h"

DatiRiparazioneSistemiElement::DatiRiparazioneSistemiElement(const DatiRiparazioneSistemi& dati_, bool editable, QWidget *parent)
    : AbstSectionElement(QString("Dati Riparazione Sistemi"),parent ){

    addCampi(dati_,editable);
}

AbstDataSection* DatiRiparazioneSistemiElement::getData() const{

        return  new DatiDatabase(
                                    ore_stallo_mensili_widget->getValue().toUInt(),
                                    ore_straordinari_widget->getValue().toUInt(),
                                    perc_riparazioni_sussistenti_widget->getValue().toDouble());
    }
void DatiRiparazioneSistemiElement::addCampi(const DatiRiparazioneSistemi& dati, bool editable){

    ore_stallo_mensili_widget = new LineEditAttribute(nome_campi[0],LineEditAttribute::TipoInserimento::INTEGER,QString::number(dati.ore_stallo_mensili),0,0,editable,this);
    layout->addWidget(ore_stallo_mensili_widget);
    connect(ore_stallo_mensili_widget,SIGNAL(isModify()), this, SLOT(setModifyed()));

    ore_straordinari_widget = new LineEditAttribute(nome_campi[1],LineEditAttribute::TipoInserimento::INTEGER,QString::number(dati.ore_straordinari),0,0,editable,this);
    layout->addWidget(ore_straordinari_widget);
    connect(ore_straordinari_widget,SIGNAL(isModify()), this, SLOT(setModifyed()));

    perc_riparazioni_sussistenti_widget = new SlideAttribute(nome_campi[2],dati.perc_riparazioni_sussistenti,0,1,2,editable,this);
    layout->addWidget(perc_riparazioni_sussistenti_widget);
    connect(perc_riparazioni_sussistenti_widget,SIGNAL(isModify()), this, SLOT(setModifyed()));
}
QString DatiRiparazioneSistemiElement::nome_campi[3] ={"Ore stallo mensili", "Ore straordinari", "Percentuale riparazioni sussistenti"};
