#include "DatiPersonaElement.h"

QString DatiPersonaElement::nome_campi[4] ={"Nome", "Cognome", "Codice Fiscale", "Data di nascita"};

DatiPersonaElement::DatiPersonaElement(const DatiPersona& dati_, bool editable, QWidget *parent)
    : AbstSectionElement(QString("Dati Persona"),parent ){
        addCampi(dati_, editable);
}

AbstDataSection* DatiPersonaElement::getData() const{
    return  new DatiPersona(
                nome_widget->getValue().toStdString(),
                cognome_widget->getValue().toStdString(),
                cf_widget->getValue().toStdString(),
                Data(dataNascita_widget->getValue().toStdString())
    );
}

void DatiPersonaElement::addCampi(const DatiPersona& dati, bool editable){
    nome_widget = new LineEditAttribute(nome_campi[0],LineEditAttribute::TipoInserimento::STRING,QString::fromStdString(dati.nome),editable,this);
    layout->addWidget(nome_widget);
    connect(nome_widget,SIGNAL(isModify()), this, SIGNAL(setModifyed()));

    cognome_widget = new LineEditAttribute(nome_campi[1],LineEditAttribute::TipoInserimento::STRING,QString::fromStdString(dati.cognome),editable,this);
    layout->addWidget(cognome_widget);
    connect(cognome_widget,SIGNAL(isModify()), this, SIGNAL(setModifyed()));

    cf_widget = new LineEditAttribute(nome_campi[2],LineEditAttribute::TipoInserimento::STRING,QString::fromStdString(dati.CF),editable,this);
    layout->addWidget(cf_widget);
    connect(cf_widget,SIGNAL(isModify()), this, SIGNAL(setModifyed()));

    dataNascita_widget = new DateEditAttribute(nome_campi[3],dati.nascita,editable,this);
    layout->addWidget(dataNascita_widget);
    connect(dataNascita_widget,SIGNAL(isModify()), this, SIGNAL(setModifyed()));
}
