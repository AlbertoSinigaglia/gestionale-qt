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

    /**     GRADO INTUITIVITa               (metodo intero da 1 a 10)
     * Il metodo restituisce il grado (da 1 a 10) di intuitivita che viene rispettata nelle  
     * Grafic User Interface del GUIDev in questione.
     */
    unsigned int gradoIntuitiva() const;

protected:

    /*      VALORE LAVORO                   (metodo che eredita l'obbiettivo della classe base)*/
    virtual float valoreLavoro() const;

    /**     RIUTILIZZABILITa                (metodo che eredita l'obbiettivo della classe base)*/
    virtual unsigned int riutilizzabilita() const;

    /**     GRADO PROFESSIONALITa             (metodo intero da 1 a 10)
     * Il metodo restituisce il grado (da 1 a 10) di professionalita delle funzionalita proposte nella  
     * Grafic User Interface del GUIDev in questione. Una funzionalita professionale è una funzionalita
     * che per priorita antepone alla semplicita e univocita l'incremento delle performance 
     * sulla base di un lavoro professionale e consapevole.
     */
    unsigned int gradoProfessionalita() const;

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
 