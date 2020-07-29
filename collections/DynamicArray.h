//
// Created by Alberto Sinigaglia on 13/04/2020.
//

#ifndef CSVPARSER_DYNAMICARRAY_H
#define CSVPARSER_DYNAMICARRAY_H
#include <memory>
template<class T> class DynamicArray;
template<class T> class iterator;
template<class T> class const_iterator;

template<class T>const_iterator<T> operator+(const const_iterator<T>& iter, int  diff);
template<class T>const_iterator<T> operator+(int  diff, const const_iterator<T>& iter);
template<class T>const_iterator<T> operator-(int  diff, const const_iterator<T>& iter);
template<class T>const_iterator<T> operator-(const const_iterator<T>& iter, int  diff);

template<class T> iterator<T> operator+(const iterator<T>& iter, int  diff);
template<class T> iterator<T> operator+(int  diff, const iterator<T>& iter);
template<class T> iterator<T> operator-(int  diff, const iterator<T>& iter);
template<class T> iterator<T> operator-(const iterator<T>& iter, int  diff);

template<class T>
class const_iterator  {
    friend DynamicArray<T>;
    friend iterator<T>;
    /**
     * Operator + : ritorna un iteratore che dista diff posizioni da iter(non fa nessun controllo sui bound)
     * @param iter : iteratore di partenza
     * @param diff :  posizione da avanzare o indietreggiare, in base a sign(diff)
     * @return puntatore che corrisponde a invocare operator++ (o operator-- se diff è negativo) diff volte, su una copia di iter
     */
    friend const_iterator operator+<>(const const_iterator& iter, int  diff);
    /**
     * Operator + : ritorna un iteratore che dista diff posizioni da iter(non fa nessun controllo sui bound)
     * @param iter : iteratore di partenza
     * @param diff :  posizione da avanzare o indietreggiare, in base a sign(diff)
     * @return puntatore che corrisponde a invocare operator++ (o operator-- se diff è negativo) diff volte, su una copia di iter
     */
    friend const_iterator operator+<>(int  diff, const const_iterator& iter);
    /**
     * Operator - : ritorna un iteratore che dista diff posizioni da iter(non fa nessun controllo sui bound)
     * @param iter : iteratore di partenza
     * @param diff :  posizione da avanzare o indietreggiare, in base a sign(diff)
     * @return puntatore che corrisponde a invocare operator-- (o operator++ se diff è positivo) diff volte, su una copia di iter
     */
    friend const_iterator operator-<>(int  diff, const const_iterator& iter);
    /**
     * Operator - : ritorna un iteratore che dista diff posizioni da iter(non fa nessun controllo sui bound)
     * @param iter : iteratore di partenza
     * @param diff :  posizione da avanzare o indietreggiare, in base a sign(diff)
     * @return puntatore che corrisponde a invocare operator-- (o operator++ se diff è positivo) diff volte, su una copia di iter
     */
    friend const_iterator operator-<>(const const_iterator& iter, int  diff);
private:
    /**
     * Costruttore privato di supporto
     * @param container : riferimento al contenitore a cui si riferisce
     * @param position : posizione corrente dell'iteratore dentro al contenitore
     */
    const_iterator(const DynamicArray<T>* container, unsigned int position) :
            arr(container),
            pos(static_cast<int>(position))
    {}
    const DynamicArray<T>* arr;
    int pos;
public:
    /**
     * Operator - : restituisce la distanza tra i due iteratori
     * @param iter : iteratore a cui confrontare this
     * @return distanza tra i due iteratori
     */
    int operator-(const const_iterator& iter) const;
    /**
     * Operator == : controlla se i due iteratori puntano allo stesso elemento
     * @param it : iterator a cui confrontare this
     * @return
     *          true se puntano allo stesso contenitore e alla stessa sua posizione
     *          false altrimenti
     */
    bool operator==(const const_iterator &it) const;
    /**
     * Operator != : controlla se i due iteratori puntano a elementi diversi
     * @param it : iterator a cui confrontare this
     * @return
     *          true se puntano a contenitori diversi o se si riferiscono a posizioni diverse
     *          false altrimenti
     */
    bool operator!=(const const_iterator &it) const;
    /**
     * Operator ++ (post-incrementato) : avanza il puntatore e restituisce il suo stato iniziale
     * @return puntatore copia di this allo stato iniziale, this invece avanzato di 1
     */
    const_iterator operator++(int);
    /**
     * Operator ++ (pre-incrementato) : avanza il puntatore di una posizione e ritorna un riferimento ad esso
     * @return il puntatore di invocazione avanzato di una posizione
     */
    const_iterator& operator++();
    /**
     * Operator -- (post-decrementato) : indietreggia il puntatore e restituisce il suo stato iniziale
     * @return puntatore copia di this allo stato iniziale, this invece indietreggiato di 1
     */
    const_iterator operator--(int);
    /**
     * Operator -- (pre-decrementato) : indietreggia il puntatore e ne restituisce il riferimento
     * @return il puntatore di invocazione avanzato di una posizione
     */
    const_iterator &operator--();
    /**
     * Operator * : ritorna il riferimento dell'elemento corrente
     * @return riferimento costante all'elemento corrente
     */
    const T& operator*() const;
    /**
     * Operator -> : ritorna il puntatore all'elemento corrente
     * @return puntatore costante all'elemento corrente
     */
    const T* operator->() const;
    /**
     * Operator [] : ritorna un riferimento al diff-esimo elemento dalla posizione corrente
     * @param diff : posizione dell'elemento da ritornare rispetto alla posizione corrente
     * @return riferimento costante al diff-esimo elemento
     */
    const T& operator[](unsigned int diff);
    /**
     * Operator += : fa avanzare (se diff>0 , altrimenti indietreggiare) l'iteratore di diff posizioni
     * @param diff : posizioni da far avanzare l'iteratore
     * @return riferimento al puntatore avanzato di diff posizioni
     */
    const_iterator& operator+=(unsigned int diff);
    /**
     * Operator -= : fa indietreggiare (se diff>0 , altrimenti avanzare) l'iteratore di diff posizioni
     * @param diff : posizioni da far avanzare l'iteratore
     * @return riferimento al puntatore indietreggiato (se diff>0 , altrimenti avanzare) di diff posizioni
     */
    const_iterator& operator-=(unsigned int diff);
};

