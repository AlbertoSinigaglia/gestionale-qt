//
// Created by Alberto Sinigaglia on 10/04/2020.
// 

#ifndef CSVPARSER_TECNICO_H 
#define CSVPARSER_TECNICO_H
 
 
#include "Hardware.h"
#include "Manutenzione.h"


/** ASSUNZIONE:
 *  1) Il tecnico può prendere ore di straodinari se e solo se queste servono 
 *     a svolgere una riparazione che sta obbligando uno stallo nella produzione dell'azienda.
 *  2) Gli stalli vengono causati da tutte e sole le riparazioni a sistemi di sussistenza
 */


class Tecnico : public Manutenzione, public Hardware{

public:

    Tecnico(Persona persona, DatiLavoratore dati_lavoratore, DatiManutenzione dati_manutenzione, DatiSistemi dati_sistemi, DatiRiparazioneSistemi dati_riparazione_sistemi);

    /**     PERCENTUALE RIPRISTINO          (metodo che eredita l'obbiettivo della classe base Manutenzione)*/
    virtual double percRipristino() const;

    /*      PRODUTTIVO                      (metodo che eredita l'obbiettivo della classe base)*/
    virtual bool produttivo() const override;

    /*      BOUNS STIPENDIO                 (metodo che eredita l'obbiettivo della classe base)*/
    virtual float bonusStipendio() const;

    /**     AGGIORNA MESE                   (metodo che eredita l'obbiettivo della classe base)*/
    virtual void aggiornaMese();


protected:                       

    /*      VALORE LAVORO                   (metodo che eredita l'obbiettivo della classe base)*/
    virtual float valoreLavoro() const = 0;

    /**     REMUNERAZIONE ORA ROUTINE       (metodo che eredita l'obbiettivo della classe: Employee)*/
    virtual float remunerazioneOraRoutine() const;

    /*      VALORE RIPARAZIONE              (metodo che eredita l'obbiettivo della classe base)*/
    virtual float valoreMedioRiparazione() const;

    /**     ORE LAVORO NEL MESE             (metodo che eredita l'obbiettivo della classe: Employee)
     *  in più aggiungo gli straordinari di riparazioni
    */
    virtual unsigned int oreLavoroNelMese() const;

    /*      QUANTITÀ CONSIDEREVOLE RIPARAZIONI         (metodo che eredita l'obbiettivo della classe base)*/  
    virtual unsigned int quantitàConsiderevoleRiparazioni() const;


private:


    unsigned int oreRiparazioneStallo() const;

    unsigned int orePiccolaRiparazione() const;

    unsigned int oreRisparmiateStalli() const;

/**
 * CAMPI MENSILI
 */
    unsigned int perc_riparazioni_sussistenti;

    unsigned int ore_stallo_mensili;
    
    unsigned int ore_straordinari;
};


#endif //CSVPARSER_TECNICO_H
