#include "DatiFullstackElement.h"

DatiFullstackElement::DatiFullstackElement(const DatiFullStack& dati_, bool editable, QWidget *parent)
    : AbstSectionElement(QString("Dati Fullstack"),parent ){
addCampi(dati_,editable);

}

AbstDataSection* DatiFullstackElement::getData() const{

        return  new DatiFullStack(
                                    perc_lavoro_back_widget->getValue().toDouble(),
                                    separa_interfacce_widget->getValue().toInt());
    }
void DatiFullstackElement::addCampi(const DatiFullStack& dati, bool editable){

    perc_lavoro_back_widget = new SlideAttribute(nome_campi[0],dati.perc_lavoro_back,0,1,2,editable,this);
    layout->addWidget(perc_lavoro_back_widget);
    connect(perc_lavoro_back_widget,SIGNAL(isModify()), this, SLOT(setModifyed()));

    separa_interfacce_widget = new FlagAttribute(nome_campi[1],dati.separa_interfacce,editable,this);
    layout->addWidget(separa_interfacce_widget);
    connect(separa_interfacce_widget,SIGNAL(isModify()), this, SLOT(setModifyed()));


}
QString DatiFullstackElement::nome_campi[2] ={"Percentuale lavoro back", "Separazione interfacce"};
