#include<vector>
#include "Data.h"




const int Data::giorni_al_mese[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int Data::giorniDelMese(unsigned int mese_, int anno_) {
    return (((mese_ == 1) && (anno_ % 4 == 0)) ? 29 : Data::giorni_al_mese[mese_]);
}

Data Data::oggi() {
    std::time_t now = time(nullptr);
    tm *lt = std::localtime(&now);
    return Data(lt->tm_year + 1900, lt->tm_mon + 1 , lt->tm_mday);
}

Data::Data(int a, unsigned int m, unsigned int g) : anno(a), mese(m-1), giorno(g) {
    if ( mese > 11 )
        throw std::invalid_argument("Mese non valido");
    else if(giorno > giorniDelMese(mese, anno) || giorno < 1)
        throw std::invalid_argument("Giorno non valido");
}

Data::Data(int num_giorni) {
    int a, m;
    a = num_giorni / (1461) * 4;   //366+365*3
    num_giorni = num_giorni % 1461;
    if (num_giorni > 366) {
        num_giorni -= 366;
        a += num_giorni / 365 + 1;
        num_giorni = num_giorni % 365;
    }
    m = 1;
    while (num_giorni > giorniDelMese(m -1 , a))
        num_giorni -= giorniDelMese(m++ - 1 , a);
    anno = a;
    mese = m-1;
    giorno = num_giorni;
}

bool Data::operator==(const Data &d) const {
    return (this == &d) || (anno == d.anno && mese == d.mese && giorno == d.giorno);
}

bool Data::operator<(const Data &d) const {
    if (operator==(d)) return false;    // serve per la condizione dell'esistenza
    if (anno > d.anno) return false;
    if (anno < d.anno) return true;
    if (mese > d.mese) return false;
    if (mese < d.mese) return true;
    return giorno < d.giorno;
}

bool Data::operator>(const Data &d) const {
    return !(operator==(d) || operator<(d));
}

int Data::differenzaGiorni(const Data &d) const {
    return static_cast<int>(*this) - static_cast<int>(d);
}
int Data::differenzaMesi(const Data &d) const {
    int count_mesi = 0;
    const Data *max, *min;
    if (operator>(d)) {
        max = this;
        min = &d;
    }
    else {
        max = &d;
        min = this;
    }
    count_mesi += static_cast<int>(max->mese) - static_cast<int>(min->mese);
    count_mesi += 12 * (max->anno - min->anno);
    return count_mesi * (max == this ? 1 : -1);
}
int Data::differenzaAnni(const Data &d) const {
    return anno - d.anno;
}
DifferenzaDate Data::operator-(const Data &d) const {
    int diff=static_cast<int>(std::max(*this, d)) - static_cast<int>(std::min(*this, d));
    return {
            diff % 365 % 31,
            diff % 365 / 31,
            diff / 365,
    };
}

Data::operator int() const {
    int g = static_cast<int>(giorno);

    int m = 0;
    for(unsigned int i = 0 ; i < mese ; i++ )
        m += giorniDelMese(i,m);
    return  m + g;
}

void Data::addRemoveGiorni(int g) {
    int tot_giorni = static_cast<int>(*this);
    tot_giorni+=g;
    Data data(tot_giorni);
    giorno = data.giorno;
    mese = data.mese;
    anno = data.anno;
}

void Data::addRemoveMesi(int m) {
    int a_ = m / 12;
    int m_ = m % 12;
    if(m_ < 0 && -m > mese){
        mese = 12 - (-m - mese);
        a_ -= 1;
    }
    else
        mese += m_;
    anno += a_;
}

void Data::addRemoveAnni(int a) {
    anno += a;
}

void Data::setGiorno(unsigned int g) {
    if( g > 0 && g<= giorniDelMese(mese, anno) )
        giorno = g;
    else
        throw std::invalid_argument("Giorno non valido");
}

void Data::setMese(unsigned int m) {
    if( m > 0 && m <= 12 && giorno <= giorniDelMese(m - 1 , anno))
        mese = m - 1;
    else
        throw std::invalid_argument("Mese non valido");
}

void Data::setAnno(int a) {
    anno = a;
}

unsigned int Data::getGiorno() const {
    return giorno;
}

unsigned int Data::getMese() const {
    return mese + 1;
}

int Data::getAnno() const {
    return anno;
}

std::istream &operator>>(std::istream & input, Data &data) {
    unsigned int d, m;
    int y;
    std::string s;
    input >> s;

    auto pos_f = s.find('/');
    if(pos_f == std::string::npos)
        throw std::invalid_argument("L'input fornito non è nel formato GG/MM/(-)YYYY");
    std::istringstream (s.substr(0, pos_f)) >> d;
    s = s.substr(pos_f+1);

    auto pos_s = s.find('/');
    if(pos_s == std::string::npos)
        throw std::invalid_argument("L'input fornito non è nel formato GG/MM/(-)YYYY");
    std::istringstream (s.substr(0, pos_s)) >> m;
    s = s.substr(pos_s+1);

    std::istringstream (s) >> y;

    try {
        data = Data(y, m-1, d);
    } catch (const std::invalid_argument& e ){
        throw std::invalid_argument("L'input fornito non è valido");
    }
    return input;
}

std::ostream &operator<<(std::ostream &os, const Data &data) {
    return os << data.giorno << "/" << data.mese+1 << "/" << data.anno;
}

Data operator+(const Data &d, const DifferenzaDate &diff) {
    Data cp(d);
    cp.addRemoveAnni(diff.anni);
    cp.addRemoveMesi(diff.mesi);
    cp.addRemoveGiorni(diff.giorni);
    return cp;
}

Data operator+(const DifferenzaDate &diff, const Data &d) {
    Data cp(d);
    cp.addRemoveAnni(diff.anni);
    cp.addRemoveMesi(diff.mesi);
    cp.addRemoveGiorni(diff.giorni);
    return cp;
}

Data &Data::operator+=(const DifferenzaDate &diff) {
    addRemoveAnni(diff.anni);
    addRemoveMesi(diff.mesi);
    addRemoveGiorni(diff.giorni);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const DifferenzaDate& d){
     return os<<d.giorni<<" giorni, "<< d.mesi << " mesi, "<<d.anni<<" anni";
}