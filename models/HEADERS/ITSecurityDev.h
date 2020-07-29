//
// Created by Alberto Sinigaglia on 05/04/2020.
//
 
#ifndef CSVPARSER_ITSECURITYDEV_H
#define CSVPARSER_ITSECURITYDEV_H


#include "Software.h"
#include "Manutenzione.h"

class ITSecurityDev: public Software, public Manutenzione{

public:

    ITSecurityDev(Persona persona, DatiLavoratore dati_lavoratore, DatiManutenzione dati_manutenzione, DatiSistemi dati_sistemi, DatiRiparazioneSistemi drs);

    /*      PERCENTUALE RIPRISTINO          (metodo che eredita l'obbiettivo della classe base Manutenzione)*/
    virtual double percRipristino() const;

    /*      PRODUTTIVO                      (metodo che eredita l'obbiettivo della classe base)*/
    virtual bool produttivo() const override;

    /*      BOUNS STIPENDIO                 (metodo che eredita l'obbiettivo della classe base)*/
    virtual float bonusStipendio() const;

    /*      AGGIORNA MESE                   (metodo che eredita l'obbiettivo della classe base)*/
    virtual void aggiornaMese();

    /**     VELOCITÀ SCRITTURA              (metodo che eredita l'obbiettivo della classe base Software)*/
    virtual double velocitàScrittura() const;

    /**     COMMIT PROBLEMA RISOLTO         (metodo booleano)
     * Il metodo consente di fare il commit di una manutenzione andata a buon fine facendo distinzione se questa
     * ha trattato un problema critico, e riturna true sse la procedura è andata a buon fine
     */
    bool commitProblemaRisolto(bool isCriticità = false);


    unsigned int getNManutenzioniNonCritiche() const;
    unsigned int getNManutenzioniCritiche() const;


protected:

    /*      VALORE LAVORO                   (metodo che eredita l'obbiettivo della classe base)*/
    virtual float valoreLavoro() const;

    /**     RIUTILIZZABILITÀ                (metodo che eredita l'obbiettivo della classe base Software)*/
    virtual unsigned int riutilizzabilità() const;

    /**     INFLUENZA PROGETTO              (metodo che eredita l'obbiettivo della classe base Software)*/
    virtual double influenzaProgetto() const;

    /**     REMUNERAZIONE ORA ROUTINE       (metodo che eredita l'obbiettivo della classe: Employee)*/
    virtual float remunerazioneOraRoutine() const;

    /*      VALORE RIPARAZIONE              (metodo che eredita l'obbiettivo della classe base Manutenzione)*/
    virtual float valoreMedioRiparazione() const;

    /*      QUANTITÀ CONSIDEREVOLE RIPARAZIONI         (metodo che eredita l'obbiettivo della classe base Manutenzione)*/  
    virtual unsigned int quantitàConsiderevoleRiparazioni() const;


private:

    unsigned int righeManutenzioneNonCritica() const;

    double mediaNManutenzioniPerProgetto() const;

/**
 * CAMPI MENSILI
 */
    unsigned int n_problemi_irrsolti;   

    unsigned int n_progetti_in_arrivo;   
           
    unsigned int n_criticità_risolte;                                          
};

#endif //CSVPARSER_ITSECURITYDEV_H
 