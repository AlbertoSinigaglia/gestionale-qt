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
class EmployeeListElement : public QFrame
{
    Q_OBJECT
public:
    EmployeeListElement( QWidget *parent = 0): QFrame( parent )
    {
        QWidget::setObjectName("employeeListElement");
        QHBoxLayout *layout = new QHBoxLayout( this );
        layout->setMargin( 0 );
        QFile file(":/resources/employee_list_element.css");
        file.open(QFile::ReadOnly);
        QString styleSheet = QLatin1String(file.readAll());
        this->setStyleSheet(styleSheet);
        this->setContentsMargins(20,20,20,20);
        layout->setSpacing(0);
        layout->setAlignment(Qt::AlignLeft);
        auto name = new QLabel("Alberto");
        name->setFixedWidth(150);
        auto surname = new QLabel("Sinigaglia");
        surname->setFixedWidth(150);
        auto date_of_empl = new QLabel("14/02/21");
        date_of_empl->setFixedWidth(150);
        layout->addWidget( name );
        layout->addWidget( surname );
        layout->addWidget( date_of_empl );
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
