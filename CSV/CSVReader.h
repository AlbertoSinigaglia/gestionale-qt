#ifndef CSVREADER_H
#define CSVREADER_H
#include "collections/DynamicArray.h"
#include "models/headers/Employee.h"
#include "CSV/CSVParser.h"
#include "CSV/support/Mapper.h"
#include <QFile>
class CSVReader{
public:
    static DynamicArray<Employee*> parse(const QString& path){
        QFile file(path);
        file.open(QIODevice::ReadOnly);
        CSVParser csv;
        auto content = file.readAll().toStdString();
        csv.parseText(content);
        DynamicArray<Employee*> dyn;
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
};
#endif // CSVREADER_H
