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
    void setStyle(){
        QFile file(":/resources/employee_list_element.css");
        file.open(QFile::ReadOnly);
        QString styleSheet = QLatin1String(file.readAll());
        this->setStyleSheet(styleSheet);
    }
    void paintEvent(QPaintEvent* event)
    {
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

        auto name = new QLabel(QString(e->getNome().c_str()));
        name->setFixedWidth(150);
        auto surname = new QLabel(QString(e->getCognome().c_str()));
        surname->setFixedWidth(150);
        auto date_of_empl = new QLabel(QString(static_cast<std::string>(e->getNascita()).c_str()));
        date_of_empl->setFixedWidth(150);


        layout->addWidget(name);
        layout->addWidget(surname);
        layout->addWidget(date_of_empl);
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
};

#endif // EMPLOYEELISTELEMENT_H
