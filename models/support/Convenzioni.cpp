#include "models/support/Convenzioni.h"

namespace Conv{

        const double coeff_liquidazione{0.889};
        const double perc_remunerazione{0.8};
        const unsigned int soglia_anni_esperto{20};

        const unsigned int durata_progetto_medio_in_giorni = 200;
        const unsigned int n_righe_progetto_medio{5000};
        const unsigned int ore_progetto_medio{18};
        const unsigned int n_impiegati_progetto_medio{10};
        const float valore_al_giorno_progetto_medio{2.5};
        const double velocita_cpp{50};
        const unsigned int soglia_n_righe_senior{1000000};
        const float complessita_linguaggio[8]{0.8f, 0.85f, 0.95f, 1.0f, 0.85f, 0.98f, 0.75f, 0.7f};

        const double status_accettabile{0.7};
        const unsigned int soglia_sistemi_gestiti_esperto{1000};
        const unsigned int media_n_nuovi_sistemi_mese{3};

        const float remunerazione_ora_routine_tecnico{8};
        const unsigned int n_riparazioni_considervole_tecnico = 70;
        const float valore_piccola_riparazione = 30;
        const float valore_riparazione_sussistente = 65;
        const float perdita_di_sussistenza = 200;
        const unsigned int ore_ripristino_stallo = 5;

        const float remunerazione_ora_routine_ITSecurityDev = 10;
        const unsigned int n_riparazioni_considervole_ITSecurityDev = 110;
        const float perdita_breccia = 100;
        const float valore_manutenzione_non_critica = 50;
        const float valore_manutenzione_critica = 70;
        const double perc_pessimistica_manutenzioni_critiche = 0.1;
        const unsigned int media_n_righe_manutenzione_non_critica = 40;
        const unsigned int media_n_righe_manutenzione_critica = 55;

        const unsigned int tolleranza_n_problemi_aperti_mese = 40;
        const unsigned int n_problemi_sicurezza_nella_produzione_progetto= 10;

        const double perc_media_capo_progetto = 0.3;
        const double perc_velocita_astrazione_5 = 0.88;
        const double malus_velocita_prove_corettezza = 0.05;
        const unsigned int riutilizzo_astrazione_5 = 4;
        const float valore_capo_progetto = 200;

        const float remunerazione_ora_routine_DBDev = 12;
        const double media_attributi_ridondanti_per_entita = 0.2;
        const double moltiplicatore_ricicli_ortogonalita_10 = 1.3;
        const double speed_up_notevole_indicizzazioni = 2.0;

        const float esaustivita_libreria[5] = { 0.85 , 1.15 , 0.95 , 1 , 0.8 };
        const float evolvibilita_libreria[5] = { 0.9 , 1.1 , 0.8 , 1 , 0.85 };
        const float speed_up_angular = 1.0;
        const unsigned int riutilizzo_codice_angular = 5;
        const unsigned int righe_progetto_perfezionate_media = 200;
        const float remunerazione_ora_routine_GUIDev = 10;

        const float valore_rispetto_orientamento = 100;

        const float remunerazione_ora_routine_FullStack = 15;                                           // se modellazione, prove correttezza ecc..
        const double perc_minima_capo_progetti_FullStack = 0.5;
        const double malus_velocita_separazione_interfacce = 0.05;



        const float bonus_esperienza_generica_max = 50;
        const float bonus_influenza_progetto_doppia = 50;
        const float bonus_complessita_CPP = 20;
        const float malus_inseperto_scrittura = 0.1;
        const float bonus_status_ottimo = 80;
        const float bonus_n_riparazioni_considerevole = 50;
        const float bonus_dei_20_sistemi = 50;
        const float bonus_solo_sussistenza = 40;
        const float bonus_delle_50_criticita = 50;
        const float bonus_orientamento_ortogonalita = 80;
        const float bonus_prove_correttezza = 20;
        const float bonus_performance_DB_ottime = 80;
        const float bonus_orientamento_professionalita = 80;
        const float bonus_meta_codice_adattato = 20;
        const float bonus_stile_GUI = 80;
        const float bonus_intuitivita_ottima = 80;
        const float bonus_professionalita_ottima = 80;
        const float bonus_separazione_interfaccie = 100;
}
