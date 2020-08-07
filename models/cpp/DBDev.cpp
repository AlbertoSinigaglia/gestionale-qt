
#include "../headers/DBDev.h"


DBDev::DBDev(const Persona& persona, const DatiLavoratore& dati_lavoratore, const DatiDeveloping& dati_developing, const DatiLatoServer& dati_lato_server, const DatiDatabase& dati_database):
            Employee(persona, dati_lavoratore),
            Software(persona, dati_lavoratore, dati_developing),
            BackDev(persona, dati_lavoratore, dati_developing, dati_lato_server),
            num_attributi_ridondanti_per_entita(dati_database.num_attributi_ridondanti_per_entita),
            speed_up_indicizzazioni(dati_database.speed_up_indicizzazioni),
            perc_entita_forma_normale(dati_database.perc_entita_forma_normale){}


unsigned int DBDev::gradoOrtogonalita() const{
    // introduco un malus che è dirett proporzionale al surplus di entità ridondanti rispetto alla media
    double malus_ridondanza = Conv::media_attributi_ridondanti_per_entita / num_attributi_ridondanti_per_entita;
    // limito il malus
    if (malus_ridondanza < 0.5) malus_ridondanza = 0.5;

    unsigned int grado = static_cast<unsigned int> (perc_entita_forma_normale * 10.0 * malus_ridondanza);
    return (grado <= 10)? grado : 10;
}


unsigned int DBDev::riutilizzabilita() const{
    // calcolo di quanto incrementa il numero di progetti che potrebbero implementare il codice sulla base di quanto è ortogonale
    double incremento = 1 + calcoloBonusLineare(0.6 , gradoOrtogonalita()/10.0 , Conv::moltiplicatore_ricicli_ortogonalita_10 -1);

    return static_cast<unsigned int> (BackDev::riutilizzabilita() * incremento);
}


float DBDev::remunerazioneOraRoutine() const{
    return Conv::remunerazione_ora_routine_DBDev;
}


unsigned int DBDev::gradoPerformance() const{
    // è direttamente proprozionale allo speed_up relativo generato dalle indicizzazioni che ha introdotto
    unsigned int grado = static_cast<unsigned int> (speed_up_indicizzazioni * 10.0 / Conv::speed_up_notevole_indicizzazioni);
    return (grado <= 10)? grado : 10;
}



float DBDev::bonusStipendio() const{

    float bouns_performance_DB = calcoloBonusLineare(0.6 , gradoPerformance()/10.0 , Conv::bonus_performance_DB_ottime);

    return BackDev::bonusStipendio() + bouns_performance_DB;
}


float DBDev::valoreLavoro() const{

    float valore_lavoro = BackDev::valoreLavoro();
    // il lavoro del DBDev acquista valore ulteriore solo se si attiene al suo orientamento e consegue i sui obbiettivi con successo
    if( isOrientatoOrtogonalita() )
        valore_lavoro += calcoloBonusLineare( 0.5, gradoOrtogonalita()/10.0, Conv::valore_rispetto_orientamento);

    return valore_lavoro;
}



void DBDev::setPercEntitaFormaNormale(double value)
{
    perc_entita_forma_normale = value;
}

void DBDev::setSpeedUpIndicizzazioni(double value)
{
    speed_up_indicizzazioni = value;
}

void DBDev::setNumAttributiRidondantiPerEntita(double value)
{
    num_attributi_ridondanti_per_entita = value;
}


DatiDatabase DBDev::getDatiDatabase() const{
    return DatiDatabase{num_attributi_ridondanti_per_entita, speed_up_indicizzazioni, perc_entita_forma_normale};
}
