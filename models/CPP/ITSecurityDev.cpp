#include "ITSecurityDev.h"


ITSecurityDev::ITSecurityDev(Persona persona, DatiLavoratore dati_lavoratore, DatiManutenzione dati_manutenzione, DatiDeveloping dati_developing, DatiRipristinoSicurezza dati_ripristino_sicurezza):
                Employee(persona, dati_lavoratore), Manutenzione(persona, dati_lavoratore, dati_manutenzione), Software(persona, dati_lavoratore, dati_developing),
                n_problemi_irrsolti(dati_ripristino_sicurezza.n_problemi_irrsolti),
                n_criticità_risolte(dati_ripristino_sicurezza.n_criticità_risolte){}


bool ITSecurityDev::commitProblemaRisolto(bool isCriticità){

    if(n_problemi_irrsolti > 0){
        n_problemi_irrsolti --;
        setNRiparazioniMese( getNRiparazioniMese +1);
        if(isCriticità)
                n_criticità_risolte ++;
        return true;
    }
    return false;
}


void ITSecurityDev::aggiornaMese(){

    Manutenzione::aggiornaMese();
    Software::aggiornaMese();

    n_criticità_risolte = 0;
}


double ITSecurityDev::influenzaProgetto() const{
    //Nella produzione di un progetto un esperto di sicurezza non ha molta influenza perciò l'influenza della sua scrittura
    //è pesata negativamente con un malus del 50%
    double influenza_scrittura = Software::influenzaProgetto();  // probabilmente bassa a causa di un basso num di righe di codice scritte

    // Essere il manutentore del 60% dei problemi di sicurezza di un progetto è una condizione di influenza standard nel progetto (dal punto di vista della manutenzione)
    double influenza_mantenimento_sicurezza = (mediaNManutenzioniPerProgetto() / Conv::n_problemi_sicurezza_nella_produzione_progetto) /0.6;

    return (influenza_scrittura + influenza_mantenimento_sicurezza) /2.0;
}


double ITSecurityDev::velocitàScrittura() const{
    // Il codice scritto da un esperto di sicurezza è essenzialmente più uniforme rispetto al codice degli altri sviluppatori perciò ha un proprio speed-Up d2l 120%
    return Software::velocitàScrittura() * 1.20;
}

unsigned int ITSecurityDev::riutilizzabilità() const{
    // Il codice scritto per la manutenione di un progetto può essere impiegato solo in quel progetto
    return 1;
}


double ITSecurityDev::mediaNManutenzioniPerProgetto() const{

    return getNRiparazioniMese() / getNProgettiConclusiMese();
}



unsigned int ITSecurityDev::righeManutenzioneNonCritica() const{

    unsigned int righe_mese_manutenzione_non_critica = getNRigheMese() - n_criticità_risolte * Conv::media_n_righe_manutenzione_critica;

    return righe_mese_manutenzione_non_critica / getNManutenzioniNonCritiche();
}


double ITSecurityDev::percRipristino() const{

    // Calcolo il numero di righe per le manutenzioni di problemi previsti nel caso pessimo in cui tra di loro ci sia un alto numero di problemi critici
    double n_manutenzioni_critiche_previste = n_problemi_irrsolti * Conv::perc_pessimistica_manutenzioni_critiche;

    // Cerco di stimare il numero di righe che aspettano al ITSDev per ripristinare la situazione di normalità ponderandole nei casi Criticità / Non criticità
    double righe_previste_di_manutanzione = n_manutenzioni_critiche_previste * Conv::media_n_righe_manutenzione_critica
                                            + (n_problemi_irrsolti - n_manutenzioni_critiche_previste) * righeManutenzioneNonCritica();

    return getNRigheMese() / ( righe_previste_di_manutanzione + getNRigheMese() );
}






float ITSecurityDev::valoreLavoro() const{

    float valore_scampate_brecce = static_cast<float>( n_criticità_risolte * Conv::perdita_breccia );

    return Manutenzione::valoreLavoro() + Software::valoreLavoro() + valore_scampate_brecce;
}


bool ITSecurityDev::produttivo() const{

    bool condizione_sicurezza_accettabile = n_problemi_irrsolti > Conv::tolleranza_n_problemi_aperti_mese;
    return condizione_sicurezza_accettabile && ( Manutenzione::produttivo() && Software::produttivo() );
}


float ITSecurityDev::bonusStipendio() const{

    double n_criticità_nel_mese = n_criticità_risolte * Data::oggi().getGiorno / 31.0 ;

    float bonus_quantità_criticità_gestite = (0.5, n_criticità_nel_mese / 50.0 , Conv::bonus_delle_50_criticità);

    return Manutenzione::bonusStipendio() + Software::bonusStipendio() + bonus_quantità_criticità_gestite;

}







float ITSecurityDev::valoreMedioRiparazione() const{

    return UFMath::mediaPonderata( getNManutenzioniNonCritiche(), Conv::valore_manutenzione_non_critica, n_criticità_risolte, Conv::valore_manutenzione_critica ) ;
}

unsigned int ITSecurityDev::quantitàConsiderevoleRiparazioni() const{
    return Conv::n_riparazioni_considervole_ITSecurityDev;
}

float ITSecurityDev::remunerazioneOraRoutine() const{
    return Conv::remunerazione_ora_routine_ITSecurityDev;
}






unsigned int ITSecurityDev::getNManutenzioniNonCritiche() const{

    return getNRiparazioniMese() - n_criticità_risolte;
}
unsigned int ITSecurityDev::getNManutenzioniCritiche() const{
    
    return n_criticità_risolte;
}