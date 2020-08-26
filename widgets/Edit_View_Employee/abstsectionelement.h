#ifndef ABSTSECTIONELEMENT_H
#define ABSTSECTIONELEMENT_H

#include <QWidget>
#include<QVBoxLayout>
#include<QLabel>
#include "models/support/TipiRaggruppamento.h"
#include"widgets/Edit_View_Employee/Attribute_Elements/slideattribute.h"
#include"widgets/Edit_View_Employee/Attribute_Elements/dateeditattribute.h"
#include"widgets/Edit_View_Employee/Attribute_Elements/lineeditattribute.h"
#include"widgets/Edit_View_Employee/Attribute_Elements/comboattribute.h"
#include"widgets/Edit_View_Employee/Attribute_Elements/flagattribute.h"

class AbstSectionElement: public QWidget{
    Q_OBJECT
public:
    AbstSectionElement(QString nome_sezione, QWidget *parent = 0);
    bool isModifyed() const;
    virtual ~AbstSectionElement() = default;
    virtual AbstDataSection* getData() const = 0;

protected:
    bool is_modifyed;
    QVBoxLayout* layout;

signals:
    // questo viene chiamato quando un sotto componente viene alterato (SIGNAL)
    void setModifyed();

private slots:
    void setIs_Modifyed();
};

#endif // ABSTSECTIONELEMENT_H
