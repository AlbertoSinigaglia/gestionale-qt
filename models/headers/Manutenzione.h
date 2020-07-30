#ifndef CSVPARSER_MANUTENZIONE_H
#define CSVPARSER_MANUTENZIONE_H
 
 
#include "Employee.h" 
 
class Manutenzione: virtual public Employee{
 
public:

    Manutenzione(Persona persona, DatiLavoratore dati_lavoratore, DatiManutenzione dati_manutenzione);

    /**     PERCENTUALE RIPRISTINO                  (metodo reale  da 0 a 1)
     * Il metodo indica con una percentuale il grado di ripristino della situazione di normalità sulla base del lavoro svolto
     * a partire da inizio mese fin ora. 
     *          La situazione di normalità è uno stato del sistema produttivo dove non sono più necessari gli interventi
     *          di manutanzione dell'impiegato (è pertanto riferita alla tipoligia specifica del suo lavoro)
     */
    virtual double percRipristino() const = 0;

    /*      PRODUTTIVO                      (metodo che eredita l'obbiettivo della classe base)*/
    virtual bool produttivo() const;

    /*      BOUNS STIPENDIO                 (metodo che eredita l'obbiettivo della classe base)*/
    virtual float bonusStipendio() const;

    /**     AGGIORNA MESE                   (metodo che eredita l'obbiettivo della classe base)*/
    virtual void aggiornaMese();

protected:

    /*      VALORE LAVORO                   (metodo che eredita l'obbiettivo della classe base)*/
    virtual float valoreLavoro() const;

    /**     VALORE MEDIO RIPARAZIONE
     * Il metodo restituisce il valore medio che da all'azionda 1 riparazione
     */
    virtual float valoreMedioRiparazione() const = 0;

    /**     QUANTITÀ CONSIDEREVOLE RIPARAZIONI 
     * Il metodo ritorna la quantità di manutenzioni che è considerata meritevole (per il tipo di mansione che svolge)
     * in un mese per aggiudicarsi il bonus: bonus_n_riparazioni_considerevole (convenzione)
     */
    virtual unsigned int quantitàConsiderevoleRiparazioni() const = 0;

    unsigned int getPercRiparazioniInefficaci() const;
    unsigned int getNRiparazioniMese() const;
    void setNRiparazioniMese(unsigned int);


private:

    unsigned int perc_riparazioni_inefficaci;

    unsigned int n_riparazioni_mese;

    double perc_ripristino_medio;

};



#endif //CSVPARSER_MANUTENZIONE_H
