#include "widgets/employeelistelement.h"
void EmployeeListElement::setStyle(){
    QFile file(":/resources/employee_list_element.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    this->setStyleSheet(styleSheet);
}

void EmployeeListElement::paintEvent(QPaintEvent* event){
     QStyleOption opt;
     opt.init(this);
     QPainter p(this);
     style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
     QWidget::paintEvent(event);
}
void EmployeeListElement::mousePressEvent(QMouseEvent *e){
    e->accept();
    emit clicked(this);
}
void EmployeeListElement::mouseDoubleClickEvent( QMouseEvent * e ){
    e->accept();
    emit doubleClicked(this);
}

EmployeeListElement::EmployeeListElement(Employee *e, QWidget *parent): QWidget( parent ), e_(e){
    QHBoxLayout *layout = new QHBoxLayout( this );
    layout->setMargin( 0 );
    layout->setSpacing(0);
    layout->setAlignment(Qt::AlignLeft);
    this->setContentsMargins(20,20,20,20);
    this->setMouseTracking(true);

    //dati relativi alla persona
    name = new QLabel(QString(e->getNome().c_str()));
    surname = new QLabel(QString(e->getCognome().c_str()));
    date_of_birth = new QLabel(QString(static_cast<std::string>(e->getNascita()).c_str()));
    cf = new QLabel(QString(e->getCF().c_str()));

    //dati relativi al lavoro
    // seg fault inizio
    date_of_empl = new QLabel(QString(static_cast<std::string>(e->getDatiLavoratore().data_assunzione).c_str()));
    date_end_of_contract = new QLabel(QString(static_cast<std::string>(e->getDatiLavoratore().fine_contratto).c_str()));
    salary = new QLabel(QString(std::to_string(e->calcolaStipendio()).c_str()));
    weekly_hours = new QLabel(QString(std::to_string(e->getDatiLavoratore().ore_lavoro_sett).c_str()));
    // seg fault fine

    //dati specifici del lavoratore
    /*riparazioni = new QLabel(QString(static_cast<std::string>(e->).c_str()));
    percentualeCapo
    libreria
    percentualeBack
    gradoProfessionalita
    numSistemiGestiti
    numCriticitaRisolte
    linguaggio
    numProgConclusi
    ripSussistenti
    Produttivo*/

    name->setFixedWidth(150);
    surname->setFixedWidth(150);
    date_of_birth->setFixedWidth(150);
    cf->setFixedWidth(150);
    date_of_empl->setFixedWidth(150);
    date_end_of_contract->setFixedWidth(150);
    salary->setFixedWidth(150);
    weekly_hours->setFixedWidth(150);


    name->setWordWrap(true);
    surname->setWordWrap(true);
    date_of_birth->setWordWrap(true);
    cf->setWordWrap(true);
    date_of_empl->setWordWrap(true);
    date_end_of_contract->setWordWrap(true);
    salary->setWordWrap(true);
    weekly_hours->setWordWrap(true);

    layout->addWidget(name);
    layout->addWidget(surname);
    layout->addWidget(date_of_birth);
    layout->addWidget(cf);

    layout->addWidget(date_of_empl);
    layout->addWidget(date_end_of_contract);
    layout->addWidget(salary);
    layout->addWidget(weekly_hours);

    setStyle();
    updateStatus(false);
}
EmployeeListElement::~EmployeeListElement(){
    delete name;
    delete surname;
    delete date_of_birth;
    delete cf;

    delete date_of_empl;
    delete date_end_of_contract;
    delete salary;
    delete weekly_hours;
}
void EmployeeListElement::updateStatus(bool new_status){
    if(new_status)
        setObjectName("is_clicked");
    else
        setObjectName("is_not_clicked");
    setStyle();
}
Employee* EmployeeListElement::getEmployee() const{
    return e_;
}

void EmployeeListElement::changeVisibility(int prop, int visibility){
    if(prop & EmployeeListElement::Name)
        updateVisibility(&EmployeeListElement::name, visibility);
    if(prop & EmployeeListElement::Surname)
        updateVisibility(&EmployeeListElement::surname, visibility);
    if(prop & EmployeeListElement::CF)
        updateVisibility(&EmployeeListElement::cf, visibility);
    if(prop & EmployeeListElement::DateOfBirth)
        updateVisibility(&EmployeeListElement::date_of_birth, visibility);
    if(prop & EmployeeListElement::DateOfEmployment)
        updateVisibility(&EmployeeListElement::date_of_empl, visibility);
    if(prop & EmployeeListElement::DateEndOfContract)
        updateVisibility(&EmployeeListElement::date_end_of_contract, visibility);
    if(prop & EmployeeListElement::Salary)
        updateVisibility(&EmployeeListElement::salary, visibility);
    if(prop & EmployeeListElement::WeeklyHours)
        updateVisibility(&EmployeeListElement::weekly_hours, visibility);
}
void EmployeeListElement::updateVisibility(QLabel* EmployeeListElement::* elem, int visibility){
    visibility ? (this->*elem)->show() : (this->*elem)->hide();
}
