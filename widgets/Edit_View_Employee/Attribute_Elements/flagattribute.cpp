#include "flagattribute.h"

FlagAttribute::FlagAttribute(QString nome, bool valore_, bool editable,  QWidget *parent) : AbstAttribute(nome,editable,parent)
{
    if(editable){
        setter_bool = new QCheckBox(this);

        if(valore_) setter_bool->setCheckState(Qt::Checked);
        else setter_bool->setCheckState(Qt::Unchecked);

        connect(setter_bool, SIGNAL(stateChanged(int)), this, SIGNAL(isModify()));
        connect(setter_bool,SIGNAL(stateChanged(int)), this, SLOT(setValue(int)));

        layout->addItem(new QSpacerItem(25,15));
        layout->addWidget(setter_bool);

        layout->setAlignment(setter_bool,Qt::AlignRight);
    }

    setValue(valore_);
}


void FlagAttribute::setValue(int v){
    if(v!=0) str_value->setText(QString("SI"));
    else str_value->setText(QString("NO"));
}

