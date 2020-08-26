#include "CSV/support/Mapper.h"

int Mapper::typeToEnum(Employee* e){
    if(dynamic_cast<DBDev*>(e)) return e_DBDev;
    if(dynamic_cast<FullStack*>(e)) return e_FullStack;
    if(dynamic_cast<GUIDev*>(e)) return e_GUIDev;
    if(dynamic_cast<ITSecurityDev*>(e)) return e_ITSecurityDev;
    if(dynamic_cast<Tecnico*>(e)) return e_Tecnico;
    if(dynamic_cast<BackDev*>(e)) return e_BackDev;
    throw std::invalid_argument("Tipo non supportato, potrebbe essere causato da incompatibilità tra versioni");
}

std::map<std::string, std::string> Mapper::toMap(Employee* e){
    switch(typeToEnum(e)){
        case e_ITSecurityDev:{
            auto p = dynamic_cast<ITSecurityDev*>(e);
            auto nome = p->getNome();
            auto cognome = p->getCognome();
            auto nascita = p->getNascita();
            auto cf = p->getCF();
            auto dlavoratore = p->getDatiLavoratore();
            auto dripristinosicurezza = p->getDatiRipristinoSicurezza();
            auto ddevelping = p->getDatiDeveloping();
            auto dmanutenzione = p->getDatiManutenzione();
            return {
                {"type", std::to_string(typeToEnum(e))},
                {"nome", nome},
                {"cognome", cognome},
                {"nascita", nascita},
                {"cf", cf},
                {"dlavoratore.fine_contratto", dlavoratore.fine_contratto},
                {"dlavoratore.data_assunzione", dlavoratore.data_assunzione},
                {"dlavoratore.ore_lavoro_sett", std::to_string(dlavoratore.ore_lavoro_sett)},
                {"dlavoratore.quota_aggiuntiva", std::to_string(dlavoratore.quota_aggiuntiva)},
                {"dripristinosicurezza.n_criticita_risolte", std::to_string(dripristinosicurezza.n_criticita_risolte)},
                {"dripristinosicurezza.n_problemi_irrsolti", std::to_string(dripristinosicurezza.n_problemi_irrsolti)},
                {"ddevelping.linguaggio", std::to_string(ddevelping.linguaggio)},
                {"ddevelping.n_righe_mese", std::to_string(ddevelping.n_righe_mese)},
                {"ddevelping.n_righe_totali", std::to_string(ddevelping.n_righe_totali)},
                {"ddevelping.perc_ore_programmazione", std::to_string(ddevelping.perc_ore_programmazione)},
                {"ddevelping.n_progetti_conclusi_mese", std::to_string(ddevelping.n_progetti_conclusi_mese)},
                {"dmanutenzione.n_riparazioni_mese", std::to_string(dmanutenzione.n_riparazioni_mese)},
                {"dmanutenzione.perc_ripristino_medio", std::to_string(dmanutenzione.perc_ripristino_medio)},
                {"dmanutenzione.perc_riparazioni_inefficaci", std::to_string(dmanutenzione.perc_riparazioni_inefficaci)},
            };
        }
        case e_BackDev:{
            auto p = dynamic_cast<BackDev*>(e);
            auto nome = p->getNome();
            auto cognome = p->getCognome();
            auto nascita = p->getNascita();
            auto cf = p->getCF();
            auto dlavoratore = p->getDatiLavoratore();
            auto dlatoserver = p->getDatiLatoServer();
            auto ddevelping = p->getDatiDeveloping();
            return {
                {"type", std::to_string(typeToEnum(e))},
                {"nome", nome},
                {"cognome", cognome},
                {"nascita", nascita},
                {"cf", cf},
                {"dlavoratore.fine_contratto", dlavoratore.fine_contratto},
                {"dlavoratore.data_assunzione", dlavoratore.data_assunzione},
                {"dlavoratore.ore_lavoro_sett", std::to_string(dlavoratore.ore_lavoro_sett)},
                {"dlavoratore.quota_aggiuntiva", std::to_string(dlavoratore.quota_aggiuntiva)},
                {"ddevelping.linguaggio", std::to_string(ddevelping.linguaggio)},
                {"ddevelping.n_righe_mese", std::to_string(ddevelping.n_righe_mese)},
                {"ddevelping.n_righe_totali", std::to_string(ddevelping.n_righe_totali)},
                {"ddevelping.perc_ore_programmazione", std::to_string(ddevelping.perc_ore_programmazione)},
                {"ddevelping.n_progetti_conclusi_mese", std::to_string(ddevelping.n_progetti_conclusi_mese)},
                {"dlatoserver.prove_correttezza", std::to_string(dlatoserver.prove_correttezza)},
                {"dlatoserver.livello_astrazione", std::to_string(dlatoserver.livello_astrazione)},
                {"dlatoserver.perc_capo_progetto", std::to_string(dlatoserver.perc_capo_progetto)},
                {"dlatoserver.orientato_ortogonalita", std::to_string(dlatoserver.orientato_ortogonalita)},
            };
        }
        case e_GUIDev:{
            auto p = dynamic_cast<GUIDev*>(e);
            auto nome = p->getNome();
            auto cognome = p->getCognome();
            auto nascita = p->getNascita();
            auto cf = p->getCF();
            auto dlavoratore = p->getDatiLavoratore();
            auto ddevelping = p->getDatiDeveloping();
            auto dinterfacciautente = p->getDatiInterfacceUtente();
            auto dlatoclient = p->getDatiLatoClient();
            return {
                {"type", std::to_string(typeToEnum(e))},
                {"nome", nome},
                {"cognome", cognome},
                {"nascita", nascita},
                {"cf", cf},
                {"dlavoratore.fine_contratto", dlavoratore.fine_contratto},
                {"dlavoratore.data_assunzione", dlavoratore.data_assunzione},
                {"dlavoratore.ore_lavoro_sett", std::to_string(dlavoratore.ore_lavoro_sett)},
                {"dlavoratore.quota_aggiuntiva", std::to_string(dlavoratore.quota_aggiuntiva)},
                {"ddevelping.linguaggio", std::to_string(ddevelping.linguaggio)},
                {"ddevelping.n_righe_mese", std::to_string(ddevelping.n_righe_mese)},
                {"ddevelping.n_righe_totali", std::to_string(ddevelping.n_righe_totali)},
                {"ddevelping.perc_ore_programmazione", std::to_string(ddevelping.perc_ore_programmazione)},
                {"ddevelping.n_progetti_conclusi_mese", std::to_string(ddevelping.n_progetti_conclusi_mese)},
                {"dlatoclient.libreria", std::to_string(dlatoclient.libreria)},
                {"dlatoclient.perc_codice_perfezionato", std::to_string(dlatoclient.perc_codice_perfezionato)},
                {"dlatoclient.orientato_professionalita", std::to_string(dlatoclient.orientato_professionalita)},
                {"dinterfacciautente.quary_predefinite", std::to_string(dinterfacciautente.quary_predefinite)},
                {"dinterfacciautente.stile_minimalista", std::to_string(dinterfacciautente.stile_minimalista)},
                {"dinterfacciautente.lunghezza_max_percorso", std::to_string(dinterfacciautente.lunghezza_max_percorso)},
                {"dinterfacciautente.num_medio_percorsi_sezione", std::to_string(dinterfacciautente.num_medio_percorsi_sezione)},
            };
        }
        case e_DBDev:{
            auto p = dynamic_cast<DBDev*>(e);
            auto nome = p->getNome();
            auto cognome = p->getCognome();
            auto nascita = p->getNascita();
            auto cf = p->getCF();
            auto dlavoratore = p->getDatiLavoratore();
            auto ddevelping = p->getDatiDeveloping();
            auto ddatabase = p->getDatiDatabase();
            auto dlatoserver = p->getDatiLatoServer();
            return {
                {"type", std::to_string(typeToEnum(e))},
                {"nome", nome},
                {"cognome", cognome},
                {"nascita", nascita},
                {"cf", cf},
                {"dlavoratore.fine_contratto", dlavoratore.fine_contratto},
                {"dlavoratore.data_assunzione", dlavoratore.data_assunzione},
                {"dlavoratore.ore_lavoro_sett", std::to_string(dlavoratore.ore_lavoro_sett)},
                {"dlavoratore.quota_aggiuntiva", std::to_string(dlavoratore.quota_aggiuntiva)},
                {"ddevelping.linguaggio", std::to_string(ddevelping.linguaggio)},
                {"ddevelping.n_righe_mese", std::to_string(ddevelping.n_righe_mese)},
                {"ddevelping.n_righe_totali", std::to_string(ddevelping.n_righe_totali)},
                {"ddevelping.perc_ore_programmazione", std::to_string(ddevelping.perc_ore_programmazione)},
                {"ddevelping.n_progetti_conclusi_mese", std::to_string(ddevelping.n_progetti_conclusi_mese)},
                {"ddatabase.speed_up_indicizzazioni", std::to_string(ddatabase.speed_up_indicizzazioni)},
                {"ddatabase.perc_entita_forma_normale", std::to_string(ddatabase.perc_entita_forma_normale)},
                {"ddatabase.num_attributi_ridondanti_per_entita", std::to_string(ddatabase.num_attributi_ridondanti_per_entita)},
                {"dlatoserver.prove_correttezza", std::to_string(dlatoserver.prove_correttezza)},
                {"dlatoserver.livello_astrazione", std::to_string(dlatoserver.livello_astrazione)},
                {"dlatoserver.perc_capo_progetto", std::to_string(dlatoserver.perc_capo_progetto)},
                {"dlatoserver.orientato_ortogonalita", std::to_string(dlatoserver.orientato_ortogonalita)},
            };
        }
        case e_FullStack:{
            auto p = dynamic_cast<FullStack*>(e);
            auto nome = p->getNome();
            auto cognome = p->getCognome();
            auto nascita = p->getNascita();
            auto cf = p->getCF();
            auto dlavoratore = p->getDatiLavoratore();
            auto ddevelping = p->getDatiDeveloping();
            auto dfullstack = p->getDatiFullStack();
            auto dlatoserver = p->getDatiLatoServer();
            auto dlatoclient = p->getDatiLatoClient();
            return {
                {"type", std::to_string(typeToEnum(e))},
                {"nome", nome},
                {"cognome", cognome},
                {"nascita", nascita},
                {"cf", cf},
                {"dlavoratore.fine_contratto", dlavoratore.fine_contratto},
                {"dlavoratore.data_assunzione", dlavoratore.data_assunzione},
                {"dlavoratore.ore_lavoro_sett", std::to_string(dlavoratore.ore_lavoro_sett)},
                {"dlavoratore.quota_aggiuntiva", std::to_string(dlavoratore.quota_aggiuntiva)},
                {"ddevelping.linguaggio", std::to_string(ddevelping.linguaggio)},
                {"ddevelping.n_righe_mese", std::to_string(ddevelping.n_righe_mese)},
                {"ddevelping.n_righe_totali", std::to_string(ddevelping.n_righe_totali)},
                {"ddevelping.perc_ore_programmazione", std::to_string(ddevelping.perc_ore_programmazione)},
                {"ddevelping.n_progetti_conclusi_mese", std::to_string(ddevelping.n_progetti_conclusi_mese)},
                {"dlatoserver.prove_correttezza", std::to_string(dlatoserver.prove_correttezza)},
                {"dlatoserver.livello_astrazione", std::to_string(dlatoserver.livello_astrazione)},
                {"dlatoserver.perc_capo_progetto", std::to_string(dlatoserver.perc_capo_progetto)},
                {"dlatoserver.orientato_ortogonalita", std::to_string(dlatoserver.orientato_ortogonalita)},
                {"dlatoclient.libreria", std::to_string(dlatoclient.libreria)},
                {"dlatoclient.perc_codice_perfezionato", std::to_string(dlatoclient.perc_codice_perfezionato)},
                {"dlatoclient.orientato_professionalita", std::to_string(dlatoclient.orientato_professionalita)},
                {"dfullstack.perc_lavoro_back", std::to_string(dfullstack.perc_lavoro_back)},
                {"dfullstack.separa_interfacce", std::to_string(dfullstack.separa_interfacce)},
            };
        }
        case e_Tecnico:{
            auto p = dynamic_cast<Tecnico*>(e);
            auto nome = p->getNome();
            auto cognome = p->getCognome();
            auto nascita = p->getNascita();
            auto cf = p->getCF();
            auto dlavoratore = p->getDatiLavoratore();
            auto driparazionesistemi = p->getDatiRiparazioneSistemi();
            auto dmanutenzione = p->getDatiManutenzione();
            auto dsistemi = p->getDatiSistemi();
            return {
                {"type", std::to_string(typeToEnum(e))},
                {"nome", nome},
                {"cognome", cognome},
                {"nascita", nascita},
                {"cf", cf},
                {"dlavoratore.fine_contratto", dlavoratore.fine_contratto},
                {"dlavoratore.data_assunzione", dlavoratore.data_assunzione},
                {"dlavoratore.ore_lavoro_sett", std::to_string(dlavoratore.ore_lavoro_sett)},
                {"dlavoratore.quota_aggiuntiva", std::to_string(dlavoratore.quota_aggiuntiva)},
                {"driparazionesistemi.ore_straordinari", std::to_string(driparazionesistemi.ore_straordinari)},
                {"driparazionesistemi.ore_stallo_mensili", std::to_string(driparazionesistemi.ore_stallo_mensili)},
                {"driparazionesistemi.perc_riparazioni_sussistenti", std::to_string(driparazionesistemi.perc_riparazioni_sussistenti)},
                {"dmanutenzione.n_riparazioni_mese", std::to_string(dmanutenzione.n_riparazioni_mese)},
                {"dmanutenzione.perc_ripristino_medio", std::to_string(dmanutenzione.perc_ripristino_medio)},
                {"dmanutenzione.perc_riparazioni_inefficaci", std::to_string(dmanutenzione.perc_riparazioni_inefficaci)},
                {"dsistemi.nuovi_gestiti", std::to_string(dsistemi.nuovi_gestiti)},
                {"dsistemi.n_sistemi_gestiti", std::to_string(dsistemi.n_sistemi_gestiti)},
                {"dsistemi.n_sistemi_gestiti_totale", std::to_string(dsistemi.n_sistemi_gestiti_totale)},
                {"dsistemi.n_sistemi_malfunzionanti", std::to_string(dsistemi.n_sistemi_malfunzionanti)},
            };
        }
    }
    return {};
}

