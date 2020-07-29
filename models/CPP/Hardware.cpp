//
// Created by Alberto Sinigaglia on 05/04/2020.
//
 
#include "Hardware.h" 

 
Hardware::Hardware(Persona persona, DatiLavoratore dati_lavoratore, DatiSistemi dati_sistemi):
                Employee(persona,dati_sistemi.dati_lavoratore),
                n_sistemi_gestiti(dati_sistemi.n_sistemi_gestiti),
                n_sistemi_malfunzionanti(dati_sistemi.n_sistemi_malfunzionanti),
                n_sistemi_gestiti_totale(dati_sistemi.n_sistemi_gestiti_totale),
                nuovi_gestiti(dati_sistemi.nuovi_gestiti){}


void Hardware::aggiornaMese(){

    n_sistemi_gestiti_totale = nuovi_gestiti;
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

    return Employee::produttivo() || (nuovi_gestiti > media_nuovi_sistemi_presente);
}


float Hardware::bonusStipendio() const{

    // calcolo un bonus che viene assegnato a chi gestisce molti sistemi, questo richiede una lavoro maggiore di organizzazione
    float bonus_quantitativo = calcoloBonusLineare(0.5, static_cast<double>(n_sistemi_gestiti) / 20.0, Conv::bonus_dei_20_sistemi);
    return Employee::bonusStipendio() + bonus_responsabilità + bonus_quantitativo;
}







unsigned int Hardware::getNSistemiMalfunzionanti() const{

}
unsigned int Hardware::getNSistemiGestiti() const{

}
unsigned int Hardware::getPercSistemiSussistenza() const{

}

