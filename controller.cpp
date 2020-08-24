#include "controller.h"
#include <QDebug>
Controller::Controller(QObject *parent, Gestionale* view_):
    QObject(parent), view(view_), edit_view(nullptr), considered_employee(nullptr){
        view->show();
        model = std::make_shared<EmployeesManagement>();
        view->setModel(model);
        view->updateList();
        connect(view.get(), SIGNAL(modifyEmployeeEvent(Employee*)), this, SLOT(modifyButtonClicked(Employee *)));
        connect(view.get(), SIGNAL(insertEmployeeEvent()), this, SLOT(insertNewEmployee()));
        connect(view.get(), SIGNAL(deleteEmployeeEvent(Employee *)), this, SLOT(deleteEmployee(Employee *)));
        connect(view.get(), SIGNAL(employeeListElementDoubleClickedEvent(Employee*)), this, SLOT(openEmployeeInfo(Employee*)));
        connect(view.get(), &Gestionale::importFileRequestEvent, this, &Controller::importFile);
        connect(view.get(), &Gestionale::exportToFileRequestEvent, this, &Controller::exportToFile);
        connect(view.get(), &Gestionale::exitApplicationEvent, this, &Controller::exitApplication);

}
bool Controller::updateModel(bool want_to_export){
    bool sent = false;
    do{
        QString path =
                want_to_export ?
                QFileDialog::getSaveFileName(view.get(),"Salvataggio Dipendenti", "", "Files (*.qcsv)"):
                model->getOriginalSource();
        try {
            model->save(path);
            return true;
        } catch (...) {
            QMessageBox msgBox(view.get());
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setText(QString("Errore durante il salvataggio"));
            msgBox.setStyleSheet("QLabel{min-width: 300px;}");
            msgBox.setInformativeText("Il path fornito non è valido o il file non è accessibile, vuoi selezionare un'altro file per il salvataggio?");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::No);
            sent = msgBox.exec() == QMessageBox::Yes;
        }
    } while(sent);
    return false;
}

QString Controller::getFilePath(const QString info) const{
    return QFileDialog::getOpenFileName(view.get(),info, "", "Files (*.qcsv)");
}
void Controller::deleteEmployee(Employee * e){
    if(e){
        auto backup = DynamicArray<Employee*>(*(model->getEmployees()));
        auto employees = model->getEmployees();
        for(auto it = employees->begin(); it != employees->end(); ++it){
            if(*it == e){
                employees->erase(it);
                break;
            }
        }
        if(updateModel(false))
            view->updateList();
        else
            *(model->getEmployees()) = backup;
    }
}
void Controller::insertNewEmployee(){
    TypeCreation scelta_inserimento;
    scelta_inserimento.setModal(true);
    scelta_inserimento.exec();
    qDebug() << "test";
}

void Controller::setTypeInsert(QString q){
    if(q=="GUIDev"){
        considered_employee=new GUIDev(Persona(),DatiLavoratore(),DatiDeveloping(),DatiLatoClient(),DatiInterfacceUtente());
    }else if(q=="DatBaseDev"){
        considered_employee=new DBDev(Persona(),DatiLavoratore(),DatiDeveloping(),DatiLatoServer(),DatiDatabase());
    }else if(q=="FullStack"){
        considered_employee=new FullStack(Persona(),DatiLavoratore(),DatiDeveloping(),DatiLatoServer(),DatiLatoClient(),DatiFullStack());
    }else if(q=="ITSecurityDev"){
        considered_employee=new ITSecurityDev(Persona(),DatiLavoratore(),DatiManutenzione(),DatiDeveloping(),DatiRipristinoSicurezza());
    }else if(q=="Tecnico"){
        considered_employee=new Tecnico(Persona(),DatiLavoratore(),DatiManutenzione(),DatiSistemi(),DatiRiparazioneSistemi());
    }else return;

    OpenEditView(considered_employee,EditViewEmployee::Utilizzo::CREAZIONE);
}

void Controller::openEmployeeInfo(Employee* e){
    OpenEditView(e,EditViewEmployee::Utilizzo::VISUALIZZA);
}
void Controller::modifyButtonClicked(Employee * e){
    if(e){
        OpenEditView(e,EditViewEmployee::Utilizzo::MODIFICA);
    } else {
        auto reply = QMessageBox::question(view.get(), "Nessun dipendente selezionato", "Nessun dipendente selezionato, vuoi crearne uno?",QMessageBox::Yes|QMessageBox::No);
        if(reply == QMessageBox::Yes) this->insertNewEmployee() ;
    }
}

