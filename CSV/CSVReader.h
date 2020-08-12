#ifndef CSVREADER_H
#define CSVREADER_H
#include "collections/DynamicArray.h"
#include "models/headers/Employee.h"
#include "CSV/CSVParser.h"
#include "CSV/support/Mapper.h"
#include <QFile>
class CSVReader{
public:
    /**
     * @brief genera una collezione di dipendenti interpretando il testo ottenuto dal file il cui path è quello fornito
     * @param path: path del file di cui fare il parsing del contenuto
     * @return la corrispondente collezione
     * @throws illformed_file_exception: se il contentuo del file non è del formato supportato, o se contiene errori nel contenuto (es: se a un certo tipo, mancano dati necessari per la cotruzione di quel tipo)
     */
    static DynamicArray<Employee*> parse(const QString& path);
};
#endif // CSVREADER_H
