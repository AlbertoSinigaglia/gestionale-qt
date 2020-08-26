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

    num_sistemi_gestiti_widget = new LineEditAttribute(nome_campi[0],LineEditAttribute::TipoInserimento::INTEGER,QString::number(dati.n_sistemi_gestiti),editable,this);
    num_sistemi_gestiti_widget->setValMax(20);
    layout->addWidget(num_sistemi_gestiti_widget);
    connect(num_sistemi_gestiti_widget,SIGNAL(isModify()), this, SIGNAL(setModifyed()));

    num_sistemi_malfunzionanti_widget = new LineEditAttribute(nome_campi[1],LineEditAttribute::TipoInserimento::INTEGER,QString::number(dati.n_sistemi_malfunzionanti),editable,this);
    num_sistemi_malfunzionanti_widget->setValMax(10);
    layout->addWidget(num_sistemi_malfunzionanti_widget);
    connect(num_sistemi_malfunzionanti_widget,SIGNAL(isModify()), this, SIGNAL(setModifyed()));

    num_sistemi_gestiti_totale_widget = new LineEditAttribute(nome_campi[2],LineEditAttribute::TipoInserimento::INTEGER,QString::number(dati.n_sistemi_gestiti_totale),editable,this);
    layout->addWidget(num_sistemi_gestiti_totale_widget);
    connect(num_sistemi_gestiti_totale_widget,SIGNAL(isModify()), this, SIGNAL(setModifyed()));

    nuovi_gestiti_widget = new LineEditAttribute(nome_campi[3],LineEditAttribute::TipoInserimento::INTEGER,QString::number(dati.nuovi_gestiti),editable,this);
    nuovi_gestiti_widget->setValMax(5);
    layout->addWidget(nuovi_gestiti_widget);
    connect(nuovi_gestiti_widget,SIGNAL(isModify()), this, SIGNAL(setModifyed()));
}

QString DatiSistemiElement::nome_campi[4] ={"# sistemi gestiti nel mese", "# sistemi malfunzionanti", "# sistemi gestiti dall'assuzione", "# nuovi sistemi gestiti nel mese"};