Employee* Mapper::fromMap(const std::map<std::string, std::string>& map){
    switch(std::stoi(map.at("type"))){
        case e_ITSecurityDev:{
        return new ITSecurityDev(
                        getPersona(map),
                        getDatiLavoratore(map),
                        getDatiManutenzione(map),
                        getDatiDeveloping(map),
                        getDatiRipristinoSicurezza(map)
                    );
        }
        case e_Tecnico:{
            return new Tecnico(
                        getPersona(map),
                        getDatiLavoratore(map),
                        getDatiManutenzione(map),
                        getDatiSistemi(map),
                        getDatiRiparazioneSistemi(map));
        }
        case e_FullStack:{
            return new FullStack(
                        getPersona(map),
                        getDatiLavoratore(map),
                        getDatiDeveloping(map),
                        getDatiLatoServer(map),
                        getDatiLatoClient(map),
                        getDatiFullStack(map)
            );
        }
        case e_GUIDev:{
            return new GUIDev(
                        getPersona(map),
                        getDatiLavoratore(map),
                        getDatiDeveloping(map),
                        getDatiLatoClient(map),
                        getDatiInterfacceUtente(map)
            );
        }
        case e_DBDev:{
            return new DBDev(
                        getPersona(map),
                        getDatiLavoratore(map),
                        getDatiDeveloping(map),
                        getDatiLatoServer(map),
                        getDatiDatabase(map)
            );
        }
    }
    throw std::invalid_argument("Tipo non supportato, potrebbe essere causato da incompatibilità tra versioni");
}

