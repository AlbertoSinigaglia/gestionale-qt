#include "DatiInterfacciaUtenteElement.h"

QString DatiInterfacciaUtenteElement::nome_campi[4] ={"Crea query predefinite?", "Segue stile minimaista?", "# medio di path a sezioni","# clicks path più lungo"};

DatiInterfacciaUtenteElement::DatiInterfacciaUtenteElement(const DatiInterfacceUtente& dati_, bool editable, QWidget *parent)
    : AbstSectionElement(QString("Dati Interfacce Utente"),parent ){
        addCampi(dati_,editable);
}

AbstDataSection* DatiInterfacciaUtenteElement::getData() const{
    return  new DatiInterfacceUtente(
                query_predefinite_widget->getValue()=="SI",
                stile_minimalista_widget->getValue()=="SI",
                num_medio_percorsi_widget->getValue().toUInt(),
                lunghezza_massima_percorso_widget->getValue().toUInt()
    );
}

void DatiInterfacciaUtenteElement::addCampi(const DatiInterfacceUtente& dati, bool editable){
    query_predefinite_widget = new FlagAttribute(nome_campi[0],dati.quary_predefinite,editable,this);
    layout->addWidget(query_predefinite_widget);
    query_predefinite_widget->insertInfo("Crea delle quary predefinite per automatizzare richieste frequenti?");
    connect(query_predefinite_widget,SIGNAL(isModify()), this, SIGNAL(setModifyed()));

    stile_minimalista_widget = new FlagAttribute(nome_campi[1],dati.stile_minimalista,editable,this);
    layout->addWidget(stile_minimalista_widget);
    connect(stile_minimalista_widget,SIGNAL(isModify()), this, SIGNAL(setModifyed()));

    num_medio_percorsi_widget = new LineEditAttribute(nome_campi[2],LineEditAttribute::TipoInserimento::INTEGER,QString::number(dati.num_medio_percorsi_sezione),editable,this);
    num_medio_percorsi_widget->setValMin(1); num_medio_percorsi_widget->setValMax(10);
    num_medio_percorsi_widget->insertInfo("Mediamente quanti prescorsi diversi possono portare ad una stessa sezione del sito?");
    layout->addWidget(num_medio_percorsi_widget);
    connect(num_medio_percorsi_widget,SIGNAL(isModify()), this, SIGNAL(setModifyed()));

    lunghezza_massima_percorso_widget = new LineEditAttribute(nome_campi[3],LineEditAttribute::TipoInserimento::INTEGER,QString::number(dati.lunghezza_max_percorso),editable,this);
    lunghezza_massima_percorso_widget->setValMin(1);lunghezza_massima_percorso_widget->setValMax(10);
    lunghezza_massima_percorso_widget->insertInfo("Quanti cliks semparano le due sezioni del sito più distanti tra loro?");
    layout->addWidget(lunghezza_massima_percorso_widget);
    connect(lunghezza_massima_percorso_widget,SIGNAL(isModify()), this, SIGNAL(setModifyed()));
}