template<class T>
class iterator {
    friend DynamicArray<T>;
    friend const_iterator<T>;
    /**
     * Operator + : ritorna un iteratore che dista diff posizioni da iter(non fa nessun controllo sui bound)
     * @param iter : iteratore di partenza
     * @param diff :  posizione da avanzare o indietreggiare, in base a sign(diff)
     * @return puntatore che corrisponde a invocare operator++ (o operator-- se diff è negativo) diff volte, su una copia di iter
     */
    friend iterator operator+<>(const iterator& iter, int  diff);
    /**
     * Operator + : ritorna un iteratore che dista diff posizioni da iter(non fa nessun controllo sui bound)
     * @param iter : iteratore di partenza
     * @param diff :  posizione da avanzare o indietreggiare, in base a sign(diff)
     * @return puntatore che corrisponde a invocare operator++ (o operator-- se diff è negativo) diff volte, su una copia di iter
     */
    friend iterator operator+<>(int  diff, const iterator& iter);
    /**
     * Operator - : ritorna un iteratore che dista diff posizioni da iter(non fa nessun controllo sui bound)
     * @param iter : iteratore di partenza
     * @param diff :  posizione da avanzare o indietreggiare, in base a sign(diff)
     * @return puntatore che corrisponde a invocare operator-- (o operator++ se diff è positivo) diff volte, su una copia di iter
     */
    friend iterator operator-<>(int  diff, const iterator& iter);
    /**
     * Operator - : ritorna un iteratore che dista diff posizioni da iter(non fa nessun controllo sui bound)
     * @param iter : iteratore di partenza
     * @param diff :  posizione da avanzare o indietreggiare, in base a sign(diff)
     * @return puntatore che corrisponde a invocare operator-- (o operator++ se diff è positivo) diff volte, su una copia di iter
     */
    friend iterator operator-<>(const iterator& iter, int  diff);
private:
    /**
     * Costruttore privato di supporto
     * @param container : riferimento al contenitore a cui si riferisce
     * @param position : posizione corrente dell'iteratore dentro al contenitore
     */
    iterator(DynamicArray<T>* container, unsigned int position) : arr(container), pos(static_cast<int>(position)) {}
    DynamicArray<T>* arr;
    int pos;
public:
    /**
     * Operator - : restituisce la distanza tra i due iteratori
     * @param iter : iteratore a cui confrontare this
     * @return distanza tra i due iteratori
     */
    int operator-(const iterator& iter) const;
    /**
     * Operator == : controlla se i due iteratori puntano allo stesso elemento
     * @param it : iterator a cui confrontare this
     * @return
     *          true se puntano allo stesso contenitore e alla stessa sua posizione
     *          false altrimenti
     */
    bool operator==(const iterator &it) const ;
    /**
     * Operator != : controlla se i due iteratori puntano a elementi diversi
     * @param it : iterator a cui confrontare this
     * @return
     *          true se puntano a contenitori diversi o se si riferiscono a posizioni diverse
     *          false altrimenti
     */
    bool operator!=(const iterator &it) const ;
    /**
     * Operator ++ (post-incrementato) : avanza il puntatore e restituisce il suo stato iniziale
     * @return puntatore copia di this allo stato iniziale, this invece avanzato di 1
     */
    iterator operator++(int) ;
    /**
     * Operator ++ (preincrementato) : avanza il puntatore di una posizione e ritorna un riferimento ad esso
     * @return
     */
    iterator &operator++() ;
    /**
     * Operator -- (post-decrementato) : indietreggia il puntatore e restituisce il suo stato iniziale
     * @return puntatore copia di this allo stato iniziale, this invece indietreggiato di 1
     */
    iterator operator--(int) ;
    /**
     * Operator -- (pre-decrementato) : indietreggia il puntatore e ne restituisce il riferimento
     * @return il puntatore di invocazione avanzato di una posizione
     */
    iterator &operator--() ;
    /**
     * Operator * : ritorna il riferimento dell'elemento corrente
     * @return riferimento all'elemento corrente
     */
    T& operator*() const ;
    /**
     * Operator -> : ritorna il puntatore all'elemento corrente
     * @return puntatore costante all'elemento corrente
     */
    T* operator->() const ;
    /**
     * Operator [] : ritorna un riferimento al diff-esimo elemento dalla posizione corrente
     * @param diff : posizione dell'elemento da ritornare rispetto alla posizione corrente
     * @return riferimento al diff-esimo elemento
     */
    T& operator[](unsigned int diff);
    /**
     * Opeerator += : fa avanzare (se diff>0 , altrimenti indietreggiare) l'iteratore di diff posizioni
     * @param diff : posizioni da far avanzare l'iteratore
     * @return riferimento al puntatore avanzato di diff posizioni
     */
    iterator& operator+=(int diff);
    /**
     * Operator -= : fa indietreggiare (se diff>0 , altrimenti avanzare) l'iteratore di diff posizioni
     * @param diff : posizioni da far avanzare l'iteratore
     * @return riferimento al puntatore indietreggaito (se diff>0 , altrimenti avanzare) di diff posizioni
     */
    iterator& operator-=(int diff);
    /**
     * Cast a const_iterator
     * @return promuove this a const_iterator
     */
    operator const_iterator<T> () const;
};
template<class T>
class DynamicArray{
public:
    typedef iterator<T> iterator;
    typedef const_iterator<T> const_iterator;

