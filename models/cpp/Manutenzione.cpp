
#include "../headers/Manutenzione.h"

Manutenzione::Manutenzione(const Persona& persona, const DatiLavoratore& dati_lavoratore, const DatiManutenzione& dati_manutenzione):
                Employee(persona,dati_lavoratore),
                perc_riparazioni_inefficaci(dati_manutenzione.perc_riparazioni_inefficaci),
                n_riparazioni_mese(dati_manutenzione.n_riparazioni_mese),
                perc_ripristino_medio(dati_manutenzione.perc_ripristino_medio){}


void Manutenzione::aggiornaMese(){
    // aggiorno la percentuale di ripristino medio che tiene conto del grado di manutenzione in tutto l'arco lavorativo
    int mesi_dall_assunzione = (Data::oggi()-getDataAssunzione()).inMesi();
    // ..sotto l'assunzione che percRipristino mi ritorna il grado di manutenzione del mese contemporaneo..
    //Calcolo una media pesata in modo che rimanga rispettata la definizione di perc_ripristino_medio 
    perc_ripristino_medio = UFMath::mediaPonderata(static_cast<double>(mesi_dall_assunzione), perc_ripristino_medio, 1.0, percRipristino());

    n_riparazioni_mese = 0;
}


bool Manutenzione::produttivo() const{
    // integro la condizione di mantenere nel mese presente un buon grado di manutenzione 
    return Employee::produttivo() || (percRipristino() > Conv::status_accettabile);
}


float Manutenzione::bonusStipendio() const{

    float bonus_competenza = calcoloBonusLineare( Conv::status_accettabile, perc_ripristino_medio, Conv::bonus_status_ottimo );
    
    unsigned int n_riparazioni_considerevoli_nel_mese = quantitaConsiderevoleRiparazioni() * Data::oggi().getGiorno() / 31 ;
    float bonus_quantita_riparazioni = calcoloBonusLineare( 0.5,
                                                            n_riparazioni_mese / n_riparazioni_considerevoli_nel_mese,
                                                            Conv::bonus_n_riparazioni_considerevole );

    return Employee::bonusStipendio() + bonus_competenza + bonus_quantita_riparazioni;
}


float Manutenzione::valoreLavoro() const{
    //tolgo un malus (derivato dalle riparazioni inefficaci) al valore del suo lavoro ottenuto dal valore di tutte le sue riparazioni
    float valore_riparzioni = (n_riparazioni_mese * (1.0 - perc_riparazioni_inefficaci)) * valoreMedioRiparazione();
    return valore_riparzioni;
}





double Manutenzione::getPercRiparazioniInefficaci() const{
    return perc_riparazioni_inefficaci;
}

unsigned int Manutenzione::getNRiparazioniMese() const{
    return n_riparazioni_mese;
}




void Manutenzione::setPercRipristinoMedio(double value)
{
    perc_ripristino_medio = value;
}

void Manutenzione::setNRiparazioniMese(unsigned int value)
{
    n_riparazioni_mese = value;
}

void Manutenzione::setPercRiparazioniInefficaci(double value)
{
    perc_riparazioni_inefficaci = value;
}



DatiManutenzione Manutenzione::getDatiManutenzione() const{
    return DatiManutenzione{perc_riparazioni_inefficaci, perc_ripristino_medio, n_riparazioni_mese};
}


void Manutenzione::setDatiManutenzione(const DatiManutenzione& d){
    n_riparazioni_mese=d.n_riparazioni_mese;
    perc_ripristino_medio=d.perc_ripristino_medio;
    perc_riparazioni_inefficaci=d.perc_riparazioni_inefficaci;
}
