
#include "../headers/GUIDev.h"


GUIDev::GUIDev(Persona persona, DatiLavoratore dati_lavoratore, DatiDeveloping dati_developing, DatiLatoClient dati_lato_client, DatiInterfacceUtente dati_GUI):
            GUIDev(persona, dati_lavoratore, dati_developing, dati_lato_client),
            quary_predefinite(GUIDev.quary_predefinite),
            stile_minimalista(GUIDev.stile_minimalista),
            lunghezza_max_percorso(GUIDev.lunghezza_max_percorso),
            num_medio_percorsi_sezione(GUIDev.num_medio_percorsi_sezione){}


unsigned int GUIDev::gradoIntuitivita() const{

    if(stile_minimalista) return 10u;
    
    double grado_disambiguita_sistema = 10;
    if(num_medio_percorsi_sezione > 1) grado_disambiguita_sistema /= num_medio_percorsi_sezione;

    return static_cast<unsigned int> (grado_disambiguita_sistema);
}


unsigned int GUIDev::gradoProfessionalita() const{
    //fun : funzione inversamente proporzionale rispetto al parametro 
    double fun(unsigned int l){     // 1->1 , 2->3/4 , 3->5/6 ... 
        return static_cast<double>(1+l)/static_cast<double>(2*l);}

    double grado = (quary_predefinite) ? 10u : 8u;
    //quanti più è lungo il percoso massimo tanto decrementa il grado di professionalità:  
    grado *= fun(lunghezza_max_percorso);

    return static_cast<unsigned int>(grado);
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