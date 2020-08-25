#include "abstattribute.h"

AbstAttribute::AbstAttribute(QString nome, bool editable_, QWidget *parent) : QWidget(parent), editable(editable_)
{
    setFixedWidth(725);
    layout= new QHBoxLayout(this);
    layout->setSpacing(30);

    QLabel* title = new QLabel(nome, this);
    title->setWordWrap(true);
    title->setFixedWidth(170);
    title->setFixedHeight(30);

    str_value = new QLabel(this);
    str_value->setMaximumWidth(170);
    str_value->setWordWrap(true);

    layout->addWidget(title);
    layout->addWidget(str_value);
    setLayout(layout);
}


void AbstAttribute::insertInfo(QString info){
    Suggerimento* s =new Suggerimento(info,this);
    layout->insertWidget(2,s,0,Qt::AlignLeft);
}



QString AbstAttribute::getValue() const{
    return str_value->text();
}

