//
// Created by Alberto Sinigaglia on 10/04/2020.
//

#include "DBDev.h"


unsigned int DBDev::calcolaStipendio() const {
    auto bonus_righe_codice = 0.0f;
    auto bonus_libreria = 0u;
    switch(linguaggio){
        case Linguaggio::PYTHON:
            bonus_righe_codice+= 0.2f;
            bonus_libreria = 10u;
            break;
        case Linguaggio::JAVA:
            bonus_righe_codice+= 0.4f;
            bonus_libreria = 20u;
            break; 
        case Linguaggio::PHP:
            bonus_righe_codice+= 0.6f;
            bonus_libreria = 20u;
            break;
        case Linguaggio::C_SHARP:
            bonus_righe_codice+= 0.5f;
            bonus_libreria = 30u;
            break;
        case Linguaggio::JAVASCRIPT:
            bonus_righe_codice+= 0.6f;
            bonus_libreria = 20u;
            break;
        case Linguaggio::RUBY:
            bonus_righe_codice+= 0.3f;
            bonus_libreria = 20u;
            break;
        default:
            break;
    }
    bonus_righe_codice *= static_cast<float>(Software::getRigheCodice());
    auto bonus_db = database * 200u;
    return
            static_cast<unsigned int>(bonus_righe_codice) +
            static_cast<unsigned int>(Software::calcolaStipendio())+
            bonus_db +
            bonus_libreria;
}

double DBDev::valoreLavoro() const {
    auto valore_codice = 0.0f;
    switch(linguaggio){
        case Linguaggio::PYTHON:
            valore_codice+= 0.2f;
            break;
        case Linguaggio::JAVA:
            valore_codice+= 0.2f;
            break;
        case Linguaggio::PHP:
            valore_codice+= 0.3f;
            break;
        case Linguaggio::C_SHARP:
            valore_codice+= 0.2f;
            break;
        case Linguaggio::JAVASCRIPT:
            valore_codice+= 0.3f;
            break;
        case Linguaggio::RUBY:
            valore_codice+= 0.3f;
            break;
        default:
            break;
    }
    valore_codice *= getRigheCodice();
    // in media un programmatore fa un database ogni 3 progetti
    auto valore_db = getDataAssunzione().differenzaMesi(date::oggi()) *0.3;
    return valore_db+valore_codice;

}


unsigned int DBDev::getStipendioFisso() const{
    return DBDEV_STIPENDIO_FISSO;
}