#include "../headers/Persona.h"



Persona::Persona(const std::string &nome_, const std::string &cognome_, const std::string &cf_, const Data &nascita_):
        nome(nome_), cognome(cognome_), CF(cf_), nascita(nascita_){}

void Persona::setNome(const std::string &value)
{
    nome = value;
}

void Persona::setCognome(const std::string &value)
{
    cognome = value;
}

void Persona::setCF(const std::string &value)
{
    CF = value;
}

void Persona::setNascita(const Data &value)
{
    nascita = value;
}



std::string Persona::getNome() const
{
    return nome;
}

std::string Persona::getCognome() const
{
    return cognome;
}

std::string Persona::getCF() const
{
    return CF;
}

Data Persona::getNascita() const
{
    return nascita;
}