void Controller::importFile(){
    auto be_sure = true;
    if(!view->disableSaveEnableImport()){
        be_sure = (QMessageBox::question(view.get(), "Conferma importazione", "I dipendenti salvati nel file che verrà selezionato, saranno inseriti nel file corrente, confermi di voler procedere?",QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes);
    }
    if(be_sure){
        model->import(getFilePath("Carica Dipendenti"));
        updateModel(false);
        view->updateList();
    }
}
void Controller::exportToFile(){
    this->updateModel(true);
}
void Controller::exitApplication(){
    if(edit_view) ExitEditView();
    QMessageBox msgBox(view.get());
    msgBox.setText(QString("Sicuro di voler uscire?"));
    msgBox.setStyleSheet("QLabel{min-width: 300px;}");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    if(msgBox.exec() == QMessageBox::Yes)
        emit exitEvent();
}





void Controller::OpenEditView(Employee* considerato, EditViewEmployee::Utilizzo stato_utilizzo){

    considered_employee = considerato;
    view->setEnabled(false);

    edit_view = new EditViewEmployee(EmployeesManagement::serializeEmployee(considered_employee), stato_utilizzo);
    edit_view->setModal(true);
    edit_view->show();
    connect(edit_view, SIGNAL(handleExitEditView()), this, SLOT(ExitEditView()));
    connect(edit_view, SIGNAL(SaveDataConsiderd(AbstDataSection*)), this, SLOT(SaveChanges(AbstDataSection*)));

}



void Controller::SaveChanges(AbstDataSection* data_){

      if(typeid(*data_)==typeid(DatiPersona)){
        considered_employee->setDatiPersona(*dynamic_cast<DatiPersona*>(data_));
      }else if(typeid(*data_)==typeid(DatiLavoratore)){
        considered_employee->setDatiLavoratore(*dynamic_cast<DatiLavoratore*>(data_));
      }else if(typeid(*data_)==typeid(DatiDeveloping)){
        DatiDeveloping* p = dynamic_cast<DatiDeveloping*>(data_);
        if(p) dynamic_cast<Software*>(considered_employee)->setDatiDeveloping(*p);
            else {throw std::invalid_argument("Inserimento non valido");}
      }else if(typeid(*data_)==typeid(DatiLatoServer)){
        DatiLatoServer* p = dynamic_cast<DatiLatoServer*>(data_);
        if(p) dynamic_cast<BackDev*>(considered_employee)->setDatiLatoServer(*p);
            else {throw std::invalid_argument("Inserimento non valido");}
      }else  if(typeid(*data_)==typeid(DatiLatoClient)){
        DatiLatoClient* p = dynamic_cast<DatiLatoClient*>(data_);
        if(p) dynamic_cast<FrontDev*>(considered_employee)->setDatiLatoClient(*p);
              else {throw std::invalid_argument("Inserimento non valido");}
      }else  if(typeid(*data_)==typeid(DatiFullStack)){
          DatiFullStack* p = dynamic_cast<DatiFullStack*>(data_);
          if(p) dynamic_cast<FullStack*>(considered_employee)->setDatiFullStack(*p);
              else {throw std::invalid_argument("Inserimento non valido");}
      }else  if(typeid(*data_)==typeid(DatiDatabase)){
          DatiDatabase* p = dynamic_cast<DatiDatabase*>(data_);
          if(p) dynamic_cast<DBDev*>(considered_employee)->setDatiDatabase(*p);
              else {throw std::invalid_argument("Inserimento non valido");}
      }else  if(typeid(*data_)==typeid(DatiInterfacceUtente)){
          DatiInterfacceUtente* p = dynamic_cast<DatiInterfacceUtente*>(data_);
          if(p) dynamic_cast<GUIDev*>(considered_employee)->setDatiInterfacceUtente(*p);
              else {throw std::invalid_argument("Inserimento non valido");}
      }else  if(typeid(*data_)==typeid(DatiManutenzione)){
          DatiManutenzione* p = dynamic_cast<DatiManutenzione*>(data_);
          if(p) dynamic_cast<Manutenzione*>(considered_employee)->setDatiManutenzione(*p);
              else {throw std::invalid_argument("Inserimento non valido");}
      }else  if(typeid(*data_)==typeid(DatiSistemi)){
          DatiSistemi* p = dynamic_cast<DatiSistemi*>(data_);
          if(p) dynamic_cast<Hardware*>(considered_employee)->setDatiSistemi(*p);
              else {throw std::invalid_argument("Inserimento non valido");}
      }else  if(typeid(*data_)==typeid(DatiRiparazioneSistemi)){
          DatiRiparazioneSistemi* p = dynamic_cast<DatiRiparazioneSistemi*>(data_);
          if(p) dynamic_cast<Tecnico*>(considered_employee)->setDatiRiparazioneSistemi(*p);
              else {throw std::invalid_argument("Inserimento non valido");}
      }else  if(typeid(*data_)==typeid(DatiRipristinoSicurezza)){
          DatiRipristinoSicurezza* p = dynamic_cast<DatiRipristinoSicurezza*>(data_);
          if(p) dynamic_cast<ITSecurityDev*>(considered_employee)->setDatiRipristinoSicurezza(*p);
              else {throw std::invalid_argument("Inserimento non valido");}
            }

    delete data_;
}



void Controller::ExitEditView(){

    bool is_creazione = edit_view->getStato()==EditViewEmployee::Utilizzo::CREAZIONE;

    if(edit_view->isModifyed()||is_creazione){

        QString testo=(is_creazione)? "Creazione":"Modifica";
        QMessageBox::StandardButton reply= QMessageBox::question(edit_view, testo,"Vuoi che salvi le modifiche?",QMessageBox::Save | QMessageBox::Discard);

        if(reply==QMessageBox::Save){
            edit_view->chooseAndSend();

            if(is_creazione)
                model->addEmployee(considered_employee);

            view->updateList();
        }else if(is_creazione) delete considered_employee;

    }

    considered_employee=nullptr;
    delete edit_view;
    edit_view=nullptr;
    view->setEnabled(true);
}


