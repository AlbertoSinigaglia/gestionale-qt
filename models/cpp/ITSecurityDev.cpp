#include "../headers/ITSecurityDev.h"


ITSecurityDev::ITSecurityDev(const Persona & persona, const DatiLavoratore & dati_lavoratore, const DatiManutenzione & dati_manutenzione, const DatiDeveloping & dati_developing, const DatiRipristinoSicurezza & dati_ripristino_sicurezza):
                Employee(persona, dati_lavoratore), Software(persona, dati_lavoratore, dati_developing), Manutenzione(persona, dati_lavoratore, dati_manutenzione),
                n_problemi_irrsolti(dati_ripristino_sicurezza.n_problemi_irrsolti),
                n_criticita_risolte(dati_ripristino_sicurezza.n_criticita_risolte){}


bool ITSecurityDev::commitProblemaRisolto(bool isCriticita){

    if(n_problemi_irrsolti > 0){
        n_problemi_irrsolti --;
        setNRiparazioniMese( getNRiparazioniMese() +1);
        if(isCriticita)
                n_criticita_risolte ++;
        return true;
    }
    return false;
}


void ITSecurityDev::aggiornaMese(){

    Manutenzione::aggiornaMese();
    Software::aggiornaMese();

    n_criticita_risolte = 0;
}


double ITSecurityDev::NManutenzioniPerProgetto() const{
    if(getNProgettiConclusiMese()>2 && getNRiparazioniMese()>Conv::n_problemi_sicurezza_nella_produzione_progetto)
        return getNRiparazioniMese() / getNProgettiConclusiMese();
        else  // se le informazioni non sono sufficienti ritorno quella che è la media del numero di manutenzioni per un progetto
        return Conv::n_problemi_sicurezza_nella_produzione_progetto;
}


double ITSecurityDev::influenzaProgetto() const{
    //Nella produzione di un progetto un esperto di sicurezza non ha molta influenza percio l'influenza della sua scrittura
    //e pesata negativamente con un malus del 50%
    double influenza_scrittura = Software::influenzaProgetto();  // probabilmente bassa a causa di un basso num di righe di codice scritte

    // Essere il manutentore del 60% dei problemi di sicurezza di un progetto è una condizione di influenza standard nel progetto (dal punto di vista della manutenzione)
    double influenza_mantenimento_sicurezza = (NManutenzioniPerProgetto() / Conv::n_problemi_sicurezza_nella_produzione_progetto) /0.6;

    return (influenza_scrittura + influenza_mantenimento_sicurezza) /2.0;
}


double ITSecurityDev::velocitaScrittura() const{
    // Il codice scritto da un esperto di sicurezza e essenzialmente più uniforme rispetto al codice degli altri sviluppatori percio ha un proprio speed-Up d2l 120%
    return Software::velocitaScrittura() * 1.20;
}

unsigned int ITSecurityDev::riutilizzabilita() const{
    // Il codice scritto per la manutenione di un progetto puo essere impiegato solo in quel progetto
    return 1;
}


double ITSecurityDev::percRipristino() const{

    // Calcolo il numero di righe per le manutenzioni di problemi previsti nel caso pessimo in cui tra di loro ci sia un alto numero di problemi critici
    double n_manutenzioni_critiche_previste = n_problemi_irrsolti * Conv::perc_pessimistica_manutenzioni_critiche;

    // Cerco di stimare il numero di righe che aspettano al ITSDev per ripristinare la situazione di normalita ponderandole nei casi criticita / Non criticita
    double righe_previste_di_manutanzione = n_manutenzioni_critiche_previste * Conv::media_n_righe_manutenzione_critica
                                            + (n_problemi_irrsolti - n_manutenzioni_critiche_previste) * Conv::media_n_righe_manutenzione_non_critica;

    return getNRigheMese() / ( righe_previste_di_manutanzione + getNRigheMese() );
}






float ITSecurityDev::valoreLavoro() const{

    float valore_scampate_brecce = static_cast<float>( n_criticita_risolte * Conv::perdita_breccia );

    return Manutenzione::valoreLavoro() + valore_scampate_brecce;
}


bool ITSecurityDev::produttivo() const{

    bool condizione_sicurezza_accettabile = n_problemi_irrsolti < Conv::tolleranza_n_problemi_aperti_mese;
    return condizione_sicurezza_accettabile && ( Manutenzione::produttivo() && Software::produttivo() );
}


float ITSecurityDev::bonusStipendio() const{

    double n_criticita_nel_mese = n_criticita_risolte * Data::oggi().getGiorno() / 31.0 ;

    float bonus_quantita_criticita_gestite = calcoloBonusLineare(0.5, n_criticita_nel_mese / 50.0 , Conv::bonus_delle_50_criticita);

    return bonus_quantita_criticita_gestite + Manutenzione::bonusStipendio() + Software::bonusStipendio() - Employee::bonusStipendio();

}





float ITSecurityDev::valoreMedioRiparazione() const{
    int p = getNRiparazioniMese() - n_criticita_risolte; if(p<0) p=0;
    return UFMath::mediaPonderata( static_cast<unsigned int>(p) , Conv::valore_manutenzione_non_critica, n_criticita_risolte, Conv::valore_manutenzione_critica ) ;
}

unsigned int ITSecurityDev::quantitaConsiderevoleRiparazioni() const{
    return Conv::n_riparazioni_considervole_ITSecurityDev;
}

float ITSecurityDev::remunerazioneOraRoutine() const{
    return Conv::remunerazione_ora_routine_ITSecurityDev;
}




void ITSecurityDev::setNCriticitaRisolte(unsigned int value)
{
    n_criticita_risolte = value;
}

void ITSecurityDev::setNProblemiIrrsolti(unsigned int value)
{
    n_problemi_irrsolti = value;
}



DatiRipristinoSicurezza ITSecurityDev::getDatiRipristinoSicurezza() const{
    return DatiRipristinoSicurezza{n_problemi_irrsolti, n_criticita_risolte};
    }


void ITSecurityDev::setDatiRipristinoSicurezza(const DatiRipristinoSicurezza& d){
    n_criticita_risolte=d.n_criticita_risolte;
    n_problemi_irrsolti=d.n_problemi_irrsolti;
}
