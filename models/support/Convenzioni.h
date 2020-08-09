#ifndef CONVENZIONI_GERARCHIA_H
#define CONVENZIONI_GERARCHIA_H

#include"Data.h"



namespace Conv{         // CONVENZIONI

// ------------------------------------------------------------------
//                          EXTRA AZIENDALI
// ------------------------------------------------------------------

    enum Libreria : short{
        BOOTSTRAP = 0,
        JQUERY = 1,
        TREEJS = 2,
        ANGULAR = 3,
        VUEJS = 4
    };
    enum Linguaggio :short {
         PYTHON = 0,
         JAVA = 1,
         PHP = 2,
         CPP = 3,
         SWIFT = 4,
         JAVASCRIPT = 5,
         RUBY = 6,
         SQL =7,
         TYPESCRIPT =8
    };


// ------------------------------------------------------------------
//                          DESIGN AZIENDALE
// ------------------------------------------------------------------

// --------
// EMPLOYEE
// --------

    /**
    * coeff_liquidazione:                      (Modificabile)
    *  coefficente (del TFR) * calcolaStipendio() -> ultima retribuzione per una possibile liquidazione
    */
    extern const double coeff_liquidazione;

    /**     PERCENTUALE REMUNERAZIONE
     * Stabilisce il raporto tra:      la remunerazione (per l'impiegato) del suo lavoro
     *                         e:      il valore lordo del lavoro dell'impiegato che apporta all'azienda
     */
    extern const double perc_remunerazione;

    extern const unsigned int soglia_anni_esperto;


// --------
// SOFTWARE
// --------

    extern const DifferenzaDate durata_progetto_medio;
    extern const unsigned int n_righe_progetto_medio;
    extern const unsigned int n_impiegati_progetto_medio;
    extern const float valore_annuo_progetto_medio;

    extern const double perc_codice_scritto;

    extern const double velocita_cpp;   // righe all'ora

    extern const unsigned int soglia_n_righe_senior;

    /*  array di corrispondenze: Linguaggio -> grado relativo di complessita del linguaggio,
        complessita relativa linguaggio(i) = (a parita di requisito) tempo impiegato per scrivere codice
                                             in linguaggio(i) / quello impiegato usando il C++
    */
    extern const float complessita_linguaggio[8];


// -----------
// MANUTENTORE
// -----------

    extern const double status_accettabile;

// --------
// HARDWARE
// -------- 

    extern const unsigned int soglia_sistemi_gestiti_esperto;

    extern const unsigned int media_n_nuovi_sistemi_mese;


// -------
// TECNICO
// ------- 

    extern const float remunerazione_ora_routine_tecnico;
    extern const unsigned int n_riparazioni_considervole_tecnico;

    extern const float valore_piccola_riparazione;
    extern const float valore_riparazione_sussistente;

    extern const float perdita_di_sussistenza;  // esprime quanto perde l'azienda all'ora in stallo a causa dell' assenza di un sistema di sussistenza

    extern const unsigned int ore_ripristino_stallo_pessimo;


// -------------
// ITSECURITYDEV
// -------------

    extern const float remunerazione_ora_routine_ITSecurityDev;
    extern const unsigned int n_riparazioni_considervole_ITSecurityDev;

    extern const float perdita_breccia;

    extern const float valore_manutenzione_non_critica;
    extern const float valore_manutenzione_critica;

    extern const double perc_pessimistica_manutenzioni_critiche;

    extern const unsigned int media_n_righe_manutenzione_critica;

    extern const unsigned int tolleranza_n_problemi_aperti_mese;

    extern const unsigned int n_problemi_sicurezza_nella_produzione_progetto;

// -------
// BACKDEV
// ------- 

    extern const double perc_media_capo_progetto ;

    extern const double perc_velocita_astrazione_5 ;
    extern const double malus_velocita_prove_corettezza ;

