#ifndef MAPPER_H
#define MAPPER_H
#include<map>
#include<string>
#include<exception>
#include "models/headers/ITSecurityDev.h"
#include "models/headers/BackDev.h"
#include "models/headers/GUIDev.h"
#include "models/headers/DBDev.h"
#include "models/headers/FullStack.h"
#include "models/headers/Tecnico.h"
#include "models/support/Convenzioni.h"

class Mapper{
    enum supported{
        e_ITSecurityDev = 0,
        e_Tecnico = 1,
        e_FullStack = 2,
        e_BackDev = 3,
        e_GUIDev = 4,
        e_DBDev = 5
    };

    /**
     * @brief mappa da tipo dinamico a enum il puntatore fornito
     * @param e: puntatore di cui si vuole sapere il tipo dinamico
     * @return enumerativo rispetto al tipo dinamico di e
     */
    static int typeToEnum(Employee* e);

public:

    /**
     * @brief genera una mappa (string -> string) del dipendente fornito
     * @param e: dipendente di cui si vuole la mappa
     * @return mappa rappresentate il dipendente fornito
     */
    static std::map<std::string, std::string> toMap(Employee* e);

    /**
     * @brief data una mappa, ne genera il dipendente corrispondente (inverso di toMap)
     * @param map: mappa da cui generare il dipendente
     * @return il dipendente generato dalla mappa
     */
    static Employee* fromMap(const std::map<std::string, std::string>& map);

private:

    /**
     * ognuno di questi metodi produce la rispettiva struttura di supporto presente nel nome (get+StrutturaCheGenera)
     * @param map: mappa da cui estrarre i dati
     * @return la corrispondente struttura di supporto
     */
    static Persona getPersona(const std::map<std::string, std::string>& map);
    static DatiLavoratore getDatiLavoratore(const std::map<std::string, std::string>& map);
    static DatiManutenzione getDatiManutenzione (const std::map<std::string, std::string>& map);
    static DatiDeveloping getDatiDeveloping(const std::map<std::string, std::string>& map);
    static DatiRipristinoSicurezza getDatiRipristinoSicurezza(const std::map<std::string, std::string>& map);
    static DatiSistemi getDatiSistemi(const std::map<std::string, std::string>& map);
    static DatiRiparazioneSistemi getDatiRiparazioneSistemi(const std::map<std::string, std::string>& map);
    static DatiLatoServer getDatiLatoServer(const std::map<std::string, std::string>& map);
    static DatiLatoClient getDatiLatoClient(const std::map<std::string, std::string>& map);
    static DatiFullStack getDatiFullStack(const std::map<std::string, std::string>& map);
    static DatiInterfacceUtente getDatiInterfacceUtente(const std::map<std::string, std::string>& map);
    static DatiDatabase getDatiDatabase(const std::map<std::string, std::string>& map);
};
#endif // MAPPER_H
