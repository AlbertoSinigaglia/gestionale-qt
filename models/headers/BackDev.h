//
// Created by Alberto Sinigaglia on 09/04/2020.
//
 
#ifndef CSVPARSER_BACKDEV_H
#define CSVPARSER_BACKDEV_H
 

#include "Software.h"

class BackDev : virtual public Software{

public: 

    BackDev(Persona persona, DatiLavoratore dati_lavoratore, DatiDeveloping dati_developing, DatiLatoServer dati_lato_server);
    
    /*      PRODUTTIVO                      (metodo che eredita l'obbiettivo della classe base)*/
    virtual bool produttivo() const override;

    /*      BOUNS STIPENDIO                 (metodo che eredita l'obbiettivo della classe base)*/
    virtual float bonusStipendio() const;

    /**     VELOCITa SCRITTURA              (metodo che eredita l'obbiettivo della classe base)*/
    virtual double velocitaScrittura() const;

protected:

    /*      VALORE LAVORO                   (metodo che eredita l'obbiettivo della classe base)*/
    virtual float valoreLavoro() const;

    /**     RIUTILIZZABILITa                (metodo che eredita l'obbiettivo della classe base)*/
    virtual unsigned int riutilizzabilita() const;

    bool isOrientatoOrtogonalita() const;

private:

    double perc_capo_progetto;

    unsigned int livello_astrazione;

    bool prove_correttezza;
    bool orientato_ortogonalita;
    
};


#endif //CSVPARSER_BACKDEV_H