    /**
     *  Costruttore di default della classe (rappresenta un contenitore vuoto)
     */
    DynamicArray():
            p(std::make_unique<T[]>(0)) ,
            size_(0),
            capacity_(0){};
    /**
     * Costruttore di copia della classe
     * @param ar : contenitore da "copiare"
     */
    DynamicArray(const DynamicArray& ar);
    /**
     * Operator = : duplica il contenuto di ar in this
     * @param ar : elemento da copiare in this
     * @return riferimento a this
     */
    DynamicArray& operator=(const DynamicArray& ar);
    /**
     * Costruttore per rvalue
     * @param ar : elemento da spostare in this
     * @return riferimento a this
     */
    DynamicArray(DynamicArray&& ar)  noexcept;
    /**
     * copia gli elementi di l in this
     * @param l : lista di inizializzazione
     * @return riferimento a this
     */
    DynamicArray&operator=(std::initializer_list<T> l);
    /**
     * Operator = (per rvalue) : sposta l in this
     * @param l : lista di inizializzazione
     * @return riferimento a this
     */
    DynamicArray& operator=(DynamicArray&& l) noexcept ;
    /**
     * distruttore : default
     */
    ~DynamicArray() = default;

    /**
     * Costruttore : istanzia s copie di el
     * @param s
     * @param el
     */
    explicit DynamicArray(unsigned int s, const T& el = T()) ;
    /**
     * Costruttore : copia gli elementi [first , last) in this
     * @tparam InputIt : Iteratore che sia compatibile con InputIterator (check : http://www.cplusplus.com/reference/iterator/InputIterator/)
     * @param first: posizione primo elemento
     * @param last: posizione a cui fermarsi
     */
    template<class InputIt, typename = std::enable_if_t<!std::is_convertible_v<InputIt, const_iterator>>>
    DynamicArray(const InputIt& first, const InputIt& last );
    DynamicArray(const const_iterator& first, const const_iterator& last );
    /**
     * Costruttore con lista di inizializzazione : copia gli elementi della lista in this
     * @param l : lista di inizializzaizone
     */
    DynamicArray(std::initializer_list<T> l);
    /**
     * Restituisce il riferiemnto al pos-esimo elemento (fa controllo dei range)
     * @param pos : posizione elemento
     * @return riferimento pos-esimo elemento
     * @throws out_of_range : se pos non è una posiziona valida ( pos >= size() )
     */
    T& at(unsigned int pos);
    /**
     * Restituisce il riferiemnto costante al pos-esimo elemento (fa controllo dei range)
     * @param pos : posizione elemento
     * @return riferimento costante pos-esimo elemento
     * @throws out_of_range : se pos non è una posiziona valida ( pos >= size() )
     */
    [[nodiscard]] const T& at(unsigned int pos) const;
    /**
     * Restituisce il riferimento al primo elemento
     * @return riferimento al primo elemento
     * @warning : non fa controllo sui bound (se il contenitore è vuoto, è Undefined Behaviour)
     */
    T& front();
    /**
     * Restituisce il riferimento costante al primo elemento
     * @return riferimento costante al primo elemento
     * @warning : non fa controllo sui bound (se il contenitore è vuoto, è Undefined Behaviour)
     */
    [[nodiscard]] const T& front() const;
    /**
     * Restituisce il riferimento all'ultimo elemento
     * @return riferimento all'ultimo elemento
     * @warning : non fa controllo sui bound (se il contenitore è vuoto, è Undefined Behaviour)
     */
    T& back(){
        return p[size_-1];
    }
    /**
     * Restituisce il riferimento all'ultimo elemento
     * @return riferimento all'ultimo elemento
     * @warning : non fa controllo sui bound (se il contenitore è vuoto, è Undefined Behaviour)
     */
    [[nodiscard]] const T& back() const;
    /**
     * Segnala se il contenitore è vuoto
     * @return
     *          true se il contenitore è vuoto
     *          false altrimenti
     */
    [[nodiscard]] bool empty() const;
    /**
     * Restituisce la dimensione corrente del contenitore
     * @return dimensione corrente del contenitore
     */
    [[nodiscard]] unsigned int size() const;
    /**
     * Restituisce la capacità corrente del contenitore
     * @return capacità corrente del contenitore
     */
    [[nodiscard]] unsigned int capacity() const;
    /**
     * Incrementa la capacità del contenitore ad un valore maggiore o uguale a new_cap. Se new_cap è maggiore di capacity() allora avviene una reallocazione, altrimenti non succede nulla
     * @param new_cap : capacità desiderata
     */
    void reserve( unsigned int new_cap );
    /**
     * Reimposta lo stato del contenitore allo stato iniziale e vuoto
     */
    void clear();
    /**
     * Inserisce una copia di value in coda al contentiore
     * @param value : valore da inserire
     */
    void push_back( const T& value );
    /**
     * "Muove" value in coda al contentiore
     * @param value : valore da "muovere"
     */
    void push_back( T&& value );
    /**
     * Inserisce in posizione pos value
     * @param pos : iteratore valido che rappresenta la posizione desiderata
     * @param value : valore da inserire
     * @return iteratore all'elemento inserito
     */
    iterator insert(const const_iterator& pos, const T& value );
    /**
     * Inserisce in posizione pos value (per rvalue reference)
     * @param pos : iteratore valido che rappresenta la posizione desiderata
     * @param value : valore da inserire
     * @return iteratore all'elemento inserito
     */
    iterator insert(const const_iterator& pos, T&& value );

