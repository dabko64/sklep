#include <exception>
using namespace std;

#include "Koszyk.h"
#include "Gosc.h"
#include "Klient.h"
#include "Produkt.h"
#include "Zamowienie.h"

void Koszyk::usunZKoszyka() {
	throw "Not yet implemented";
}

void Koszyk::zlozZamowienie() {
	throw "Not yet implemented";
}



/*
#include "Koszyk.h"
#include "Klient.h"
#include "Produkt.h"
#include <algorithm>

Koszyk::Koszyk(Klient* wlasciciel)
    : _wlasciciel(wlasciciel)
{
    if (!_wlasciciel)
        throw std::invalid_argument("Koszyk: wlasciciel nie moze byc nullptr");
}

void Koszyk::dodajProdukt(Produkt* produkt, int ilosc)
{
    if (!produkt) throw std::invalid_argument("Koszyk::dodajProdukt: produkt == nullptr");
    if (ilosc <= 0) throw std::invalid_argument("Koszyk::dodajProdukt: ilosc musi byc > 0");

    // jeśli już jest w koszyku -> zwiększ ilość
    for (auto& p : _pozycje)
    {
        if (p.produkt == produkt)
        {
            p.ilosc += ilosc;
            return;
        }
    }

    // jeśli nie ma -> dodaj nową pozycję
    _pozycje.push_back(Pozycja{produkt, ilosc});
}

void Koszyk::usunZKoszyka(Produkt* produkt, int ilosc)
{
    if (!produkt) throw std::invalid_argument("Koszyk::usunZKoszyka: produkt == nullptr");
    if (ilosc <= 0) throw std::invalid_argument("Koszyk::usunZKoszyka: ilosc musi byc > 0");

    for (auto it = _pozycje.begin(); it != _pozycje.end(); ++it)
    {
        if (it->produkt == produkt)
        {
            it->ilosc -= ilosc;
            if (it->ilosc <= 0) _pozycje.erase(it);
            return;
        }
    }

    throw std::runtime_error("Koszyk::usunZKoszyka: produkt nie istnieje w koszyku");
}

void Koszyk::wyczysc()
{
    _pozycje.clear();
}

int Koszyk::ilePozycji() const
{
    return (int)_pozycje.size();
}

void Koszyk::zlozZamowienie()
{
    if (_pozycje.empty())
        throw std::runtime_error("Koszyk::zlozZamowienie: koszyk jest pusty");

    // TODO: tutaj tworzysz Zamowienie na podstawie _pozycje i _wlasciciel
    // np. Zamowienie z(_wlasciciel, _pozycje); itp.
}

*/
