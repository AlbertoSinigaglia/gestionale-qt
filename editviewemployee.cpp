#include"editviewemployee.h"

EditViewEmployee::EditViewEmployee(const DynamicArray<AbstDataSection*>& dati_, bool editable, QWidget *parent): QWidget(parent){
        QLabel* nome;
        if(editable)
            nome = new QLabel(QString("Modifica Impiegato"));
            else nome = new QLabel(QString("Visualizza Impiegato"));
        nome->setFixedWidth(200);

        this->setFixedSize(800, 700);
        mainLayout = new QVBoxLayout(this);
        mainLayout->setContentsMargins(0,0,0,0);
        mainLayout->setSpacing(10);
        mainLayout->setAlignment(Qt::AlignCenter);

        QScrollArea* impiegato = new QScrollArea(this);
        impiegato->setFixedSize(750,600);
        impiegato->setLayout(buildSections(dati_, editable, impiegato));

        QPushButton* salva_button = new QPushButton("Salva e Esci", this);
        QPushButton* esci_button = new QPushButton("Esci", this);
        QHBoxLayout* options =new QHBoxLayout(this);
        options->addWidget(salva_button);
        options->addWidget(esci_button);
        options->setAlignment(Qt::AlignRight);

        mainLayout->addWidget(nome);
        mainLayout->addWidget(impiegato);
        mainLayout->addLayout(options);


        connect(salva_button, SIGNAL(clicked()), this, SLOT(chooseAndSend()));
        connect(esci_button, SIGNAL(clicked()), this, SIGNAL(handleExitEditView()));

        setLayout(mainLayout);
        }


void EditViewEmployee::chooseAndSend() const{

        for(auto i=lista_elementi.begin(); i!=lista_elementi.end(); i++){
            if((*i)->isModifyed())
            emit SaveDataConsiderd((*i)->getData());
        }

        emit handleExitEditView();
    }



QVBoxLayout* EditViewEmployee::buildSections(const DynamicArray<AbstDataSection*>& dati_, bool editable, QWidget* parent){

    QVBoxLayout* layout = new QVBoxLayout(parent);
    layout->setSpacing(20);


    DatiLavoratore* d;
    for(auto i = dati_.begin(); i!=dati_.end(); i++){
        d=dynamic_cast<DatiLavoratore*>(*i);
        if(d) layout->addWidget(new DatiLavoratoreElement(*d,editable,this));
    }
/*
    for(DynamicArray<AbstDataSection*>::const_iterator i = dati_.begin(); i!=dati_.end(); i++){
        AbstDataSection* objct = *i;

        if(typeid(objct)==typeid(Employee)) {
            const DatiLavoratore* dati_lavoratore = dynamic_cast<const DatiLavoratore*>(objct);
            DatiLavoratoreElement* sezione_employee = new DatiLavoratoreElement(*dati_lavoratore, editable, this);

            layout->addWidget(sezione_employee);
            lista_elementi.push_back(sezione_employee);

            delete(dati_lavoratore);
            break;}
        else
        if(typeid(objct)==typeid(Software)) {
            const DatiDeveloping* dati_developing = dynamic_cast<const DatiDeveloping*>(objct);
            DatiDevelopingElement* sezione_software = new DatiDevelopingElement(*dati_developing, editable, this);

            layout->addWidget(sezione_software);
            lista_elementi.push_back(sezione_software);

            delete(dati_developing);

        //ECCETRA....

        }

    }*/
return layout;

    }
