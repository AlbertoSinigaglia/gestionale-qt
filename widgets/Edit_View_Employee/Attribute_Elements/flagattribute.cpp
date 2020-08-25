#include "flagattribute.h"

FlagAttribute::FlagAttribute(QString nome, bool valore_, bool editable,  QWidget *parent) : AbstAttribute(nome,editable,parent)
{
    if(editable){
        setter_bool = new QCheckBox(this);
        QWidget* c= new QWidget(this);
        QVBoxLayout* Lc = new QVBoxLayout(c);
        Lc->addWidget(setter_bool);
        Lc->setAlignment(setter_bool,Qt::AlignRight);
        c->setFixedWidth(300);

        if(valore_) setter_bool->setCheckState(Qt::Checked);
        else setter_bool->setCheckState(Qt::Unchecked);

        connect(setter_bool, SIGNAL(stateChanged(int)), this, SIGNAL(isModify()));
        connect(setter_bool,SIGNAL(stateChanged(int)), this, SLOT(setValue(int)));

        layout->addWidget(c);
    }

    setValue(valore_);
}


void FlagAttribute::setValue(int v){
    if(v!=0) str_value->setText(QString("SI"));
    else str_value->setText(QString("NO"));
}

