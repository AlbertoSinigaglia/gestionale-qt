#include "gestionale.h"
#include "ui_gestionale.h"


Gestionale::Gestionale(QWidget *parent): QWidget(parent){
    mainLayout = new QHBoxLayout(this);
    this->setMinimumSize(1280, 800);
    mainLayout->setAlignment(Qt::AlignTop);
    mainLayout->setContentsMargins(0,0,0,0);
    mainLayout->setSpacing(0);
	addBoxSinistro();
	addBoxDestro();
	setStyle();
    setLayout(mainLayout);
}

Gestionale::~Gestionale(){}


void Gestionale::addBoxSinistro()
{
    auto* Gestione = new QFrame(this);
    Gestione->setFixedWidth(250);
    layoutGestione = new QVBoxLayout(Gestione);
    layoutGestione->setAlignment(Qt::AlignTop);
    addComboBox();
    addFirstBox();
    addAzioni();
    auto scroll = new QScrollArea();
    scroll->setWidgetResizable(true);
    scroll->setObjectName("scroll-left");
    scroll->setFixedWidth(270);
    scroll->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    scroll->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    scroll->setWidget(Gestione);
    scroll->setAlignment(Qt::AlignHCenter);
    mainLayout->addWidget(scroll);
}

void Gestionale::addComboBox()
{
    QLabel* Visualizza = new QLabel("Metriche visualizzazione:", this, Qt::WindowFlags());
    Visualizza->setObjectName("title-left");
	layoutGestione->addWidget(Visualizza);
	QComboBox* Dipendenti = new QComboBox(this);
	Dipendenti->addItems({
		"Tutti",
		"Manutentore",
		"Hardware",
		"Software",
		"BackDev",
		"FrontDev",
		"FullStack",
		"BDDeveloper",
		"GUIDeveloper",
		"ITSecurityDev",
		"Tecnico"
	});
	layoutGestione->addWidget(Dipendenti);
}

void Gestionale::addFirstBox()
{
    Visualizzare = new QGroupBox(this);
	Visualizzare->setTitle("Cosa Visualizzare");
    LayoutVisualizzare = new QVBoxLayout(Visualizzare);
	addBoxPersona();
    addBoxLavoro();
	layoutGestione->addWidget(Visualizzare);
}

void Gestionale::addBoxPersona()
{
    QGroupBox* DatiPersona = new QGroupBox(this);
	DatiPersona->setObjectName("DatiPersona");
	DatiPersona->setTitle("Dati della persona");
    QVBoxLayout* layoutDatiPersona = new QVBoxLayout(DatiPersona);
	QCheckBox* Cognome = new QCheckBox("Cognome",this);
	layoutDatiPersona->addWidget(Cognome);
	QCheckBox* Nome = new QCheckBox("Nome",this);
	layoutDatiPersona->addWidget(Nome);
	QCheckBox* Sesso = new QCheckBox("Sesso",this);
	layoutDatiPersona->addWidget(Sesso);
	QCheckBox* Eta = new QCheckBox("Eta'",this);
	layoutDatiPersona->addWidget(Eta);
	LayoutVisualizzare->addWidget(DatiPersona);
}

void Gestionale::addBoxLavoro()
{
	QGroupBox* DatiDip = new QGroupBox(this);
	DatiDip->setTitle("Dati relativi al lavoro");
	QVBoxLayout* layoutDatiDip = new QVBoxLayout(DatiDip);
	QCheckBox* DataA = new QCheckBox("Data assunzione",this);
	layoutDatiDip->addWidget(DataA);
	QCheckBox* DataFineContratto = new QCheckBox("Data fine contratto",this);
	layoutDatiDip->addWidget(DataFineContratto);
    QCheckBox* StipendioBase = new QCheckBox("Stipendio Base \nMensile",this);
	layoutDatiDip->addWidget(StipendioBase);
    QCheckBox* OreLavoro= new QCheckBox("Ore di lavoro \nsettimanale",this);
	layoutDatiDip->addWidget(OreLavoro);
	LayoutVisualizzare->addWidget(DatiDip);
}

void Gestionale::addAzioni()
{

	QGroupBox* Azioni = new QGroupBox(this);
	Azioni->setTitle("Azioni sui dipendenti");
    Azioni->setObjectName("azioni-left");
	QVBoxLayout* layoutAzioni = new QVBoxLayout(Azioni);
	QPushButton* Inserisci = new QPushButton("Inserisci",Azioni);
	layoutAzioni->addWidget(Inserisci);
	QPushButton* Modifica = new QPushButton("Modifica",Azioni);
	layoutAzioni->addWidget(Modifica);
	QPushButton* Elimina = new QPushButton("Elimina",Azioni);
	layoutAzioni->addWidget(Elimina);
	layoutGestione->addWidget(Azioni);
}

void Gestionale::addBoxDestro()
{
    auto scroll = new QScrollArea();
    scroll->setContentsMargins(0,0,0,0);
    scroll->setWidgetResizable(true);
    scroll->setObjectName("scroll-right");
    scroll->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    scroll->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    auto* Visualizza = new QFrame(this);
    auto layoutLista = new QVBoxLayout(Visualizza);
    layoutLista->setAlignment(Qt::AlignTop);
    scroll->setWidget(Visualizza);
    Visualizza->setObjectName("frame-right");
    Visualizza->setContentsMargins(0,0,0,0);
    Visualizza->layout()->setContentsMargins(0,0,0,0);
    layoutLista->setSpacing(0);
    for(auto i = 0; i < 30; i++)
        layoutLista->addWidget(new EmployeeListElement(this));
    mainLayout->addWidget(scroll);
}

void Gestionale::setStyle()
{
	QFile file(":/resources/style.css");
	file.open(QFile::ReadOnly);
	QString styleSheet = QLatin1String(file.readAll());
	setStyleSheet(styleSheet);
}


