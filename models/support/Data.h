//
// Created by Alberto Sinigaglia on 12/04/2020.
//

#ifndef CSVPARSER_DATA_H
#define CSVPARSER_DATA_H

#include <istream>
#include <iostream>
#include <string>
#include <sstream>
struct DifferenzaDate{
    int giorni = 0;
    int mesi = 0;
    int anni = 0;
    inline int inGiorni() const{ return giorni + mesi * 31 + anni * 365; };
    inline int inMesi() const{ return mesi + anni * 12; };
    inline int inAnni() const{ return anni; };
};
std::ostream& operator<<(std::ostream& os, const DifferenzaDate& d);



class Data {
    friend std::istream &operator>>(std::istream &, Data &);
    friend std::ostream &operator<<(std::ostream &,const Data &);
    friend Data operator+(const Data& d, const DifferenzaDate& diff);
    friend Data operator+(const DifferenzaDate& diff,const Data& d);
private:

    static const int giorni_al_mese[12];    //gennaio -> 0  , dicembre -> 11
    static int giorniDelMese(unsigned int mese_, int anno_ = 1);
    unsigned int giorno, mese;    // data non esiste (mai) corrisponde ai tre campi = 0
    int anno;

public:
    /*
     * Costruttori
     */
    explicit Data(int num_giorni = 0);     //dalla data base (0,1,1)
    explicit Data(int a, unsigned int m, unsigned int g);

    /*
     * Setter
     */
    void setGiorno(unsigned int g);
    void setMese(unsigned int m);
    void setAnno(int a);

    /*
     * Getter
     */
    inline unsigned int getGiorno() const;
    inline unsigned int getMese() const;
    inline int getAnno() const;

    /*
     * Setter Helpers
     */
    void addRemoveGiorni(int g);    // accetta anche valori negativi => toglie giorni
    void addRemoveMesi(int m);
    void addRemoveAnni(int a);

    /*
     * Getter Helper
     */
    int differenzaGiorni(const Data &) const;
    int differenzaMesi(const Data &) const;
    int differenzaAnni(const Data &) const;

    /*
     * Operatori
     */
    bool operator==(const Data &d1) const;
    bool operator<(const Data &) const;        //assunzione: qualsiasi data è maggiore di una data che non esiste
    bool operator>(const Data &) const;
    /**
     * Restituisce la differenza delle date tra (this, d);
     * @param d : data da sottrarre
     * @return : differenza date
     */
    DifferenzaDate operator-(const Data &d) const;
    Data& operator+=(const DifferenzaDate& diff);


    /*
     * Cast
     */
    explicit operator int() const; // differenza giorni dalla base (0,1,1)


    /*
     * Metodi statici
     */
    static Data oggi();

};

#endif //CSVPARSER_DATA_H
