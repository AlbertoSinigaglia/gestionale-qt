#ifndef SLIDEATTRIBUTE_H
#define SLIDEATTRIBUTE_H

#include <QWidget>
#include<QString>
#include<QLabel>
#include<QHBoxLayout>
#include<QSlider>

#include"widgets/Edit_View_Employee/abstattribute.h"

class SlideAttribute : public AbstAttribute{
Q_OBJECT

public:
    explicit SlideAttribute(QString nome, double valore_, double start_=0.0, double end_=1.0, unsigned int cifre_approx_=0, bool editable=false, QWidget *parent = nullptr);

private:

    double start,end;
    unsigned int cifre_approx;

    QSlider* setter_num;

private slots:
    void setValue(double v=0.0);

signals:

    void isModify();

};

#endif // SLIDEATTRIBUTE_H
