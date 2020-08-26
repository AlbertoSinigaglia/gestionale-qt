#include "CSV/CSVReader.h"

DynamicArray<Employee*> CSVReader::parse(const QString& path){
    QFile file(path);
    if(file.exists() && file.open(QIODevice::ReadOnly)){
        CSVParser csv;
        auto content = file.readAll().toStdString();
        csv.parseText(content);
        DynamicArray<Employee*> dyn;
        dyn.reserve(csv.size());
        auto table = csv.getTable();
        for(size_t i = 0; i < csv.size(); ++i){
            std::map<std::string, std::string> element;
            for(auto& el : table){
                element[el.first] = el.second[i];
            }
            dyn.push_back(Mapper::fromMap(element));
        }
        return dyn;
    }
    throw std::invalid_argument("path non valido");
}
