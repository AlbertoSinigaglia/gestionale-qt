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

    Tecnico(const Persona& persona, const DatiLavoratore& dati_lavoratore, const DatiManutenzione& dati_manutenzione, const DatiSistemi& dati_sistemi, const DatiRiparazioneSistemi& dati_riparazione_sistemi);

    /*      PERCENTUALE RIPRISTINO          (metodo che eredita l'obbiettivo della classe base Manutenzione)*/
    virtual double percRipristino() const override;

    /*      PRODUTTIVO                      (metodo che eredita l'obbiettivo della classe base)*/
    virtual bool produttivo() const override;

    /*      BOUNS STIPENDIO                 (metodo che eredita l'obbiettivo della classe base)*/
    virtual float bonusStipendio() const override;

    /*      AGGIORNA MESE                   (metodo che eredita l'obbiettivo della classe base)*/
    virtual void aggiornaMese() override;



    void setPercRiparazioniSussistenti(double value);

    void setOreStalloMensili(unsigned int value);

    void setOreStraordinari(unsigned int value);


    DatiRiparazioneSistemi getDatiRiparazioneSistemi() const;
    void setDatiRiparazioneSistemi(const DatiRiparazioneSistemi& d);


protected:

    /*      VALORE LAVORO                   (metodo che eredita l'obbiettivo della classe base)*/
    virtual float valoreLavoro() const override;

    /*      REMUNERAZIONE ORA ROUTINE       (metodo che eredita l'obbiettivo della classe: Employee)*/
    virtual float remunerazioneOraRoutine() const override;

    /*      VALORE RIPARAZIONE              (metodo che eredita l'obbiettivo della classe base)*/
    virtual float valoreMedioRiparazione() const override;

    /*      ORE LAVORO NEL MESE             (metodo che eredita l'obbiettivo della classe: Employee)
     *  in più aggiungo gli straordinari di riparazioni
    */
    virtual unsigned int oreLavoroNelMese() const override;

    /*      QUANTITÀ CONSIDEREVOLE RIPARAZIONI         (metodo che eredita l'obbiettivo della classe base)*/
    virtual unsigned int quantitaConsiderevoleRiparazioni() const override;


private:

    unsigned int orePiccolaRiparazione() const;

/**
 * CAMPI MENSILI
 */
    double perc_riparazioni_sussistenti;      // SLIDE (da 0 a 1, approx =2)

    unsigned int ore_stallo_mensili;                // LINE_EDIT (solo integer, val minimo 0)
    
    unsigned int ore_straordinari;                  // LINE_EDIT (solo integer, val minimo 0)
};


#endif //CSVPARSER_TECNICO_H
