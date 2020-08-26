#include "CSV/CSVWriter.h"

void CSVWriterTable::addRawRow(const std::map<std::string, std::string>& row){
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

void CSVWriterTable::escape_all(std::string& source, char to_escape, char escape){
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

std::string CSVWriterTable::escape(const std::string& source, const  std::vector<char>& to_escape, char escape) {
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

void CSVWriterTable::addRow(const std::map<std::string, std::string>& row){
    // creo una mappa su cui assegnare i valori con l'escape
    std::map<std::string, std::string> map;
    // per ogni elemento di row
    for(auto &[key, value]: row)
        // aggiungo alla mappa una nuova colonna con il nome di colonna con gli escape necessari con il valore associato, il valore originale con gli escape necessari
        map[escape(key, TO_ESCAPE)] = escape(value, TO_ESCAPE);
    // aggiungo alla mappa dell'oggetto di invocazione questo nuovo elemento (appunto con gli escape necessari)
    addRawRow(map);
}

std::string CSVWriterTable::toString(char row_delimiter , char column_delimiter ){
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

void CSVWriter::write(const QString& path, const DynamicArray<Employee*>& c){
    QFile file(path);
    CSVWriterTable table;
    if(file.open(QIODevice::WriteOnly)){
          for(auto& e: c){
              table.addRow(Mapper::toMap(e));
          }
          QTextStream stream(&file);
          stream << table.toString().c_str();
          file.close();
    } else throw std::invalid_argument("il path fornito non è valido");
}
