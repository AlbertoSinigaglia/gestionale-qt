#include"TipiRaggruppamento.h"


double AbstDataSection::puntoDelMese(){
        return static_cast<double>(Data::oggi().getGiorno()) / 31.0;
    }


// Campi dati estesi dalla classe Persona

DatiPersona::DatiPersona(std::string nome_, std::string cognome_, std::string CF_, Data nascita_):
            nome(nome_),
            cognome(cognome_),
            CF(CF_),
            nascita(nascita_){}

// Campi dati estesi dalla classe Employee

DatiLavoratore::DatiLavoratore(Data da, Data fc, unsigned int ols, float qa):
            data_assunzione(da),
            fine_contratto(fc),
            ore_lavoro_sett(ols),
            quota_aggiuntiva(qa){}

// Campi dati estesi dalla classe Software

DatiDeveloping::DatiDeveloping(Conv::Linguaggio l, double pop, unsigned int nrt,
                    unsigned int nrm, unsigned int npcm ):
            linguaggio(l),
            perc_ore_programmazione(pop),
            n_righe_totali(nrt),
            n_righe_mese(nrm),
            n_progetti_conclusi_mese(npcm){}

// Campi dati estesi dalla classe Manutentore

DatiManutenzione::DatiManutenzione(double prp, double prm, unsigned int nrm):
            perc_riparazioni_inefficaci(prp),
            perc_ripristino_medio(prm),
            n_riparazioni_mese(nrm){}

// Campi dati estesi dalla classe Hardware

DatiSistemi::DatiSistemi(unsigned int nsg, unsigned int nsm,
                unsigned int nsgt, unsigned int ng):
            n_sistemi_gestiti(nsg),
            n_sistemi_malfunzionanti(nsm),
            n_sistemi_gestiti_totale(nsgt),
            nuovi_gestiti(ng){}

// Campi dati estesi dalla classe Tecnico

DatiRiparazioneSistemi::DatiRiparazioneSistemi(double prs, unsigned int osm, unsigned int os):
            perc_riparazioni_sussistenti(prs),
            ore_stallo_mensili(osm),
            ore_straordinari(os){}

// Campi dati estesi dalla classe ITSecurityDev

DatiRipristinoSicurezza::DatiRipristinoSicurezza(unsigned int npi, unsigned int ncr):
            n_problemi_irrsolti(npi),
            n_criticita_risolte(ncr){}

// Campi dati estesi dalla classe BackDev

DatiLatoServer::DatiLatoServer(double pcp, unsigned int la, bool pc, bool oo):
            perc_capo_progetto(pcp),
            livello_astrazione(la),
            prove_correttezza(pc),
            orientato_ortogonalita(oo){}

// Campi dati estesi dalla classe DBDev

DatiDatabase::DatiDatabase(double narpe, double sui, double pefn):
            num_attributi_ridondanti_per_entita(narpe),
            speed_up_indicizzazioni(sui),
            perc_entita_forma_normale(pefn){}

// Campi dati estesi dalla classe FrontDev

DatiLatoClient::DatiLatoClient(Conv::Libreria l, bool op, double pcp):
            libreria(l),
            orientato_professionalita(op),
            perc_codice_perfezionato(pcp){}

// Campi dati estesi dalla classe GUIDev

DatiInterfacceUtente::DatiInterfacceUtente(bool qp, bool sm, unsigned int lmp, unsigned int nmps):
            quary_predefinite(qp),
            stile_minimalista(sm),
            lunghezza_max_percorso(lmp),
            num_medio_percorsi_sezione(nmps){}

// Campi dati estesi dalla classe FullStack

DatiFullStack::DatiFullStack(double plb, bool si):
            perc_lavoro_back(plb),
            separa_interfacce(si){}
