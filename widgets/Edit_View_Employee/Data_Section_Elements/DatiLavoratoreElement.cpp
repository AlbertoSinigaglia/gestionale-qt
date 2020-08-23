#include "DatiLavoratoreElement.h"



DatiLavoratoreElement::DatiLavoratoreElement(const DatiLavoratore& dati_, bool editable, QWidget *parent)
    : AbstSectionElement(QString("Dati Lavoratore"),parent ){


    addCampi(dati_, editable);
}


AbstDataSection* DatiLavoratoreElement::getData() const{

        return  new DatiLavoratore( Data(data_assunzione_widget->getValue().toStdString()),
                                    Data(fine_contratto_widget->getValue().toStdString()),
                                    ore_lavoro_sett_widget->getValue().toInt(),
                                    quota_aggiuntiva_widget->getValue().toFloat());
    }


void DatiLavoratoreElement::addCampi(const DatiLavoratore& dati, bool editable){

    data_assunzione_widget = new DateEditAttribute(nome_campi[0],dati.data_assunzione,editable,this);
    layout->addWidget(data_assunzione_widget);
    connect(data_assunzione_widget,SIGNAL(isModify()), this, SIGNAL(setModifyed()));

    fine_contratto_widget = new DateEditAttribute(nome_campi[1],dati.fine_contratto,editable,this);
    layout->addWidget(fine_contratto_widget);
    connect(fine_contratto_widget,SIGNAL(isModify()), this, SIGNAL(setModifyed()));

    ore_lavoro_sett_widget = new SlideAttribute(nome_campi[2],dati.ore_lavoro_sett,1,100,0,editable,this);
    layout->addWidget(ore_lavoro_sett_widget);
    connect(ore_lavoro_sett_widget,SIGNAL(isModify()), this, SIGNAL(setModifyed()));

    quota_aggiuntiva_widget = new LineEditAttribute(nome_campi[3],LineEditAttribute::TipoInserimento::REAL,QString::number(dati.quota_aggiuntiva),editable,this);
    layout->addWidget(quota_aggiuntiva_widget);
    connect(quota_aggiuntiva_widget,SIGNAL(isModify()), this, SIGNAL(setModifyed()));
}
QString DatiLavoratoreElement::nome_campi[4] ={"data di assunzione", "data di fine contratto", "ore di lavoro settimanali", "quota aggiuntiva"};




