#ifndef ABSTSECTIONELEMENT_H
#define ABSTSECTIONELEMENT_H

#include <QWidget>
#include<QVBoxLayout>
#include<QLabel>
#include "models/support/TipiRaggruppamento.h"

class AbstSectionElement: public QWidget
{
    Q_OBJECT

public:

    AbstSectionElement(QString nome_sezione, QWidget *parent = 0);

    bool isModifyed() const;

    virtual AbstDataSection* getData() const = 0;

protected:
    bool is_modifyed;

    QVBoxLayout* layout;

private slots:
    // questo viene chiamato quando un sotto componente viene alterato (SIGNAL)
    void setModifyed();

};

#endif // ABSTSECTIONELEMENT_H
