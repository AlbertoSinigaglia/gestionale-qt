#ifndef CSVPARSER_BACKDEV_H
#define CSVPARSER_BACKDEV_H
 

#include "Software.h"
#include "Persona.h"
class BackDev : virtual public Software{

public: 

    BackDev(const Persona& persona, const DatiLavoratore& dati_lavoratore, const DatiDeveloping& dati_developing, const DatiLatoServer& dati_lato_server);
    
    /*      PRODUTTIVO                      (metodo che eredita l'obbiettivo della classe base)*/
    virtual bool produttivo() const override;

    /*      BOUNS STIPENDIO                 (metodo che eredita l'obbiettivo della classe base)*/
    virtual float bonusStipendio() const override;

    /**     VELOCITa SCRITTURA              (metodo che eredita l'obbiettivo della classe base)*/
    virtual double velocitaScrittura() const override;

    double getPercCapoProgetto() const;

protected:

    /*      INFLUENZA PROGETTO              (metodo che eredita l'obbiettivo della classe base)*/
    virtual double influenzaProgetto() const override;

    /**     RIUTILIZZABILITa                (metodo che eredita l'obbiettivo della classe base)*/
    virtual unsigned int riutilizzabilita() const override;

    bool isOrientatoOrtogonalita() const;

private:

    double perc_capo_progetto;

    unsigned int livello_astrazione;

    bool prove_correttezza;
    bool orientato_ortogonalita;
    
};


#endif //CSVPARSER_BACKDEV_H
