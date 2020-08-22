#include"editviewemployee.h"

EditViewEmployee::EditViewEmployee(const DynamicArray<AbstDataSection*>& dati_, Utilizzo stato_utilizzo, QWidget *parent):
    QWidget(parent), stato(stato_utilizzo), isModify(false){

        this->setFixedSize(800, 700);
        mainLayout = new QVBoxLayout(this);
        mainLayout->setContentsMargins(0,0,0,0);
        mainLayout->setSpacing(10);
        mainLayout->setAlignment(Qt::AlignCenter);

        QScrollArea* impiegato = new QScrollArea(this);
        impiegato->setFixedSize(750,600);
        impiegato->setLayout(buildSections(dati_, impiegato));


        SalvaEsci = new QPushButton("Esci", this);

        mainLayout->addLayout(buildIntestazione());
        mainLayout->addWidget(impiegato);
        mainLayout->addWidget(SalvaEsci);
        mainLayout->setAlignment(SalvaEsci,Qt::AlignRight);


        connect(SalvaEsci, SIGNAL(clicked()), this, SIGNAL(handleExitEditView()));

        setLayout(mainLayout);
        }


QHBoxLayout* EditViewEmployee::buildIntestazione(){

    QLabel* testo_titolo;
    Suggerimento* info=nullptr;
    QString tx_info= QString("Gli attributi seguiti dal suffisso: <nel mese> indicano dati accumulati dall'inizio del mese, gli altri sono accumulativi dalla data assunzione (o estemporanei)\n");

    if(stato==Utilizzo::MODIFICA){
        testo_titolo = new QLabel(QString("Modifica Impiegato"));
    }else if(stato==Utilizzo::CREAZIONE){
        testo_titolo = new QLabel(QString("Creazione Impiegato"));
        tx_info="1) "+tx_info+"2) I valori di default degli attributi indicano dei valori medi rispetto a precedenti inserimenti, essi pongono luce su equilibri di design aziendale preesistenti";
    }else{
        testo_titolo = new QLabel(QString("Visualizza Impiegato"));
    }

    info = new Suggerimento(tx_info);
    testo_titolo->setFixedWidth(200);
    QHBoxLayout* titolo =new QHBoxLayout(this);

    titolo->addWidget(testo_titolo);
    titolo->addWidget(info);
    titolo->setAlignment(Qt::AlignLeft);

    return titolo;
}


void EditViewEmployee::chooseAndSend() const{

        for(auto i=lista_elementi.begin(); i!=lista_elementi.end(); i++){
            if((*i)->isModifyed())
            emit SaveDataConsiderd((*i)->getData());
            //Con getData() genero dei dati allocati nello heap di tipo AbstDataSection
            //Questi verranno gestiti ed eliminati dalla destinazione : il Controller
        }
    }



QVBoxLayout* EditViewEmployee::buildSections(const DynamicArray<AbstDataSection*>& dati_, QWidget* parent){

    QVBoxLayout* layout = new QVBoxLayout(parent);
    layout->setSpacing(20);

    bool editable= (stato==Utilizzo::VISUALIZZA)? false: true;

    for(auto i = dati_.begin(); i!=dati_.end(); i++){
        AbstDataSection* objct = *i;
        AbstSectionElement* sezione;

        if(typeid(objct)==typeid(Persona)) {
            sezione = new DatiPersonaElement(*dynamic_cast<const DatiPersona*>(objct), editable, this);
        }
        else if(typeid(objct)==typeid(Employee)) {
            sezione = new DatiLavoratoreElement(*dynamic_cast<const DatiLavoratore*>(objct), editable, this);
        }
        else if(typeid(objct)==typeid(Software)) {
            sezione = new DatiDevelopingElement(*dynamic_cast<const DatiDeveloping*>(objct), editable, this);
        }
        else if(typeid(objct)==typeid(Manutenzione)) {
            sezione = new DatiManutenzioneElement(*dynamic_cast<const DatiManutenzione*>(objct), editable, this);
        }
        else if(typeid(objct)==typeid(Hardware)) {
            sezione = new DatiSistemiElement(*dynamic_cast<const DatiSistemi*>(objct), editable, this);
        }
        else if(typeid(objct)==typeid(Tecnico)) {
            sezione = new DatiRiparazioneSistemiElement(*dynamic_cast<const DatiRiparazioneSistemi*>(objct), editable, this);
        }
        else if(typeid(objct)==typeid(ITSecurityDev)) {
            sezione = new DatiRipristinoSicurezzaElement(*dynamic_cast<const DatiRipristinoSicurezza*>(objct), editable, this);
        }
        else if(typeid(objct)==typeid(FrontDev)) {
            sezione = new DatiLatoClientElement(*dynamic_cast<const DatiLatoClient*>(objct), editable, this);
        }
        else if(typeid(objct)==typeid(BackDev)) {
            sezione = new DatiLatoServerElement(*dynamic_cast<const DatiLatoServer*>(objct), editable, this);
        }
        else if(typeid(objct)==typeid(FullStack)) {
            sezione = new DatiFullstackElement(*dynamic_cast<const DatiFullStack*>(objct), editable, this);
        }
        else if(typeid(objct)==typeid(GUIDev)) {
            sezione = new DatiInterfacciaUtenteElement(*dynamic_cast<const DatiInterfacceUtente*>(objct), editable, this);
        }
        else if(typeid(objct)==typeid(DBDev)) {
            sezione = new DatiDatabaseElement(*dynamic_cast<const DatiDatabase*>(objct), editable, this);
        }

        connect(sezione, SIGNAL(setModifyed()),this, SLOT(setModifed()));
        layout->addWidget(sezione);
        lista_elementi.push_back(sezione);
        delete objct;
    }

    return layout;
    }

bool EditViewEmployee::isModifyed() const{
    return isModify;
}


void EditViewEmployee::setModifed(){
    isModify=true;
    SalvaEsci->setText("Esci...");
}
