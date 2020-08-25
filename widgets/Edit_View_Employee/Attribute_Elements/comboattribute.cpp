#include "comboattribute.h"

ComboAttribute::ComboAttribute(QString nome, const DynamicArray<QString>& opzioni_, int index_valore_inizio, bool editable,  QWidget *parent)
    :AbstAttribute(nome,editable,parent), opzioni(opzioni_){

    if(editable){
        setter_combo = new QComboBox(this);

        for(auto i=opzioni.begin(); i!=opzioni.end(); i++)
            setter_combo->addItem(*i);
        setter_combo->setCurrentIndex(index_valore_inizio);
        setter_combo->setFixedWidth(200);

        connect(setter_combo, SIGNAL(currentIndexChanged(int)), this, SLOT(setValue(int)));
        connect(setter_combo, SIGNAL(currentIndexChanged(int)), this, SIGNAL(isModify()));

        layout->setAlignment(setter_combo,Qt::AlignRight);
        layout->addWidget(setter_combo);
    }
    setValue(index_valore_inizio);
}


void ComboAttribute::setValue(int i){
    str_value->setText(opzioni[i]);
}
