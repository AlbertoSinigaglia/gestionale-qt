#include"Data.h"
#include"Convenzioni.cpp"


// Campi dati estesi dalla classe Employee

struct DatiLavoratore{
    Data data_assunzione;
    Data fine_contratto; 
    unsigned int ore_lavoro_sett; 
    float quota_aggiuntiva;

    DatiLavoratore(Data da, Data fc, unsigned int ols, float qa = 0.0f):
            data_assunzione(da),
            fine_contratto(fc),
            ore_lavoro_sett(ols),
            quota_aggiuntiva(qa){}
};

// Campi dati estesi dalla classe Software

struct DatiDeveloping{
    Conv::Linguaggio linguaggio;
    double perc_ore_programmazione;
    unsigned int n_righe_totali;  
    unsigned int n_righe_mese;      
    unsigned int n_progetti_conclusi_mese;

    DatiDeveloping(Conv::Linguaggio l, double pop, unsigned int nrt = 0, 
                    unsigned int nrm = 0, unsigned int npcm = 0):
            linguaggio(l),
            perc_ore_programmazione(pop),
            n_righe_totali(nrt),
            n_righe_mese(nrm),
            n_progetti_conclusi_mese(npcm){}
};

// Campi dati estesi dalla classe Manutentore

struct DatiManutenzione{
    unsigned int perc_riparazioni_inefficaci;
    double perc_ripristino_medio;
    unsigned int n_riparazioni_mese;

    DatiManutenzione(unsigned int prp, double prm = 1, unsigned int nrm = 0):
            perc_riparazioni_inefficaci(prp),
            perc_ripristino_medio(prm),
            n_riparazioni_mese(nrm){}
};

// Campi dati estesi dalla classe Hardware

struct DatiSistemi{
    unsigned int n_sistemi_gestiti;     
    unsigned int n_sistemi_malfunzionanti;
    unsigned int n_sistemi_gestiti_totale;   
    unsigned int nuovi_gestiti;   

    DatiSistemi(unsigned int nsg, unsigned int nsm, 
                unsigned int nsgt = 0, unsigned int ng = 0):
            n_sistemi_gestiti(nsg),
            n_sistemi_malfunzionanti(nsm),
            n_sistemi_gestiti_totale(nsgt),
            nuovi_gestiti(ng){}
};

// Campi dati estesi dalla classe Tecnico

struct DatiRiparazioneSistemi{
    unsigned int n_riparazioni_senza_stallo;
    unsigned int perc_riparazioni_sussistenti;
    unsigned int ore_stallo_mensili;
    unsigned int ore_straordinari;

    DatiRiparazioneSistemi(unsigned int prs = 0, unsigned int osm = 0, unsigned int os = 0):
            perc_riparazioni_sussistenti(prs),
            ore_stallo_mensili(osm),
            ore_straordinari(os){}
};

// Campi dati estesi dalla classe ITSecurityDev

struct DatiRipristinoSicurezza{
    unsigned int n_problemi_irrsolti;   
    unsigned int n_progetti_in_arrivo;          
    unsigned int n_criticità_risolte;  

    DatiRipristinoSicurezza(unsigned int npi = 0, unsigned int npin = 0, unsigned int ncr = 0):
            n_problemi_irrsolti(npi),
            n_progetti_in_arrivo(npin),
            n_criticità_risolte(ncr){}
};

// Campi dati estesi dalla classe BackDev

struct DatiLatoServer{
    double perc_capo_progetto;
    unsigned int livello_astrazione;
    bool prove_correttezza;
    bool orientato_ortogonalità;

    DatiLatoServer(double pcp, unsigned int la, bool pc, bool oo):
            perc_capo_progetto(pcp),
            livello_astrazione(la),
            prove_correttezza(pc),
            orientato_ortogonalità(oo){}
};

// Campi dati estesi dalla classe DBDev

struct DatiDatabase{
    double num_attributi_ridondanti_per_entità;
    double speed_up_indicizzazioni;
    double perc_entità_forma_normale;

    DatiDatabase(double narpe, double sui, double pefn):
            num_attributi_ridondanti_per_entità(narpe),
            speed_up_indicizzazioni(sui),
            perc_entità_forma_normale(pefn){}
};

// Campi dati estesi dalla classe FrontDev

struct DatiLatoClient{
    Conv::Libreria libreria;
    bool orientato_professionalità;
    double perc_righe_esterne;        
    double perc_codice_perfezionato; 

    DatiLatoClient(Conv::Libreria l, bool op, double pre, double pcp):
            libreria(l),
            orientato_professionalità(op),
            perc_righe_esterne(pre),
            perc_codice_perfezionato(pcp){}
};

// Campi dati estesi dalla classe GUIDev

struct DatiInterfacceUtente{
    bool quary_predefinite;
    bool stile_minimalista;
    unsigned int lunghezza_max_percorso;
    unsigned int num_medio_percorsi_sezione;

    DatiInterfacceUtente(bool qp, bool sm, unsigned int lmp, unsigned int nmps):
            quary_predefinite(qp),
            stile_minimalista(sm),
            lunghezza_max_percorso(lmp),
            num_medio_percorsi_sezione(nmps){}
};

// Campi dati estesi dalla classe FullStack

struct DatiFullStack{
    double perc_lavoro_back;                                                  
    bool separa_interfacce;   

    DatiFullStack(double plb, bool si):
            perc_lavoro_back(plb),
            separa_interfacce(si){}
}