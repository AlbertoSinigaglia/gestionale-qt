#include "typecreation.h"

QStringList TypeCreation::testo_opzioni ={"GUIDev","DatBaseDev","FullStack","ITSecurityDev","Tecnico"};

TypeCreation::TypeCreation(QWidget* parent): QDialog(parent){
    this->setObjectName("sfondo");
    QVBoxLayout* layout = new QVBoxLayout(this);
    setMinimumSize(400, 350);
    layout->setAlignment(Qt::AlignCenter);
    layout->setContentsMargins(10,10,10,10);
    layout->setSpacing(50);


    QLabel* titolo = new QLabel("Che tipo di dipendente vuoi inserire?",this);
    titolo->setObjectName("title");
    titolo->setAlignment(Qt::AlignCenter);
    QPushButton* ok = new QPushButton("Scelto!", this);
    ok->setObjectName("pulsanti");
    ok->setFixedWidth(100);
    QPushButton* annulla = new QPushButton("Annulla", this);
    annulla->setFixedWidth(100);

    annulla->setObjectName("pulsanti");

    QWidget* pulsanti = new QWidget(this);
    QHBoxLayout* Lpulsanti = new QHBoxLayout(pulsanti);
    Lpulsanti->setAlignment(Qt::AlignCenter);
    Lpulsanti->addWidget(annulla); Lpulsanti->addWidget(ok);
    pulsanti->setLayout(Lpulsanti);
    Lpulsanti->setAlignment(Qt::AlignCenter);

    opzioni = new QComboBox(this);
    opzioni->setObjectName("comboBox");
    opzioni->addItems(testo_opzioni);
    opzioni->setFixedSize(300,30);

    layout->addWidget(titolo);
    layout->addWidget(opzioni);
    layout->addWidget(pulsanti);
    layout->setAlignment(titolo,Qt::AlignCenter);

    setLayout(layout);

    connect(ok,SIGNAL(clicked()),this,SLOT(sendChoice()));
    connect(annulla,SIGNAL(clicked()),this,SLOT(abort()));
    setStyle();
}

void TypeCreation::sendChoice(){
    emit choosed(opzioni->currentText());
    close();
}

void TypeCreation::abort(){
    close();
}

void TypeCreation::setStyle()
{
    QFile file(":/resources/inserisci.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    setStyleSheet(styleSheet);
}
