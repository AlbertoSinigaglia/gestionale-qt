#include "Software.h" 

  

Software(Persona persona, DatiLavoratore dati_lavoratore, DatiDeveloping dati_developing):
                Employee(persona,dati_lavoratore),
                linguaggio(dati_developing.linguaggio),
                perc_ore_programmazione(dati_developing.perc_ore_programmazione),
                n_righe_totali(dati_developing.n_righe_totali),
                n_progetti_conclusi_mese(dati_developing.n_progetti_conclusi_mese),
                n_righe_mese(dati_developing.n_righe_mese),
                {}


void Software::aggiornaMese(){

    n_righe_totali += n_righe_mese;
    n_righe_mese = 0;
    n_progetti_conclusi_mese = 0;
}


unsigned int Software::gradoEsperienza() const{
    // Calcolo la proporzione tale per cui SOGLIA_N_RIGHE_SENIOR corrisponde a grado 10 
    int exp_software = 10 * n_righe_totali / Conv::soglia_n_righe_senior;
    if(exp_software>10) exp_software = 10;
    // Ora faccio la media pesata con l'esperienza offerta a livello Employee
    return (Employee::gradoEsperienza() + 2*exp_software) / 3;
}


double Software::velocitàScrittura() const{
    // ogni linguaggio introduce un aumento o decremento di velocità dovuto alla sua complessità
    double velocità_linguaggio = Conv::velocità_cpp / Conv::complessità_linguaggio[linguaggio];

    // tolgo un malus alla velocità di scrittura proporzionale all'esperienza se questa è inferiore alla sufficienza ( 6 )
    double malus_exp = velocità_linguaggio 
                      * calcoloBonusLineare( 6 , (10 - gradoEsperienza())/10.0 , Conv::malus_inseperto_scrittura);

    return velocità_linguaggio - malus_exp;
}


DifferenzaDate Software::durataCodice() const{
    // sulla base della stima del numero dei progetti a cui può sopravvivere il codice calcolo il tempo di vita del codice
    return static_const<DifferenzaDate> ( riutilizzabilità() * static_const<int>(Conv::durata_progetto_medio) );
}


unsigned int Software::riutilizzabilità() const{
    // impiegato di esperienza nella media produce un codice che mediamente viene riutilizzato in 3 progetti
    float peso_esperienza = UFMath::proporzionaleAMedia(3.0f, gradoEsperienza() );
    // maggiore sarà il rapporto: progettazione/sviluppo per un progetto migliori saranno le possibilità di riutilizzo del codice 
    // questo se 
    float peso_progettazione = UFMath::proporzionaleAMedia(10.0f, (1 - perc_ore_programmazione) );
    // return la media dei due pesi
    return static_cast<unsigned int> ( (peso_esperienza+peso_progettazione)/2 );
}


unsigned int Software::orePerProgetto() const{
    // calcolato sulla base di quanti progetti sono stati conclusi fino a questo punto del mese
    return  oreLavoroNelMese() / n_progetti_conclusi_mese;
}


unsigned int Software::righePerProgetto() const{

    return  n_righe_mese / n_progetti_conclusi_mese;
}


double Software::influenzaProgetto() const{
    //calcolo la media di righe prodotte per un progetto da un sviluppantore generico
    unsigned int media_righe_per_progetto = Conv::n_righe_progetto_medio / Conv::n_impiegati_progetto_medio;
    //restituisco il rapporto tra il num di righe che lui ha prodotto e quelle che produrrebbe uno sviluppatore generico 
    return static_cast<double>(righePerProgetto()) / static_cast<double>(media_righe_per_progetto);
}


float Software::valoreLavoro() const{
    /* Calcolo il valore che l'impiegato ha dato all'azienda dal punto di vista del contributo che ha dato ai progetti*/
    // calcolo il valore dei progetti in cui compare il codice che produce lo sviluppatore in questo mese
    float valore_totale_progetti = (n_progetti_conclusi_mese * durataCodice().anni) * Conv::valore_annuo_progetto_medio;
    // Dal valore totale dei progetti ricavo il valore apportato all'azienda dallo sviluppatore (rispetto al suo contributo)
    float valore_relativo_progetti = (valore_totale_progetti / Conv::n_impiegati_progetto_medio) * influenzaProgetto();

    return Employee::valoreLavoro() + valore_relativo_progetti;
}


bool Software::produttivo() const{
    // Calcolo quante righe si aspetterebbe che venissero prodotte da uno sviluppatore 
    // con le caratteristiche DA CONTRATTO dello sviluppantore in questione
    double ore_programmazione_tot = static_cast<double>(orePerProgetto()) * perc_ore_programmazione;
    int aspettativa_righe_per_progetto = static_cast<int>( velocitàScrittura() * ore_programmazione_tot );
    
    return Employee::produttivo() || (righePerProgetto() > aspettativa_righe_per_progetto);
}


float Software::bonusStipendio() const { 

    // calcolo il bonus dell'influenza sui progetti, assumendo valore di fondo scala un influenza = 2 e  influenza media = 1,
    // Pperciò adatto conseguentemmente calcoloBonusLineare(..)
    float bonus_influenza_progetti = calcoloBonusLineare(0.5, influenzaProgetto() / 2.0, Conv::bonus_influenza_progetto_doppia);    

    float bonus_linguaggio = bonus_complessità_CPP * complessità_linguaggio[linguaggio];

    return  Employee::bonusStipendio() + bonus_influenza_progetti + bonus_linguaggio;
}