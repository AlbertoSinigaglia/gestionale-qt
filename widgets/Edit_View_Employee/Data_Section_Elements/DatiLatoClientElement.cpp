#include "DatiLatoClientElement.h"

/*DatiLatoClientElement::DatiLatoClientElement(const DatiLatoClient& dati_, bool editable, QWidget *parent)
    : AbstSectionElement(QString("Dati Lato Client"),parent ){

addCampi(dati_,editable);


}
AbstDataSection* DatiLatoClientElement::getData() const{

        return  new DatiLatoClient(
                                    libreria_widget->getValue(),
                                    orientato_professionalita_widget->getValue().toInt(),
                                    perc_codice_perfezionato_widget->getValue().toDouble());
    }
void DatiLatoClientElement::addCampi(const DatiLatoClient& dati, bool editable){

    libreria_widget = new ComboAttribute(nome_campi[1],editable,this);
    layout->addWidget(libreria_widget);
    connect(libreria_widget,SIGNAL(isModify()), this, SLOT(setModifyed()));

    orientato_professionalita_widget = new ComboAttribute(nome_campi[0],editable,this);
    layout->addWidget(orientato_professionalita_widget);
    connect(orientato_professionalita_widget->,SIGNAL(isModify()), this, SLOT(setModifyed()));

    perc_codice_perfezionato_widget = new ComboAttribute(nome_campi[2],editable,this);
    layout->addWidget(perc_codice_perfezionato_widget);
    connect(perc_codice_perfezionato_widget,SIGNAL(isModify()), this, SLOT(setModifyed()));
}
QString DatiLatoClientElement::nome_campi[3] ={"Libreria", "Orientato Professionalità", "Percentuale codice perfezionato"};
*/
