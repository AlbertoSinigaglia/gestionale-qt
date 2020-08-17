#ifndef CSVPARSER_GUIDEV_H
#define CSVPARSER_GUIDEV_H
 

#include "FrontDev.h"

class GUIDev : public FrontDev{

public:

    GUIDev(const Persona & persona, const DatiLavoratore & dati_lavoratore, const DatiDeveloping & dati_developing, const DatiLatoClient & dati_lato_client, const DatiInterfacceUtente & dati_interfaccia_utente);

    /*      BOUNS STIPENDIO                 (metodo che eredita l'obbiettivo della classe base)*/
    virtual float bonusStipendio() const override;

    /*      GRADO INTUITIVITÀ               (metodo intero da 1 a 10)
     * Il metodo restituisce il grado (da 1 a 10) di intuitività che viene rispettata nelle  
     * Grafic User Interface del GUIDev in questione.
     */
    unsigned int gradoIntuitivita() const;



    void setQuaryPredefinite(bool value);

    void setStileMinimalista(bool value);

    void setLunghezzaMaxPercorso(unsigned int value);

    void setNumMedioPercorsiSezione(unsigned int value);

    DatiInterfacceUtente getDatiInterfacceUtente() const;
    void setDatiInterfacceUtente(const DatiInterfacceUtente& d);


protected:

    /*      VALORE LAVORO                   (metodo che eredita l'obbiettivo della classe base)*/
    virtual float valoreLavoro() const override;

    /*      GRADO PROFESSIONALITÀ             (metodo intero da 1 a 10)
     * Il metodo restituisce il grado (da 1 a 10) di professionalita delle funzionalita proposte nella  
     * Grafic User Interface del GUIDev in questione. Una funzionalita professionale è una funzionalita
     * che per priorità antepone alla semplicita e univocita l'incremento delle performance 
     * sulla base di un lavoro professionale e consapevole.
     */
    unsigned int gradoProfessionalita() const;

    /*      REMUNERAZIONE ORA ROUTINE       (metodo che eredita l'obbiettivo della classe: Employee)*/
    virtual float remunerazioneOraRoutine() const override;


private:

    bool quary_predefinite;
    bool stile_minimalista;

    // il numero massimo di passi necessari che devo compiere per giungere su una sezione del sistema
    unsigned int lunghezza_max_percorso;

    //nuumero medio di percorsi diversi che permettono di giungere a una stessa sezione del sistema
    unsigned int num_medio_percorsi_sezione;

};


#endif //CSVPARSER_GUIDEV_H
 
