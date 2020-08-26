#include "dateeditattribute.h"
#include<QDebug>

DateEditAttribute::DateEditAttribute(QString nome, const Data& valore_, bool editable,  QWidget *parent) : AbstAttribute(nome,editable,parent){
    if(editable){
        setter_data = new QCalendarWidget(this);
        qDebug() << setter_data->sizeHint();
        setter_data->setSelectedDate(QDate(valore_.getAnno(),valore_.getMese(),valore_.getGiorno()));
        setter_data->setFixedWidth(400);
        setter_data->setVerticalHeaderFormat(setter_data->NoVerticalHeader);
        layout->setAlignment(setter_data,Qt::AlignRight);

        connect(setter_data,SIGNAL(selectionChanged()),this, SLOT(catchValue()));
        connect(setter_data,SIGNAL(selectionChanged()),this, SIGNAL(isModify()));

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
