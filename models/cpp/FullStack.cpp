
#include "../headers/FullStack.h"

FullStack::FullStack(const Persona& persona, const DatiLavoratore& dati_lavoratore, const DatiDeveloping& dati_developing, const DatiLatoServer& dati_lato_server, const DatiLatoClient& dati_lato_client, const DatiFullStack& dati_fullstack):
            Employee(persona, dati_lavoratore),
            Software(persona, dati_lavoratore, dati_developing),
            BackDev(persona, dati_lavoratore, dati_developing, dati_lato_server),
            FrontDev(persona, dati_lavoratore, dati_developing, dati_lato_client),
            perc_lavoro_back(dati_fullstack.perc_lavoro_back),
            separa_interfacce(dati_fullstack.separa_interfacce){}


double FullStack::velocitaScrittura() const{
    // velocità di scrittura dipende da quanto tempo passa a lavorare nel lato server e quanto in quello client
    double velocita_media = UFMath::mediaPonderata(perc_lavoro_back, BackDev::velocitaScrittura(), 1-perc_lavoro_back, FrontDev::velocitaScrittura());

    return (separa_interfacce)? velocita_media * Conv::malus_velocita_separazione_interfacce : velocita_media;
}


unsigned int FullStack::riutilizzabilita() const{
    
    return UFMath::mediaPonderata(perc_lavoro_back, BackDev::riutilizzabilita(), 1-perc_lavoro_back, FrontDev::riutilizzabilita());
}


float FullStack::remunerazioneOraRoutine() const{
    return Conv::remunerazione_ora_routine_FullStack;
}




bool FullStack::produttivo() const{    

    bool sufficentemente_autorevole = ( getPercCapoProgetto() >= Conv::perc_minima_capo_progetti_FullStack );

    return sufficentemente_autorevole && ( BackDev::produttivo() && FrontDev::produttivo() );
}


float FullStack::bonusStipendio() const{

    float bonus_strutturazione = (separa_interfacce && isOrientatoOrtogonalita())? Conv::bonus_separazione_interfaccie : 0;
    
    return bonus_strutturazione + BackDev::bonusStipendio() + FrontDev::bonusStipendio() - Software::bonusStipendio();
}


float FullStack::valoreLavoro() const{

    return BackDev::valoreLavoro()*perc_lavoro_back + Software::valoreLavoro()*(1-perc_lavoro_back);
}



void FullStack::setSeparaInterfacce(bool value)
{
    separa_interfacce = value;
}

void FullStack::setPercLavoroBack(double value)
{
    perc_lavoro_back = value;
}


DatiFullStack FullStack::getDatiFullStack() const{
    return DatiFullStack{perc_lavoro_back, separa_interfacce};
}

