#include "DatiRipristinoSicurezzaElement.h"

QString DatiRipristinoSicurezzaElement::nome_campi[2] ={"# problemi irrisolti", "# criticità risolte nel mese"};

DatiRipristinoSicurezzaElement::DatiRipristinoSicurezzaElement(const DatiRipristinoSicurezza& dati_, bool editable, QWidget *parent)
    : AbstSectionElement(QString("Dati Ripristino Sicurezza"),parent ){
        addCampi(dati_,editable);
}

AbstDataSection* DatiRipristinoSicurezzaElement::getData() const{
    return  new DatiRipristinoSicurezza(
                num_problemi_irrsolti_widget->getValue().toUInt(),
                num_criticita_risolte_widget->getValue().toUInt()
    );
}

void DatiRipristinoSicurezzaElement::addCampi(const DatiRipristinoSicurezza& dati, bool editable){
    num_problemi_irrsolti_widget = new LineEditAttribute(nome_campi[0],LineEditAttribute::TipoInserimento::INTEGER,QString::number(dati.n_problemi_irrsolti),editable,this);
    num_problemi_irrsolti_widget->setValMax(80);
    layout->addWidget(num_problemi_irrsolti_widget);
    connect(num_problemi_irrsolti_widget,SIGNAL(isModify()), this, SIGNAL(setModifyed()));

    num_criticita_risolte_widget = new LineEditAttribute(nome_campi[1],LineEditAttribute::TipoInserimento::INTEGER,QString::number(dati.n_criticita_risolte),editable,this);
    num_criticita_risolte_widget->setValMax(20);
    num_criticita_risolte_widget->insertInfo("Una criticità è una falla di sicurezza nel sistema che può portare a ingenti perdite dovute a sottrazione di informazioni, non tutti i problemi sono criticità");
    layout->addWidget(num_criticita_risolte_widget);
    connect(num_criticita_risolte_widget,SIGNAL(isModify()), this, SIGNAL(setModifyed()));
}
