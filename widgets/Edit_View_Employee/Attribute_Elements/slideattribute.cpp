
#include"slideattribute.h"




SlideAttribute::SlideAttribute(QString nome, double valore_, double start_, double end_, unsigned int cifre_approx_, bool editable, QWidget *parent)
        :AbstAttribute(nome,editable,parent), start(start_), end(end_), cifre_approx(cifre_approx_){

    if(editable){
    setter_num = new QSlider(Qt::Horizontal,this);
    setter_num->setFixedWidth(150);
    setter_num->setRange(0,500); setter_num->setTickInterval(1);
    int posizione_iniziale= static_cast<int>(valore_-start_)*500.0/(end_-start_);
    setter_num->setSliderPosition(posizione_iniziale);

    connect(setter_num,SIGNAL(valueChanged(int)), this, SIGNAL(isModify()));
    connect(setter_num,SIGNAL(valueChanged(int)), this, SLOT(setValue(int)));

    layout->addWidget(setter_num);
    }

    setValue(valore_);
}


void SlideAttribute::setValue(double v){
    double num;
    if(editable){
        num= static_cast<double>(setter_num->sliderPosition()) * (end-start)/500.0 + start;
        num= static_cast<double>(round(num*pow(10,cifre_approx)))/pow(10,cifre_approx);
    }else num = v;
    str_value->setText(QString::number(num));
}


