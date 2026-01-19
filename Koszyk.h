#ifndef __Koszyk_h__
#define __Koszyk_h__

#include <string>
#include <vector>
#include <stdexcept>

class Gosc;
class Klient;
class Produkt;
class Zamowienie;

class Koszyk
{
private:
    struct Pozycja
    {
        Produkt* produkt = nullptr;
        int ilosc = 0;
    };

    Klient* _wlasciciel = nullptr;
    std::vector<Pozycja> _pozycje;

    // Metoda prywatna - tylko Klient (friend) może dodawać produkty
    void dodajProdukt(Produkt* produkt, int ilosc);

public:
    explicit Koszyk(Klient* wlasciciel);
    ~Koszyk(); // Destruktor do sprzątania

    void usunZKoszyka(std::string nazwaProduktu);
    void wyczysc();
    
    // Nowe metody do obsługi interfejsu
    void wyswietlZawartosc() const;
    double pobierzWartoscCalkowita() const;
    bool czyPusty() const;

    friend class Klient; 
};

#endif