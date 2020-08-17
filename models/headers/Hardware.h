#ifndef CSVPARSER_HARDWARE_H
#define CSVPARSER_HARDWARE_H


#include "Employee.h" 

class Hardware: virtual public Employee{

public:

    Hardware(const Persona& persona, const DatiLavoratore& dati_lavoratore, const DatiSistemi& dati_sistemi);

    /*      PRODUTTIVO                      (metodo che eredita l'obbiettivo della classe base)*/
    virtual bool produttivo() const override;

    /*      BOUNS STIPENDIO                 (metodo che eredita l'obbiettivo della classe base)*/
    virtual float bonusStipendio() const override;                                                                       //solo con certificato

    /*      AGGIORNA MESE                   (metodo che eredita l'obbiettivo della classe base)*/
    virtual void aggiornaMese() override;

    /*      GRADO ESPERIENZA                (metodo che eredita l'obbiettivo della classe base)
    * Viene calcolato sulla base del numero di sistemi gestiti totale
    */
    virtual unsigned int gradoEsperienza() const override;



    void setNuoviGestiti(unsigned int value);

    void setNSistemiGestiti(unsigned int value);

    void setNSistemiMalfunzionanti(unsigned int value);

    void setNSistemiGestitiTotale(unsigned int value);


    DatiSistemi getDatiSistemi() const;
    void setDatiSistemi(const DatiSistemi& d);

protected:

    unsigned int getNSistemiMalfunzionanti() const;
    unsigned int getNSistemiGestiti() const;


private:

    //     CAMPO MENSILE
    unsigned int nuovi_gestiti;                 // LINE_EDIT ( val minimo = 0, solo integer)

    unsigned int n_sistemi_gestiti;             // LINE_EDIT ( val minimo = 0, solo integer)
    unsigned int n_sistemi_malfunzionanti;      // LINE_EDIT ( val minimo = 0, solo integer)
    unsigned int n_sistemi_gestiti_totale;      // LINE_EDIT ( val minimo = 0, solo integer)
};



#endif //CSVPARSER_HARDWARE_H
