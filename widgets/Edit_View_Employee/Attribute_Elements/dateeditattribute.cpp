#include "dateeditattribute.h"

DateEditAttribute::DateEditAttribute(QString nome, const Data& valore_, bool editable,  QWidget *parent) : AbstAttribute(nome,editable,parent){

    if(editable){
        setter_data = new QCalendarWidget(this);
        setter_data->setSelectedDate(QDate(valore_.getAnno(),valore_.getMese(),valore_.getGiorno()));

        connect(setter_data,SIGNAL(selectionChanged()),this, SLOT(catchValue()));
        connect(setter_data,SIGNAL(selectionChanged()),this, SLOT(isModify()));

        layout->addWidget(setter_data);
    }
    setValue(valore_);
}

void DateEditAttribute::catchValue(){
    QDate d = setter_data->selectedDate();
    setValue(Data(d.year(),d.month(),d.day()));
}


void DateEditAttribute::setValue(Data d){
    str_value->setText(QString::fromStdString(d.operator std::string()));
}
