#include "DatiRiparazioneSistemiElement.h"

QString DatiRiparazioneSistemiElement::nome_campi[3] ={"ore di stallo nel mese", "ore straordinari nel mese", "% delle riparazioni di sussistenza"};

DatiRiparazioneSistemiElement::DatiRiparazioneSistemiElement(const DatiRiparazioneSistemi& dati_, bool editable, QWidget *parent)
    : AbstSectionElement(QString("Dati Riparazione Sistemi"),parent ){
        addCampi(dati_,editable);
}

AbstDataSection* DatiRiparazioneSistemiElement::getData() const{
    return  new DatiRiparazioneSistemi(
                perc_riparazioni_sussistenti_widget->getValue().toDouble(),
                ore_stallo_mensili_widget->getValue().toUInt(),
                ore_straordinari_widget->getValue().toUInt()

    );
}

void DatiRiparazioneSistemiElement::addCampi(const DatiRiparazioneSistemi& dati, bool editable){
    ore_stallo_mensili_widget = new LineEditAttribute(nome_campi[0],LineEditAttribute::TipoInserimento::INTEGER,QString::number(dati.ore_stallo_mensili),editable,this);
    ore_stallo_mensili_widget->setValMax(40);
    ore_stallo_mensili_widget->insertInfo("Gli stalli nel sistema produttivo vengono causati da tutte e sole le riparazioni a sistemi di sussistenza");
    layout->addWidget(ore_stallo_mensili_widget);
    connect(ore_stallo_mensili_widget,SIGNAL(isModify()), this, SIGNAL(setModifyed()));

    ore_straordinari_widget = new LineEditAttribute(nome_campi[1],LineEditAttribute::TipoInserimento::INTEGER,QString::number(dati.ore_straordinari),editable,this);
    ore_straordinari_widget->setValMax(40);
    ore_straordinari_widget->insertInfo("Le ore di straodinari di un Tecnico servono solo a svolgere una riparazione a un sistema di sussistenza");
    layout->addWidget(ore_straordinari_widget);
    connect(ore_straordinari_widget,SIGNAL(isModify()), this, SIGNAL(setModifyed()));

    perc_riparazioni_sussistenti_widget = new SlideAttribute(nome_campi[2],dati.perc_riparazioni_sussistenti,0,1,2,editable,this);
    perc_riparazioni_sussistenti_widget->insertInfo("La percentuale delle riparazioni che coinvolcono sistemi di sussistenza per l'azienda");
    layout->addWidget(perc_riparazioni_sussistenti_widget);
    connect(perc_riparazioni_sussistenti_widget,SIGNAL(isModify()), this, SIGNAL(setModifyed()));
}