    extern const unsigned int riutilizzo_astrazione_5 ;
    extern const float valore_capo_progetto ;

// -----
// DBDEV
// ----- 

    extern const float remunerazione_ora_routine_DBDev ;

    extern const double media_attributi_ridondanti_per_entita ;
    extern const double moltiplicatore_ricicli_ortogonalita_10 ;
                 // indica di quante volte BackDev::riutilizzabilita() incrementa sulla base di quanto è ortogonale il codice
    extern const double speed_up_notevole_indicizzazioni ;

// --------
// FRONTDEV
// --------

    /*  array di corrispondenze: Libreria -> grado relativo di esaustivita e evolvibilita della libreria,
        esaustivita relativa libreria(i) = numero di unita di codice di tale libreria sfruttate in un progetto mediamente 
                                            / il numero di unita impiegate con ANGULAR
        evolvibilita della libreria(i) = numero di anni previsti di aggiornamento delle classi della libreria (i) / quelli previsti per la libreria ANGULAR
    */
    extern const float esaustivita_libreria[5] ;
    extern const float evolvibilita_libreria[5] ;

    extern const float speed_up_angular ;
    extern const unsigned int riutilizzo_codice_angular ;

    extern const unsigned int righe_progetto_perfezionate_media ;


// ------
// GUIDEV
// ------

    extern const float remunerazione_ora_routine_GUIDev ;


// --------------
// GUIDEV & DBDEV
// --------------
    extern const float valore_rispetto_orientamento ;


// ---------
// FULLSTACK
// ---------


    extern const float remunerazione_ora_routine_FullStack ;                                           // se modellazione, prove correttezza ecc..
    extern const double perc_minima_capo_progetti_FullStack ;

    extern const double malus_velocita_separazione_interfacce ;




// ------------------------------------------------------------------
//                        BONUS E MALUS AZIENDALI
// ------------------------------------------------------------------

// --------
// EMPLOYEE
// --------

    // bonus che viene dato all'impiegato che ha esperienza 10
    extern const float bonus_esperienza_generica_max ;

// --------
// SOFTWARE
// --------

    // assumo come valore di fondo scala di influenza in un progetto un influenza doppia rispetto a un generico
    // sviluppatore software quindi ne attribuisco un bonus
    extern const float bonus_influenza_progetto_doppia ;
    //bonus complessita del linguaggio rispetto al C++
    extern const float bonus_complessita_CPP ;

    // è un malus che esprime in quale percentuale la velocita di scrittura diminuisce per uno sviluppatore con grado Esperienza == 0
    extern const float malus_inseperto_scrittura ;

// -----------
// MANUTENTORE
// -----------

    extern const float bonus_status_ottimo ;

    extern const float bonus_n_riparazioni_considerevole ;

// --------
// HARDWARE
// --------

    // è il bonus che viene dato a chi raggiunge nell'istate a un nuomero di sitemi gestiti pari a 20
    extern const float bonus_dei_20_sistemi ;

// -------
// TECNICO
// -------

    // bonus che viene dato all'impiegato che gestisce solo sistemi di sussistenza
    extern const float bonus_solo_sussistenza ;


// -------------
// ITSECURITYDEV
// -------------

    extern const float bonus_delle_50_criticita ;

// -------
// BACKDEV
// -------

    extern const float bonus_orientamento_ortogonalita ;
    extern const float bonus_prove_correttezza ;

// -----
// DBDEV
// -----

    extern const float bonus_performance_DB_ottime ;

// --------
// FRONTDEV
// --------

    extern const float bonus_orientamento_professionalita ;
    extern const float bonus_meta_codice_adattato ;

// ------
// GUIDEV
// ------

    extern const float bonus_stile_GUI ;
    extern const float bonus_intuitivita_ottima ;
    extern const float bonus_professionalita_ottima ;

// ---------
// FULLSTACK
// ---------

    extern const float bonus_separazione_interfaccie ;

}
#endif // CONVENZIONI_GERARCHIA_H
