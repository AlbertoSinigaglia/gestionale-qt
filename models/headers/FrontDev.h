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

    /**     VELOCITa SCRITTURA              (metodo che eredita l'obbiettivo della classe base)*/
    virtual double velocitaScrittura() const;

protected:

    /**     RIUTILIZZABILITa                (metodo che eredita l'obbiettivo della classe base)*/
    virtual unsigned int riutilizzabilita() const;

    bool isOrientatoProfessionalita() const;

private:

    Conv::Libreria libreria;
    
    bool orientato_professionaita;

    double perc_codice_perfezionato;   // percentuale di codice esterno (derivante da cut&paste) adattato per il progetto

};
 

#endif //CSVPARSER_FRONTDEV_H
