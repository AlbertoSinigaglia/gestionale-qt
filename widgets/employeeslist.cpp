#include "employeeslist.h"

QVBoxLayout* EmployeesList::getNewLayout(){
    auto layout = new QVBoxLayout(this);
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(0);
    layout->setAlignment(Qt::AlignTop);
    return layout;
}
EmployeesList::EmployeesList( QWidget *parent): QFrame( parent )
{
    this->setLayout(getNewLayout());
    this->setObjectName("frame-right");
    this->setContentsMargins(0,0,0,0);
    this->setStyleSheet("background-color:white;");

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
    // do something
}
void EmployeesList::childClickedEvent(EmployeeListElement* e){
    // do something
    emit ListElementDoubleClicked(e);
}
