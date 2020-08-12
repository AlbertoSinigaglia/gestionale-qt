#ifndef CSVREADER_H
#define CSVREADER_H
#include "collections/DynamicArray.h"
#include "models/headers/Employee.h"
#include "CSV/CSVParser.h"
#include "CSV/support/Mapper.h"
#include <QFile>
class CSVReader{
public:
    static DynamicArray<Employee*> parse(const QString& path);
};
#endif // CSVREADER_H
