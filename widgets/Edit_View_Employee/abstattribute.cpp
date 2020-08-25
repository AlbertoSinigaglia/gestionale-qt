#include "abstattribute.h"

AbstAttribute::AbstAttribute(QString nome, bool editable_, QWidget *parent) : QWidget(parent), editable(editable_)
{
    setObjectName("abstract-attribute");
    setFixedWidth(780);
    layout= new QHBoxLayout(this);
    layout->setSpacing(30);
    layout->setAlignment(Qt::AlignLeft);
    layout->setContentsMargins(20,0,0,0);

    QLabel* title = new QLabel(nome, this);
    title->setWordWrap(true);
    title->setFixedWidth(170);
    title->setFixedHeight(30);

    str_value = new QLabel(this);
    str_value->setFixedWidth(170);
    str_value->setWordWrap(true);

    layout->addWidget(title);
    layout->addWidget(str_value);
    layout->addItem(new QSpacerItem(60, 28));
    setLayout(layout);
}


void AbstAttribute::insertInfo(QString info){
    Suggerimento* s =new Suggerimento(info,this);
    layout->removeItem(layout->itemAt(2));
    layout->insertWidget(2,s,0,Qt::AlignLeft);
}



QString AbstAttribute::getValue() const{
    return str_value->text();
}

