#ifndef CSVWRITER_H
#define CSVWRITER_H
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "collections/DynamicArray.h"
#include "models/headers/Employee.h"
#include "CSV/CSVReader.h"
#include "CSV/support/Mapper.h"
class CSVWriterTable{
private:
    //valori generali di cui fare l'escape
    const std::vector<char> TO_ESCAPE = {
            '\n',
            '\"'
    };
    // mappa che manterrà la mia tabella ( pair(string, vector) per rappresentare "nome colonna"->"colonna di valori")
    std::map<std::string, std::vector<std::string>> table;
    // numero di elementi che la mia tabella contiene
    unsigned int n_elem = 0;
    /**
     * aggiunge all'oggetto di invocazione un nuovo elemento
     * @param row : nuova riga da inserire nell'oggetto di invocazione
     */
    void addRawRow(const std::map<std::string, std::string>& row);
    static void escape_all(std::string& source, char to_escape, char escape = '\\');
    /**
     * effettua l'escape della stringa data di tutti i caratteri passati
     * @param source : stringa di cui fare l'escape
     * @param to_escape : vettore di caratteri di cui fare l'escape
     * @param escape : carattere con cui fare l'escape
     * @return stringa con l'escape dei caratteri passati
     *
     * @note : non passare il valore di scape dentro al vettore dei caratteri di cui fare l'escape
     */
    static std::string escape(const std::string& source, const  std::vector<char>& to_escape, char escape ='\\');
public:
    void addRow(const std::map<std::string, std::string>& row);
    std::string toString(char row_delimiter = '\n', char column_delimiter = ',');

};
class CSVWriter{
public:
    static void write(const QString& path, const DynamicArray<Employee*>& c);
};
#endif // CSVWRITER_H
