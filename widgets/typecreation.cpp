#include "typecreation.h"


QStringList TypeCreation::testo_opzioni ={"GUIDev","DatBaseDev","FullStack","ITSecurityDev","Tecnico"};

TypeCreation::TypeCreation(QWidget* parent): QFrame(parent){

    QVBoxLayout* layout = new QVBoxLayout(this);
    setMinimumSize(500, 400);
    layout->setAlignment(Qt::AlignTop);
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(10);

    QLabel* titolo = new QLabel("Che tipo di dipendente vuoi inserire?",this);
    QPushButton* ok = new QPushButton("Scelto!", this);
    QPushButton* annulla = new QPushButton("Annulla", this);

    QWidget* pulsanti = new QWidget(this);
    QHBoxLayout* Lpulsanti = new QHBoxLayout(this);
    Lpulsanti->addWidget(annulla); Lpulsanti->addWidget(ok);
    pulsanti->setLayout(Lpulsanti);

    opzioni = new QComboBox(this);
    opzioni->addItems(testo_opzioni);

    layout->addWidget(titolo);
    layout->addWidget(opzioni);
    layout->addWidget(pulsanti);

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
