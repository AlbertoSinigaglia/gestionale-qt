
#include "../headers/GUIDev.h"


GUIDev::GUIDev(const Persona & persona, const DatiLavoratore & dati_lavoratore, const DatiDeveloping & dati_developing, const DatiLatoClient & dati_lato_client, const DatiInterfacceUtente & dati_GUI):
            Employee(persona, dati_lavoratore),
            Software(persona, dati_lavoratore, dati_developing),
            FrontDev(persona, dati_lavoratore, dati_developing, dati_lato_client),
            quary_predefinite(dati_GUI.quary_predefinite),
            stile_minimalista(dati_GUI.stile_minimalista),
            lunghezza_max_percorso(dati_GUI.lunghezza_max_percorso),
            num_medio_percorsi_sezione(dati_GUI.num_medio_percorsi_sezione){}


unsigned int GUIDev::gradoIntuitivita() const{

    if(stile_minimalista) return 10u;
    
    double grado_disambiguita_sistema = 10;
    if(num_medio_percorsi_sezione > 1) grado_disambiguita_sistema /= num_medio_percorsi_sezione/2;

    return static_cast<unsigned int> (grado_disambiguita_sistema);
}


unsigned int GUIDev::gradoProfessionalita() const{
    double grado = (quary_predefinite) ? 10u : 8u;
    //quanti più è lungo il percoso massimo tanto decrementa il grado di professionalità
    //perciò introduco un coefficiente inversamente proporzionale a lunghezza_max_percorso:
    grado *= static_cast<double>(1+lunghezza_max_percorso)/static_cast<double>(1+2*lunghezza_max_percorso);

    return (grado <= 10)? static_cast<unsigned int>(grado) : 10u;
}


float GUIDev::remunerazioneOraRoutine() const{
    return Conv::remunerazione_ora_routine_GUIDev;
}




float GUIDev::bonusStipendio() const{

    float bonus_stile = (stile_minimalista) ? Conv::bonus_stile_GUI : 0;
    float bonus_intuitivita = calcoloBonusLineare(0.8 , gradoIntuitivita()/10.0 , Conv::bonus_intuitivita_ottima);
    float bonus_professionalita = calcoloBonusLineare(0.8 , gradoProfessionalita()/10.0 , Conv::bonus_professionalita_ottima);

    return FrontDev::bonusStipendio() + bonus_stile + bonus_intuitivita + bonus_professionalita;
}


float GUIDev::valoreLavoro() const{

    unsigned int grado_proprieta_orientamento = (isOrientatoProfessionalita()) ? gradoProfessionalita() : gradoIntuitivita();

    float valore_orientamento = calcoloBonusLineare( 0.5, grado_proprieta_orientamento/10.0, Conv::valore_rispetto_orientamento);

    return FrontDev::valoreLavoro() + valore_orientamento;
}



void GUIDev::setNumMedioPercorsiSezione(unsigned int value)
{
    num_medio_percorsi_sezione = value;
}

void GUIDev::setLunghezzaMaxPercorso(unsigned int value)
{
    lunghezza_max_percorso = value;
}

void GUIDev::setStileMinimalista(bool value)
{
    stile_minimalista = value;
}

void GUIDev::setQuaryPredefinite(bool value)
{
    quary_predefinite = value;
}



DatiInterfacceUtente GUIDev::getDatiInterfacceUtente() const{
    return DatiInterfacceUtente{quary_predefinite, stile_minimalista, lunghezza_max_percorso, num_medio_percorsi_sezione};
}

