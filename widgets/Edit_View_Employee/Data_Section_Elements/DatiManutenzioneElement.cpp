#include "DatiManutenzioneElement.h"

DatiManutenzioneElement::DatiManutenzioneElement(const DatiManutenzione& dati_, bool editable, QWidget *parent)
    : AbstSectionElement(QString("Dati Manutenzione"),parent ){

addCampi(dati_,editable);


}
AbstDataSection* DatiManutenzioneElement::getData() const{

        return  new DatiManutenzione(

                                    perc_riparazioni_inefficaci_widget->getValue().toDouble(),
                                    perc_ripristino_medio_widget->getValue().toDouble(),
                                    n_riparazioni_mese_widget->getValue().toInt());
    }
void DatiManutenzioneElement::addCampi(const DatiManutenzione& dati, bool editable){


    perc_riparazioni_inefficaci_widget = new SlideAttribute(nome_campi[0],dati.perc_riparazioni_inefficaci,0,1,2,editable,this);
    layout->addWidget(perc_riparazioni_inefficaci_widget);
    connect(perc_riparazioni_inefficaci_widget,SIGNAL(isModify()), this, SLOT(setModifyed()));

    perc_ripristino_medio_widget = new SlideAttribute(nome_campi[1],dati.perc_ripristino_medio,0,1,2,editable,this);
    layout->addWidget(perc_ripristino_medio_widget);
    connect(perc_ripristino_medio_widget,SIGNAL(isModify()), this, SLOT(setModifyed()));

    n_riparazioni_mese_widget = new LineEditAttribute(nome_campi[2],LineEditAttribute::TipoInserimento::INTEGER,QString::number(dati.n_riparazioni_mese),0,0,editable,this);
    layout->addWidget(n_riparazioni_mese_widget);
    connect(n_riparazioni_mese_widget,SIGNAL(isModify()), this, SLOT(setModifyed()));

}
QString DatiManutenzioneElement::nome_campi[3] ={"Percentuale riparazioni inefficaci", "Percentuale ripristino medio", "Num riparazioni mese"};
