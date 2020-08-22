#include "abstattribute.h"

AbstAttribute::AbstAttribute(QString nome, bool editable_, QWidget *parent) : QWidget(parent), editable(editable_)
{

    layout= new QHBoxLayout(this);
    layout->setAlignment(Qt::AlignLeft);
    layout->setSpacing(30);

    QLabel* title = new QLabel(nome, this);
    title->setFixedWidth(500);
    //title->setWordWrap(true);
    layout->addWidget(title);

    str_value = new QLabel(this);
    title->setFixedWidth(100);
    layout->addWidget(str_value);

    setLayout(layout);
}


void AbstAttribute::insertInfo(QString info){
    layout->insertWidget(1,new Suggerimento(info,this));
}



QString AbstAttribute::getValue() const{
    return str_value->text();
}

