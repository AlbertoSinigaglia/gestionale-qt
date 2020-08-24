#include "DatiLatoServerElement.h"

DatiLatoServerElement::DatiLatoServerElement(const DatiLatoServer& dati_, bool editable, QWidget *parent)
    : AbstSectionElement(QString("Dati Lato server"),parent ){

addCampi(dati_,editable);
}

AbstDataSection* DatiLatoServerElement::getData() const{

        return  new DatiLatoServer( perc_capo_progetto_widget->getValue().toDouble(),
                                    livello_astrazione_widget->getValue().toUInt(),
                                    (prove_correttezza_widget->getValue()=="SI")? true:false,
                                    (orientato_ortogonalita_widget->getValue()=="SI")? true:false);
    }


void DatiLatoServerElement::addCampi(const DatiLatoServer& dati, bool editable){

    perc_capo_progetto_widget = new SlideAttribute(nome_campi[0],dati.perc_capo_progetto,0,1,2,editable,this);
    layout->addWidget(perc_capo_progetto_widget);
    connect(perc_capo_progetto_widget,SIGNAL(isModify()), this, SIGNAL(setModifyed()));

    livello_astrazione_widget = new SlideAttribute(nome_campi[1],dati.livello_astrazione,1,5,0,editable,this);
    livello_astrazione_widget->insertInfo("maggiore è il suo livello di astrazione più è vicino a prendere decisioni architetturali del sistema");
    layout->addWidget(livello_astrazione_widget);
    connect(livello_astrazione_widget,SIGNAL(isModify()), this, SIGNAL(setModifyed()));

    prove_correttezza_widget = new FlagAttribute(nome_campi[2],dati.prove_correttezza,editable,this);
    layout->addWidget(prove_correttezza_widget);
    connect(prove_correttezza_widget,SIGNAL(isModify()), this, SIGNAL(setModifyed()));

    orientato_ortogonalita_widget = new FlagAttribute(nome_campi[3],dati.orientato_ortogonalita,editable,this);
    orientato_ortogonalita_widget->insertInfo("PROPRIETÀ: Ortognoalità \ncon ortogonalità intendiamo il principio sostenuto nella prospettiva AGLILE");
    layout->addWidget(orientato_ortogonalita_widget);
    connect(orientato_ortogonalita_widget,SIGNAL(isModify()), this, SIGNAL(setModifyed()));




}
QString DatiLatoServerElement::nome_campi[4] ={"% dei progetti in cui era capo", "Livello Astrazione", "Adotta prove di correttezza?", "È orientato all'ortogonalità"};
