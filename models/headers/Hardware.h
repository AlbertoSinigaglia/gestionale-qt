//
// Created by Alberto Sinigaglia on 05/04/2020.
// 
  
#ifndef CSVPARSER_HARDWARE_H
#define CSVPARSER_HARDWARE_H


#include "Employee.h" 

class Hardware: virtual public Employee{

public:

    Hardware(Persona persona, DatiLavoratore dati_lavoratore, DatiSistemi dati_sistemi);

    /*      PRODUTTIVO                      (metodo che eredita l'obbiettivo della classe base)*/
    virtual bool produttivo() const;

    /*      BOUNS STIPENDIO                 (metodo che eredita l'obbiettivo della classe base)*/
    virtual float bonusStipendio() const;                                                                       //solo con certificato

    /**     AGGIORNA MESE                   (metodo che eredita l'obbiettivo della classe base)*/
    virtual void aggiornaMese();

    /*      GRADO ESPERIENZA                (metodo che eredita l'obbiettivo della classe base)
    * Viene calcolato sulla base del numero di sistemi gestiti totale
    */
    virtual unsigned int gradoEsperienza()  const;  


protected:

unsigned int getNSistemiMalfunzionanti() const;
unsigned int getNSistemiGestiti() const;
unsigned int getPercSistemiSussistenza() const;


private:

    //     CAMPO MENSILE
    unsigned int nuovi_gestiti;                

    unsigned int n_sistemi_gestiti;
    unsigned int n_sistemi_malfunzionanti;
    unsigned int n_sistemi_gestiti_totale;    
};



#endif //CSVPARSER_HARDWARE_H