    /**
     * Inserisce dalla posizione pos count copie di value
     * @param pos : iteratore valido rappresentante la posizione a cui iniziare a inserire
     * @param count : numero di occorrenze
     * @param value : valore da inserire
     * @return iteratore al primo elemento inserito
     */
    iterator insert(const const_iterator& pos, unsigned int count, const T& value );
    /**
     * Inserisce dalla posizione pos gli elementi [first,last)
     * @tparam InputIt : Iteratore che sia compatibile con InputIterator (check : http://www.cplusplus.com/reference/iterator/InputIterator/)
     * @param pos : iteratore valido rappresentante la posizione a cui iniziare a inserire
     * @param first : primo elemento da copiare
     * @param last : iteratore rappresentante la fine degli elementi da inserire
     * @return itertore al primo elemento inserito
     */
    template< class InputIt >
    std::enable_if_t<!std::is_convertible_v<InputIt, const_iterator>, iterator> insert(const const_iterator& pos, const InputIt& first, const InputIt& last );
    template< class Const_Iterator >
    std::enable_if_t<std::is_convertible_v<Const_Iterator, const_iterator>, iterator> insert(const const_iterator& pos, const Const_Iterator& first, const Const_Iterator& last );
    /**
     * Inserisce alla posizione pos un nuovo elemento construito con args
     * @tparam Args : tipi parametri da passare al costruttore di T
     * @param pos : iteratore valido rappresentante la posizione desiderata (se pos == end() allora equivale a emplace_back)
     * @param args : valori da passare al costruttore
     * @return iteratore alla posizione in cui è stato inserito il nuovo elemento
     */
    template< class... Args >
    iterator emplace(const const_iterator& pos, Args&&... args );
    /**
     * Rimuove l'elemento in posizione pos
     * @param pos : iteratore valido e dereferenziabile rappresentante la posizione elemento da rimuovere
     * @return iteratore all'elemento successivo all'elemento rimosso
     */
    iterator erase(const const_iterator& pos );
    /**
     * Rimuove tutti gli elementi nell'intervallo [first,last)
     * @param first : iteratore valido rappresentante la posizione del primo elemento da rimuovere
     * @param last : iteratore valido rappresentante la posizione a cui fermarsi a rimuovere
     * @warning se last è precedente o coincidente a first non avviene nulla
     */
    void erase(const const_iterator& first, const const_iterator& last );
    /**
     * Rimuove l'ultimo elemento
     * @warning se il contenitore è vuoto, è Undefined Behaviour
     */
    void pop_back();
    /**
     * Effettua lo swap tra this e other
     * @param other : elemento con cui fare lo swap
     */
    void swap( DynamicArray& other ) noexcept ;
    /**
     * Inserisce alla fine un nuovo elemento construito con args
     * @tparam Args : tipi parametri da passare al costruttore di T
     * @param args : valori da passare al costruttore
     * @return riferimento al nuovo elemento
     */
    template< class... Args >
    T& emplace_back( Args&&... args );


