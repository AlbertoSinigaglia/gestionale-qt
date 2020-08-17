#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include "../support/Data.h"
#include "../support/TipiRaggruppamento.h"
#include "../support/Data.h"
#include "../support/Convenzioni.h"
#include "../support/UsefullMath.h"



class Persona{

public:
    Persona(const std::string & nome_, const std::string & cognome_, const std::string & cf_, const Data & nascita_);

    virtual ~Persona() = default;
    
    void setNome(const std::string &value);

    void setCognome(const std::string &value);

    void setCF(const std::string &value);

    void setNascita(const Data &value);


    std::string getNome() const;

    std::string getCognome() const;

    std::string getCF() const;

    Data getNascita() const;

    DatiPersona getDatiPersona() const;
    void setDatiPersona(const DatiPersona& d);


private:

    /**     DATI PERSONA
     * Nome, Cognome, Codice Fiscale, Data di Nascita
     */
    std::string nome;
    std::string cognome;
    std::string CF;
    Data nascita;


};




#endif   //PERSONA_H
