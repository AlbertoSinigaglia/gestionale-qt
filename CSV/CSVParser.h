
//
// Created by Alberto Sinigaglia on 03/04/2020.
//

#ifndef CSVPARSER_CSVPARSER_H
#define CSVPARSER_CSVPARSER_H

#include <vector>
#include <string>
#include <map>
#include <array>
#include <algorithm>
#include <iostream>
#include <sstream>


class illformed_file_exception: public std::exception{
    const std::string message_;
public:
    illformed_file_exception(const std::string& message = "the submited text is illformed");
    const char* what() const throw() override;
};


class CSVParser{
private:
    //valori generali di cui fare l'escape
    const std::vector<char> TO_ESCAPE = {'\n','\"'};

    // mappa che manterrà la mia tabella ( pair(string, vector) per rappresentare "nome colonna"->"colonna di valori")
    std::map<std::string, std::vector<std::string>> table;

    // numero di elementi che la mia tabella contiene
    unsigned int n_elem = 0;

public:

    explicit CSVParser();

    /**
     * implementazione di default
     * @param csv elemento da copiare in this
     * @return l'oggetto corrente
     */
    CSVParser& operator=(const CSVParser& csv);

    /**
     * @brief getter per tabella costruita fino ad ora
     * @return tabella con i dati parsati
     */
    std::map<std::string, std::vector<std::string>> getTable() const;

    /**
     * @brief getter per numero di elementi trovati fino ad ora dentro alla sorgente fornita
     * @return numero elementi dentro a tabella (equivalete a this->getTable().begin()->second.size())
     */
    unsigned int size() const;

    /**
     * Popola l'oggetto di invocazione con i dati ottenuti dal parsing della stringa data in input (senza effettuare nessuna operazione di escaping e unescaping)
     * @param text : il testo di cui fare il parsing
     * @param column_delimiter : il delimitatore della colonna, di default è ","
     * @param row_delimiter : il delimitatore della riga, di default è "\n" (new line)
     */
    void parseText(std::string& text, char column_delimiter = ',', char row_delimiter = '\n');

private:
    /**
     * effettua l'unescape della stringa data in input
     * @param source : stringa di cui fare l'unescape
     * @param to_escape : carattere di cui fare l'unescape -> è il valore originale, quindi senza escape, quindi se vogliamo fare l'unescape delle ",", passiamo "," e basta, non "\,"
     * @param escape : carattere con cui fare l'unescape
     */
    static void unescape_all(std::string& source, const std::string& to_unescape, char escape = '\\');

    /**
     * effettua l'unescape della stringa data di tutti i caratteri passati
     * @param source : stringa di cui fare l'unescape
     * @param to_unescape : vettore di caratteri di cui fare l'escape
     * @param escape : carattere con cui fare l'unescape
     * @return stringa con l'unescape dei caratteri passati
     *
     * @note : non passare il valore di scape dentro al vettore dei caratteri di cui fare l'unescape
     */
    static std::string unescape(const std::string& source, const  std::vector<char>& to_unescape, char escape ='\\');

    /**
     * rimuove le " iniziali e finali delle stringhe passate
     * @param strs : vector di stringhe da cui rimuovere le " all'inizio e alla fine
     */
    static void remove_quotes(std::vector<std::string> &strs);

    /**
     * rimuove le " iniziali e finali della stringa
     * @param str : stringa a cui rimuovere le "
     * @return : str senza le "
     *
     * @note si rimuove solo la prima occorrenza dall'inizio e la prima dalla fine, non tutte
     */
    static std::string remove_quotes(const std::string &str);

    /**
     * "esplode" la string data in input rispetto a delimiter
     * @param str : stringa da "esplodere"
     * @param delimiter : delimiter da usare
     * @return vector delle sottostringhe
     */
    static std::vector<std::string> explode_rows(const std::string &str,char delimiter ='\n');

    /**
     * "esplode" la string data in input rispetto a delimiter
     * @param str : stringa da "esplodere"
     * @param escape : escape per verificare falsi positivi
     * @param delimiter : delimiter da usare
     * @return vector delle varie sottostringhe
     */
    std::vector<std::string> explode_columns(const std::string &str, char escape = '\\' ,char delimiter = ',');

    /**
     * aggiunge all'oggetto di invocazione un nuovo elemento
     * @param row : nuova riga da inserire nell'oggetto di invocazione
     */
    void addRawRow(const std::map<std::string, std::string>& row);

    /**
     * @brief effettua il trim (rimossione spazi iniziali e finali) sulla stringa fornita
     * @param str: sorgente su cui fare il trim
     * @param to_trim : carattere di cui fare il trim a inizio e fine riga
     */
    void trim(std::string& str, char to_trim = '\n');
};



#endif //CSVPARSER_CSVPARSER_H

