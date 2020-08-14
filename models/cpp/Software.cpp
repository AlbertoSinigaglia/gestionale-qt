#include "../headers/Software.h"

Software::Software(const Persona& persona, const DatiLavoratore& dati_lavoratore, const DatiDeveloping& dati_developing):
                Employee(persona,dati_lavoratore),
                linguaggio(dati_developing.linguaggio),
                perc_ore_programmazione(dati_developing.perc_ore_programmazione),
                n_righe_totali(dati_developing.n_righe_totali),
                n_progetti_conclusi_mese(dati_developing.n_progetti_conclusi_mese),
                n_righe_mese(dati_developing.n_righe_mese)
                {};


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


double Software::velocitaScrittura() const{
    // ogni linguaggio introduce un aumento o decremento di velocita dovuto alla sua complessita
    double velocita_linguaggio = Conv::velocita_cpp / Conv::complessita_linguaggio[linguaggio];

    // tolgo un malus alla velocita di scrittura proporzionale all'esperienza se questa e inferiore alla sufficienza ( 6 )
    double malus_exp = velocita_linguaggio 
                      * calcoloBonusLineare( 6 , (10 - gradoEsperienza())/10.0 , Conv::malus_inseperto_scrittura);

    return velocita_linguaggio - malus_exp;
}


DifferenzaDate Software::durataCodice() const{
    // sulla base della stima del numero dei progetti a cui puo sopravvivere il codice calcolo il tempo di vita del codice
    return DifferenzaDate{0,0,static_cast<int>(riutilizzabilita() *Conv::durata_progetto_medio_in_giorni)};
}


unsigned int Software::riutilizzabilita() const{
    // impiegato di esperienza ottima produce un codice che mediamente viene riutilizzato in 5 progetti
    float peso_esperienza = calcoloBonusLineare( 0 , (gradoEsperienza()/10.0) , 5);
    // maggiore sara il rapporto: progettazione/sviluppo per un progetto migliori saranno le possibilita di riutilizzo del codice 
    // questo se 
    float peso_progettazione = calcoloBonusLineare( 0 , (1 - perc_ore_programmazione) , 8);
    // return la media dei due pesi
    return static_cast<unsigned int> ( (peso_esperienza+peso_progettazione)/2 );
}


unsigned int Software::orePerProgetto() const{
    // calcolato sulla base di quanti progetti sono stati conclusi fino a questo punto del mese
    if(n_progetti_conclusi_mese<2)
        return Conv::ore_progetto_medio;
        else   // se i dati sono sufficenti a dare una stima più precisa del caso specifico
    return  oreLavoroNelMese() / n_progetti_conclusi_mese;
}


unsigned int Software::righePerProgetto() const{
    int numero_medio_righe_per_progetto = Conv::n_righe_progetto_medio / Conv::n_impiegati_progetto_medio;
    if(n_progetti_conclusi_mese>1 && n_righe_mese > numero_medio_righe_per_progetto)
        return  n_righe_mese / n_progetti_conclusi_mese;
        else// Se ho un insufficienza di dati per caclolare questo valore mi avvalgo di una media
        return numero_medio_righe_per_progetto;
}


double Software::influenzaProgetto() const{

    //restituisco il rapporto tra il num di righe che lui ha prodotto e quelle che produrrebbe uno sviluppatore generico 
    return static_cast<double>(righePerProgetto()) / static_cast<double>(Conv::n_righe_progetto_medio / Conv::n_impiegati_progetto_medio);

}


float Software::valoreLavoro() const{
    /* Calcolo il valore che l'impiegato ha dato all'azienda dal punto di vista del contributo che ha dato ai progetti*/
    // calcolo il valore dei progetti in cui compare il codice che produce lo sviluppatore in questo mese
    float valore_totale_progetti = (n_progetti_conclusi_mese * durataCodice().giorni) * Conv::valore_al_giorno_progetto_medio;
    // Dal valore totale dei progetti ricavo il valore apportato all'azienda dallo sviluppatore (rispetto al suo contributo)
    float valore_relativo_progetti = (valore_totale_progetti / Conv::n_impiegati_progetto_medio) * influenzaProgetto();

    return valore_relativo_progetti;
}


bool Software::produttivo() const{
    //se uno sviluppatore ha un influenza inferiore alla metà di uno sviluppatore generico nel progetto allora non è produttivo
    if(influenzaProgetto() < 0.5) return false;
    // Calcolo quante righe si aspetterebbe che venissero prodotte da uno sviluppatore 
    // con le caratteristiche DA CONTRATTO dello sviluppantore in questione
    double ore_programmazione_tot = static_cast<double>(orePerProgetto()) * perc_ore_programmazione;
    int aspettativa_righe_per_progetto = static_cast<int>( velocitaScrittura() * ore_programmazione_tot );
    
    return Employee::produttivo() || (righePerProgetto() > aspettativa_righe_per_progetto);
}


float Software::bonusStipendio() const { 

    // calcolo il bonus dell'influenza sui progetti, assumendo valore di fondo scala un influenza = 2 e  influenza media = 1,
    // Ppercio adatto conseguentemmente calcoloBonusLineare(..)
    float bonus_influenza_progetti = calcoloBonusLineare(0.5, influenzaProgetto() / 2.0, Conv::bonus_influenza_progetto_doppia);    

    float bonus_linguaggio = Conv::bonus_complessita_CPP * Conv::complessita_linguaggio[linguaggio];

    return  Employee::bonusStipendio() + bonus_influenza_progetti + bonus_linguaggio;
}


unsigned int Software::getNProgettiConclusiMese() const{
    return n_progetti_conclusi_mese;
}

unsigned int Software::getNRigheMese() const{
    return n_righe_mese;
}



void Software::setPercOreProgrammazione(double value)
{
    perc_ore_programmazione = value;
}

void Software::setNRigheTotali(unsigned int value)
{
    n_righe_totali = value;
}

void Software::setNProgettiConclusiMese(unsigned int value)
{
    n_progetti_conclusi_mese = value;
}

void Software::setNRigheMese(unsigned int value)
{
    n_righe_mese = value;
}



DatiDeveloping Software::getDatiDeveloping() const{
    return DatiDeveloping{linguaggio, perc_ore_programmazione, n_righe_totali, n_righe_mese, n_progetti_conclusi_mese};
}


void Software::setDatiDeveloping(const DatiDeveloping& d){
    linguaggio=d.linguaggio;
    n_righe_mese=d.n_righe_mese;
    n_righe_totali=d.n_righe_totali;
    perc_ore_programmazione=d.perc_ore_programmazione;
    n_progetti_conclusi_mese=d.n_progetti_conclusi_mese;
}
