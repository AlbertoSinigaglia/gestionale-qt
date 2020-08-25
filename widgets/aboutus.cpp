#include "aboutus.h"

AboutUs::AboutUs(QWidget *parent): QDialog(parent)
{
    aboutUsLayout = new QVBoxLayout(this);
    addImage();
    addName();
    addVersion();
    addCreators();

}

void AboutUs::addImage()
{
    QPixmap image(":/resources/MyG.jpeg");
    QLabel* imageLabel = new QLabel(this);
    imageLabel->setPixmap(image);
    aboutUsLayout->addWidget(imageLabel);
    imageLabel->setAlignment(Qt::AlignCenter);
}

void AboutUs::addName()
{
    QLabel* name = new QLabel("MyGestionale",this, Qt::WindowFlags());
    name->setAlignment(Qt::AlignCenter);
    aboutUsLayout->addWidget(name);
}

void AboutUs::addVersion()
{
    QLabel* version = new QLabel("Version 1.0",this, Qt::WindowFlags());
    version->setAlignment(Qt::AlignCenter);
    aboutUsLayout->addWidget(version);
}

void AboutUs::addCreators()
{
    QGroupBox* creators = new QGroupBox("Creators",this);
    creators->setAlignment(Qt::AlignCenter);
    QVBoxLayout* creatorsLayout = new QVBoxLayout(creators);
    QLabel* creator1 = new QLabel("Sinigaglia Alberto, matricola:1193384",this, Qt::WindowFlags());
    QLabel* creator2 = new QLabel("Calcagno Riccardo, matricola:1193479",this, Qt::WindowFlags());
    QLabel* creator3 = new QLabel("Privitera Sara, matricola:1201157",this, Qt::WindowFlags());
    creatorsLayout->addWidget(creator1);
    creatorsLayout->addWidget(creator2);
    creatorsLayout->addWidget(creator3);
    creators->setLayout(creatorsLayout);
    aboutUsLayout->addWidget(creators);
}
