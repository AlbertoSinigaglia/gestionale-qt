#include "DatiRipristinoSicurezzaElement.h"

DatiRipristinoSicurezzaElement::DatiRipristinoSicurezzaElement(const DatiRipristinoSicurezza& dati_, bool editable, QWidget *parent)
    : AbstSectionElement(QString("Dati Ripristino Sicurezza"),parent ){

    addCampi(dati_,editable);

}
AbstDataSection* DatiRipristinoSicurezzaElement::getData() const{

        return  new DatiRipristinoSicurezza(
                                    num_problemi_irrsolti_widget->getValue().toDouble(),
                                    num_criticita_risolte_widget->getValue().toDouble());
    }
void DatiRipristinoSicurezzaElement::addCampi(const DatiRipristinoSicurezza& dati, bool editable){

    num_problemi_irrsolti_widget = new LineEditAttribute(nome_campi[0],LineEditAttribute::TipoInserimento::INTEGER,QString::number(dati.n_problemi_irrsolti),0,0,editable,this);
    layout->addWidget(num_problemi_irrsolti_widget);
    connect(num_problemi_irrsolti_widget,SIGNAL(isModify()), this, SLOT(setModifyed()));

    num_criticita_risolte_widget = new LineEditAttribute(nome_campi[1],LineEditAttribute::TipoInserimento::INTEGER,QString::number(dati.n_criticita_risolte),0,0,editable,this);
    layout->addWidget(num_criticita_risolte_widget);
    connect(num_criticita_risolte_widget,SIGNAL(isModify()), this, SLOT(setModifyed()));

    }
QString DatiRipristinoSicurezzaElement::nome_campi[2] ={"Numero problemi irrisolti", "Numero criticità risolte"};
