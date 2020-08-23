#include "employeesmanagement.h"

EmployeesManagement::EmployeesManagement():
    employees(std::make_shared<DynamicArray<Employee*>>()),
    source(){


    Employee* impiegato1 = new DBDev(
                                Persona{"Alberto", "Sinigaglia", "ASDGEIWIJFIK", Data::oggi()},
                                DatiLavoratore{Data::oggi(), Data::oggi(), 10, 10.},
                                DatiDeveloping(Conv::Linguaggio::PYTHON, 1, 1, 1, 10),
                                DatiLatoServer{0,0,0,0},
                                DatiDatabase{0,0,0});
    employees->push_back(impiegato1);

}

bool EmployeesManagement::import(const QString& path){
    try {
        auto empls = CSVReader::parse(path);
        employees->insert(employees->end(), empls.begin(), empls.end());
        source = path;
        return true;
    } catch (std::exception& e) {
        return false;
    }
}

void EmployeesManagement::save(const QString& source_){
    CSVWriter::write(source_.endsWith("qcsv") ? source_ : source_ + ".qcsv", *employees);
}

 std::shared_ptr<DynamicArray<Employee*>> EmployeesManagement::getEmployees() const{
    return employees;
}

QString EmployeesManagement::getOriginalSource() const{
    return source;
}



DynamicArray<AbstDataSection*> EmployeesManagement::serializeEmployee(Employee* e){

    DynamicArray<AbstDataSection*> vett;
    vett.push_back(new DatiPersona(e->getDatiPersona()));
    vett.push_back(new DatiLavoratore(e->getDatiLavoratore()));

    Software* p = dynamic_cast<Software*>(e);
    if(p){
        vett.push_back(new DatiDeveloping(p->getDatiDeveloping()));
        if(typeid(*e)==typeid(GUIDev)){
            GUIDev* p = dynamic_cast<GUIDev*>(e);
            vett.push_back(new DatiLatoClient(p->getDatiLatoClient()));
            vett.push_back(new DatiInterfacceUtente(p->getDatiInterfacceUtente()));
        }else if(typeid(*e)==typeid(DBDev)){
            DBDev* p = dynamic_cast<DBDev*>(e);
            vett.push_back(new DatiLatoServer(p->getDatiLatoServer()));
            vett.push_back(new DatiDatabase(p->getDatiDatabase()));
        }else if(typeid(*e)==typeid(FullStack)){
            FullStack* p = dynamic_cast<FullStack*>(e);
            vett.push_back(new DatiLatoServer(p->getDatiLatoServer()));
            vett.push_back(new DatiLatoClient(p->getDatiLatoClient()));
            vett.push_back(new DatiFullStack(p->getDatiFullStack()));
        }else if(typeid(*e)==typeid(ITSecurityDev)){
            ITSecurityDev* p = dynamic_cast<ITSecurityDev*>(e);
            vett.push_back(new DatiManutenzione(p->getDatiManutenzione()));
            vett.push_back(new DatiRipristinoSicurezza(p->getDatiRipristinoSicurezza()));}
    }else if(typeid(*e)==typeid(Tecnico)){
        Tecnico* p = dynamic_cast<Tecnico*>(e);
        vett.push_back(new DatiManutenzione(p->getDatiManutenzione()));
        vett.push_back(new DatiSistemi(p->getDatiSistemi()));
        vett.push_back(new DatiRiparazioneSistemi(p->getDatiRiparazioneSistemi()));
    }

    return vett;
}
