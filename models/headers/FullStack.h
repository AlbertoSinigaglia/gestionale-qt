#ifndef CSVPARSER_FULLSTACK_H
#define CSVPARSER_FULLSTACK_H


#include "FrontDev.h"
#include "BackDev.h"
 
class FullStack: public FrontDev, public BackDev{
public:

    FullStack(const Persona& persona, const DatiLavoratore& dati_lavoratore, const DatiDeveloping& dati_developing, const DatiLatoServer& dati_lato_server, const DatiLatoClient& dati_lato_client, const DatiFullStack& dati_fullstack);

    /*      PRODUTTIVO                      (metodo che eredita l'obbiettivo della classe base)*/
    virtual bool produttivo() const override;

    /*      BOUNS STIPENDIO                 (metodo che eredita l'obbiettivo della classe base)*/
    virtual float bonusStipendio() const override;

    /*      VELOCITÀ SCRITTURA              (metodo che eredita l'obbiettivo della classe base)*/
    virtual double velocitaScrittura() const override;



    void setPercLavoroBack(double value);

    void setSeparaInterfacce(bool value);

    DatiFullStack getDatiFullStack() const;
    void setDatiFullStack(const DatiFullStack& d);


protected:

    /*      VALORE LAVORO                   (metodo che eredita l'obbiettivo della classe base)*/
    virtual float valoreLavoro() const override;

    /*      RIUTILIZZABILITÀ                (metodo che eredita l'obbiettivo della classe base)*/
    virtual unsigned int riutilizzabilita() const override;

    /*      REMUNERAZIONE ORA ROUTINE       (metodo che eredita l'obbiettivo della classe: Employee)*/
    virtual float remunerazioneOraRoutine() const override;

private:

    double perc_lavoro_back;       //SLIDE (da 0 a 1, approx =2)                                                     // (1 - perc_lavoro_back) = perc_lavoro_front

    bool separa_interfacce;        // FLAG


};

#endif //CSVPARSER_FULLSTACK_H 
