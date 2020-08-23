#include "DatiLatoClientElement.h"

DatiLatoClientElement::DatiLatoClientElement(const DatiLatoClient& dati_, bool editable, QWidget *parent)
    : AbstSectionElement(QString("Dati Lato Client"),parent ){

addCampi(dati_,editable);
}


QString DatiLatoClientElement::nome_campi[3] ={"Libreria usata", "È orientato alla professionalità?", "% di codice perfezionato"};

DynamicArray<QString> DatiLatoClientElement::opzioni_libreria = {"Bootstrap","Jquery","Treejs","Angular","Vuejs"};


AbstDataSection* DatiLatoClientElement::getData() const{

        int indx=0; QString val=libreria_widget->getValue();
        while(indx<static_cast<int>(opzioni_libreria.size()) && val!=opzioni_libreria[indx])
            indx++;

        return  new DatiLatoClient( static_cast<Conv::Libreria>(indx),
                                    (orientato_professionalita_widget->getValue()=="SI")? true:false,
                                    perc_codice_perfezionato_widget->getValue().toDouble());
    }


void DatiLatoClientElement::addCampi(const DatiLatoClient& dati, bool editable){

    libreria_widget = new ComboAttribute(nome_campi[0],opzioni_libreria, dati.libreria, editable,this);
    layout->addWidget(libreria_widget);
    connect(libreria_widget,SIGNAL(isModify()), this, SIGNAL(setModifyed()));

    orientato_professionalita_widget = new FlagAttribute(nome_campi[1],dati.orientato_professionalita,editable,this);
    orientato_professionalita_widget->insertInfo(" PROPRIETÀ: Professionalità/n intendiamo un ambiente professionale l'ambiente che mette a disposizione strumenti per un lavoro ragionato e consapevole, che mira a minimizzare gli sforzi a sfovore dell'intuitività del sistema");
    layout->addWidget(orientato_professionalita_widget);
    connect(orientato_professionalita_widget,SIGNAL(isModify()), this, SIGNAL(setModifyed()));

    perc_codice_perfezionato_widget = new SlideAttribute(nome_campi[2],dati.perc_codice_perfezionato,0,1,2,editable,this);
    perc_codice_perfezionato_widget->insertInfo("Rispetto al codice derivante da refactor e copy&paste quanto di questo è stato modificato per le esigenze contingenti?");
    layout->addWidget(perc_codice_perfezionato_widget);
    connect(perc_codice_perfezionato_widget,SIGNAL(isModify()), this, SIGNAL(setModifyed()));
}

