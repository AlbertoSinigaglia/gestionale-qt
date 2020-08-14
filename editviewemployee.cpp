#include"editviewemployee.h"

EditViewEmployee::EditViewEmployee(const DynamicArray<AbstDataSection*>& dati_, bool editable, QWidget *parent): QWidget(parent){

        this->setFixedSize(800, 700);
        mainLayout = new QVBoxLayout(this);
        mainLayout->setAlignment(Qt::AlignTop);
        mainLayout->setContentsMargins(0,0,0,0);
        mainLayout->setSpacing(0);

        QScrollArea* impiegato = new QScrollArea(this);
        impiegato->setFixedSize(750,500);
        impiegato->setLayout(buildSections(dati_, editable));

        QPushButton* salva_button = new QPushButton("Salva e Esci", this);
        QPushButton* esci_button = new QPushButton("Esci", this);
        QHBoxLayout* options =new QHBoxLayout(this);
        options->addWidget(salva_button);
        options->addWidget(esci_button);
        options->setAlignment(Qt::AlignLeft);

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



QVBoxLayout* EditViewEmployee::buildSections(const DynamicArray<AbstDataSection*>& dati_, bool editable){

    QVBoxLayout* layout = new QVBoxLayout(this);

    for(DynamicArray<AbstDataSection*>::const_iterator i = dati_.begin(); i!=dati_.end(); i++){
        layout->addWidget(new QPushButton("bohhh",this));}
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
