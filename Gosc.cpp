#include "Gosc.h"
#include <fstream>
#include <iostream>

using namespace std;

// konstruktor
Gosc::Gosc() : akceptacjaCookies(false) {}

// glowna metoda tworzenia konta
void Gosc::stworzKonto() {
    wybierzLogin();
    wybierzHaslo();

    ofstream plik("klienci.txt", ios::app);
    if (!plik) {
        cout << "Blad zapisu do pliku\n";
        return;
    }

    // zapis danych do pliku
    plik << login << ";" << haslo << ";" << endl;
    cout << "Konto utworzone poprawnie\n";
    plik.close();
}

void Gosc::wybierzHaslo() {
    cout << "Podaj haslo: ";
    cin >> haslo;
}

void Gosc::wybierzLogin() {
    string tmpLogin;
    cout << "Podaj login: ";
    cin >> tmpLogin;

    // sprawdzenie czy login juz istnieje
    if (czyIstniejeTakiLogin(tmpLogin)) {
        cout << "Login juz istnieje. Wybierz inny.\n";
        wybierzLogin();
    }
    else {
        login = tmpLogin;
    }
}

// sprawdzenie czy login znajduje sie w pliku klienci.txt
bool Gosc::czyIstniejeTakiLogin(const string& login) const {
    ifstream plik("klienci.txt");
    if (!plik) return false;

    string linia;
    while (getline(plik, linia)) {
        if (linia.find(login + ";") == 0) {
            return true;
        }
    }
    return false;
}

// metoda wywolywana po otrzymaniu promocji
void Gosc::aktualizuj(const string& promocja) {
    cout << "Gosc otrzymal promocje: " << promocja << endl;
}