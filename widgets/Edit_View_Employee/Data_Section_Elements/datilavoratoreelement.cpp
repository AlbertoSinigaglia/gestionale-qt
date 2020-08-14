#include "datilavoratoreelement.h"



DatiLavoratoreElement::DatiLavoratoreElement(const DatiLavoratore& dati_, bool editable, QWidget *parent)
    : AbstSectionElement(parent ){

    addCampi(dati_, editable);
}


AbstDataSection* DatiLavoratoreElement::getData() const{

        return  /*new DatiLavoratore(  data_assunzione_label->text(),
                                 fine_contratto_label->text(),
                                 ore_lavoro_sett_label->text(),
                                 quota_aggiuntiva_label->text() );*/
                0;
    }


void DatiLavoratoreElement::addCampi(const DatiLavoratore& dati, bool editable){

}






