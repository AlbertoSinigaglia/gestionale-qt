#include "aboutus.h"

AboutUs::AboutUs(QWidget *parent): QDialog(parent)
{
    this->setObjectName("sfondo");
    this->setMinimumSize(600, 400);
    this->setContentsMargins(30,30,30,30);
    aboutUsLayout = new QVBoxLayout(this);
    addImage();
    addName();
    addVersion();
    addCreators();
    setStyle();
}

void AboutUs::addImage()
{
    QPixmap image(":/resources/MyG.png");
    image=image.scaled(200,200,Qt::KeepAspectRatio);
    QLabel* imageLabel = new QLabel(this);
    imageLabel->setPixmap(image);
    aboutUsLayout->addWidget(imageLabel);
    imageLabel->setAlignment(Qt::AlignCenter);
}

void AboutUs::addName()
{
    QLabel* name = new QLabel("MyGestionale",this, Qt::WindowFlags());
    name->setObjectName("nome");
    name->setAlignment(Qt::AlignCenter);
    aboutUsLayout->addWidget(name);
}

void AboutUs::addVersion()
{
    QLabel* version = new QLabel("Version 1.0",this, Qt::WindowFlags());
    version->setObjectName("versione");
    version->setMargin(15);
    version->setAlignment(Qt::AlignCenter);
    aboutUsLayout->addWidget(version);
}

void AboutUs::addCreators()
{
    QLabel* creators = new QLabel("Creators:",this, Qt::WindowFlags());
    creators->setAlignment(Qt::AlignCenter);
    creators->setObjectName("creatori");
    QLabel* creator1 = new QLabel("Sinigaglia Alberto, matricola:1193384",this, Qt::WindowFlags());
    creator1->setAlignment(Qt::AlignCenter);
    QLabel* creator2 = new QLabel("Calcagno Riccardo, matricola:1193479",this, Qt::WindowFlags());
    creator2->setAlignment(Qt::AlignCenter);
    QLabel* creator3 = new QLabel("Privitera Sara, matricola:1201157",this, Qt::WindowFlags());
    creator3->setAlignment(Qt::AlignCenter);
    creator1->setObjectName("creatore");
    creator2->setObjectName("creatore");
    creator3->setObjectName("creatore");
    aboutUsLayout->addWidget(creators);
    aboutUsLayout->addWidget(creator1);
    aboutUsLayout->addWidget(creator2);
    aboutUsLayout->addWidget(creator3);
}

void AboutUs::setStyle()
{
    QFile file(":/resources/aboutUs.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    setStyleSheet(styleSheet);
}
