#include"editviewemployee.h"
#include<QDebug>

EditViewEmployee::EditViewEmployee(const DynamicArray<AbstDataSection*>& dati_, Utilizzo stato_utilizzo, QWidget *parent):
    QDialog(parent), stato(stato_utilizzo), isModify(false){

        topLevelWidget();
        this->setFixedSize(850, 730);
        mainLayout = new QVBoxLayout(this);
        mainLayout->setContentsMargins(20,20,20,20);
        mainLayout->setSpacing(12);
        mainLayout->setAlignment(Qt::AlignCenter);

        QScrollArea* impiegato = new QScrollArea(this);
        impiegato->setFixedSize(780,600);
        impiegato->setWidget(buildSections(dati_, impiegato));

        LSalvaEsci= new QHBoxLayout();
        Esci = new QPushButton("Esci", this);
        LSalvaEsci->addWidget(Esci);
        if(stato_utilizzo==Utilizzo::CREAZIONE)
            setModifed();

        mainLayout->addLayout(buildIntestazione());
        mainLayout->addWidget(impiegato);
        mainLayout->addLayout(LSalvaEsci);
        mainLayout->setAlignment(LSalvaEsci,Qt::AlignRight);


        connect(Esci, SIGNAL(clicked()), this, SIGNAL(closeDirect()));

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
    QHBoxLayout* titolo =new QHBoxLayout();

    titolo->addWidget(testo_titolo);
    titolo->addWidget(info);
    titolo->setAlignment(Qt::AlignLeft);

    return titolo;
}


void EditViewEmployee::chooseAndSend() const{

        for(auto i=lista_elementi.begin(); i!=lista_elementi.end(); i++){
            if((*i)->isModifyed())
               emit SaveDataConsiderd((*i)->getData());
            // Con getData() genero dei dati allocati nello heap di tipo AbstDataSection
            // Questi verranno gestiti ed eliminati dalla destinazione : il Controller
        }
    }



QFrame* EditViewEmployee::buildSections(const DynamicArray<AbstDataSection*>& dati_, QWidget* parent){

    QFrame* frame = new QFrame(parent);
    QVBoxLayout* layout = new QVBoxLayout(frame);
    layout->setSpacing(20);

    bool editable= (stato==Utilizzo::VISUALIZZA)? false: true;

    for(auto i = dati_.begin(); i!=dati_.end(); i++){
        AbstDataSection* objct = *i;
        AbstSectionElement* sezione=nullptr;

        if(typeid(*objct)==typeid(DatiPersona)) {
            sezione = new DatiPersonaElement(*dynamic_cast<const DatiPersona*>(objct), editable, this);
        }
        else if(typeid(*objct)==typeid(DatiLavoratore)) {
            sezione = new DatiLavoratoreElement(*dynamic_cast<const DatiLavoratore*>(objct), editable, this);
        }
        else if(typeid(*objct)==typeid(DatiDeveloping)) {
            sezione = new DatiDevelopingElement(*dynamic_cast<const DatiDeveloping*>(objct), editable, this);
        }
        else if(typeid(*objct)==typeid(DatiManutenzione)) {
            sezione = new DatiManutenzioneElement(*dynamic_cast<const DatiManutenzione*>(objct), editable, this);
        }
        else if(typeid(*objct)==typeid(DatiSistemi)) {
            sezione = new DatiSistemiElement(*dynamic_cast<const DatiSistemi*>(objct), editable, this);
        }
        else if(typeid(*objct)==typeid(DatiRiparazioneSistemi)) {
            sezione = new DatiRiparazioneSistemiElement(*dynamic_cast<const DatiRiparazioneSistemi*>(objct), editable, this);
        }
        else if(typeid(*objct)==typeid(DatiRipristinoSicurezza)) {
            sezione = new DatiRipristinoSicurezzaElement(*dynamic_cast<const DatiRipristinoSicurezza*>(objct), editable, this);
        }
        else if(typeid(*objct)==typeid(DatiLatoClient)) {
            sezione = new DatiLatoClientElement(*dynamic_cast<const DatiLatoClient*>(objct), editable, this);
        }
        else if(typeid(*objct)==typeid(DatiLatoServer)) {
            sezione = new DatiLatoServerElement(*dynamic_cast<const DatiLatoServer*>(objct), editable, this);
        }
        else if(typeid(*objct)==typeid(DatiFullStack)) {
            sezione = new DatiFullstackElement(*dynamic_cast<const DatiFullStack*>(objct), editable, this);
        }
        else if(typeid(*objct)==typeid(DatiInterfacceUtente)) {
            sezione = new DatiInterfacciaUtenteElement(*dynamic_cast<const DatiInterfacceUtente*>(objct), editable, this);
        }
        else if(typeid(*objct)==typeid(DatiDatabase)) {
            sezione = new DatiDatabaseElement(*dynamic_cast<const DatiDatabase*>(objct), editable, this);
        }

        connect(sezione, SIGNAL(setModifyed()),this, SLOT(setModifed()));
        layout->addWidget(sezione);
        lista_elementi.push_back(sezione);
        delete objct;
    }
    frame->setLayout(layout);
    return frame;
    }

bool EditViewEmployee::isModifyed() const{
    return isModify;
}

void EditViewEmployee::closeEvent(QCloseEvent *event)
{
    emit closeDirect();
}
void EditViewEmployee::setModifed(){
    if(!isModify){
        Esci->setText("Annulla");
        QPushButton* salva = new QPushButton("Salva ed Esci",this);
        LSalvaEsci->addWidget(salva);
        connect(salva,SIGNAL(clicked()),this,SIGNAL(saveAndClose()));

        isModify=true;
    }
}

EditViewEmployee::Utilizzo EditViewEmployee::getStato() const{
    return stato;
}