Persona Mapper::getPersona(const std::map<std::string, std::string>& map){
    return Persona(map.at("nome"), map.at("cognome"), map.at("cf"), Data(map.at("nascita")));
}
DatiLavoratore Mapper::getDatiLavoratore(const std::map<std::string, std::string>& map){
    return DatiLavoratore(Data(map.at("dlavoratore.data_assunzione")),Data(map.at("dlavoratore.fine_contratto")),std::stoi(map.at("dlavoratore.ore_lavoro_sett")),std::stoi(map.at("dlavoratore.quota_aggiuntiva")));
}
DatiManutenzione Mapper::getDatiManutenzione (const std::map<std::string, std::string>& map){
    return DatiManutenzione(std::stoi(map.at("dmanutenzione.perc_riparazioni_inefficaci")), std::stod(map.at("dmanutenzione.perc_ripristino_medio")), std::stoi(map.at("dmanutenzione.n_riparazioni_mese")));
}
DatiDeveloping Mapper::getDatiDeveloping(const std::map<std::string, std::string>& map){
    return DatiDeveloping(static_cast<Conv::Linguaggio>(std::stoi(map.at("ddevelping.linguaggio"))), std::stod(map.at("ddevelping.perc_ore_programmazione")), std::stoi(map.at("ddevelping.n_righe_totali")),std::stoi(map.at("ddevelping.n_righe_mese")), std::stoi(map.at("ddevelping.n_progetti_conclusi_mese")));
}
DatiRipristinoSicurezza Mapper::getDatiRipristinoSicurezza(const std::map<std::string, std::string>& map){
    return DatiRipristinoSicurezza(std::stoi(map.at("dripristinosicurezza.n_problemi_irrsolti")), std::stoi(map.at("dripristinosicurezza.n_criticita_risolte")));
}
DatiSistemi Mapper::getDatiSistemi(const std::map<std::string, std::string>& map){
     return DatiSistemi(std::stoi(map.at("dsistemi.n_sistemi_gestiti")), std::stoi(map.at("dsistemi.n_sistemi_gestiti_totale")), std::stoi(map.at("dsistemi.n_sistemi_malfunzionanti")), std::stoi(map.at("dsistemi.nuovi_gestiti")));
}
DatiRiparazioneSistemi Mapper::getDatiRiparazioneSistemi(const std::map<std::string, std::string>& map){
     return DatiRiparazioneSistemi(std::stoi(map.at("driparazionesistemi.perc_riparazioni_sussistenti")),std::stoi(map.at("driparazionesistemi.ore_stallo_mensili")),std::stoi(map.at("driparazionesistemi.ore_straordinari")));
}
DatiLatoServer Mapper::getDatiLatoServer(const std::map<std::string, std::string>& map){
    return DatiLatoServer(std::stod(map.at("dlatoserver.perc_capo_progetto")), std::stoi(map.at("dlatoserver.livello_astrazione")), std::stoi(map.at("dlatoserver.prove_correttezza")), std::stoi(map.at("dlatoserver.orientato_ortogonalita")));
}
DatiLatoClient Mapper::getDatiLatoClient(const std::map<std::string, std::string>& map){
    return DatiLatoClient(static_cast<Conv::Libreria>(std::stoi(map.at("dlatoclient.libreria"))), std::stoi(map.at("dlatoclient.orientato_professionalita")), std::stod(map.at("dlatoclient.perc_codice_perfezionato")));
}
DatiFullStack Mapper::getDatiFullStack(const std::map<std::string, std::string>& map){
    return DatiFullStack(std::stod(map.at("dfullstack.perc_lavoro_back")), std::stoi(map.at("dfullstack.separa_interfacce")));
}
DatiInterfacceUtente Mapper::getDatiInterfacceUtente(const std::map<std::string, std::string>& map){
    return DatiInterfacceUtente(std::stoi(map.at("dinterfacciautente.quary_predefinite")), std::stoi(map.at("dinterfacciautente.stile_minimalista")), std::stoi(map.at("dinterfacciautente.lunghezza_max_percorso")),std::stoi(map.at("dinterfacciautente.num_medio_percorsi_sezione")));
}
DatiDatabase Mapper::getDatiDatabase(const std::map<std::string, std::string>& map){
    return DatiDatabase(std::stod(map.at("ddatabase.num_attributi_ridondanti_per_entita")),std::stod(map.at("ddatabase.speed_up_indicizzazioni")), std::stod(map.at("ddatabase.perc_entita_forma_normale")));
}
