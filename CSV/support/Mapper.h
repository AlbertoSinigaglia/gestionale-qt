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
#include <QDebug>
class Mapper{
    enum supported{
        e_ITSecurityDev = 0,
        e_Tecnico = 1,
        e_FullStack = 2,
        e_BackDev = 3,
        e_GUIDev = 4,
        e_DBDev = 5
    };
    static int typeToEnum(Employee* e);
public:
    static std::map<std::string, std::string> toMap(Employee* e);
    static Employee* fromMap(const std::map<std::string, std::string>& map);
private:
private:
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
//    static Dati get(const std::map<std::string, std::string>& map){

//    }
};
#endif // MAPPER_H
