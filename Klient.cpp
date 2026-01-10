#include "Klient.h"
#include <iostream>

using namespace std;

//konstruktor
Klient::Klient(const string& l,
               const string& h,
               const string& e,
               const string& i,
               const string& n,
               const string& a,
               int nrTel)
    : login(l),
      haslo(h),
      email(e),
      imie(i),
      nazwisko(n),
      adres(a),
      nrTelefonu(nrTel) {}

string Klient::getLogin() const {
    return login;
}

bool Klient::sprawdzHaslo(const string& h) const {
    return haslo == h;
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

//Observer pattern
void Klient::aktualizuj(const string& promocja) {
    cout << "promocja dla: "
         << login << ": "
         << promocja << endl;
}



