#ifndef CSVPARSER_SOFTWARE_H
#define CSVPARSER_SOFTWARE_H 


#include "Employee.h"  


class Software: virtual public Employee{

public: 

    Software(Persona persona, DatiLavoratore dati_lavoratore, DatiDeveloping dati_developing);

// ---------------
// METODI VIRTUALI
// ---------------


    /**     AGGIORNA MESE                   (metodo che eredita l'obbiettivo della classe base)*/
    virtual void aggiornaMese();

    /*      PRODUTTIVO                      (metodo che eredita l'obbiettivo della classe base)*/
    virtual bool produttivo() const;

    /*      BOUNS STIPENDIO                 (metodo che eredita l'obbiettivo della classe base)*/
    virtual float bonusStipendio() const;  

    /*      GRADO ESPERIENZA                (metodo che eredita l'obbiettivo della classe base)
    * Viene calcolato sulla base del numero di righe di codice prodotte dalla data di assunzione
    */
    virtual unsigned int gradoEsperienza()  const; 
 
    /**     VELOCITÀ SCRITTURA              (metodo reale)
     * Il metodo offre una stima della velocità di produzione di codice (# righe all' ora) che ci si aspetta dall'impiegato.
     * viene calcolato sulla base del linguaggio usato, l'esperienza e altre caratteristiche dei vari ambiti di impiego
     * Quindi è un valore indipendente dalle caratteristiche di efficienza e produttività dell'impiegato
     */
    virtual double velocitàScrittura() const;


// -------------------
// METODI NON VIRTUALI
// -------------------


    /**     DURATA CODICE                   (metodo di tipo: Data)
     * Il metodo ritorna il tempo stimato di vita del codice 
     * Il periodo può andare oltre al tempo di vita del progetto per cui è scritto se il codice viene
     * direttamente implementato in un altro progetto
     */
    DifferenzaDate durataCodice() const;


protected:


// ---------------
// METODI VIRTUALI
// ---------------


    /*      VALORE LAVORO                   (metodo che eredita l'obbiettivo della classe base)*/
    virtual float valoreLavoro() const;

    /**     RIUTILIZZABILITÀ                (metodo intero)
     * Il metodo ritorna un valore corrispondente a una stima del numero di progetti che potrebbero riutilizzare il codice
     * scritto dalo sviluppatroe software in questione.
     */
    virtual unsigned int riutilizzabilità() const;

    /**     INFLUENZA PROGETTO              (metodo reale)
     * Il metodo ritorna un rapporto che esprime una maggiore o minore influenza nella produzione del progetto
     * Il contributo che da lo sviluppatore in questione viene rapportato a quello di un generico sviluppatore
     * perciò il contributo dello sviluppatore = influenzaProgetto() * contributo sviluppatore medio ( = dimensione_progetto/n_impiegati_per_progetto)
     */
    virtual double influenzaProgetto() const; 


// -------------------
// METODI NON VIRTUALI
// -------------------


    /**     ORE PER PROGETTO                (metodo intero)
     * Il metodo ritorna il numero di ore che in media lo sviluppatore software in questione produce
     * per terminare i suoi incarichi nel progetto
     */
    unsigned int orePerProgetto() const;

    /**     RIGHE PER PROGETTO              (metodo intero)
     * Il metodo ritorna il numero di righe che in media lo sviluppatore software in questione impiega per concludere un progetto
     */
    unsigned int righePerProgetto() const; 


private:         


// ----------
// CAMPI DATI
// ----------

    /**
     * MENSILI
     */
    unsigned int n_righe_mese;        // Codice prodotto (che è diverso da codice scritto)
    unsigned int n_progetti_conclusi_mese;

    /**
     * ESTEMPORANEI
     */
    unsigned int n_righe_totali;       
    double perc_ore_programmazione;
    /* (1 - perc_ore_programmazione) = percentuale ore di progettazione
    */
    Conv::Linguaggio linguaggio;

};

#endif //CSVPARSER_SOFTWARE_H
 
