#ifndef ABSTATTRIBUTE_H
#define ABSTATTRIBUTE_H

#include <QWidget>
#include<QHBoxLayout>
#include<QLabel>
#include"widgets/suggerimento.h"

class AbstAttribute : public QWidget
{
    Q_OBJECT
public:
    explicit AbstAttribute(QString nome, bool editable=false, QWidget *parent = nullptr);

    QString getValue() const;

    void insertInfo(QString info);

protected:

        QHBoxLayout* layout;
        QLabel* str_value;
        bool editable;

};

#endif // ABSTATTRIBUTE_H
