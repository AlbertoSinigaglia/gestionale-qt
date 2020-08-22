#include "DatiInterfacciaUtenteElement.h"

DatiInterfacciaUtenteElement::DatiInterfacciaUtenteElement(const DatiInterfacceUtente& dati_, bool editable, QWidget *parent)
    : AbstSectionElement(QString("Dati Interfacce Utente"),parent ){

addCampi(dati_,editable);
}
AbstDataSection* DatiInterfacciaUtenteElement::getData() const{

        return  new DatiInterfacceUtente(
                                    query_predefinite_widget->getValue().toInt(),
                                    stile_minimalista_widget->getValue().toInt(),
                                    num_medio_percorsi_widget->getValue().toInt(),
                                    lunghezza_massima_percorso_widget->getValue().toInt());
    }
void DatiInterfacciaUtenteElement::addCampi(const DatiInterfacceUtente& dati, bool editable){

    query_predefinite_widget = new FlagAttribute(nome_campi[0],dati.quary_predefinite,editable,this);
    layout->addWidget(query_predefinite_widget);
    connect(query_predefinite_widget,SIGNAL(isModify()), this, SLOT(setModifyed()));

    stile_minimalista_widget = new FlagAttribute(nome_campi[1],dati.stile_minimalista,editable,this);
    layout->addWidget(query_predefinite_widget);
    connect(query_predefinite_widget,SIGNAL(isModify()), this, SLOT(setModifyed()));

    num_medio_percorsi_widget = new LineEditAttribute(nome_campi[2],LineEditAttribute::TipoInserimento::INTEGER,QString::number(dati.num_medio_percorsi_sezione),1,editable,this);
    layout->addWidget(num_medio_percorsi_widget);
    connect(num_medio_percorsi_widget,SIGNAL(isModify()), this, SLOT(setModifyed()));

    lunghezza_massima_percorso_widget = new LineEditAttribute(nome_campi[3],LineEditAttribute::TipoInserimento::INTEGER,QString::number(dati.lunghezza_max_percorso),1,editable,this);
    layout->addWidget(lunghezza_massima_percorso_widget);
    connect(lunghezza_massima_percorso_widget,SIGNAL(isModify()), this, SLOT(setModifyed()));

   }
QString DatiInterfacciaUtenteElement::nome_campi[4] ={"Query Predefinite", "Stile Minimaista", "Numero medio percorsi","lunghezza massima percorso"};

