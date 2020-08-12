#include "CSV/CSVParser.h"
illformed_file_exception::illformed_file_exception(const std::string& message): std::exception(), message_(message){};
const char* illformed_file_exception::what() const throw(){
    return message_.c_str();
}
CSVParser::CSVParser(): n_elem(0){}



CSVParser& CSVParser::operator=(const CSVParser& csv){
    if(this != &csv){
        table = csv.table;
        n_elem = csv.n_elem;
    }
    return *this;
}
std::map<std::string, std::vector<std::string>> CSVParser::getTable() const{
    return table;
}
unsigned int CSVParser::size() const{
    return n_elem;
}
/**
 * Popola l'oggetto di invocazione con i dati ottenuti dal parsing della stringa data in input (senza effettuare nessuna operazione di escaping e unescaping)
 * @param text : il testo di cui fare il parsing
 * @param column_delimiter : il delimitatore della colonna, di default è ","
 * @param row_delimiter : il delimitatore della riga, di default è "\n" (new line)
 */
void CSVParser::parseText(std::string& text, char column_delimiter, char row_delimiter){
    //resetto l'oggetto corrente
    *this = CSVParser();
    trim(text, ' ');
    trim(text, '\t');
    trim(text, '\n');
    // "esplodo" il testo rispetto al delimitatore di righe
    std::vector<std::string> rows ( explode_rows(text, row_delimiter) );
    // se non è vuoto
    if(!rows.empty()){
        // assegno a columns_name la prima riga che dovrebbe contenere il nome delle colonne
        auto columns_name = explode_columns(rows[0], column_delimiter);
        // rimuovo le " iniziali dai nomi delle colonne
        remove_quotes(columns_name);


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

                if(tmp.size() != columns_name.size()){
                    std::cerr << "da: " << table.size() << " a: " << tmp.size();
                    throw illformed_file_exception("Il file è malformato");
                }
                // aggiungo al mio oggetto questa nuova mappa con la riga corrente
                addRawRow(tmp);
            }
        }
    }
}



void CSVParser::unescape_all(std::string& source, const std::string& to_unescape, char escape){
    std::string to_find;
    // trovo la stringa da cercare da portare poi alla forma originale
    if(to_unescape == "\n")
        to_find = "\\n";
    else if(to_unescape == "\t")
        to_find = "\\t";
    else
        to_find = escape + to_unescape;
    size_t index = 0;
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


std::string CSVParser::unescape(const std::string& source, const  std::vector<char>& to_unescape, char escape) {
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

void CSVParser::remove_quotes(std::vector<std::string> &strs){
    // per ogni stringa, rimuovo le "
    for(auto& str : strs)
        str = remove_quotes(str);
}

std::string CSVParser::remove_quotes(const std::string &str){
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

std::vector<std::string> CSVParser::explode_rows(const std::string &str,char delimiter){
    std::vector<std::string> exploded_strings;
    // posizione carattere corrente
    size_t i=0;
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


std::vector<std::string> CSVParser::explode_columns(const std::string &str, char escape,char delimiter){
    std::vector<std::string> exploded_strings;

    // lambda usata per verificare se la stringa termina per " dover però quelle " non siano con l'escape prima
    auto ends_with_quote = [&](const std::string& str){
        if(str.length()<2) return true;
        return str[str.length()-1] == '"' && str[str.length()-2] != escape;
    };

    // posizione dell'ultimo delimiter
    auto oldpos = 0;

    for(size_t i = 0; i < str.length() ; ++i){
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


void CSVParser::addRawRow(const std::map<std::string, std::string>& row){
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


void CSVParser::trim(std::string& str, char to_trim ){
    size_t first = str.find_first_not_of(to_trim);
    if (std::string::npos == first){
        size_t last = str.find_last_not_of(to_trim);
        str =  str.substr(first, (last - first + 1));
    }
}
