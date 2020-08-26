#include "DatiDatabaseElement.h"

QString DatiDatabaseElement::nome_campi[3] ={"# Attributi ridondanti per entitità", "Speed up indicizzazioni", "% delle entità in forma normale"};

DatiDatabaseElement::DatiDatabaseElement(const DatiDatabase& dati_, bool editable, QWidget *parent)
    : AbstSectionElement(QString("Dati Database"),parent ){
        addCampi(dati_,editable);
}

AbstDataSection* DatiDatabaseElement::getData() const{
    return new DatiDatabase(
                num_attributi_ridondanti_per_entita_widget->getValue().toDouble(),
                speed_up_indicizzazioni_widget->getValue().toDouble(),
                perc_entita_forma_normale_widget->getValue().toDouble()
    );
}

void DatiDatabaseElement::addCampi(const DatiDatabase& dati, bool editable){
    num_attributi_ridondanti_per_entita_widget = new LineEditAttribute(nome_campi[0],LineEditAttribute::TipoInserimento::REAL,QString::number(dati.num_attributi_ridondanti_per_entita),editable,this);
    num_attributi_ridondanti_per_entita_widget->insertInfo("mediamente quanti attributi di un entità del DB sono ridondanti?");
    layout->addWidget(num_attributi_ridondanti_per_entita_widget);
    connect(num_attributi_ridondanti_per_entita_widget,SIGNAL(isModify()), this, SIGNAL(setModifyed()));

    speed_up_indicizzazioni_widget = new LineEditAttribute(nome_campi[1],LineEditAttribute::TipoInserimento::REAL,QString::number(dati.speed_up_indicizzazioni),editable,this);
    speed_up_indicizzazioni_widget->insertInfo("che speed up è stato portato dalle indicizzazioni nel DB?");
    layout->addWidget(speed_up_indicizzazioni_widget);
    connect(speed_up_indicizzazioni_widget,SIGNAL(isModify()), this, SIGNAL(setModifyed()));

    perc_entita_forma_normale_widget = new SlideAttribute(nome_campi[2],dati.perc_entita_forma_normale,0,1,2,editable,this);
    layout->addWidget(perc_entita_forma_normale_widget);
    connect(perc_entita_forma_normale_widget,SIGNAL(isModify()), this, SIGNAL(setModifyed()));
}
