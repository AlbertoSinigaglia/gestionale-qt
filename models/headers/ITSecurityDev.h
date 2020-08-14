#ifndef CSVPARSER_ITSECURITYDEV_H
#define CSVPARSER_ITSECURITYDEV_H


#include "Software.h"
#include "Manutenzione.h"

class ITSecurityDev: public Software, public Manutenzione{

public:

    ITSecurityDev(const Persona & persona, const DatiLavoratore & dati_lavoratore, const DatiManutenzione & dati_manutenzione, const DatiDeveloping & dati_developing, const DatiRipristinoSicurezza & dati_ripristino_sicurezza);

    /*      PERCENTUALE RIPRISTINO          (metodo che eredita l'obbiettivo della classe base Manutenzione)*/
    virtual double percRipristino() const override;

    /*      PRODUTTIVO                      (metodo che eredita l'obbiettivo della classe base)*/
    virtual bool produttivo() const override;

    /*      BOUNS STIPENDIO                 (metodo che eredita l'obbiettivo della classe base)*/
    virtual float bonusStipendio() const override;

    /*      AGGIORNA MESE                   (metodo che eredita l'obbiettivo della classe base)*/
    virtual void aggiornaMese() override;

    /*      VELOCITÀ SCRITTURA              (metodo che eredita l'obbiettivo della classe base Software)*/
    virtual double velocitaScrittura() const override;

    /*      COMMIT PROBLEMA RISOLTO         (metodo booleano)
     * Il metodo consente di fare il commit di una manutenzione andata a buon fine facendo distinzione se questa
     * ha trattato un problema critico, e riturna true sse la procedura è andata a buon fine
     */
    bool commitProblemaRisolto(bool isCriticita = false);



    void setNProblemiIrrsolti(unsigned int value);

    void setNProgettiInArrivo(unsigned int value);

    void setNCriticitaRisolte(unsigned int value);


    DatiRipristinoSicurezza getDatiRipristinoSicurezza() const;
    void setDatiRipristinoSicurezza(const DatiRipristinoSicurezza& d);


protected:

    /*      VALORE LAVORO                   (metodo che eredita l'obbiettivo della classe base)*/
    virtual float valoreLavoro() const override;

    /*      RIUTILIZZABILITÀ                (metodo che eredita l'obbiettivo della classe base Software)*/
    virtual unsigned int riutilizzabilita() const override;

    /*      INFLUENZA PROGETTO              (metodo che eredita l'obbiettivo della classe base Software)*/
    virtual double influenzaProgetto() const override;

    /*      REMUNERAZIONE ORA ROUTINE       (metodo che eredita l'obbiettivo della classe: Employee)*/
    virtual float remunerazioneOraRoutine() const override;

    /*      VALORE RIPARAZIONE              (metodo che eredita l'obbiettivo della classe base Manutenzione)*/
    virtual float valoreMedioRiparazione() const override;

    /*      QUANTITÀ CONSIDEREVOLE RIPARAZIONI         (metodo che eredita l'obbiettivo della classe base Manutenzione)*/
    virtual unsigned int quantitaConsiderevoleRiparazioni() const override;


private:

    double NManutenzioniPerProgetto() const;

/**
 * CAMPI MENSILI
 */
    unsigned int n_problemi_irrsolti;   

    unsigned int n_progetti_in_arrivo;   
           
    unsigned int n_criticita_risolte;                                          
};

#endif //CSVPARSER_ITSECURITYDEV_H
 
