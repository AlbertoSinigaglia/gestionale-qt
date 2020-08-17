#ifndef EDITVIEWEMPLOYEE_H
#define EDITVIEWEMPLOYEE_H

#include"models/support/TipiRaggruppamento.h"
#include"collections/DynamicArray.h"
#include <qwidget.h>
#include <iostream>
#include<QVBoxLayout>
#include <QPushButton>
#include<QScrollArea>
#include<QLabel>
#include<QFile>

#include"models/headers/GUIDev.h"
#include"models/headers/DBDev.h"
#include"models/headers/FullStack.h"
#include"models/headers/ITSecurityDev.h"
#include"models/headers/Tecnico.h"


#include"widgets/Edit_View_Employee/Data_Section_Elements/DatiLavoratoreElement.h"



class EditViewEmployee: public QWidget{
Q_OBJECT

public:

    EditViewEmployee(const DynamicArray<AbstDataSection*>& dati_, bool editable =false, QWidget *parent =0);

public slots:

    void chooseAndSend() const;

signals:

    void handleExitEditView() const;      // TO CONTROLLER

    void SaveDataConsiderd(AbstDataSection* dati_) const;     // TO CONTROLLER


private:

    DynamicArray<AbstSectionElement*> lista_elementi;

    QVBoxLayout* mainLayout;

    // Metodo per costruttore
    QVBoxLayout* buildSections(const DynamicArray<AbstDataSection*>& dati_, bool editable, QWidget* parent);



};




#endif // EDITVIEWEMPLOYEE_H
