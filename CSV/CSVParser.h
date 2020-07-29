
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
#include "CSVInterface.h"
namespace CSVParserDesign{
    template<class InIter, class T, class Funct>
    void split(InIter first, InIter last, const T&t, Funct f){
        while(true){
            InIter found = std::find(first, last, t);
            f(first, last);
            if(found == last)
                break;
            first == ++found;
        }
    }
};
class CSVParser{
    //valori generali di cui fare l'escape
    const std::vector<char> TO_ESCAPE = {
            '\n',
            '\"'
    };
    // mappa che manterrà la mia tabella ( pair(string, vector) per rappresentare "nome colonna"->"colonna di valori")
    std::map<std::string, std::vector<std::string>> table;
    // numero di elementi che la mia tabella contiene
    unsigned int n_elem = 0;
public:
    explicit CSVParser(const std::vector<std::string>& columns = {}): n_elem(0){
        // preparo le colonne della tabella (se necessarie)
        std::for_each(columns.begin(), columns.end(),[&](auto& col){
            table.emplace(col, std::vector<std::string>());
        });
    }
    /**
     * implementazione di default
     * @param csv elemento da copiare in this
     * @return l'oggetto corrente
     */
    CSVParser& operator=(const CSVParser& csv){
        if(this != &csv){
            table = csv.table;
            n_elem = csv.n_elem;
        }
        return *this;
    }
    /**
     * aggiunge row all'oggetto di invocazione, facendo l'escaping dei valori particolari
     * @param row
     */
    void addRow(const std::map<std::string, std::string>& row){
        // creo una mappa su cui assegnare i valori con l'escape
        std::map<std::string, std::string> map;
        // per ogni elemento di row
        for(auto &[key, value]: row)
            // aggiungo alla mappa una nuova colonna con il nome di colonna con gli escape necessari con il valore associato, il valore originale con gli escape necessari
            map[escape(key, TO_ESCAPE)] = escape(value, TO_ESCAPE);
        // aggiungo alla mappa dell'oggetto di invocazione questo nuovo elemento (appunto con gli escape necessari)
        addRawRow(map);
    }
    /**
     * Popola l'oggetto di invocazione con i dati ottenuti dal parsing della stringa data in input (senza effettuare nessuna operazione di escaping e unescaping)
     * @param text : il testo di cui fare il parsing
     * @param column_delimiter : il delimitatore della colonna, di default è ","
     * @param row_delimiter : il delimitatore della riga, di default è "\n" (new line)
     */
    void parseText(const std::string& text, char column_delimiter = ',', char row_delimiter = '\n'){
        // "esplodo" il testo rispetto al delimitatore di righe
        std::vector<std::string> rows ( explode_rows(text, row_delimiter) );
        // se non è vuoto
        if(!rows.empty()){
            // assegno a columns_name la prima riga che dovrebbe contenere il nome delle colonne
            auto columns_name = explode_columns(rows[0], column_delimiter);
            // rimuovo le " iniziali dai nomi delle colonne
            remove_quotes(columns_name);

            //resetto l'oggetto corrente
            *this = CSVParser(columns_name);

            // rimuovo la prima riga (che erano i nomi delle colonne)
            rows.erase(rows.begin());

            // se ho dei dati
            if(!rows.empty()){
                // per ogni riga
                for(auto& row : rows){
                    // "esplodo" la riga
                    auto datas = explode_columns(row, column_delimiter);
                    // rimuovo le virgolette dalli vari valori
                    remove_quotes(datas);
                    // creo una nuova mappa per contenere i valori
                    std::map<std::string, std::string> tmp;

                    // assegno alla mappa la coppia [nome_colonna[i] & valore_colonna_della_riga_corrente[i] ]
                    for(unsigned int i = 0; i < datas.size() && i < columns_name.size(); ++i){
                        tmp.emplace(columns_name[i], datas[i]);
                    }
                    // aggiungo al mio oggetto questa nuova mappa con la riga corrente
                    addRawRow(tmp);
                }
            }
        }
    }
    /**
     * produce una stringa contente la serializzazione dell'oggetto di invocazione (principalmente da usare per output su stream di salvataggio)
     * @param row_delimiter : il delimitatore della riga, di default è "\n" (new line)
     * @param column_delimiter : il delimitatore della colonna, di default è ","
     * @return serializzazione degli oggetti passati sottoforma di CSV
     */
    std::string toString(char row_delimiter = '\n', char column_delimiter = ','){
        std::stringstream ss;
        // per ogni elemnto della tabella
        for(auto iter = table.begin() ; iter != table.end();){
            // stampo "nome_colonna"
            ss << '"' << iter->first << '"' ;
            // se non sono alla fine, metto il delimitatore di colonna
            if(++iter != table.end())
                ss<< column_delimiter;
        }
        // se ho elementi nella tabella
        if( n_elem > 0) {
            // inserisco il delimitatore di riga (separare tra la prima riga [nome colonne] e questi che saranno i valori)
            ss << row_delimiter;
            //per ogni elemento inserito nella tabella
            for (unsigned int i = 0; i < n_elem;) {
                //per ogni colonna della tabella
                for (auto iter = table.begin(); iter != table.end();) {
                    // stampo "valore_corrente"
                    ss << '"' << iter->second[i] << '"';
                    // se non sono alla fine metto il delimitatore di colonna
                    if (++iter != table.end())
                        ss << column_delimiter;
                }
                // se non sono alla fine (all'ultima riga) metto il delimitatore di fine riga
                if (++i < n_elem)
                    ss << row_delimiter;
            }
        }
        return ss.str();
    }
private:
    /**
     * effettua l'escape della stringa data in input
     * @param source : stringa di cui fare l'escape
     * @param to_escape : carattere di cui fare l'escape
     * @param escape : carattere con cui fare l'escape
     */
    static void escape_all(std::string& source, char to_escape, char escape = '\\'){
        // cenco nella stringa il valore di cui fare l'escape
        auto pos = source.find(to_escape);
        //finchè quella posizione non è la la fine
        while (pos != std::string::npos) {
            // valore con cui rimpiazzare
            std::string to_replace = {escape, to_escape};
            // gestisco i casi particolare di tab e new line
            if (to_escape=='\n')
                to_replace = {escape, 'n'};
            else if (to_escape=='\t')
                to_replace = {escape, 't'};
            // sosituisco il vecchio valore con quello con l'escape
            source.replace(pos, 1, to_replace);
            // cerco il prossimo valore di vui fare l'escape dalla (posizione corrente + la dimensione del valore) con l'escape in poi
            pos = source.find(to_escape, pos + to_replace.size());
        }
    }
    /**
     * effettua l'escape della stringa data di tutti i caratteri passati
     * @param source : stringa di cui fare l'escape
     * @param to_escape : vettore di caratteri di cui fare l'escape
     * @param escape : carattere con cui fare l'escape
     * @return stringa con l'escape dei caratteri passati
     *
     * @note : non passare il valore di scape dentro al vettore dei caratteri di cui fare l'escape
     */
    static std::string escape(const std::string& source, const  std::vector<char>& to_escape, char escape ='\\') {
        // copia della stringa di input su cui lavorare e poi ritornare
        auto to_return(source);
        // facendo l'escape del valore di escape
        escape_all(to_return, escape, escape);

        //per ogni carattere di cui fare l'escape, faccio l'escape
        for (const auto &e : to_escape)
            // controllo di non fare due volte l'escape del valore di escape
            if(e != escape)
                // faccio l'escape sulla stringa del carattere corrente
                escape_all(to_return, e, escape);
        return to_return;
    }
    /**
     * TODO: vedere se escape si può fare così
     */
    /*

    std::string escape(const std::string& source) {
        std::string res;
        for (const char ch : source) {
            switch(ch) {
                default: res += ch; break;
                case '\n': res += "\\n"; break;
                case '\\': res += "\\\\"; break;
                case '\"': res += "\\\""; break;
            }
        }
        return res;
    }
    */
    /**
     * effettua l'unescape della stringa data in input
     * @param source : stringa di cui fare l'unescape
     * @param to_escape : carattere di cui fare l'unescape -> è il valore originale, quindi senza escape, quindi se vogliamo fare l'unescape delle ",", passiamo "," e basta, non "\,"
     * @param escape : carattere con cui fare l'unescape
     */
    static void unescape_all(std::string& source, const std::string& to_unescape, char escape = '\\'){
        std::string to_find;
        // trovo la stringa da cercare da portare poi alla forma originale
        if(to_unescape == "\n")
            to_find = "\\n";
        else if(to_unescape == "\t")
            to_find = "\\t";
        else
            to_find = escape + to_unescape;
        auto index = 0;
        while (true) {
            // cerco la stringa di cui fare l'unescape
            index = source.find(to_find, index);
            //se index è npos -> non l'ho trovato e quindi esco dal ciclo
            if (index >= std::string::npos) break;
            // altrimenti faccio la sostituzione
            source.replace(index, to_find.length(), to_unescape);
            // faccio avanzare l'indice fino a dopo la stringa che ho sostituito
            index += to_unescape.length();
        }
    }

