#include "controller.h"
#include <QDebug>
Controller::Controller(QObject *parent, Gestionale* view_): QObject(parent), view(view_){
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
    QMessageBox::information(view.get(), "inserimento dipendente", "Stai per inserire un nuovo dipendente");
}
void Controller::openEmployeeInfo(Employee* e){
    QMessageBox::information(view.get(), "Info dipendente", QString("Stai modificando ") + QString(e->getNome().c_str()) + QString(" ") + QString(e->getCognome().c_str()));
}
void Controller::modifyButtonClicked(Employee * e){
    if(e){
        QMessageBox msgBox(view.get());
        msgBox.setText(QString("Stai modificando ") + QString(e->getNome().c_str()) + QString(" ") + QString(e->getCognome().c_str()));
        msgBox.setInformativeText("Vuoi che lo faccia esplodere?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        msgBox.exec();
    } else {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(view.get(), "Nessun dipendente selezionato", "Nessun dipendente selezionato, vuoi crearne uno?",QMessageBox::Yes|QMessageBox::No);
        if(reply == QMessageBox::Yes) this->insertNewEmployee() ;
    }
}

void Controller::importFile(){
    model->import(getFilePath("Carica Dipendenti"));
    view->updateList();
}
void Controller::exportToFile(){
    this->updateModel(true);
}
void Controller::exitApplication(){
    QMessageBox msgBox(view.get());
    msgBox.setText(QString("Sicuro di voler uscire?"));
    msgBox.setStyleSheet("QLabel{min-width: 300px;}");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    if(msgBox.exec() == QMessageBox::Yes)
        emit exitEvent();
}
