#include "typecreation.h"


QStringList TypeCreation::testo_opzioni ={"GUIDev","DatBaseDev","FullStack","ITSecurityDev","Tecnico"};

TypeCreation::TypeCreation(QWidget* parent): QDialog(parent){

    QVBoxLayout* layout = new QVBoxLayout(this);
    setMinimumSize(300, 250);
    layout->setAlignment(Qt::AlignCenter);
    layout->setContentsMargins(10,10,10,10);
    layout->setSpacing(30);

    QLabel* titolo = new QLabel("Che tipo di dipendente vuoi inserire?",this);
    QPushButton* ok = new QPushButton("Scelto!", this);
    ok->setFixedWidth(100);
    QPushButton* annulla = new QPushButton("Annulla", this);
    annulla->setFixedWidth(100);

    QWidget* pulsanti = new QWidget(this);
    QHBoxLayout* Lpulsanti = new QHBoxLayout(pulsanti);
    Lpulsanti->setAlignment(Qt::AlignCenter);
    Lpulsanti->addWidget(annulla); Lpulsanti->addWidget(ok);
    pulsanti->setLayout(Lpulsanti);

    opzioni = new QComboBox(this);
    opzioni->addItems(testo_opzioni);

    layout->addWidget(titolo);
    layout->addWidget(opzioni);
    layout->addWidget(pulsanti);
    layout->setAlignment(titolo,Qt::AlignCenter);

    setLayout(layout);

    connect(ok,SIGNAL(clicked()),this,SLOT(sendChoice()));
    connect(annulla,SIGNAL(clicked()),this,SLOT(abort()));
}

void TypeCreation::sendChoice(){
    emit choosed(opzioni->currentText());
    close();
}

void TypeCreation::abort(){
    close();
}
