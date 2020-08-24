#include "flagattribute.h"

FlagAttribute::FlagAttribute(QString nome, bool valore_, bool editable,  QWidget *parent) : AbstAttribute(nome,editable,parent)
{
    if(editable){
        setter_bool = new QCheckBox(this);
        if(valore_) setter_bool->setCheckState(Qt::Checked);
        else setter_bool->setCheckState(Qt::Unchecked);

        layout->setAlignment(setter_bool,Qt::AlignRight);

        connect(setter_bool, SIGNAL(stateChanged(int)), this, SIGNAL(isModify()));
        connect(setter_bool,SIGNAL(stateChanged(int)), this, SLOT(setValue(int)));

        layout->addWidget(setter_bool);
    }

    setValue(valore_);
}


void FlagAttribute::setValue(int v){
    if(v!=0) str_value->setText(QString("SI"));
    else str_value->setText(QString("NO"));
}
