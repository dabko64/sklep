#include "Klient.h"
#include <iostream>

using namespace std;

// konstruktor
Klient::Klient(const string& l,
    const string& h,
    const string& e,
    const string& i,
    const string& n,
    const string& a,
    int nrTel)
    : email(e),
    imie(i),
    nazwisko(n),
    adres(a),
    nrTelefonu(nrTel)
{
    // Przypisujemy login i hasło do pól odziedziczonych po klasie Gosc
    this->login = l;
    this->haslo = h;
}

string Klient::getLogin() const {
    return login; // Zwraca pole odziedziczone po Gosc
}

bool Klient::sprawdzHaslo(const string& h) const {
    return haslo == h; // Sprawdza pole odziedziczone po Gosc
}

void Klient::zalogujSie() {
    cout << "klient " << login << " zalogowany" << endl;
}

void Klient::wylogujSie() {
    cout << "klient " << login << " wylogowany" << endl;
}

void Klient::przejdzDoKoszyka() {
    cout << "przechodzenie do koszyka..." << endl;
}

void Klient::przejdzDoZamowienia() {
    cout << "przechodzenie do zamowienia..." << endl;
}

// Implementacja wzorca Obserwator
void Klient::aktualizuj(const string& promocja) {
    cout << "promocja dla: "
        << login << ": "
        << promocja << endl;
}