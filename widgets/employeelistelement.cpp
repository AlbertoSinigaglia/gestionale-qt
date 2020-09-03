#include "widgets/employeelistelement.h"
#include "models/headers/FullStack.h"
#include "models/headers/GUIDev.h"
#include "models/headers/ITSecurityDev.h"
#include "models/headers/Tecnico.h"
#include "models/support/Data.h"
#include <math.h>
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

EmployeeListElement::EmployeeListElement(Employee *e, QWidget *parent): QFrame( parent ), e_(e){
    QHBoxLayout *layout = new QHBoxLayout( this );
    layout->setMargin( 0 );
    layout->setSpacing(0);
    layout->setAlignment(Qt::AlignLeft);
    this->setMouseTracking(true);

    //dati relativi alla persona
    name = new QLabel(QString(e->getNome().c_str()).simplified());
    surname = new QLabel(QString(e->getCognome().c_str()).simplified());
    date_of_birth = new QLabel(QString(static_cast<std::string>(e->getNascita()).c_str()));
    cf = new QLabel(QString(e->getCF().c_str()));

    //dati relativi al lavoro
    date_of_empl = new QLabel(QString(static_cast<std::string>(e->getDatiLavoratore().data_assunzione).c_str()));
    date_end_of_contract = new QLabel(QString(static_cast<std::string>(e->getDatiLavoratore().fine_contratto).c_str()));
    salary = new QLabel(QString::number(e->calcolaStipendio())+" €");
    weekly_hours = new QLabel(QString(std::to_string(e->getDatiLavoratore().ore_lavoro_sett).c_str()));
    produttivo = new QLabel();


     bonus_stipendio = new QLabel(QString::number(static_cast<float>(round(e->bonusStipendio()*100))/100.0f)+" €");
     grado_esperienza= new QLabel(std::to_string(e->gradoEsperienza()).c_str());
     numero_righe_totali = new QLabel("");
     linguaggio = new QLabel("");
     if(auto p = dynamic_cast<Software*>(e)) {
         numero_righe_totali->setText(std::to_string(p->getDatiDeveloping().n_righe_totali).c_str());
         std::map<int, const char*> linguaggi = {
             {Conv::Linguaggio::CPP , "C++"},
             {Conv::Linguaggio::PHP , "PHP"},
             {Conv::Linguaggio::SQL , "SQL"},
             {Conv::Linguaggio::JAVA , "Java"},
             {Conv::Linguaggio::RUBY , "Ruby"},
             {Conv::Linguaggio::SWIFT , "Swift"},
             {Conv::Linguaggio::PYTHON , "Python"},
             {Conv::Linguaggio::JAVASCRIPT , "JavaScript"},
             {Conv::Linguaggio::TYPESCRIPT , "TypeScript"},
         };
         linguaggio->setText(linguaggi[p->getDatiDeveloping().linguaggio]);
     }

     percentuale_ripristino = new QLabel("");
     if(auto p = dynamic_cast<Manutenzione*>(e))
         percentuale_ripristino->setText(std::to_string(p->getDatiManutenzione().perc_ripristino_medio).c_str());

     numero_criticita_risolte = new QLabel("");
     if(auto p = dynamic_cast<ITSecurityDev*>(e))
         numero_criticita_risolte->setText(std::to_string(p->getDatiRipristinoSicurezza().n_criticita_risolte).c_str());
     ore_straordinari = new QLabel("");
     if(auto p = dynamic_cast<Tecnico*>(e))
         numero_righe_totali->setText(std::to_string(p->getDatiRiparazioneSistemi().ore_straordinari).c_str());
     auto width = 170;
     produttivo->setFixedWidth(width);
     name->setFixedWidth(width);
     surname->setFixedWidth(width);
     date_of_birth->setFixedWidth(width);
     cf->setFixedWidth(width);
     date_of_empl->setFixedWidth(width);
     date_end_of_contract->setFixedWidth(width);
     salary->setFixedWidth(width);
     weekly_hours->setFixedWidth(width);
     bonus_stipendio->setFixedWidth(width);
     grado_esperienza->setFixedWidth(width);
     numero_righe_totali->setFixedWidth(width);
     linguaggio->setFixedWidth(width);
     percentuale_ripristino->setFixedWidth(width);
     numero_criticita_risolte->setFixedWidth(width);
     ore_straordinari->setFixedWidth(width);

     name->setWordWrap(true);
     surname->setWordWrap(true);
     date_of_birth->setWordWrap(true);
     cf->setWordWrap(true);
     date_of_empl->setWordWrap(true);
     date_end_of_contract->setWordWrap(true);
     salary->setWordWrap(true);
     weekly_hours->setWordWrap(true);
     bonus_stipendio->setWordWrap(true);
     grado_esperienza->setWordWrap(true);
     numero_righe_totali->setWordWrap(true);
     linguaggio->setWordWrap(true);
     percentuale_ripristino->setWordWrap(true);
     numero_criticita_risolte->setWordWrap(true);
     ore_straordinari->setWordWrap(true);

     layout->addWidget(produttivo);
     layout->addWidget(name);
     layout->addWidget(surname);
     layout->addWidget(date_of_birth);
     layout->addWidget(cf);

     layout->addWidget(date_of_empl);
     layout->addWidget(date_end_of_contract);
     layout->addWidget(salary);
     layout->addWidget(weekly_hours);
     layout->addWidget(bonus_stipendio);
     layout->addWidget(grado_esperienza);
     layout->addWidget(numero_righe_totali);
     layout->addWidget(linguaggio);
     layout->addWidget(percentuale_ripristino);
     layout->addWidget(numero_criticita_risolte);
     layout->addWidget(ore_straordinari);
     changeVisibility(
                NumeroRigheTotali |
                Linguaggio |
                PercentualeRipristino |
                NumeroCriticitaRisolte |
                OreStraordinari , static_cast<int>(false)
     );
     QPixmap produttivo_image;
     QString path = e->produttivo() ? ":/resources/tick.png" : ":/resources/close.png";
     if(produttivo_image.load(path)){
         produttivo_image = produttivo_image.scaled(20, 20);
         produttivo->setPixmap(produttivo_image);
     }
     setStyle();
     updateStatus(false);
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

bool EmployeeListElement::lessThan(const EmployeeListElement &o, EmployeeListElement::FIELDS prop) const {
    if(prop & EmployeeListElement::Name)                    return e_->getDatiPersona().nome                        < o.e_->getDatiPersona().nome;
    if(prop & EmployeeListElement::Surname)                 return e_->getDatiPersona().cognome                     < o.e_->getDatiPersona().cognome;
    if(prop & EmployeeListElement::CF)                      return e_->getDatiPersona().CF                          < o.e_->getDatiPersona().CF;
    if(prop & EmployeeListElement::DateOfBirth)             return e_->getDatiPersona().nascita                     < o.e_->getDatiPersona().nascita;
    if(prop & EmployeeListElement::DateOfEmployment)        return e_->getDatiLavoratore().data_assunzione          < o.e_->getDatiLavoratore().data_assunzione;
    if(prop & EmployeeListElement::DateEndOfContract)       return e_->getDatiLavoratore().fine_contratto           < o.e_->getDatiLavoratore().fine_contratto;
    if(prop & EmployeeListElement::Salary)                  return e_->calcolaStipendio()                           < o.e_->calcolaStipendio();
    if(prop & EmployeeListElement::WeeklyHours)             return e_->getDatiLavoratore().ore_lavoro_sett          < o.e_->getDatiLavoratore().ore_lavoro_sett;
    if(prop & EmployeeListElement::Produttivo)              return static_cast<int>(e_->produttivo())               < static_cast<int>(o.e_->produttivo());
    if(prop & EmployeeListElement::BonusStipendio)          return e_->bonusStipendio()                             < o.e_->bonusStipendio();
    if(prop & EmployeeListElement::GradoEsperienza)         return e_->gradoEsperienza()                            < o.e_->gradoEsperienza();
    if(prop & EmployeeListElement::NumeroRigheTotali)       return numero_righe_totali->text().toInt()              < o.numero_righe_totali->text().toInt();
    if(prop & EmployeeListElement::Linguaggio)              return linguaggio->text()                               < o.linguaggio->text();
    if(prop & EmployeeListElement::PercentualeRipristino)   return percentuale_ripristino->text().toDouble()        < o.percentuale_ripristino->text().toDouble();
    if(prop & EmployeeListElement::NumeroRigheTotali)       return numero_righe_totali->text().toInt()              < o.numero_righe_totali->text().toInt();
    if(prop & EmployeeListElement::OreStraordinari)         return ore_straordinari->text().toInt()                 < o.ore_straordinari->text().toInt();
    return false;
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
    if(prop & EmployeeListElement::Produttivo)
        updateVisibility(&EmployeeListElement::produttivo, visibility);

    if(prop & EmployeeListElement::BonusStipendio)
        updateVisibility(&EmployeeListElement::bonus_stipendio, visibility);
    if(prop & EmployeeListElement::GradoEsperienza)
        updateVisibility(&EmployeeListElement::grado_esperienza, visibility);
    if(prop & EmployeeListElement::NumeroRigheTotali)
        updateVisibility(&EmployeeListElement::numero_righe_totali, visibility);
    if(prop & EmployeeListElement::Linguaggio)
        updateVisibility(&EmployeeListElement::linguaggio, visibility);
    if(prop & EmployeeListElement::PercentualeRipristino)
        updateVisibility(&EmployeeListElement::percentuale_ripristino, visibility);
    if(prop & EmployeeListElement::NumeroRigheTotali)
        updateVisibility(&EmployeeListElement::numero_righe_totali, visibility);
    if(prop & EmployeeListElement::OreStraordinari)
        updateVisibility(&EmployeeListElement::ore_straordinari, visibility);
    if(prop & EmployeeListElement::NumeroCriticitaRisolte)
        updateVisibility(&EmployeeListElement::numero_criticita_risolte, visibility);
}

void EmployeeListElement::updateVisibility(QLabel* EmployeeListElement::* elem, int visibility){
    visibility ? (this->*elem)->show() : (this->*elem)->hide();
}
