#include "employeesmanagement.h"

EmployeesManagement::EmployeesManagement():
    employees(std::make_shared<DynamicArray<Employee*>>()),
    source(){}

bool EmployeesManagement::import(const QString& path){
    try {
        *employees = CSVReader::parse(path);
        source = path;
        return true;
    } catch (std::invalid_argument& e) {
        qDebug() << "Attenzione eccezione: " << e.what();
        return false;
    } catch (illformed_file_exception& e) {
        qDebug() << "Attenzione eccezione: "<< e.what();
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
    vett.push_back(new AbstDataSection(e->getDatiPersona()));
    vett.push_back(new AbstDataSection(e->getDatiLavoratore()));

    if(typeid(e)==typeid(GUIDev)){
        GUIDev* p = dynamic_cast<GUIDev*>(e);
        vett.push_back(new AbstDataSection(p->getDatiDeveloping()));
        vett.push_back(new AbstDataSection(p->getDatiLatoClient()));
        vett.push_back(new AbstDataSection(p->getDatiInterfacceUtente()));
    }else if(typeid(e)==typeid(DBDev)){
        DBDev* p = dynamic_cast<DBDev*>(e);
        vett.push_back(new AbstDataSection(p->getDatiDeveloping()));
        vett.push_back(new AbstDataSection(p->getDatiLatoServer()));
        vett.push_back(new AbstDataSection(p->getDatiDatabase()));
    }else if(typeid(e)==typeid(FullStack)){
        FullStack* p = dynamic_cast<FullStack*>(e);
        vett.push_back(new AbstDataSection(p->getDatiDeveloping()));
        vett.push_back(new AbstDataSection(p->getDatiLatoServer()));
        vett.push_back(new AbstDataSection(p->getDatiLatoClient()));
        vett.push_back(new AbstDataSection(p->getDatiFullStack()));
    }else if(typeid(e)==typeid(ITSecurityDev)){
        ITSecurityDev* p = dynamic_cast<ITSecurityDev*>(e);
        vett.push_back(new AbstDataSection(p->getDatiDeveloping()));
        vett.push_back(new AbstDataSection(p->getDatiManutenzione()));
        vett.push_back(new AbstDataSection(p->getDatiRipristinoSicurezza()));
    }else if(typeid(e)==typeid(Tecnico)){
        Tecnico* p = dynamic_cast<Tecnico*>(e);
        vett.push_back(new AbstDataSection(p->getDatiManutenzione()));
        vett.push_back(new AbstDataSection(p->getDatiSistemi()));
        vett.push_back(new AbstDataSection(p->getDatiRiparazioneSistemi()));
    }

    return vett;
}
