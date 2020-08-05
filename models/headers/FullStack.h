#ifndef CSVPARSER_FULLSTACK_H
#define CSVPARSER_FULLSTACK_H


#include "FrontDev.h"
#include "BackDev.h"
 
class FullStack: public FrontDev, public BackDev{
public:

    FullStack(Persona persona, DatiLavoratore dati_lavoratore, DatiDeveloping dati_developing, DatiLatoServer dati_lato_server, DatiLatoClient dati_lato_client)

    /*      PRODUTTIVO                      (metodo che eredita l'obbiettivo della classe base)*/
    virtual bool produttivo() const override;

    /*      BOUNS STIPENDIO                 (metodo che eredita l'obbiettivo della classe base)*/
    virtual float bonusStipendio() const;

    /**     VELOCITa SCRITTURA              (metodo che eredita l'obbiettivo della classe base)*/
    virtual double velocitaScrittura() const;

protected:

    /*      VALORE LAVORO                   (metodo che eredita l'obbiettivo della classe base)*/
    virtual float valoreLavoro() const;

    /**     RIUTILIZZABILITÀ                (metodo che eredita l'obbiettivo della classe base)*/
    virtual unsigned int riutilizzabilita() const;

    /**     REMUNERAZIONE ORA ROUTINE       (metodo che eredita l'obbiettivo della classe: Employee)*/
    virtual float remunerazioneOraRoutine() const;

private:

    double perc_lavoro_back;                                                            // (1 - perc_lavoro_back) = perc_lavoro_front

    bool separa_interfacce;          


};

#endif //CSVPARSER_FULLSTACK_H 
