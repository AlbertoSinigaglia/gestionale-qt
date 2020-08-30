#include"editviewemployee.h"

void EditViewEmployee::setStyle(QWidget* w){
    QFile file(":/resources/edit_view_employee.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    w->setStyleSheet(styleSheet);
}

EditViewEmployee::EditViewEmployee(const DynamicArray<AbstDataSection*>& dati_,QString type_employee, Utilizzo stato_utilizzo, QWidget *parent):
    QDialog(parent), stato(stato_utilizzo), isModify(false){
        setStyle(this);
        topLevelWidget();
        mainLayout = new QVBoxLayout(this);
        mainLayout->setContentsMargins(0,10,0,10);
        mainLayout->setSpacing(12);
        mainLayout->setAlignment(Qt::AlignCenter);

        QScrollArea* impiegato = new QScrollArea(this);
        impiegato->setFixedWidth(970);
        impiegato->setWidget(buildSections(dati_, impiegato));
        impiegato->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        LSalvaEsci= new QHBoxLayout();
        Esci = new QPushButton("Esci", this);
        Esci->setObjectName("bottom-button");
        LSalvaEsci->addWidget(Esci);
        if(stato_utilizzo==Utilizzo::CREAZIONE)
            setModifed();

        mainLayout->addWidget(buildIntestazione(type_employee));
        mainLayout->addWidget(impiegato);
        mainLayout->addLayout(LSalvaEsci);
        mainLayout->setAlignment(LSalvaEsci,Qt::AlignRight);

        connect(Esci, SIGNAL(clicked()), this, SIGNAL(closeDirect()));
        setLayout(mainLayout);
        this->setMaximumWidth(this->width() + 30);
        this->resize(this->minimumHeight(), 800);
}

QWidget* EditViewEmployee::buildIntestazione(QString type_employee){
    QLabel* testo_titolo;
    Suggerimento* info=nullptr;
    QString tx_info= QString("Gli attributi seguiti dal suffisso: <nel mese> indicano dati accumulati dall'inizio del mese, gli altri sono accumulativi dalla data assunzione (o estemporanei)\n");
    if(stato==Utilizzo::MODIFICA){
        testo_titolo = new QLabel(QString("Modifica Impiegato"),this);
    }else if(stato==Utilizzo::CREAZIONE){
        testo_titolo = new QLabel(QString("Creazione Impiegato"),this);
        tx_info="1) "+tx_info+"2) I valori di default degli attributi indicano dei valori medi rispetto a precedenti inserimenti, essi pongono luce su equilibri di design aziendale preesistenti";
    }else{
        testo_titolo = new QLabel(QString("Visualizza Impiegato"),this);
    }
    info = new Suggerimento(tx_info);

    QWidget* intestazione = new QWidget(this);
    QHBoxLayout* titolo =new QHBoxLayout(intestazione);

    titolo->addWidget(testo_titolo);
    titolo->addWidget(new QLabel(type_employee,this));
    titolo->addWidget(info);
    titolo->setAlignment(Qt::AlignLeft);
    intestazione->setLayout(titolo);
    return intestazione;
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
    bool editable = stato!=Utilizzo::VISUALIZZA;
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

void EditViewEmployee::closeEvent(QCloseEvent *event){
    event->accept();
    emit closeDirect();
}

void EditViewEmployee::setModifed(){
    if(!isModify){
        Esci->setText("Annulla");
        QPushButton* salva = new QPushButton("Salva ed Esci",this);
        Esci->setObjectName("bottom-button");
        salva->setObjectName("bottom-button");
        setStyle(salva);
        LSalvaEsci->addWidget(salva);
        connect(salva,SIGNAL(clicked()),this,SIGNAL(saveAndClose()));
        isModify=true;
    }
}

EditViewEmployee::Utilizzo EditViewEmployee::getStato() const{
    return stato;
}
