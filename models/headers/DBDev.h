#ifndef CSVPARSER_DBDEV_H
#define CSVPARSER_DBDEV_H

  
#include "BackDev.h"

class DBDev : public BackDev{

public:

    DBDev(Persona persona, DatiLavoratore dati_lavoratore, DatiDeveloping dati_developing, DatiLatoServer dati_lato_server, DatiDatabase dati_database);

    /*      PRODUTTIVO                      (metodo che eredita l'obbiettivo della classe base)*/
    virtual bool produttivo() const override;

    /*      BOUNS STIPENDIO                 (metodo che eredita l'obbiettivo della classe base)*/
    virtual float bonusStipendio() const;

    /*      AGGIORNA MESE                   (metodo che eredita l'obbiettivo della classe base)*/
    virtual void aggiornaMese();

    /**     GRADO ORTOGONALITa              (metodo intero da 1 a 10)
     * Il metodo restituisce il grado (da 1 a 10) dell'ortogonalita che viene mantenuta nei database progettati 
     * dal DBDev in questione 
     */
    unsigned int gradoOrtogonalita() const;

protected:

    /*      VALORE LAVORO                   (metodo che eredita l'obbiettivo della classe base)*/
    virtual float valoreLavoro() const;

    /**     RIUTILIZZABILITa                (metodo che eredita l'obbiettivo della classe base)*/
    virtual unsigned int riutilizzabilita() const;                                                             // sfrutta grado ortogonalita

    /**     REMUNERAZIONE ORA ROUTINE       (metodo che eredita l'obbiettivo della classe: Employee)*/
    virtual float remunerazioneOraRoutine() const;

private:

    /**     GRADO PERFORMANCE               (metodo intero da 1 a 10)
     * Il metodo restituisce il grado (da 1 a 10) di efficienza (velocita di risposta dataBase) garantita nel DataBase 
     * dal DBDev in questione 
     */
    unsigned int gradoPerformance() const;

    static const float VALORE_ORA_ROUTINE_BASE = 10;
    static const double MEDIA_ATTRIBUTI_RIDONDANTI_PER_ENTITa = 0.2;

/*
* CAMPI x PROGETTO
*/
    double num_attributi_ridondanti_per_entita;

    double speed_up_indicizzazioni;

    double perc_entita_forma_normale;

};


#endif //CSVPARSER_DBDEV_H
 