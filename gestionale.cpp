#include "gestionale.h"
#include "ui_gestionale.h"
#include "models/headers/BackDev.h"
#include "widgets/employeelistelement.h"

Gestionale::Gestionale(QWidget *parent): QWidget(parent), model(nullptr){
    this->setMinimumSize(1280, 800);
    mainLayout = new QHBoxLayout(this);
    mainLayout->setAlignment(Qt::AlignTop);
    mainLayout->setContentsMargins(0,0,0,0);
    mainLayout->setSpacing(0);
	addBoxSinistro();
	addBoxDestro();
    setStyle();
    setLayout(mainLayout);
    connect(
        c_nome,&QCheckBox::stateChanged,
        [=](int state){
            employeesList->changeListAttributeVisibility(EmployeeListElement::Name, state);
        }
    );
    connect(
        c_cognome,&QCheckBox::stateChanged,
        [=](int state){
            employeesList->changeListAttributeVisibility(EmployeeListElement::Surname, state);
        }
    );
    connect(
        c_cf,&QCheckBox::stateChanged,
        [=](int state){
            employeesList->changeListAttributeVisibility(EmployeeListElement::CF, state);
        }
    );
    connect(
        c_dataNascita,&QCheckBox::stateChanged,
        [=](int state){
            employeesList->changeListAttributeVisibility(EmployeeListElement::DateOfBirth, state);
        }
    );

    connect(
        DataA,&QCheckBox::stateChanged,
        [=](int state){
            employeesList->changeListAttributeVisibility(EmployeeListElement::DateOfEmployment, state);
        }
    );
    connect(
        DataFineContratto,&QCheckBox::stateChanged,
        [=](int state){
            employeesList->changeListAttributeVisibility(EmployeeListElement::DateEndOfContract, state);
        }
    );
    connect(
        StipendioBase,&QCheckBox::stateChanged,
        [=](int state){
            employeesList->changeListAttributeVisibility(EmployeeListElement::Salary, state);
        }
    );
    connect(
        OreLavoro,&QCheckBox::stateChanged,
        [=](int state){
            employeesList->changeListAttributeVisibility(EmployeeListElement::WeeklyHours, state);
        }
    );
    connect(elimina, SIGNAL(clicked()), this, SLOT(deleteButtonClicked()));
    connect(inserisci, SIGNAL(clicked()), this, SLOT(insertButtonClicked( )));
    connect(modifica, SIGNAL(clicked()), this, SLOT(modifyButtonClicked( )));
    connect(employeesList, SIGNAL(ListElementDoubleClicked(EmployeeListElement*)), this, SLOT(employeeListElementDoubleClicked( EmployeeListElement* )));
}

Gestionale::~Gestionale(){}


void Gestionale::addBoxSinistro()
{
    auto* frameFiltri = new QFrame(this);
    frameFiltri->setFixedWidth(250);
    layoutFrameFiltri = new QVBoxLayout(frameFiltri);
    layoutFrameFiltri->setAlignment(Qt::AlignTop);

    auto scroll = new QScrollArea();
    scroll->setWidgetResizable(true);
    scroll->setObjectName("scroll-left");
    scroll->setFixedWidth(270);
    scroll->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    scroll->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    scroll->setWidget(frameFiltri);
    scroll->setAlignment(Qt::AlignHCenter);
    mainLayout->addWidget(scroll);
    addTitleSinistro();
    addComboBox();
    addFirstBox();
    addAzioni();
}

void Gestionale::addTitleSinistro(){
    QLabel* Visualizza = new QLabel("Metriche visualizzazione:", this, Qt::WindowFlags());
    Visualizza->setObjectName("title-left");
    layoutFrameFiltri->addWidget(Visualizza);
}
void Gestionale::addComboBox()
{
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
    layoutFrameFiltri->addWidget(Dipendenti);
}

void Gestionale::addFirstBox()
{
    Visualizzare = new QGroupBox(this);
	Visualizzare->setTitle("Cosa Visualizzare");
    LayoutVisualizzare = new QVBoxLayout(Visualizzare);
    layoutFrameFiltri->addWidget(Visualizzare);
	addBoxPersona();
    addBoxLavoro();
}

void Gestionale::addBoxPersona()
{
    QGroupBox* DatiPersona = new QGroupBox(this);
    DatiPersona->setObjectName("dati-persona-left");
	DatiPersona->setTitle("Dati della persona");
    QVBoxLayout* layoutDatiPersona = new QVBoxLayout(DatiPersona);


    c_cognome = new QCheckBox("Cognome",this);
    layoutDatiPersona->addWidget(c_cognome);
    c_nome = new QCheckBox("Nome",this);
    layoutDatiPersona->addWidget(c_nome);
    c_cf = new QCheckBox("Codice Fiscale",this);
    layoutDatiPersona->addWidget(c_cf);
    c_dataNascita = new QCheckBox("Data di nascita",this);
    layoutDatiPersona->addWidget(c_dataNascita);
    c_nome->setCheckState(Qt::CheckState::Checked);
    c_cognome->setCheckState(Qt::CheckState::Checked);
    c_cf->setCheckState(Qt::CheckState::Checked);
    c_dataNascita->setCheckState(Qt::CheckState::Checked);
	LayoutVisualizzare->addWidget(DatiPersona);
}

void Gestionale::addBoxLavoro()
{
	QGroupBox* DatiDip = new QGroupBox(this);
	DatiDip->setTitle("Dati relativi al lavoro");
	QVBoxLayout* layoutDatiDip = new QVBoxLayout(DatiDip);
    DataA = new QCheckBox("Data assunzione",this);
	layoutDatiDip->addWidget(DataA);
    DataFineContratto = new QCheckBox("Data fine contratto",this);
	layoutDatiDip->addWidget(DataFineContratto);
    StipendioBase = new QCheckBox("Stipendio Base \nMensile",this);
	layoutDatiDip->addWidget(StipendioBase);
    OreLavoro= new QCheckBox("Ore di lavoro \nsettimanale",this);
    layoutDatiDip->addWidget(OreLavoro);
    DataA->setCheckState(Qt::CheckState::Checked);
    DataFineContratto->setCheckState(Qt::CheckState::Checked);
    StipendioBase->setCheckState(Qt::CheckState::Checked);
    OreLavoro->setCheckState(Qt::CheckState::Checked);
	LayoutVisualizzare->addWidget(DatiDip);
}

void Gestionale::addAzioni()
{
	QGroupBox* Azioni = new QGroupBox(this);
	Azioni->setTitle("Azioni sui dipendenti");
    Azioni->setObjectName("azioni-left");
	QVBoxLayout* layoutAzioni = new QVBoxLayout(Azioni);
    inserisci = new QPushButton("Inserisci",Azioni);
    layoutAzioni->addWidget(inserisci);
    modifica = new QPushButton("Modifica",Azioni);
    layoutAzioni->addWidget(modifica);
    elimina = new QPushButton("Elimina",Azioni);
    layoutAzioni->addWidget(elimina);
    layoutFrameFiltri->addWidget(Azioni);
}

void Gestionale::addBoxDestro()
{
    auto scroll = new QScrollArea();
    scroll->setContentsMargins(0,0,0,0);
    scroll->setWidgetResizable(true);
    scroll->setObjectName("scroll-right");
    scroll->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    employeesList = new EmployeesList(this);
    scroll->setWidget(employeesList);
    mainLayout->addWidget(scroll);
}

void Gestionale::setStyle()
{
	QFile file(":/resources/style.css");
	file.open(QFile::ReadOnly);
	QString styleSheet = QLatin1String(file.readAll());
	setStyleSheet(styleSheet);
}


