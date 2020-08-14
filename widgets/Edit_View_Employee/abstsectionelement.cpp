#include "abstsectionelement.h"



AbstSectionElement::AbstSectionElement(QWidget *parent): QWidget(parent){
        is_modifyed=false;
    }


bool AbstSectionElement::isModifyed() const{
    return is_modifyed;
}


void AbstSectionElement::setModifyed(){
    is_modifyed = true;
}
