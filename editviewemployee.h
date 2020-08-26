#ifndef EDITVIEWEMPLOYEE_H
#define EDITVIEWEMPLOYEE_H

#include"models/support/TipiRaggruppamento.h"
#include"collections/DynamicArray.h"
#include <qwidget.h>
#include <iostream>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include <QPushButton>
#include<QScrollArea>
#include<QLabel>
#include<QFile>
#include<QIcon>
#include<QDialog>
#include<QCloseEvent>
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

/**
 * @brief La vista < EditViewEmployee>  si  occupa  di  creare  un interfaccia  per  visualizzare
 * sezioni indipendenti di dati di tipo <TipiRaggruppamento>, è con questi che interagisce
 * e non direttamente su  un impiegato.
 */
class EditViewEmployee: public QDialog{
    Q_OBJECT
    static void setStyle(QWidget*);

public:
    /**
     * Utilizzo:
     * La vista può essere aperta per visualizzare un impiegato (in questo caso genererà
     * dei widget in sola lettura), oppure per modificarlo (in lettura/scrittura) o per
     * crearlo.
     */
    enum Utilizzo: short{
        CREAZIONE =0,
        MODIFICA =1,
        VISUALIZZA =2
    };

    /**
     * @brief Si occupa di creare una vista che rappresenta un impiegato composto da un certo numero di sezioni dati
     * @param dati_
     * @param stato_utilizzo (VISUALIZZA, CREAZIONE, MODIFICA)
     * @param parent
     */
    EditViewEmployee(const DynamicArray<AbstDataSection*>& dati_, Utilizzo stato_utilizzo =Utilizzo::VISUALIZZA, QWidget *parent =0);

    /**
     * IS MODIFYED
     * @brief Permette di capire se dal momento della creazione della vista l'utente
     * ha eseguito una qualche azione sui widget per la modifica dei campi dati
     */
    bool isModifyed() const;

    /**
     * @brief Si occupa di scegliere tra le varie sezioni dati quelle modificate
     * e trasmetterle con un signal
     */
    void chooseAndSend() const;

    // GETTER STATO
    Utilizzo getStato() const;

signals:
    /**
     * @brief Il segnale richiede che <dati_> venga intesa e gestita come la nuova
     * versione modificata della sezione univocata dal suo tipo dinamico
     * @param dati_
     */
    void SaveDataConsiderd(AbstDataSection* dati_) const;     // TO CONTROLLER

    //Il segnale richiama la gestione della chiusura della vista
    void closeDirect();

    /**
     * Il segnale richiama la gestione del salvataggio dei dati al momento della chiusura della vista
     */
    void saveAndClose();

private:
    // lista_elementi è un vettore di riferimenti ai widget che riguardano ogni sezione
    // volutamente ridondante (mainLayout: *exist*)
    DynamicArray<AbstSectionElement*> lista_elementi;
    Utilizzo stato;
    bool isModify;
    QHBoxLayout* LSalvaEsci;
    QPushButton* Esci;
    QVBoxLayout* mainLayout;

    /**
     * @brief metodo x la costruzione, permette di generare e connettere i widget che
     * gestiscono le varie sezioni di dati
     * @param dati_
     * @param parent
     */
    QFrame* buildSections(const DynamicArray<AbstDataSection*>& dati_, QWidget* parent);
    QHBoxLayout* buildIntestazione();

private slots:
    /**
     * @brief si occupa di gestire a livello di vista l'avvenuta alterazione delle
     * informazioni
     */
    void setModifed();
    void closeEvent(QCloseEvent *event) override;
};

#endif // EDITVIEWEMPLOYEE_H
