#include "Fullstack.h"

unsigned int FullStack::calcolaStipendio() const {
    auto stipendio_software = FrontEnd::Software::calcolaStipendio();
    auto stipendio_fe = FrontEnd::calcolaStipendio();
    auto stipendio_be = BackEnd::calcolaStipendio();

    auto stipendio = 0;
    switch(specializzazione_segmento){ 
        case Segmento::DATABASE:
            stipendio = stipendio_software + (stipendio_fe - stipendio_software) * 0.2 + (stipendio_be - stipendio_software) * 0.2;
            break;
        case Segmento::BACKEND:
            stipendio = stipendio_be + (stipendio_fe - stipendio_software) * 0.2;
            break;
        case Segmento::FRONTEND:
            stipendio = stipendio_fe + (stipendio_be - stipendio_software) * 0.2;
            break; 
        case Segmento::ANY:
            stipendio =  stipendio_fe + stipendio_be - stipendio_software;
            break;
        default:
            break;
    }
    return stipendio;
}


bool FullStack::efficiente() const { {
    auto fe_valore =FrontEnd::valoreLavoro();
    auto be_valore =BackEnd::valoreLavoro();
    return ((fe_valore+be_valore) / 2)/ getDataAssunzione().differenzaMesi(data::oggi()) > calcolaStipendio();
}


unsigned int FullStack::getStipendioFisso() const{
    return FULLSTACK_STIPENDIO_FISSO;
}