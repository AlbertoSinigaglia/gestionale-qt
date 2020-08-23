
#include "../headers/Hardware.h"

 
Hardware::Hardware(const Persona& persona, const DatiLavoratore& dati_lavoratore, const DatiSistemi& dati_sistemi):
                Employee(persona, dati_lavoratore),
                nuovi_gestiti(dati_sistemi.nuovi_gestiti),
                n_sistemi_gestiti(dati_sistemi.n_sistemi_gestiti),
                n_sistemi_malfunzionanti(dati_sistemi.n_sistemi_malfunzionanti),
                n_sistemi_gestiti_totale(dati_sistemi.n_sistemi_gestiti_totale){}


void Hardware::aggiornaMese(){

    n_sistemi_gestiti_totale += nuovi_gestiti;
    nuovi_gestiti = 0;
}


unsigned int Hardware::gradoEsperienza()  const{
    // Calocolo l'esperienza nel campo lavorativo Hardware
    int exp_hardware = 10 * n_sistemi_gestiti_totale / Conv::soglia_sistemi_gestiti_esperto;
    if(exp_hardware>10) exp_hardware = 10;
    // Ora calcolo la media pesata con l'esperienza a livello Employee
    return (Employee::gradoEsperienza() + 2*exp_hardware) / 3;
}


bool Hardware::produttivo() const{
    // Vene calcolato confrontando quanti sistemi ha acquisito fin ora nel mese con il numero di quelli che un impiegato hardware generico dovrebbe aver acquisito fin ora
    float punto_del_mese = static_cast<float>(Data::oggi().getGiorno()) / 31.0f;
    int media_nuovi_sistemi_presente = static_cast<int>( punto_del_mese * Conv::media_n_nuovi_sistemi_mese );

    return Employee::produttivo() || (static_cast<int>(nuovi_gestiti) > media_nuovi_sistemi_presente);
}


float Hardware::bonusStipendio() const{

    // calcolo un bonus che viene assegnato a chi gestisce molti sistemi, questo richiede una lavoro maggiore di organizzazione
    float bonus_quantitativo = calcoloBonusLineare(0.5, static_cast<double>(n_sistemi_gestiti) / 20.0, Conv::bonus_dei_20_sistemi);
    return Employee::bonusStipendio() + bonus_quantitativo;
}



unsigned int Hardware::getNSistemiMalfunzionanti() const{
    return n_sistemi_malfunzionanti;
}
unsigned int Hardware::getNSistemiGestiti() const{
    return n_sistemi_gestiti;
}




void Hardware::setNSistemiGestitiTotale(unsigned int value)
{
    n_sistemi_gestiti_totale = value;
}

void Hardware::setNSistemiMalfunzionanti(unsigned int value)
{
    n_sistemi_malfunzionanti = value;
}

void Hardware::setNSistemiGestiti(unsigned int value)
{
    n_sistemi_gestiti = value;
}

void Hardware::setNuoviGestiti(unsigned int value)
{
    nuovi_gestiti = value;
}



DatiSistemi Hardware::getDatiSistemi() const{
    return DatiSistemi{n_sistemi_gestiti, n_sistemi_malfunzionanti, n_sistemi_gestiti_totale, nuovi_gestiti};
}


void Hardware::setDatiSistemi(const DatiSistemi& d){
    nuovi_gestiti=d.nuovi_gestiti;
    n_sistemi_gestiti=d.n_sistemi_gestiti;
    n_sistemi_gestiti_totale=d.n_sistemi_gestiti_totale;
    n_sistemi_malfunzionanti=d.n_sistemi_malfunzionanti;
}
