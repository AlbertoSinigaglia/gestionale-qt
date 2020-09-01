#include "employeeslist.h"

const std::map<unsigned int, const char *> EmployeesList::fields = {
    {EmployeeListElement::Produttivo, "Produttivo"},
    {EmployeeListElement::Name, "Nome"},
    {EmployeeListElement::Surname, "Cognome"},
    {EmployeeListElement::CF, "Codice Fiscale"},
    {EmployeeListElement::DateOfBirth, "Data di nascita"},
    {EmployeeListElement::DateOfEmployment, "Data di assunzione"},
    {EmployeeListElement::DateEndOfContract, "Data fine contratto"},
    {EmployeeListElement::Salary, "Salario"},
    {EmployeeListElement::WeeklyHours, "Ore lavoro settimanale"},
    {EmployeeListElement::BonusStipendio, "Bonus stipendio"},
    {EmployeeListElement::GradoEsperienza, "Grado esperienza"},
    {EmployeeListElement::NumeroRigheTotali, "Numero righe totali"},
    {EmployeeListElement::Linguaggio, "Linguaggio"},
    {EmployeeListElement::PercentualeRipristino, "Percentuale ripristino"},
    {EmployeeListElement::OreStraordinari, "Ore straordinari"},
    {EmployeeListElement::NumeroCriticitaRisolte, "Numero criticità risolte"},
};
const std::vector<const char *> EmployeesList::ordered_fields = {
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

QVBoxLayout* EmployeesList::getNewLayout(){
    auto layout = new QVBoxLayout(this);
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(0);
    layout->setAlignment(Qt::AlignTop);
    return layout;
}
#include <QDebug>
EmployeesList::EmployeesList( QWidget *parent): QFrame( parent ), header(new TableHeader(this)){
    this->setLayout(getNewLayout());
    this->setObjectName("frame-right");
    this->setContentsMargins(0,0,0,0);
    this->setStyleSheet("background-color:white;");
    this->layout()->addWidget(header);
    std::for_each(ordered_fields.begin(), ordered_fields.end(), [&](auto &el){
        header->addField(el);
    });
    header->show();

    header->setVisibility(fields.at(EmployeeListElement::NumeroCriticitaRisolte), static_cast<int>(false));
    header->setVisibility(fields.at(EmployeeListElement::Linguaggio), static_cast<int>(false));
    header->setVisibility(fields.at(EmployeeListElement::PercentualeRipristino), static_cast<int>(false));
    header->setVisibility(fields.at(EmployeeListElement::NumeroRigheTotali), static_cast<int>(false));
    header->setVisibility(fields.at(EmployeeListElement::OreStraordinari), static_cast<int>(false));
}

void EmployeesList::filter(std::function<bool (Employee *)> f){
    if(current && f(current->getEmployee())) {
        current->updateStatus(false);
        current = nullptr;
    }
    for(auto &e:children){
        if(f(e->getEmployee()))
            e->show();
        else
            e->hide();
    }
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
    if(props & EmployeeListElement::Produttivo) header->setVisibility(fields.at(EmployeeListElement::Produttivo), visibility);
    if(props & EmployeeListElement::Name) header->setVisibility(fields.at(EmployeeListElement::Name), visibility);
    if(props & EmployeeListElement::Surname) header->setVisibility(fields.at(EmployeeListElement::Surname), visibility);
    if(props & EmployeeListElement::CF) header->setVisibility(fields.at(EmployeeListElement::CF), visibility);
    if(props & EmployeeListElement::DateOfBirth) header->setVisibility(fields.at(EmployeeListElement::DateOfBirth), visibility);
    if(props & EmployeeListElement::DateOfEmployment) header->setVisibility(fields.at(EmployeeListElement::DateOfEmployment), visibility);
    if(props & EmployeeListElement::DateEndOfContract) header->setVisibility(fields.at(EmployeeListElement::DateEndOfContract), visibility);
    if(props & EmployeeListElement::Salary) header->setVisibility(fields.at(EmployeeListElement::Salary), visibility);
    if(props & EmployeeListElement::WeeklyHours) header->setVisibility(fields.at(EmployeeListElement::WeeklyHours), visibility);
    if(props & EmployeeListElement::BonusStipendio)header->setVisibility(fields.at(EmployeeListElement::BonusStipendio), visibility);
    if(props & EmployeeListElement::GradoEsperienza)header->setVisibility(fields.at(EmployeeListElement::GradoEsperienza), visibility);

    if(props & EmployeeListElement::NumeroRigheTotali)header->setVisibility(fields.at(EmployeeListElement::NumeroRigheTotali), visibility);
    if(props & EmployeeListElement::Linguaggio)header->setVisibility(fields.at(EmployeeListElement::Linguaggio), visibility);
    if(props & EmployeeListElement::PercentualeRipristino)header->setVisibility(fields.at(EmployeeListElement::PercentualeRipristino), visibility);
    if(props & EmployeeListElement::OreStraordinari)header->setVisibility(fields.at(EmployeeListElement::OreStraordinari), visibility);
    if(props & EmployeeListElement::NumeroCriticitaRisolte)header->setVisibility(fields.at(EmployeeListElement::NumeroCriticitaRisolte), visibility);
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

void EmployeesList::orderBy(EmployeeListElement::FIELDS field){
    std::sort(children.begin(), children.end(), [&](auto &f, auto& s){ return f->lessThan(*s, field);});
    std::vector<Employee*> v;
    std::transform(children.begin(), children.end(), std::back_inserter(v), [](auto&el){ return el->getEmployee();});
    setEmployees(DynamicArray<Employee*>(v.begin(), v.end()));
}
