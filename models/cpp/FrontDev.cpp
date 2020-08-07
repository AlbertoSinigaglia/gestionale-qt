
#include "../headers/FrontDev.h"
   
FrontDev::FrontDev(const Persona & persona, const DatiLavoratore & dati_lavoratore, const DatiDeveloping & dati_developing, const DatiLatoClient & dati_client):
            Software(persona, dati_lavoratore, dati_developing),
            libreria(dati_client.libreria),
            orientato_professionalita(dati_client.orientato_professionalita),
            perc_codice_perfezionato(dati_client.perc_codice_perfezionato){}


double FrontDev::velocitaScrittura() const{

    double speed_up_libreria = Conv::speed_up_angular * Conv::esaustivita_libreria[ libreria ];
    
    return Software::velocitaScrittura() * speed_up_libreria;
}


unsigned int FrontDev::riutilizzabilita() const{

    // assumo che il numero di progetti futuri in cui verra riutilizzato il codice sia proporzionale a lla prospettiva di 
    // miglioramento (evoluzione) della libreria usata per quel codice
    int num_ricicli_per_libreria = Conv::riutilizzo_codice_angular * Conv::evolvibilita_libreria[ libreria ];
    int num_ricicli_per_qualita_codice = Software::riutilizzabilita();

    if(num_ricicli_per_libreria > num_ricicli_per_qualita_codice) 
        return num_ricicli_per_libreria;   else   return num_ricicli_per_qualita_codice;
}




 bool FrontDev::produttivo() const{
     
     unsigned int righe_adattate_per_progetto = righePerProgetto() * perc_codice_perfezionato;
     
     return Software::produttivo() && righe_adattate_per_progetto >= Conv::righe_progetto_perfezionate_media;
 }


float FrontDev::bonusStipendio() const{

    float bonus_adattamento =  (perc_codice_perfezionato > 0.5)  ? Conv::bonus_meta_codice_adattato : 0;
    float bonus_orientamento = (orientato_professionalita)? Conv::bonus_orientamento_professionalita : 0;

    return Software::bonusStipendio() + bonus_adattamento + bonus_orientamento;
}


bool FrontDev::isOrientatoProfessionalita() const{
    return orientato_professionalita;
}





void FrontDev::setPercCodicePerfezionato(double value)
{
    perc_codice_perfezionato = value;
}

void FrontDev::setOrientatoProfessionalita(bool value)
{
    orientato_professionalita = value;
}

void FrontDev::setLibreria(const Conv::Libreria &value)
{
    libreria = value;
}



DatiLatoClient FrontDev::getDatiLatoClient() const{
    return DatiLatoClient{libreria, orientato_professionalita, perc_codice_perfezionato};
}


