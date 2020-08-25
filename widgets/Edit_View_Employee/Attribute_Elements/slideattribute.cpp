
#include"slideattribute.h"
#include"math.h"
#include<QDebug>



SlideAttribute::SlideAttribute(QString nome, double valore_, double start_, double end_, unsigned int cifre_approx_, bool editable, QWidget *parent)
        :AbstAttribute(nome,editable,parent), start(start_), end(end_), cifre_approx(cifre_approx_){

    if(editable){
    setter_num = new QSlider(Qt::Horizontal,this);
    setter_num->setFixedWidth(300);

    setter_num->setRange(0,500); setter_num->setTickInterval(1);
    int posizione_iniziale= static_cast<int>((valore_-start_)*500.0/(end_-start_));
    setter_num->setSliderPosition(posizione_iniziale);

    connect(setter_num,SIGNAL(valueChanged(int)), this, SIGNAL(isModify()));
    connect(setter_num,SIGNAL(valueChanged(int)), this, SLOT(catchValue()));

    layout->addWidget(setter_num);
    }

    setValue(valore_);
}

void SlideAttribute::catchValue(){
    double num = static_cast<double>(setter_num->sliderPosition()) * (end-start)/500.0 + start;
    num= static_cast<double>(round(num*pow(10,cifre_approx)))/pow(10,cifre_approx);

    setValue(num);
}

void SlideAttribute::setValue(double v){

    str_value->setText(QString::number(v));
}


