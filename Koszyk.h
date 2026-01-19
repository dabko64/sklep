#include <exception>
using namespace std;

#ifndef __Koszyk_h__
#define __Koszyk_h__

// #include "Gosc.h"
// #include "Klient.h"
// #include "Produkt.h"
// #include "Zamowienie.h"

class Gosc;
class Klient;
class Produkt;
class Zamowienie;
class Koszyk;

class Koszyk
{
	private: int _idProduktu;
	private: string _nazwaProduktu;
	private: bool _czyJestDostepny;
	public: Gosc* _unnamed_Gosc_;
	public: Klient* _unnamed_Klient_20;
	public: Produkt* _unnamed_Produkt_;
	public: Zamowienie* _unnamed_Zamowienie_;

	public: void usunZKoszyka();

	public: void zlozZamowienie();
};

#endif









/*
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

    Klient* _wlasciciel = nullptr;              // tylko ten klient może dodawać
    std::vector<Pozycja> _pozycje;

    // TYLKO Klient może wywołać (bo private + friend)
    void dodajProdukt(Produkt* produkt, int ilosc);

public:
    // ważne: tworzymy koszyk przypisany do klienta
    explicit Koszyk(Klient* wlasciciel);

    void usunZKoszyka(Produkt* produkt, int ilosc = 1);
    void wyczysc();

    // opcjonalnie: żebyś mógł policzyć sumę itp.
    int ilePozycji() const;

    // jeśli masz Zamowienie w projekcie, możesz tu zwracać wskaźnik/obiekt
    void zlozZamowienie();

    friend class Klient; // <-- KLUCZ: tylko Klient ma dostęp do dodajProdukt()
};

#endif
*/
