//
// Created by Alberto Sinigaglia on 10/04/2020.
//

#include "GUIDev.h"

unsigned int GUIDev::calcolaStipendio() const {
    auto bonus_righe_codice = 0.0f;
    auto bonus_pagine = static_cast<float>(num_pagine)*0.02f;
    auto bonus_libreria = 0;
    switch(libreria){
        case Libreria::BOOTSTRAP:
            bonus_righe_codice+= 0.1;
            bonus_libreria = 10;
            break;
        case Libreria::JQUERY:
            bonus_righe_codice+= 0.2;
            bonus_libreria = 20;
            break;
        case Libreria::TREEJS:
            bonus_righe_codice+= 0.3;
            bonus_libreria = 20;
            break;
        case Libreria::ANGULAR:
            bonus_righe_codice+= 0.4;
            bonus_libreria = 30;
            break;
        case Libreria::VUEJS:
            bonus_righe_codice+= 0.3;
            bonus_libreria = 20;
            break;
        default:
            break; 
    }
    bonus_righe_codice *= static_cast<float>(Software::getRigheCodice());
    return static_cast<unsigned int>(bonus_righe_codice) +
           bonus_libreria +
           Software::calcolaStipendio() +
           static_cast<unsigned int>(bonus_pagine);
}

double GUIDev::valoreLavoro() const {
    auto valore_righe_codice = 0.0f;
    switch(libreria){
        case Libreria::BOOTSTRAP:
            valore_righe_codice+= 0.15;
            break;
        case Libreria::JQUERY:
            valore_righe_codice+= 0.25;
            break;
        case Libreria::TREEJS:
            valore_righe_codice+= 0.35;
            break;
        case Libreria::ANGULAR:
            valore_righe_codice+= 0.45;
            break;
        case Libreria::VUEJS:
            valore_righe_codice+= 0.35;
            break;
        default:
            break;
    }
    valore_righe_codice *= getRigheCodice();
    auto valore_pagine = num_pagine * 0.1;
    return valore_righe_codice+valore_pagine;
}


unsigned int GUIDev::getStipendioFisso() const{
    return FRONTEND_STIPENDIO_FISSO;
}