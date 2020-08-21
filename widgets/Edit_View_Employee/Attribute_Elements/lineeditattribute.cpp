#include "lineeditattribute.h"
#include"math.h"
LineEditAttribute::LineEditAttribute(QString nome, TipoInserimento tipo_, QString valore_, double min_, double max_, bool editable,  QWidget *parent)
    :AbstAttribute(nome,editable,parent), tipo(tipo_), val_min(min_), val_max(max_){

    if(!verify(valore_)) throw std::invalid_argument("<valore_> non rispetta il formato di <tipo_>");

    if(editable){
        setter_str = new QLineEdit(valore_,this);

        connect(setter_str, SIGNAL(textEdited(QString)), this, SLOT(catchValue(QString)));
        connect(setter_str, SIGNAL(textEdited(QString)), this, SLOT(isModify()));

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
