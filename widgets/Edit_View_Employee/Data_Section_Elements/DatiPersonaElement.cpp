#ifndef DATIPERSONAELEMENT_CPP
#define DATIPERSONAELEMENT_CPP
#include "DatiPersonaElement.h"

DatiPersonaElement::DatiPersonaElement(const DatiPersona& dati_, bool editable, QWidget *parent)
    : AbstSectionElement(QString("Dati Persona"),parent ){


    //addCampi(dati_, editable);
}

AbstDataSection* DatiPersonaElement::getData() const{

        return  new DatiPersona(    nome_widget->getValue().toStdString(),
                                    cognome_widget->getValue().toStdString(),
                                    cf_widget->getValue().toStdString(),
                                    Data(dataNascita_widget->getValue().toStdString()));
    }
/*void DatiPersonaElement::addCampi(const DatiPersona& dati, bool editable){

    nome_widget = new LineEditAttribute(nome_campi[0],dati.nome,editable,this);
    layout->addWidget(nome_widget);
    connect(nome_widget,SIGNAL(isModify()), this, SLOT(setModifyed()));

    cognome_widget = new LineEditAttribute(nome_campi[1],dati.cognome,editable,this);
    layout->addWidget(cognome_widget);
    connect(cognome_widget,SIGNAL(isModify()), this, SLOT(setModifyed()));

    cf_widget = new LineEditAttribute(nome_campi[2],dati.CF,editable,this);
    layout->addWidget(cf_widget);
    connect(cf_widget,SIGNAL(isModify()), this, SLOT(setModifyed()));

    dataNascita_widget = new DateEditAttribute(nome_campi[3],dati.nascita,editable,this);
    layout->addWidget(dataNascita_widget);
    connect(dataNascita_widget,SIGNAL(isModify()), this, SLOT(setModifyed()));
}*/

#endif //DATIPERSONAELEMENT.CPP
