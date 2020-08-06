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
class EmployeeListElement : public QFrame
{
    Q_OBJECT
    void setStyle(){
        QFile file(":/resources/employee_list_element.css");
        file.open(QFile::ReadOnly);
        QString styleSheet = QLatin1String(file.readAll());
        this->setStyleSheet(styleSheet);
    }
public:
    EmployeeListElement(Employee *e, QWidget *parent = 0): QFrame( parent )
    {
        QWidget::setObjectName("employeeListElement");
        QHBoxLayout *layout = new QHBoxLayout( this );
        layout->setMargin( 0 );
        layout->setSpacing(0);
        layout->setAlignment(Qt::AlignLeft);

        this->setContentsMargins(20,20,20,20);
        auto name = new QLabel(QString(e->getNome().c_str()));
        name->setFixedWidth(150);
        auto surname = new QLabel(QString(e->getCognome().c_str()));
        surname->setFixedWidth(150);
        auto date_of_empl = new QLabel(QString(static_cast<std::string>(e->getNascita()).c_str()));
        date_of_empl->setFixedWidth(150);
//        layout->addWidget( new QLabel("alberto") );
//        layout->addWidget( new QLabel("alberto") );
//        layout->addWidget( new QLabel("alberto") );
        setStyle();
    }
    ~EmployeeListElement() {}
    void paintEvent(QPaintEvent *)
    {
        QStyleOption opt;
        opt.init(this);
        QPainter p(this);
        style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    }
signals:
    void rewind();
    void play();
    void next();
    void stop();
};

#endif // EMPLOYEELISTELEMENT_H
