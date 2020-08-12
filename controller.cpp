#include "controller.h"
Controller::Controller(QObject *parent, Gestionale* view_): QObject(parent), view(view_){
    view->show();
    model = std::make_shared<EmployeesManagement>(getFilePath("Carica Dipendenti"));
    view->setModel(model);
    view->updateList();
    connect(view.get(), SIGNAL(modifyEmployeeEvent(Employee*)), this, SLOT(modifyButtonClicked(Employee *)));
    connect(view.get(), SIGNAL(insertEmployeeEvent()), this, SLOT(insertNewEmployee()));
    connect(view.get(), SIGNAL(deleteEmployeeEvent(Employee *)), this, SLOT(deleteEmployee(Employee *)));
    connect(view.get(), SIGNAL(employeeListElementDoubleClickedEvent(Employee*)), this, SLOT(openEmployeeInfo(Employee*)));
}
void Controller::updateModel(bool want_to_export){
    QString path =
            want_to_export ?
            QFileDialog::getOpenFileName(view.get(),"Salvataggio Dipendenti", "", "Files (*.qcsv)"):
            model->getOriginalSource();
    model->save(path);
}

QString Controller::getFilePath(const QString info) const{
    return QFileDialog::getOpenFileName(view.get(),info, "", "Files (*.qcsv)");
}
void Controller::deleteEmployee(Employee * e){
    if(e){
        auto employees = model->getEmployees();
        for(auto it = employees->begin(); it != employees->end(); ++it){
            if(*it == e){
                employees->erase(it);
                break;
            }
        }
        view->updateList();
        updateModel();
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