    /**
     * restituisce un iteratore che rappresenta l'inizio del contenitore
     * @return iteratore che rappresenta l'inizio del contenitore
     */
    iterator begin();
    /**
     * restituisce un iteratore che rappresenta l'inizio del contenitore
     * @return const iteratore che rappresenta l'inizio del contenitore
     */
    const_iterator begin() const ;
    /**
     * restituisce un iteratore che rappresenta l'inizio del contenitore
     * @return const iteratore che rappresenta l'inizio del contenitore
     */
    const_iterator cbegin() const ;
    /**
     * restituisce un iteratore che rappresenta la fine del contenitore
     * @return iteratore che rappresenta la fine del contenitore
     */
    iterator end();
    /**
     * restituisce un iteratore che rappresenta la fine del contenitore
     * @return const iteratore che rappresenta la fine del contenitore
     */
    const_iterator end() const;
    /**
     * restituisce un iteratore che rappresenta la fine del contenitore
     * @return const iteratore che rappresenta la fine del contenitore
     */
    const_iterator cend() const;

    /**
     * Restituisce il riferimento al pos-esimo elemento
     * @param pos : posizione dell'elemento desiderato
     * @return riferimento al pos-esimo elemento
     * @warning nessun controllo dei range è effettuato, perciò se pos >= size() è Undefined Behaviour
     * @see at
     */
    T& operator[](unsigned int pos);
    /**
     * Restituisce il riferimento al pos-esimo elemento
     * @param pos : posizione dell'elemento desiderato
     * @return riferimento costante al pos-esimo elemento
     * @warning nessun controllo dei range è effettuato, perciò se pos >= size() è Undefined Behaviour
     * @see at
     */
    const T& operator[](unsigned int pos) const;
    /**
     * Segnala se il contenuto dei due contenitori è equivalente
     * @param other : contenitore a cui confrontare this
     * @return
     *         true se i due contenitori han lo stesso numero di elementi e l'i-esimo elemento di this è equivalente all'i-esimo elemento di other
     *         false altrimenti
     */
    bool operator==(const DynamicArray& other ) const;
    /**
     * Segnala se i due contenitori non son equivalenti
     * @param other : contenitore a cui confrontare this
     * @return
     *         true se i due contenitori non han lo stesso numero di elementi o un i-esimo elemento di this non è equivalente all'i-esimo elemento di other
     *         false altrimenti
     */
    bool operator!=(const DynamicArray& other ) const;
    /**
     * Segnala se this è lessicograficamente minore di other
     * @param other : contenitore a cui confrontare this
     * @return
     *         true se this è lessicograficamente minore di other
     *         false altrimenti
     */
    bool operator<(const DynamicArray& other) const;
    /**
     * Segnala se this è lessicograficamente minore di other o equivalente ad esso
     * @param other : contenitore a cui confrontare this
     * @return
     *         true se this è lessicograficamente minore di other o equivalente ad esso
     *         false altrimenti
     */
    bool operator<=(const DynamicArray& other) const;
    /**
     * Segnala se this è lessicograficamente maggiore di other
     * @param other : contenitore a cui confrontare this
     * @return
     *         true se this è lessicograficamente maggiore di other
     *         false altrimenti
     */
    bool operator>(const DynamicArray& other) const;
    /**
     * Segnala se this è lessicograficamente maggiore di other o equivalente ad esso
     * @param other : contenitore a cui confrontare this
     * @return
     *         true se this è lessicograficamente maggiore di other o equivalente ad esso
     *         false altrimenti
     */
    bool operator>=(const DynamicArray& other) const;
private:
    /**
     * prepara this a contenere almeno altri needs elementi
     * @param needs : numero di elementi da preparare il contenitore a contenere
     */
    template<class Iter>
    void insert_distance(int dist, const const_iterator& pos, const Iter& first);
    void prepare(int needs);

    /// puntatore all'array degli elementi
    std::unique_ptr<T[]> p;
    /// dimensione corrente del contenitore
    unsigned int size_;
    /// capacità corrente del contenitore
    unsigned int capacity_;
};


/********************************/
/***         iterator         ***/
/********************************/
template<class T>
iterator<T> operator+(const iterator<T> &iter, int diff) {
    return iterator(iter.arr, iter.pos + diff);
}

template<class T>
iterator<T> operator+(int diff, const iterator<T> &iter){
    return iter + diff;
}

template<class T>
iterator<T> operator-(int diff, const iterator<T> &iter) {
    return iter + -diff;
}

template<class T>
iterator<T> operator-(const iterator<T> &iter, int diff) {
    return iter + -diff;
}

template<class T>
int iterator<T>::operator-(const iterator &iter) const {
    return pos - iter.pos;
}

