#include "lineeditattribute.h"

#include"math.h"
LineEditAttribute::LineEditAttribute(QString nome, TipoInserimento tipo_, QString valore_, bool editable,  QWidget *parent)
    :AbstAttribute(nome,editable,parent), tipo(tipo_), val_min(0), val_max(pow(10,9)){

    if(!verify(valore_)) throw std::invalid_argument("<valore_> non rispetta il formato di <tipo_>");

    if(editable){
        setter_str = new QLineEdit(valore_,this);
        setter_str->setFixedWidth(400);
        layout->setAlignment(setter_str,Qt::AlignRight);
        setter_str->setMaxLength(30);

        connect(setter_str, SIGNAL(textEdited(QString)), this, SLOT(catchValue(QString)));
        connect(setter_str, SIGNAL(textEdited(QString)), this, SIGNAL(isModify()));

        layout->addWidget(setter_str);
    }
    setValue(valore_);
}


bool LineEditAttribute::verify(QString s){
    if(tipo==TipoInserimento::STRING)
        return true;
    bool isOk;
    double num;
    if(tipo==TipoInserimento::REAL){
         num = s.toDouble(&isOk);
    }else
        num = static_cast<double>( s.toInt(&isOk)  );
    if(isOk)
        isOk= (num>=val_min)&&(num<=val_max);
    return isOk;
}

void LineEditAttribute::setError(){
    if(tipo==TipoInserimento::STRING) return;
    QString testo= "ERRORE inserimento. ";
    QString minimo;
    QString massimo;
    if(tipo==TipoInserimento::INTEGER){
        testo="tipo: intero";
        minimo= QString::number(round(val_min));
        massimo = QString::number(round(val_max));
    }else{ testo="tipo reale";
        minimo= QString::number(static_cast<float>(round(val_min*100))/100.0f);
        massimo = QString::number(static_cast<float>(round(val_max*100))/100.0f);
    }
    testo+=", min="; testo+=minimo; testo+=", max="; testo+=massimo;

    setter_str->setText(testo);
    setter_str->selectAll();
}



void LineEditAttribute::catchValue(QString q){
    if(verify(q))
        setValue(q);
    else
        setError();
}

void LineEditAttribute::setValue(QString q){
    str_value->setText(q);
}

void LineEditAttribute::setValMin(double min){
    val_min=min;
}
void LineEditAttribute::setValMax(double max){
    val_max=max;
}
