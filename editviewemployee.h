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
#include<QIcon>

#include"models/headers/GUIDev.h"
#include"models/headers/DBDev.h"
#include"models/headers/FullStack.h"
#include"models/headers/ITSecurityDev.h"
#include"models/headers/Tecnico.h"


#include"widgets/Edit_View_Employee/Data_Section_Elements/DatiLavoratoreElement.h"
#include"widgets/Edit_View_Employee/Data_Section_Elements/DatiDatabaseElement.h"
#include"widgets/Edit_View_Employee/Data_Section_Elements/DatiDevelopingElement.h"
#include"widgets/Edit_View_Employee/Data_Section_Elements/DatiFullstackElement.h"
#include"widgets/Edit_View_Employee/Data_Section_Elements/DatiInterfacciaUtenteElement.h"
#include"widgets/Edit_View_Employee/Data_Section_Elements/DatiLatoClientElement.h"
#include"widgets/Edit_View_Employee/Data_Section_Elements/DatiLatoServerElement.h"
#include"widgets/Edit_View_Employee/Data_Section_Elements/DatiManutenzioneElement.h"
#include"widgets/Edit_View_Employee/Data_Section_Elements/DatiPersonaElement.h"
#include"widgets/Edit_View_Employee/Data_Section_Elements/DatiRiparazioneSistemiElement.h"
#include"widgets/Edit_View_Employee/Data_Section_Elements/DatiRipristinoSicurezzaElement.h"
#include"widgets/Edit_View_Employee/Data_Section_Elements/DatiSistemiElement.h"

#include"widgets/suggerimento.h"



class EditViewEmployee: public QWidget{
Q_OBJECT

public:

    enum Utilizzo: short{
        CREAZIONE =0,
        MODIFICA =1,
        VISUALIZZA =2
    };

    EditViewEmployee(const DynamicArray<AbstDataSection*>& dati_, Utilizzo stato_utilizzo =Utilizzo::VISUALIZZA, QWidget *parent =0);

    bool isModifyed() const;

    void chooseAndSend() const;

signals:

    void SaveDataConsiderd(AbstDataSection* dati_) const;     // TO CONTROLLER

    void handleExitEditView() const;

private:

    Utilizzo stato;

    bool isModify;
    QPushButton* SalvaEsci;

    DynamicArray<AbstSectionElement*> lista_elementi;

    QVBoxLayout* mainLayout;

    // Metodo per costruttore
    QFrame* buildSections(const DynamicArray<AbstDataSection*>& dati_, QWidget* parent);

    QHBoxLayout* buildIntestazione();



private slots:

    void setModifed();




};




#endif // EDITVIEWEMPLOYEE_H