template<class T>
bool DynamicArray<T>::iterator::operator==(const iterator &it) const{
    return arr == it.arr && pos == it.pos;
}

template<class T>
bool DynamicArray<T>::iterator::operator!=(const iterator &it) const {
    return !(*this == it);
}

template<class T>
iterator<T> DynamicArray<T>::iterator::operator++(int){
    auto cp(*this);
    ++pos;
    return cp;
}

template<class T>
iterator<T> &DynamicArray<T>::iterator::operator++() {
    ++pos;
    return *this;
}

template<class T>
iterator<T> DynamicArray<T>::iterator::operator--(int) {
    auto cp(*this);
    --pos;
    return cp;
}

template<class T>
iterator<T> &DynamicArray<T>::iterator::operator--() {
    --pos;
    return *this;
}

template<class T>
T &DynamicArray<T>::iterator::operator*() const {
    return (*arr)[pos];
}

template<class T>
T *DynamicArray<T>::iterator::operator->() const {
    return &((*arr)[pos]);
}

template<class T>
T &DynamicArray<T>::iterator::operator[](unsigned int diff) {
    return (*arr)[pos+diff];
}

template<class T>
iterator<T> &DynamicArray<T>::iterator::operator+=(int diff) {
    pos+= diff;
    return *this;
}

template<class T>
iterator<T> &DynamicArray<T>::iterator::operator-=(int diff) {
    pos-= diff;
    return *this;
}

template<class T>
iterator<T>::operator const_iterator<T>() const{
    return const_iterator(arr, pos);
}


/********************************/
/***      const_iterator      ***/
/********************************/
template<class T>
const_iterator<T> operator+(const const_iterator<T> &iter, int diff) {
    return const_iterator(iter.arr, iter.pos + diff);
}

template<class T>
const_iterator<T> operator+(int diff, const const_iterator<T> &iter) {
    return iter + diff;
}

template<class T>
const_iterator<T> operator-(int diff, const const_iterator<T> &iter) {
    return iter + -diff;
}

template<class T>
const_iterator<T> operator-(const const_iterator<T> &iter, int diff) {
    return iter + -diff;
}

template<class T>
int const_iterator<T>::operator-(const const_iterator &iter) const {
    return pos - iter.pos;
}

template<class T>
bool const_iterator<T>::operator==(const const_iterator &it) const {
    return arr == it.arr && pos == it.pos;
}

template<class T>
bool const_iterator<T>::operator!=(const const_iterator &it) const {
    return !(*this == it);
}

template<class T>
const_iterator<T> const_iterator<T>::operator++(int) {
    auto cp(*this);
    ++pos;
    return cp;
}

template<class T>
const_iterator<T> &const_iterator<T>::operator++()  {
    ++pos;
    return *this;
}

template<class T>
const_iterator<T> const_iterator<T>::operator--(int) {
    auto cp(*this);
    --pos;
    return cp;
}

template<class T>
const_iterator<T> &const_iterator<T>::operator--() {
    --pos;
    return *this;
}

template<class T>
const T &const_iterator<T>::operator*() const {
    return (*arr)[pos];
}

template<class T>
const T *const_iterator<T>::operator->() const  {
    return &((*arr)[pos]);
}

template<class T>
const T &const_iterator<T>::operator[](unsigned int diff) {
    return (*arr)[pos+diff];
}

template<class T>
const_iterator<T> &const_iterator<T>::operator+=(unsigned int diff) {
    pos+= static_cast<int>(diff);
    return *this;
}

template<class T>
const_iterator<T> &const_iterator<T>::operator-=(unsigned int diff) {
    pos-= static_cast<int>(diff);
    return *this;
}


/********************************/
/***       DynamicArray       ***/
/********************************/
template<class T>
DynamicArray<T>::DynamicArray(const DynamicArray &ar) :
        p(std::make_unique<T[]>(ar.capacity_)),
        size_(ar.size_),
        capacity_(ar.capacity_){
    for(unsigned int i = 0; i < size_; ++i)
        p[i] = ar.p[i];
}

template<class T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray &ar) {
    if(this != &ar){
        size_ = ar.size_;
        capacity_ = ar.capacity_;
        std::unique_ptr<T> ptr(new T);
        p = std::make_unique<T[]>(capacity_);
        for(unsigned int i = 0; i < size_; ++i)
            p[i] = ar.p[i];
    }
    return *this;
}

template<class T>
DynamicArray<T>::DynamicArray(DynamicArray &&ar) noexcept  : size_(ar.size_), capacity_(ar.capacity_) , p(std::move(ar.p)){}

template<class T>
DynamicArray<T> &DynamicArray<T>::operator=(std::initializer_list<T> l) {
    size_ = l.size();
    capacity_ = l.size();
    p = std::make_unique<T[]>(l.size());
    unsigned int i = 0;
    for(auto& el : l)
        p[i++] = el;
    return *this;
}

template<class T>
DynamicArray<T> &DynamicArray<T>::operator=(DynamicArray &&l) noexcept {
    size_ = l.size_;
    capacity_ = l.capacity_;
    p = std::move(l.p);
    return *this;
}

