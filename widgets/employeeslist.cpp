#include "employeeslist.h"

QVBoxLayout* EmployeesList::getNewLayout(){
    auto layout = new QVBoxLayout(this);
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(0);
    layout->setAlignment(Qt::AlignTop);
    return layout;
}

EmployeesList::EmployeesList( QWidget *parent): QFrame( parent ), header(new TableHeader(this)){
    this->setLayout(getNewLayout());
    this->setObjectName("frame-right");
    this->setContentsMargins(0,0,0,0);
    this->setStyleSheet("background-color:white;");
    this->layout()->addWidget(header);
    std::vector<QString> fields{
        "Produttivo",
        "Nome",
        "Cognome",
        "Data di nascita",
        "Codice Fiscale",
        "Data di assunzione",
        "Data fine contratto",
        "Salario",
        "Ore lavoro settimanale",
        "Bonus stipendio",
        "Grado esperienza",
        "Numero righe totali",
        "Linguaggio",
        "Percentuale ripristino",
        "Numero criticità risolte",
        "Ore straordinari",
    };
    std::for_each(fields.begin(), fields.end(), [&](auto &el){
        header->addField(el);
    });
    header->show();

    header->setVisibility("Numero criticità risolte", static_cast<int>(false));
    header->setVisibility("Linguaggio", static_cast<int>(false));
    header->setVisibility("Percentuale ripristino", static_cast<int>(false));
    header->setVisibility("Numero righe totali", static_cast<int>(false));
    header->setVisibility("Ore straordinari", static_cast<int>(false));
}

void EmployeesList::setEmployees(const DynamicArray<Employee*>& empl){
    for(auto c: children)
        delete c;
    children.erase(children.begin(), children.end());
    for (auto e : empl) {
        auto el = new EmployeeListElement(e, this);
        children.push_back(el);
        this->layout()->addWidget(el);
        connect(this,SIGNAL(changeListAttributeVisibilityEvent(int, int)), el, SLOT(changeVisibility(int, int)));
        connect(el, SIGNAL(clicked(EmployeeListElement *)), this,SLOT(childPressedEvent(EmployeeListElement*)));
        connect(el, SIGNAL(doubleClicked(EmployeeListElement *)), this,SLOT(childClickedEvent(EmployeeListElement*)));
    }
}

Employee * EmployeesList::getCurrent() const{
    return current ? current->getEmployee() : nullptr;
}

void EmployeesList::changeListAttributeVisibility(int props, int visibility){
    if(props & EmployeeListElement::Produttivo) header->setVisibility("Produttivo", visibility);
    if(props & EmployeeListElement::Name) header->setVisibility("Nome", visibility);
    if(props & EmployeeListElement::Surname) header->setVisibility("Cognome", visibility);
    if(props & EmployeeListElement::CF) header->setVisibility("Codice Fiscale", visibility);
    if(props & EmployeeListElement::DateOfBirth) header->setVisibility("Data di nascita", visibility);
    if(props & EmployeeListElement::DateOfEmployment) header->setVisibility("Data di assunzione", visibility);
    if(props & EmployeeListElement::DateEndOfContract) header->setVisibility("Data fine contratto", visibility);
    if(props & EmployeeListElement::Salary) header->setVisibility("Salario", visibility);
    if(props & EmployeeListElement::WeeklyHours) header->setVisibility("Ore lavoro settimanale", visibility);
    if(props & EmployeeListElement::BonusStipendio)header->setVisibility("Bonus stipendio", visibility);
    if(props & EmployeeListElement::GradoEsperienza)header->setVisibility("Grado esperienza", visibility);

    if(props & EmployeeListElement::NumeroRigheTotali)header->setVisibility("Numero righe totali", visibility);
    if(props & EmployeeListElement::Linguaggio)header->setVisibility("Linguaggio", visibility);
    if(props & EmployeeListElement::PercentualeRipristino)header->setVisibility("Percentuale ripristino", visibility);
    if(props & EmployeeListElement::OreStraordinari)header->setVisibility("Ore straordinari", visibility);
    if(props & EmployeeListElement::NumeroCriticitaRisolte)header->setVisibility("Numero criticità risolte", visibility);
    emit changeListAttributeVisibilityEvent(props, visibility);
}

void EmployeesList::childPressedEvent(EmployeeListElement* e){
    if(e != current){
        current = e;
        for(auto& e : children)
            if(current != e)
                e->updateStatus(false);
        current->updateStatus(true);
    } else {
        current->updateStatus(false);
        current = nullptr;
    }
}

void EmployeesList::childClickedEvent(EmployeeListElement* e){
    emit ListElementDoubleClicked(e);
}

