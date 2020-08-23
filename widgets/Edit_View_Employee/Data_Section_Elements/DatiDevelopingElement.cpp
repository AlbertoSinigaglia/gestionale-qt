#include "DatiDevelopingElement.h"

DatiDevelopingElement::DatiDevelopingElement(const DatiDeveloping& dati_, bool editable, QWidget *parent)
    : AbstSectionElement(QString("Dati Developing"),parent ){
addCampi(dati_,editable);

}

AbstDataSection* DatiDevelopingElement::getData() const{

        int indx=0; QString val=linguaggio_widget->getValue();
        while(indx<static_cast<int>(opzioni_linguaggio.size()) && val!=opzioni_linguaggio[indx])
            indx++;

        return  new DatiDeveloping( static_cast<Conv::Linguaggio>(indx),
                                    perc_ore_programmazione_widget->getValue().toDouble(),
                                    n_righe_totali_widget->getValue().toUInt(),
                                    n_righe_mese_widget->getValue().toUInt(),
                                    n_progetti_conclusi_mese_widget->getValue().toUInt());
    }


QString DatiDevelopingElement::nome_campi[5] ={"Linguaggio usato","% ore programmazione", "# righe scritte dall'assuzione", "# righe scritte nel mese", "# progetti conclusi nel mese"};

DynamicArray<QString> DatiDevelopingElement::opzioni_linguaggio = {"Python","Java","PHP","C++","Swift","JavaScript","Ruby","SQL","TypeScript"};


void DatiDevelopingElement::addCampi(const DatiDeveloping& dati, bool editable){

    linguaggio_widget = new ComboAttribute(nome_campi[0],opzioni_linguaggio, dati.linguaggio, editable,this);
    layout->addWidget(linguaggio_widget);
    connect(linguaggio_widget,SIGNAL(isModify()), this, SIGNAL(setModifyed()));

    perc_ore_programmazione_widget = new SlideAttribute(nome_campi[1],dati.perc_ore_programmazione,0,1,2,editable,this);
    layout->addWidget(perc_ore_programmazione_widget);
    connect(perc_ore_programmazione_widget,SIGNAL(isModify()), this, SIGNAL(setModifyed()));

    n_righe_totali_widget = new LineEditAttribute(nome_campi[2],LineEditAttribute::TipoInserimento::INTEGER,QString::number(dati.n_righe_totali),editable,this);
    layout->addWidget(n_righe_totali_widget);
    connect(n_righe_totali_widget,SIGNAL(isModify()), this, SIGNAL(setModifyed()));

    n_righe_mese_widget = new LineEditAttribute(nome_campi[3],LineEditAttribute::TipoInserimento::INTEGER,QString::number(dati.n_righe_mese),editable,this);
    layout->addWidget(n_righe_mese_widget);
    connect(n_righe_mese_widget,SIGNAL(isModify()), this, SIGNAL(setModifyed()));

    n_progetti_conclusi_mese_widget = new LineEditAttribute(nome_campi[4],LineEditAttribute::TipoInserimento::INTEGER,QString::number(dati.n_progetti_conclusi_mese),editable,this);
    layout->addWidget(n_progetti_conclusi_mese_widget);
    connect(n_progetti_conclusi_mese_widget,SIGNAL(isModify()), this, SIGNAL(setModifyed()));
}
