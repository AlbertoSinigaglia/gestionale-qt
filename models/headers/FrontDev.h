//
// Created by Alberto Sinigaglia on 10/04/2020.
//

#ifndef CSVPARSER_FRONTDEV_H
#define CSVPARSER_FRONTDEV_H
  

#include "Software.h"

class FrontDev : virtual public Software{
public:

    FrontDev(Persona persona, DatiLavoratore dati_lavoratore, DatiDeveloping dati_developing, DatiLatoClient dati_lato_client)
    
    /*      PRODUTTIVO                      (metodo che eredita l'obbiettivo della classe base)*/
    virtual bool produttivo() const override;

    /*      BOUNS STIPENDIO                 (metodo che eredita l'obbiettivo della classe base)*/
    virtual float bonusStipendio() const;

    /*      AGGIORNA MESE                   (metodo che eredita l'obbiettivo della classe base)*/
    virtual void aggiornaMese();

    /**     VELOCITÀ SCRITTURA              (metodo che eredita l'obbiettivo della classe base)*/
    virtual double velocitàScrittura() const;

protected:

    /*      VALORE LAVORO                   (metodo che eredita l'obbiettivo della classe base)*/
    virtual float valoreLavoro() const;

    /**     RIUTILIZZABILITÀ                (metodo che eredita l'obbiettivo della classe base)*/
    virtual unsigned int riutilizzabilità() const;

    bool isOrientatoProfessionalità() const;

private:

    Conv::Libreria libreria;
    
    bool orientato_professionaità;
l
    double perc_righe_esterne;         // percentuale delle righe derivanti da strumenti di design automation o codice copiato 
    double perc_codice_perfezionato;   // percentuale di codice esterno perfezionato 

};
 

#endif //CSVPARSER_FRONTDEV_H
