#include "abstsectionelement.h"

AbstSectionElement::AbstSectionElement(QString nome_sezione, QWidget *parent): QWidget(parent){
    is_modifyed=false;
    setObjectName("abstract-section");
    setFixedWidth(920);
    layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignTop);
    QLabel* titolo = new QLabel(nome_sezione, this);
    layout->addWidget(titolo);
    layout->setSpacing(5);
    setLayout(layout);
    connect(this, SIGNAL(setModifyed()), this, SLOT(setIs_Modifyed()));
}

bool AbstSectionElement::isModifyed() const{
    return is_modifyed;
}

void AbstSectionElement::setIs_Modifyed(){
    is_modifyed = true;
}
