#ifndef EMPLOYEELISTELEMENT_H
#define EMPLOYEELISTELEMENT_H


#include <qwidget.h>
#include <QHBoxLayout>
#include <QPushButton>
#include <QFrame>
#include <QLabel>
#include <QFile>
#include <QStyleOption>
#include <QPainter>
#include "models/headers/Employee.h"
#include <QDebug>
#include <QPaintEvent>
#include <QMouseEvent>
class EmployeeListElement : public QWidget
{
    Q_OBJECT
    Employee* e_;
    QLabel* name;
    QLabel* surname;
    QLabel* date_of_birth;
    QLabel* cf;

    QLabel* date_of_empl;
    QLabel* date_end_of_contract;
    QLabel* salary;
    QLabel* weekly_hours;

    void setStyle(){
        QFile file(":/resources/employee_list_element.css");
        file.open(QFile::ReadOnly);
        QString styleSheet = QLatin1String(file.readAll());
        this->setStyleSheet(styleSheet);
    }
    void paintEvent(QPaintEvent* event){
         QStyleOption opt;
         opt.init(this);
         QPainter p(this);
         style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
         QWidget::paintEvent(event);
    }
    void mousePressEvent(QMouseEvent *e){
        e->accept();
        emit clicked(this);
    }
    void mouseDoubleClickEvent( QMouseEvent * e ){
        e->accept();
        emit doubleClicked(this);
    }
public:
    enum{
        Name = 1<<0,
        Surname = 1<<1,
        DateOfBirth = 1<<2,
        DateOfEmployment = 1<<3,
        DateEndOfContract = 1<<4,
    };
    Employee* getEmployee() const{
        return e_;
    }
    EmployeeListElement(Employee *e, QWidget *parent = 0): QWidget( parent ), e_(e)
    {
        QHBoxLayout *layout = new QHBoxLayout( this );
        layout->setMargin( 0 );
        layout->setSpacing(0);
        layout->setAlignment(Qt::AlignLeft);
        this->setContentsMargins(20,20,20,20);
        this->setMouseTracking(true);

        name = new QLabel(QString(e->getNome().c_str()));
        surname = new QLabel(QString(e->getCognome().c_str()));
        date_of_birth = new QLabel(QString(static_cast<std::string>(e->getNascita()).c_str()));
        cf = new QLabel(QString(e->getCF().c_str()));

        // seg fault inizio
        date_of_empl = new QLabel(QString(static_cast<std::string>(e->getDatiLavoratore().data_assunzione).c_str()));
        date_end_of_contract = new QLabel(QString(static_cast<std::string>(e->getDatiLavoratore().fine_contratto).c_str()));
        salary = new QLabel(QString(std::to_string(e->calcolaStipendio()).c_str()));
        weekly_hours = new QLabel(QString(std::to_string(e->getDatiLavoratore().ore_lavoro_sett).c_str()));
        // seg fault fine

        name->setFixedWidth(150);
        surname->setFixedWidth(150);
        date_of_birth->setFixedWidth(150);
        cf->setFixedWidth(150);
        date_of_empl->setFixedWidth(150);
        date_end_of_contract->setFixedWidth(150);
        salary->setFixedWidth(150);
        weekly_hours->setFixedWidth(150);

        layout->addWidget(name);
        layout->addWidget(surname);
        layout->addWidget(date_of_empl);
        layout->addWidget(cf);

        layout->addWidget(date_of_empl);
        layout->addWidget(date_end_of_contract);
        layout->addWidget(salary);
        layout->addWidget(weekly_hours);

        setStyle();
        updateStatus(false);
    }
    void updateStatus(bool new_status){
        if(new_status)
            setObjectName("is_clicked");
        else
            setObjectName("is_not_clicked");
        setStyle();
    }
    ~EmployeeListElement() {
        delete e_;
    }

signals:
    void clicked(EmployeeListElement*);
    void doubleClicked(EmployeeListElement *);
public slots:
    void changeVisibility(int prop, int visibility){
        if(prop & EmployeeListElement::Name)
            updateVisibility(&EmployeeListElement::name, visibility);
        if(prop & EmployeeListElement::Surname)
            updateVisibility(&EmployeeListElement::surname, visibility);
        if(prop & EmployeeListElement::DateOfBirth)
            updateVisibility(&EmployeeListElement::date_of_birth, visibility);
        if(prop & EmployeeListElement::DateOfEmployment)
            updateVisibility(&EmployeeListElement::date_of_empl, visibility);
        if(prop & EmployeeListElement::DateEndOfContract)
            updateVisibility(&EmployeeListElement::date_end_of_contract, visibility);
    }
private:
    void updateVisibility(QLabel* EmployeeListElement::* elem, int visibility){
        visibility ? (this->*elem)->show() : (this->*elem)->hide();
    }
};

#endif // EMPLOYEELISTELEMENT_H
