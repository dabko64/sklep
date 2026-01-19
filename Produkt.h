#include <exception>
using namespace std;

#ifndef __Produkt_h__
#define __Produkt_h__

#include <string>

class Klient;
class Koszyk;
class Magazyn;
class Produkt;
class Produkt {
private:
    std::string _nazwa;
    double _cena;
    int _iloscWMagazynie;

public:
    // Konstruktor
    Produkt(std::string nazwa, double cena, int ilosc);

    // Gettery (pobieranie danych)
    std::string getNazwa() const;
    double getCena() const;
    int getIlosc() const;

    // Metody modyfikujące
    void zmniejszStan(int ile);
};

#endif