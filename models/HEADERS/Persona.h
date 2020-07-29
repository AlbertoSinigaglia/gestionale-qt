//
// Created by Riccardo Calcagno on 05/05/2020.
//
  
#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include "Data.h"



class Persona{

public:
    Persona(std::string nome_, std::string cognome_, std::string cf_, Data nascita_);
    virtual ~Persona();

    std::string getNome();
    std::string getCognome();
    std::string getCF();
    Data getNascita();
    
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