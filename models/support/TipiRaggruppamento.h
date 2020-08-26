#ifndef TIPIRAGGRUPPAMENTO_H
#define TIPIRAGGRUPPAMENTO_H

#include"Data.h"
#include"Convenzioni.h"


struct AbstDataSection{
    virtual ~AbstDataSection() {}
    static double puntoDelMese(){
        return static_cast<double>(Data::oggi().getGiorno()) / 31.0;
    }
};


// Campi dati estesi dalla classe Persona

struct DatiPersona: public AbstDataSection{
    std::string nome;
    std::string cognome;
    std::string CF;
    Data nascita;

    DatiPersona(std::string nome_="", std::string cognome_="", std::string CF_="", Data nascita_=Data(1984,1,24)):
            nome(nome_),
            cognome(cognome_),
            CF(CF_),
            nascita(nascita_){}
};

// Campi dati estesi dalla classe Employee

struct DatiLavoratore: public AbstDataSection{
    Data data_assunzione;
    Data fine_contratto; 
    unsigned int ore_lavoro_sett; 
    float quota_aggiuntiva;

    DatiLavoratore(Data da=Data(Data::oggi().getAnno()-15,1,1), Data fc=Data(Data::oggi().getAnno()+2,1,1), unsigned int ols=40, float qa = 0.0f):
            data_assunzione(da),
            fine_contratto(fc),
            ore_lavoro_sett(ols),
            quota_aggiuntiva(qa){}
};

// Campi dati estesi dalla classe Software


struct DatiDeveloping: public AbstDataSection{
    Conv::Linguaggio linguaggio;
    double perc_ore_programmazione;
    unsigned int n_righe_totali;  
    unsigned int n_righe_mese;      
    unsigned int n_progetti_conclusi_mese;

    DatiDeveloping(Conv::Linguaggio l=Conv::Linguaggio::JAVA, double pop=0.75, unsigned int nrt = 800000,
                    unsigned int nrm = static_cast<unsigned int>(4500.0*puntoDelMese()), unsigned int npcm = static_cast<unsigned int>(10.0*puntoDelMese())):  // 4500, 10
            linguaggio(l),
            perc_ore_programmazione(pop),
            n_righe_totali(nrt),
            n_righe_mese(nrm),
            n_progetti_conclusi_mese(npcm){}
};

// Campi dati estesi dalla classe Manutentore

struct DatiManutenzione: public AbstDataSection{
    double perc_riparazioni_inefficaci;
    double perc_ripristino_medio;
    unsigned int n_riparazioni_mese;

    DatiManutenzione(double prp=0.2, double prm = 0.8, unsigned int nrm = static_cast<unsigned int>(70.0*puntoDelMese())):
            perc_riparazioni_inefficaci(prp),
            perc_ripristino_medio(prm),
            n_riparazioni_mese(nrm){}
};

// Campi dati estesi dalla classe Hardware

struct DatiSistemi: public AbstDataSection{
    unsigned int n_sistemi_gestiti;     
    unsigned int n_sistemi_malfunzionanti;
    unsigned int n_sistemi_gestiti_totale;   
    unsigned int nuovi_gestiti;   

    DatiSistemi(unsigned int nsg=10, unsigned int nsm=4,
                unsigned int nsgt = 800, unsigned int ng = 2):
            n_sistemi_gestiti(nsg),
            n_sistemi_malfunzionanti(nsm),
            n_sistemi_gestiti_totale(nsgt),
            nuovi_gestiti(ng){}
};

// Campi dati estesi dalla classe Tecnico

struct DatiRiparazioneSistemi: public AbstDataSection{
    double perc_riparazioni_sussistenti;
    unsigned int ore_stallo_mensili;
    unsigned int ore_straordinari;

    DatiRiparazioneSistemi(double prs = 0.3, unsigned int osm = 10, unsigned int os = 10):
            perc_riparazioni_sussistenti(prs),
            ore_stallo_mensili(osm),
            ore_straordinari(os){}
};

// Campi dati estesi dalla classe ITSecurityDev

struct DatiRipristinoSicurezza: public AbstDataSection{
    unsigned int n_problemi_irrsolti;
    unsigned int n_criticita_risolte;

    DatiRipristinoSicurezza(unsigned int npi = 40, unsigned int ncr = 5):
            n_problemi_irrsolti(npi),
            n_criticita_risolte(ncr){}
};

// Campi dati estesi dalla classe BackDev

struct DatiLatoServer: public AbstDataSection{
    double perc_capo_progetto;
    unsigned int livello_astrazione;
    bool prove_correttezza;
    bool orientato_ortogonalita;

    DatiLatoServer(double pcp=0.5, unsigned int la=3, bool pc=false, bool oo=true):
            perc_capo_progetto(pcp),
            livello_astrazione(la),
            prove_correttezza(pc),
            orientato_ortogonalita(oo){}
};

// Campi dati estesi dalla classe DBDev

struct DatiDatabase: public AbstDataSection{
    double num_attributi_ridondanti_per_entita;
    double speed_up_indicizzazioni;
    double perc_entita_forma_normale;

    DatiDatabase(double narpe=0.2, double sui=1.8, double pefn=0.9):
            num_attributi_ridondanti_per_entita(narpe),
            speed_up_indicizzazioni(sui),
            perc_entita_forma_normale(pefn){}
};

// Campi dati estesi dalla classe FrontDev

struct DatiLatoClient: public AbstDataSection{
    Conv::Libreria libreria;
    bool orientato_professionalita;     
    double perc_codice_perfezionato; 

    DatiLatoClient(Conv::Libreria l=Conv::Libreria::ANGULAR, bool op=true, double pcp=0.5):
            libreria(l),
            orientato_professionalita(op),
            perc_codice_perfezionato(pcp){}
};

// Campi dati estesi dalla classe GUIDev

struct DatiInterfacceUtente: public AbstDataSection{
    bool quary_predefinite;
    bool stile_minimalista;
    unsigned int lunghezza_max_percorso;
    unsigned int num_medio_percorsi_sezione;

    DatiInterfacceUtente(bool qp=true, bool sm=false, unsigned int lmp=2, unsigned int nmps=2):
            quary_predefinite(qp),
            stile_minimalista(sm),
            lunghezza_max_percorso(lmp),
            num_medio_percorsi_sezione(nmps){}
};

// Campi dati estesi dalla classe FullStack

struct DatiFullStack: public AbstDataSection{
    double perc_lavoro_back;                                                  
    bool separa_interfacce;   

    DatiFullStack(double plb=0.5, bool si=true):
            perc_lavoro_back(plb),
            separa_interfacce(si){}
};

#endif
