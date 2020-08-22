#include "abstsectionelement.h"



AbstSectionElement::AbstSectionElement(QString nome_sezione, QWidget *parent): QWidget(parent){
        is_modifyed=false;

        setFixedWidth(750);
        layout = new QVBoxLayout(this);
        layout->setAlignment(Qt::AlignTop);
        QLabel* titolo = new QLabel(nome_sezione, this);
        layout->addWidget(titolo);
        setLayout(layout);
    }


bool AbstSectionElement::isModifyed() const{
    return is_modifyed;
}


void AbstSectionElement::setIs_Modifyed(){
    is_modifyed = true;
}
