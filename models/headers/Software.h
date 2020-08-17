#ifndef CSVPARSER_SOFTWARE_H
#define CSVPARSER_SOFTWARE_H 


#include "../headers/Employee.h"


class Software: virtual public Employee{

public: 

    Software(const Persona& persona, const DatiLavoratore& dati_lavoratore, const DatiDeveloping& dati_developing);

// ---------------
// METODI VIRTUALI
// ---------------

    /*      AGGIORNA MESE                   (metodo che eredita l'obbiettivo della classe base)*/
    virtual void aggiornaMese() override;

    /*      PRODUTTIVO                      (metodo che eredita l'obbiettivo della classe base)*/
    virtual bool produttivo() const override;

    /*      BOUNS STIPENDIO                 (metodo che eredita l'obbiettivo della classe base)*/
    virtual float bonusStipendio() const override;

    /*      GRADO ESPERIENZA                (metodo che eredita l'obbiettivo della classe base)
    * Viene calcolato sulla base del numero di righe di codice prodotte dalla data di assunzione
    */
    virtual unsigned int gradoEsperienza()  const override;
 
    /*      VELOCITÀ SCRITTURA              (metodo reale)
     * Il metodo offre una stima della velocita di produzione di codice (# righe all' ora) che ci si aspetta dall'impiegato.
     * viene calcolato sulla base del linguaggio usato, l'esperienza e altre caratteristiche dei vari ambiti di impiego
     * Quindi e un valore indipendente dalle caratteristiche di efficienza e produttivita dell'impiegato
     */
    virtual double velocitaScrittura() const;


// -------------------
// METODI NON VIRTUALI
// -------------------


    /*      DURATA CODICE                   (metodo di tipo: Data)
     * Il metodo ritorna il tempo stimato di vita del codice 
     * Il periodo puo andare oltre al tempo di vita del progetto per cui e scritto se il codice viene
     * direttamente implementato in un altro progetto
     */
    DifferenzaDate durataCodice() const;


    void setNRigheMese(unsigned int value);

    void setNProgettiConclusiMese(unsigned int value);

    void setNRigheTotali(unsigned int value);

    void setPercOreProgrammazione(double value);


    DatiDeveloping getDatiDeveloping() const;
    void setDatiDeveloping(const DatiDeveloping& d);


protected:


    // ---------------
    // METODI VIRTUALI
    // ---------------


    /*      VALORE LAVORO                   (metodo che eredita l'obbiettivo della classe base)*/
    virtual float valoreLavoro() const override;

    /*      RIUTILIZZABILITÀ                (metodo intero)
     * Il metodo ritorna un valore corrispondente a una stima del numero di progetti che potrebbero riutilizzare il codice
     * scritto dalo sviluppatroe software in questione.
     */
    virtual unsigned int riutilizzabilita() const;

    /*      INFLUENZA PROGETTO              (metodo reale)
     * Il metodo ritorna un rapporto che esprime una maggiore o minore influenza nella produzione del progetto
     * Il contributo che da lo sviluppatore in questione viene rapportato a quello di un generico sviluppatore
     * percio il contributo dello sviluppatore = influenzaProgetto() * contributo sviluppatore medio ( = dimensione_progetto/n_impiegati_per_progetto)
     */
    virtual double influenzaProgetto() const; 


// -------------------
// METODI NON VIRTUALI
// -------------------


    /*      ORE PER PROGETTO                (metodo intero)
     * Il metodo ritorna il numero di ore che in media lo sviluppatore software in questione produce
     * per terminare i suoi incarichi nel progetto
     */
    unsigned int orePerProgetto() const;

    /*      RIGHE PER PROGETTO              (metodo intero)
     * Il metodo ritorna il numero di righe che in media lo sviluppatore software in questione impiega per concludere un progetto
     */
    unsigned int righePerProgetto() const; 



    unsigned int getNProgettiConclusiMese() const;
    unsigned int getNRigheMese() const;




private:         


// ----------
// CAMPI DATI
// ----------

    /**
     * MENSILI
     */
    unsigned int n_righe_mese;                              //LINE_EDIT (solo integer, val minimo 0)
    // Codice prodotto (che e diverso da codice scritto)

    unsigned int n_progetti_conclusi_mese;                  //LINE_EDIT (solo integer, val minimo 0)

    /**
     * ESTEMPORANEI
     */
    unsigned int n_righe_totali;                            // LINE_EDIT (solo integer, val minimo 0)
    double perc_ore_programmazione;                         // SLIDE (da 0 a 1, approx =2)
    /* (1 - perc_ore_programmazione) = percentuale ore di progettazione
    */
    Conv::Linguaggio linguaggio;                            // COBO BOX( valori= <i vari linguaggi>)

};

#endif //CSVPARSER_SOFTWARE_H
 
