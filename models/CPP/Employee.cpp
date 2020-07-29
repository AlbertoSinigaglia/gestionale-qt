#include "Employee.h"
#include "Data.h"  
#include "Convenzioni.cpp"
#include "UsefullMath.cpp"
#include <math.h>
 


Employee::Employee(Persona persona, DatiLavoratore dati_lavoratore): 
                    Persona(persona),
                    data_assunzione(dati_lavoratore.data_assunzione), 
                    fine_contratto(dati_lavoratore.fine_contratto), 
                    ore_lavoro_sett(dati_lavoratore.ore_lavoro_sett), 
                    quota_aggiuntiva(dati_lavoratore.quota_aggiuntiva) {}


float Employee::calcolaStipendio() const{
    /* Assunzione: Lo stipendio di contratto è calcolato come la remunerazione 
     * delle ore mensili di lavoro di routine
     */
    float ore_al_mese = static_cast<float>(ore_lavoro_sett) * 30.0f / 7.0f;
    float stipendio_contratto = remunerazioneOraRoutine() * ore_al_mese;

    float result = stipendio_contratto + bonusStipendio() + quota_aggiuntiva;
    // e arrotondo il risultato alla seconda cifra decimale; (risultato in euro)
    return static_cast<float>(round(result*100))/100.0f;
}


unsigned int Employee::risarcimentoLiquidazione() const{
    return calcolaStipendio() * static_cast<float>(Conv::coeff_liquidazione);
}


void Employee::AumentoStipendo(float aumento){
    quota_aggiuntiva+=aumento;
}


void Employee::prorogaContratto(DifferenzaDate aggiunta){          
     fine_contratto.addRemoveGiorni(aggiunta);
}


unsigned int Employee::gradoEsperienza() const{
    int anni_dall_assunzione = (Data::oggi()-data_assunzione).anni;
    int exp_generica = 10 * anni_dall_assunzione / Conv::soglia_anni_esperto;
        if(exp_generica>10) exp_generica = 10;
    
    return exp_generica;
}


bool Employee::produttivo() const {
    /** Al primo livello di gerarchia (Employee) valore di lavoro detiene l'informazione più 
     * importante: "valuta se il valore che da all'azienda è maggiore di quanto recepisce"
     * QUESTA È UNA CONDIZIONE NON STRETTAMENTE NECESSARIA ALLA PRODUTTIVITÀ
     */
    float remunerazione_effettiva = calcolaStipendio() * static_cast<float>(Data::oggi().getGiono) / 31.0f;
    float remunerazione_meritata = valoreLavoro() * Conv::perc_remunerazione;

    return (remunerazione_meritata >= remunerazione_effettiva);
}

float Employee::bonusStipendio() const{
    float bonus_esperienza = calcoloBonusLineare(0.6, gradoEsperienza() /10.0, Conv::bonus_esperienza_generica_max );
    return bonus_esperienza;
}










float Employee::calcoloBonusLineare(double percBase, double perc, float bonus_max){
    
    if(perc < percBase) return 0;
    if(perc > 1) return bonus_max;
    //la seguente formula permette di calcolare il bonus sulla base di una proporzione (direttam. proporz.)
    // che fa corrispondere perc. = percBase a bonus = 0  e  perc. = 1  a bonus = bonusMax
    return (bonus_max / (1-percBase)) * (perc - percBase);
}


unsigned int Employee::oreLavoroNelMese() const{

    return Data::oggi().getGiorno() * ( ore_lavoro_sett / 7 ) ;
}


Data Employee::getDataAssunzione() const{

}
unsigned int Employee::getOreLavoroSett() const{

}