template<class T>
DynamicArray<T>::DynamicArray(unsigned int s, const T &el) : size_(s), capacity_(s), p(std::make_unique<T[]>(s)){
    for(unsigned int i = 0; i < size_; ++i)
        p[i] = el;
}

template<class T>
template<class InputIt, typename>
DynamicArray<T>::DynamicArray(const InputIt &first, const InputIt &last) {
    auto dist = std::distance(first, last);
    size_ = capacity_ = dist;
    p = std::make_unique<T[]>(dist);
    InputIt it = first;
    for(unsigned int i = 0; i < size_; ++i) {
        p[i] = *it;
        ++it;
    }
}

template<class T>
DynamicArray<T>::DynamicArray(const DynamicArray::const_iterator &first, const DynamicArray::const_iterator &last) {
    auto dist = last - first;
    size_ = capacity_ = dist;
    p = std::make_unique<T[]>(dist);
    iterator it(this, first.pos);
    for(unsigned int i = 0; i < size_; ++i) {
        p[i] = *it;
        ++it;
    }
}

template<class T>
DynamicArray<T>::DynamicArray(std::initializer_list<T> l) : size_(l.size()), capacity_(l.size()), p(std::make_unique<T[]>(l.size())) {
    unsigned int i = 0;
    for(auto& el : l)
        p[i++] = el;
}

template<class T>
T &DynamicArray<T>::at(unsigned int pos) {
    if(pos >= size_)
        throw std::out_of_range("L'elemento richiesto è al di fuori della dimensione del contenitore");
    return p[pos];
}

template<class T>
const T &DynamicArray<T>::at(unsigned int pos) const  {
    if(pos >= size_)
        throw std::out_of_range("L'elemento richiesto è al di fuori della dimensione del contenitore");
    return p[pos];
}

template<class T>
T &DynamicArray<T>::front() {
    return p[0];
}

template<class T>
const T &DynamicArray<T>::front() const{
    return p[0];
}

template<class T>
const T &DynamicArray<T>::back() const {
    return p[size_-1];
}

template<class T>
bool DynamicArray<T>::empty() const {
    return size_ == 0;
}

template<class T>
template<class... Args>
typename DynamicArray<T>::iterator DynamicArray<T>::emplace(const DynamicArray::const_iterator &pos, Args &&... args) {
    prepare(1);
    if(pos == end()) {
        p[size_] = T(std::forward<Args>(args)...);
        ++size_;
        return end()-1;
    }
    else {
        for (int i = size_ - 1; i >= pos.pos; --i)
            p[i + 1] = p[i];
        p[pos.pos] = T(std::forward<Args>(args)...);
        ++size_;
        return iterator(this, pos.pos);
    }
}

template<class T>
unsigned int DynamicArray<T>::size() const {
    return size_;
}

template<class T>
unsigned int DynamicArray<T>::capacity() const {
    return capacity_;
}

template<class T>
void DynamicArray<T>::reserve(unsigned int new_cap) {
    if(new_cap > capacity_) {
        auto new_p = std::make_unique<T[]>(new_cap);
        for(int i = 0; i < capacity_ ;++i)
            new_p[i] = std::move(p[i]);
        p = std::move(new_p);
        capacity_ = new_cap;
    }
}

template<class T>
void DynamicArray<T>::clear() {
    size_ = 0;
}

template<class T>
void DynamicArray<T>::push_back(const T &value) {
    prepare(1);
    p[size_] = value;
    ++size_;
}

template<class T>
void DynamicArray<T>::push_back(T &&value) {
    prepare(1);
    p[size_] = std::move(value);
    ++size_;
}

template<class T>
typename DynamicArray<T>::iterator DynamicArray<T>::insert(const DynamicArray::const_iterator &pos, const T &value) {
    prepare(1);
    for( int i = size_-1; i >= pos.pos; --i)
        p[i+1]= std::move(p[i]);
    p[pos.pos] = value;
    ++size_;
    return iterator(this, pos.pos);
}

template<class T>
typename DynamicArray<T>::iterator DynamicArray<T>::insert(const DynamicArray::const_iterator &pos, T &&value) {
    prepare(1);
    for(int i = size_-1; i >= pos.pos; --i)
        p[i+1]= std::move(p[i]);
    p[pos.pos] = std::move(value);
    ++size_;
    return iterator(this, pos.pos);
}

template<class T>
typename DynamicArray<T>::iterator DynamicArray<T>::insert(const DynamicArray::const_iterator &pos, unsigned int count, const T &value) {
    if(count > 0){
        prepare(count);
        for(int i = size_-1; i >= pos.pos; --i)
            p[i+count]= std::move(p[i]);
        for(int i = pos.pos; i < pos.pos + count; ++i)
            p[i] = value;
        size_+=count;
    }
    return iterator(this, pos.pos);
}

