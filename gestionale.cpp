#include "gestionale.h"
#include "ui_gestionale.h"


Gestionale::Gestionale(QWidget *parent): QWidget(parent){
	mainLayout = new QHBoxLayout(this);
	addBoxSinistro();
	addBoxDestro();
	setStyle();
	setLayout(mainLayout);
}

Gestionale::~Gestionale(){}


void Gestionale::addBoxSinistro()
{
	QGroupBox* Gestione = new QGroupBox(this);
	Gestione->setFixedSize(250,500);
	Gestione->setTitle("Gestione Dipendenti");
	layoutGestione = new QVBoxLayout(Gestione);
	addComboBox();
	addFirstBox();
	mainLayout->addWidget(Gestione);
}

void Gestionale::addComboBox()
{
	QLabel* Visualizza = new QLabel("Dipendenti da visualizzare:", this, Qt::WindowFlags());
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
	QCheckBox* StipendioBase = new QCheckBox("Stipendio Base Mensile",this);
	layoutDatiDip->addWidget(StipendioBase);
	QCheckBox* OreLavoro= new QCheckBox("Ore di lavoro settimanale",this);
	layoutDatiDip->addWidget(OreLavoro);
	LayoutVisualizzare->addWidget(DatiDip);
}

void Gestionale::addBoxDestro()
{
	QGroupBox* Visualizza = new QGroupBox(this);
	Visualizza->setTitle("Visualizzazione Dipendenti");
	layoutVisualizza = new QVBoxLayout(Visualizza);
	QTableView* Tabella = new QTableView();
	layoutVisualizza->addWidget(Tabella);
	addAzioni();
	mainLayout->addWidget(Visualizza);
}

void Gestionale::addAzioni()
{

	QGroupBox* Azioni = new QGroupBox(this);
	Azioni->setTitle("Azioni sui dipendenti");
	QVBoxLayout* layoutAzioni = new QVBoxLayout(Azioni);
	QPushButton* Inserisci = new QPushButton("Inserisci",Azioni);
	layoutAzioni->addWidget(Inserisci);
	QPushButton* Modifica = new QPushButton("Modifica",Azioni);
	layoutAzioni->addWidget(Modifica);
	QPushButton* Elimina = new QPushButton("Elimina",Azioni);
	layoutAzioni->addWidget(Elimina);
	layoutGestione->addWidget(Azioni);
}

void Gestionale::setStyle()
{
	QFile file(":/resources/style.css");
	file.open(QFile::ReadOnly);
	QString styleSheet = QLatin1String(file.readAll());
	setStyleSheet(styleSheet);
}