    /**
     * effettua l'unescape della stringa data di tutti i caratteri passati
     * @param source : stringa di cui fare l'unescape
     * @param to_unescape : vettore di caratteri di cui fare l'escape
     * @param escape : carattere con cui fare l'unescape
     * @return stringa con l'unescape dei caratteri passati
     *
     * @note : non passare il valore di scape dentro al vettore dei caratteri di cui fare l'unescape
     */
    static std::string unescape(const std::string& source, const  std::vector<char>& to_unescape, char escape ='\\') {
        auto to_return(source);
        // per ogni carattere di cui devo fare l'unescape
        for (const auto &e : to_unescape)
            // controllo di non fare il doppio unescape di escape
            if(e == escape)
                //effettuo l'unescape
                unescape_all(to_return, std::string(1,e), escape);
        //effettuo l'unescape di escape stesso
        unescape_all(to_return, std::string(1,escape), escape);
        return to_return;
    }

    /**
     * rimuove le " iniziali e finali delle stringhe passate
     * @param strs : vector di stringhe da cui rimuovere le " all'inizio e alla fine
     */
    static void remove_quotes(std::vector<std::string> &strs){
        // per ogni stringa, rimuovo le "
        for(auto& str : strs)
            str = remove_quotes(str);
    }
    /**
     * rimuove le " iniziali e finali della stringa
     * @param str : stringa a cui rimuovere le "
     * @return : str senza le "
     *
     * @note si rimuove solo la prima occorrenza dall'inizio e la prima dalla fine, non tutte
     */
    static std::string remove_quotes(const std::string &str){
        auto cp = str;
        // controllo se la stringa è vuota
        if(!cp.empty()){
            // se non lo è e inizia per " allora le rimuovo
            if(cp[0] == '"')
                cp.erase(cp.begin());
            // controllo che la stringa non fosse composta solo da " e se l'ultimo carattere è " allora lo rimuovo
            if(!cp.empty() && cp[cp.size()-1] == '"')
                cp.erase(cp.end()-1);
        }
        return cp;
    }
    /**
     * "esplode" la string data in input rispetto a delimiter
     * @param str : stringa da "esplodere"
     * @param delimiter : delimiter da usare
     * @return vector delle sottostringhe
     */
    static std::vector<std::string> explode_rows(const std::string &str,char delimiter ='\n'){
        std::vector<std::string> exploded_strings;
        // posizione carattere corrente
        int i=0;
        //posizione dell'ultimo delimiter trovato
        int k=0;
        while( i<str.length() ){
            // se il carattere corrente della stringa è il delimiter
            if (str[i] == delimiter){
                // allora faccio una substringa da k a i (sottostringa corrente)
                auto substr = str.substr(k, i-k);
                // lo aggiungo al vector da ritornare
                exploded_strings.push_back( substr );
                // aggiungo la posizione dell'ultimo delimiter trovato al carattere successico a questo
                k=i+1;
            }
            // passo al carattere successivo
            ++i;
        }
        //gestisco l'ultimo pezzo
        auto substr = str.substr(k, i-k);
        exploded_strings.push_back( substr );
        return exploded_strings;
    }
    /**
     * "esplode" la string data in input rispetto a delimiter
     * @param str : stringa da "esplodere"
     * @param escape : escape per verificare falsi positivi
     * @param delimiter : delimiter da usare
     * @return vector delle varie sottostringhe
     */
    std::vector<std::string> explode_columns(const std::string &str, char escape = '\\' ,char delimiter = ','){
        std::vector<std::string> exploded_strings;

        // lambda usata per verificare se la stringa termina per " dover però quelle " non siano con l'escape prima
        auto ends_with_quote = [&](const std::string& str){
            if(str.length()<2) return true;
            return str[str.length()-1] == '"' && str[str.length()-2] != escape;
        };

        // posizione dell'ultimo delimiter
        auto oldpos = 0;

        for(int i = 0; i < str.length() ; ++i){
            // se il carattere corrente è il delimiter
            if(str[i] == delimiter){
                // sottostringa dall'ultimo delimiter a posizione corrente
                auto substr= str.substr(oldpos, i-oldpos);
                // se non è un falso positivo
                if (ends_with_quote(substr)) {
                    // aggiungo la strina corrente al vettore
                    exploded_strings.push_back(remove_quotes(substr));
                    // aggiorno la posizione dell'ultimo delimiter alla posizione successiva al delimiter corrente
                    oldpos = ++i;
                }
            }
        }
        // aggiungo l'ultimo pezzo della stringa -> "asd","asd","qwe" -> "qwe" non viene trovato dal ciclo in quanto non finisce con un delimiter ,
        exploded_strings.push_back(remove_quotes(str.substr(oldpos)));
        return exploded_strings;
    }
    /**
     * aggiunge all'oggetto di invocazione un nuovo elemento
     * @param row : nuova riga da inserire nell'oggetto di invocazione
     */
    void addRawRow(const std::map<std::string, std::string>& row){
        // aumento il numero di elementi dentro al
        ++n_elem;
        // per ogni elemento della mia tabella corrente
        for(auto & [col_name, col_vec] : table) {
            // cerco se la colonna corrente della mia tabella è contenuta nel nuovo oggetto
            auto it = row.find(col_name);
            // se c'è allora semplicemente aggiungo il valore di quella colonna del nuovo oggetto alla tabella
            if(it != row.end())
                col_vec.emplace_back(it->second);
            // altrimenti inserisco una stringa vuota
            else
                col_vec.emplace_back("");
        }

        //estraggo le chiavi (nomi colonne) della mia tabella corrente
        std::vector<std::string> table_cells;
        table_cells.reserve(table.size());
        for(auto & [col_name, col_vec] : table)
            table_cells.push_back(col_name);

        //estraggo le chiavi (nomi colonne) del nuovo oggetto
        std::vector<std::string> row_cells;
        row_cells.reserve(row.size());
        for(auto & [col_name, col_vec] : row) {
            row_cells.push_back(col_name);
        }

        // salvo dentro a diff la differenza tra le colonne corrrenti e le colonne del nuovo oggetto
        std::vector<std::string> diff;
        std::set_difference(row_cells.begin(), row_cells.end(), table_cells.begin(), table_cells.end(), std::inserter(diff, diff.begin()));
        // per ogni colonna di differenza
        for(auto& new_col : diff){
            // (per sicurezza, ma non dovrebbe servire in quanto set_difference(a,b..) == a-b (differenza insiemistica non simmetrica) e quindi tutti gli elementi della differenza appartengono almeno ad a)
            if(row.find(new_col) != row.end()){
                // inserisco una nuova colonna dentro alla mia mappa (con associato un vector di stringhe vuote lunghe quanto gli elementi insieriti)
                table.emplace(new_col, std::vector<std::string>(n_elem, ""));
                // sovrascrivo il valore della nuova riga (elemento da inserire) con il valore che ha in quella colonna l'oggetto da inserire
                table.at(new_col).back() = row.at(new_col);
            }
        }
    }
};



#endif //CSVPARSER_CSVPARSER_H