template<class T>
typename DynamicArray<T>::iterator DynamicArray<T>::erase(const DynamicArray::const_iterator &pos) {
    if(pos != end() && !empty()) {
        for (int i = pos.pos; i < size_; ++i) {
            p[i] = std::move(p[i+1]);
        }
        --size_;
        return iterator(this, pos.pos);
    }
    return end();
}

template<class T>
void DynamicArray<T>::erase(const DynamicArray::const_iterator &first, const DynamicArray::const_iterator &last) {
    if(first != last) {
        iterator l_(this, last.pos);
        iterator f_(this, first.pos);
        while (f_ != l_)
            erase(--l_);
    }
}

template<class T>
void DynamicArray<T>::pop_back() {
    --size_;
}

template<class T>
template< class InputIt >
std::enable_if_t<!std::is_convertible_v<InputIt, typename DynamicArray<T>::const_iterator>, typename DynamicArray<T>::iterator> DynamicArray<T>::insert(const typename DynamicArray<T>::const_iterator& pos, const InputIt& first, const InputIt& last ){
    int dist = std::distance(first, last);
    insert_distance(dist, pos, first);
    return iterator(this, pos.pos);
}

template<class T>
template< class Const_Iterator>
std::enable_if_t<std::is_convertible_v<Const_Iterator, typename DynamicArray<T>::const_iterator>, typename DynamicArray<T>::iterator> DynamicArray<T>::insert(const typename DynamicArray<T>::const_iterator& pos, const Const_Iterator& first, const Const_Iterator& last ) {
    int dist = last - first;
    insert_distance(dist, pos, first);
    return iterator(this, pos.pos);
}

template<class T>
void DynamicArray<T>::swap(DynamicArray &other) noexcept {
    p.swap(other.p);
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
}

template<class T>
template<class... Args>
T &DynamicArray<T>::emplace_back(Args &&... args) {
    emplace(end(), std::forward<T>(args) ...);
    return p[size_-1];
}

template<class T>
typename DynamicArray<T>::iterator DynamicArray<T>::begin() {
    return iterator(this, 0);
}

template<class T>
typename DynamicArray<T>::const_iterator DynamicArray<T>::begin() const {
    return const_iterator(this, 0);
}

template<class T>
typename DynamicArray<T>::const_iterator DynamicArray<T>::cbegin() const {
    return const_iterator(this, 0);
}

template<class T>
typename DynamicArray<T>::iterator DynamicArray<T>::end() {
    return iterator(this, size_);
}

template<class T>
typename DynamicArray<T>::const_iterator DynamicArray<T>::end() const  {
    return const_iterator(this, size_);
}

template<class T>
typename DynamicArray<T>::const_iterator DynamicArray<T>::cend() const  {
    return const_iterator(this, size_);
}

template<class T>
T &DynamicArray<T>::operator[](unsigned int pos) {
    return p[pos];
}

template<class T>
const T &DynamicArray<T>::operator[](unsigned int pos) const {
    return p[pos];
}

template<class T>
bool DynamicArray<T>::operator==(const DynamicArray &other) const{
    if(size_ != other.size_) return false;
    for(int i = 0; i < size_ ; ++i)
        if(p[i] != other.p[i])
            return false;
    return true;
}

template<class T>
bool DynamicArray<T>::operator!=(const DynamicArray &other) const{
    return ! (*this == other);
}

template<class T>
bool DynamicArray<T>::operator<(const DynamicArray &other) const {
    for(int i = 0; i < size_ ; ++i){
        if(i >= other.size_) return false;
        if(p[i] >= other.p[i]) return false;
    }
    return true;
}

template<class T>
bool DynamicArray<T>::operator<=(const DynamicArray &other) const {
    for(int i = 0; i < size_ ; ++i){
        if(i >= other.size_) return false;
        if(p[i] > other.p[i]) return false;
    }
    return true;
}

template<class T>
bool DynamicArray<T>::operator>(const DynamicArray &other) const {
    for(int i = 0; i < size_ ; ++i){
        if(i >= other.size_) return true;
        if(p[i] <= other.p[i]) return false;
    }
    return true;
}

template<class T>
bool DynamicArray<T>::operator>=(const DynamicArray &other) const {
    for(int i = 0; i < size_ ; ++i){
        if(i >= other.size_) return true;
        if(p[i] < other.p[i]) return false;
    }
    return true;
}

template<class T>
template<class Iter>
void DynamicArray<T>::insert_distance(int dist, const DynamicArray::const_iterator &pos, const Iter &first) {
    if(dist > 0){
        for(int i = 0 ; i < dist ; ++i)
            insert( pos + i , *(first + i));
    }
}

template<class T>
void DynamicArray<T>::prepare(int needs) {
    if(needs > 0) {
        if(capacity_ > 0) {
            unsigned int coeff = 1;
            while (size_ + needs >= capacity_ * coeff)
                coeff *= 2;
            if (coeff > 1)
                reserve(capacity_ * coeff);
        } else {
            reserve(1);
        }
    }
}


#endif //CSVPARSER_DYNAMICARRAY_H

