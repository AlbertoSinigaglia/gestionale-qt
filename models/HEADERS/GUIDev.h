//
// Created by Alberto Sinigaglia on 10/04/2020.
//

#ifndef CSVPARSER_GUIDEV_H
#define CSVPARSER_GUIDEV_H
 

#include "FrontDev.h"

class GUIDev : public FrontDev{

public:

    GUIDev(Persona persona, DatiLavoratore dati_lavoratore, DatiDeveloping dati_developing, DatiLatoClient dati_lato_client, DatiInterfacceUtente dati_interfaccia_utente);

    /*      PRODUTTIVO                      (metodo che eredita l'obbiettivo della classe base)*/
    virtual bool produttivo() const override;

    /*      BOUNS STIPENDIO                 (metodo che eredita l'obbiettivo della classe base)*/
    virtual float bonusStipendio() const;

    /*      AGGIORNA MESE                   (metodo che eredita l'obbiettivo della classe base)*/
    virtual void aggiornaMese();

    /**     GRADO INTUITIVITÀ               (metodo intero da 1 a 10)
     * Il metodo restituisce il grado (da 1 a 10) di intuitività che viene rispettata nelle  
     * Grafic User Interface del GUIDev in questione.
     */
    unsigned int gradoIntuitivà() const;

protected:

    /*      VALORE LAVORO                   (metodo che eredita l'obbiettivo della classe base)*/
    virtual float valoreLavoro() const;

    /**     RIUTILIZZABILITÀ                (metodo che eredita l'obbiettivo della classe base)*/
    virtual unsigned int riutilizzabilità() const;

    /**     GRADO PROFESSIONALITÀ             (metodo intero da 1 a 10)
     * Il metodo restituisce il grado (da 1 a 10) di professionalità delle funzionalità proposte nella  
     * Grafic User Interface del GUIDev in questione. Una funzionalità professionale è una funzionalità
     * che per priorità antepone alla semplicità e univocità l'incremento delle performance 
     * sulla base di un lavoro professionale e consapevole.
     */
    unsigned int gradoProfessionalità() const;

    /**     REMUNERAZIONE ORA ROUTINE       (metodo che eredita l'obbiettivo della classe: Employee)*/
    virtual float remunerazioneOraRoutine() const;


private:

    static const float VALORE_ORA_ROUTINE_BASE = 10;

    bool quary_predefinite;
    bool stile_minimalista;

    unsigned int lunghezza_max_percorso;
    unsigned int num_medio_percorsi_sezione;

};


#endif //CSVPARSER_GUIDEV_H
 