#include "DatiDatabaseElement.h"

DatiDatabaseElement::DatiDatabaseElement(const DatiDatabase& dati_, bool editable, QWidget *parent)
    : AbstSectionElement(QString("Dati Database"),parent ){

addCampi(dati_,editable);
}
AbstDataSection* DatiDatabaseElement::getData() const{

        return  new DatiDatabase(
                                    num_attributi_ridondanti_per_entita_widget->getValue().toDouble(),
                                    speed_up_indicizzazioni_widget->getValue().toDouble(),
                                    perc_entita_forma_normale_widget->getValue().toDouble());
    }
void DatiDatabaseElement::addCampi(const DatiDatabase& dati, bool editable){

    num_attributi_ridondanti_per_entita_widget = new LineEditAttribute(nome_campi[0],LineEditAttribute::TipoInserimento::INTEGER,QString::number(dati.num_attributi_ridondanti_per_entita),0,editable,this);
    layout->addWidget(num_attributi_ridondanti_per_entita_widget);
    connect(num_attributi_ridondanti_per_entita_widget,SIGNAL(isModify()), this, SLOT(setModifyed()));

    speed_up_indicizzazioni_widget = new LineEditAttribute(nome_campi[1],LineEditAttribute::TipoInserimento::INTEGER,QString::number(dati.speed_up_indicizzazioni),0,editable,this);
    layout->addWidget(speed_up_indicizzazioni_widget);
    connect(speed_up_indicizzazioni_widget,SIGNAL(isModify()), this, SLOT(setModifyed()));

    perc_entita_forma_normale_widget = new SlideAttribute(nome_campi[2],dati.perc_entita_forma_normale,0,1,2,editable,this);
    layout->addWidget(perc_entita_forma_normale_widget);
    connect(perc_entita_forma_normale_widget,SIGNAL(isModify()), this, SLOT(setModifyed()));
}
QString DatiDatabaseElement::nome_campi[3] ={"Attributi ridondanti", "Speed up", "Percentuale"};
