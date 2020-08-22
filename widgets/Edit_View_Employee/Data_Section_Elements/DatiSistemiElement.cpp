#include "DatiSistemiElement.h"

DatiSistemiElement::DatiSistemiElement(const DatiSistemi& dati_, bool editable, QWidget *parent)
    : AbstSectionElement(QString("Dati Sistemi"),parent ){

    addCampi(dati_,editable);
}
AbstDataSection* DatiSistemiElement::getData() const{

        return  new DatiSistemi(
                                    num_sistemi_gestiti_widget->getValue().toUInt(),
                                    num_sistemi_malfunzionanti_widget->getValue().toUInt(),
                                    num_sistemi_gestiti_totale_widget->getValue().toUInt(),
                                    nuovi_gestiti_widget->getValue().toUInt());
    }
void DatiSistemiElement::addCampi(const DatiSistemi& dati, bool editable){

    num_sistemi_gestiti_widget = new LineEditAttribute(nome_campi[0],LineEditAttribute::TipoInserimento::INTEGER,QString::number(dati.n_sistemi_gestiti),0,editable,this);
    layout->addWidget(num_sistemi_gestiti_widget);
    connect(num_sistemi_gestiti_widget,SIGNAL(isModify()), this, SLOT(setModifyed()));

    num_sistemi_malfunzionanti_widget = new LineEditAttribute(nome_campi[1],LineEditAttribute::TipoInserimento::INTEGER,QString::number(dati.n_sistemi_malfunzionanti),0,editable,this);
    layout->addWidget(num_sistemi_malfunzionanti_widget);
    connect(num_sistemi_malfunzionanti_widget,SIGNAL(isModify()), this, SLOT(setModifyed()));

    num_sistemi_gestiti_totale_widget = new LineEditAttribute(nome_campi[0],LineEditAttribute::TipoInserimento::INTEGER,QString::number(dati.n_sistemi_gestiti_totale),0,editable,this);
    layout->addWidget(num_sistemi_gestiti_totale_widget);
    connect(num_sistemi_gestiti_totale_widget,SIGNAL(isModify()), this, SLOT(setModifyed()));

    nuovi_gestiti_widget = new LineEditAttribute(nome_campi[1],LineEditAttribute::TipoInserimento::INTEGER,QString::number(dati.nuovi_gestiti),0,editable,this);
    layout->addWidget(nuovi_gestiti_widget);
    connect(nuovi_gestiti_widget,SIGNAL(isModify()), this, SLOT(setModifyed()));


}
QString DatiSistemiElement::nome_campi[4] ={"Num sistemi gestiti", "Num sistemi malfunzionanti", "Num sistemi gestiti totale", "Nuovi gestiti"};
