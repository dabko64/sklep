#include "SystemLogowania.h"
#include "Klient.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// menu glowne
Klient* SystemLogowania::menu() {
    int wybor;
    cout << "1 - rejestracja\n";
    cout << "2 - logowanie\n";
    cout << "wybor: ";
    // Zabezpieczenie przed wpisaniem litery w menu
    if (!(cin >> wybor)) {
        cin.clear(); // czysci stan bledu
        cin.ignore(1000, '\n'); // usuwa bledne znaki
        cout << "Blad: Wpisz cyfre 1 lub 2!\n";
        return nullptr;
    }

    if (wybor == 1) {
        rejestracja();
        return nullptr;
    }

    if (wybor == 2) {
        return logowanie();
    }

    cout << "zly wybor\n";
    return nullptr;
}

// Metoda sprawdzająca czy login już istnieje w pliku
bool SystemLogowania::czyIstniejeTakiLogin(const string& login) {
    ifstream plik("klienci.txt");
    if (!plik) return false;
    string linia;
    while (getline(plik, linia)) {
        if (linia.empty()) continue;
        stringstream ss(linia);
        string l;
        getline(ss, l, ';'); // Pobieramy tylko pierwszy człon (login)
        if (l == login) return true;
    }
    return false;
}

bool SystemLogowania::czyIstniejeTakiEmail(const string& email) {
    ifstream plik("klienci.txt");
    if (!plik) return false;
    string linia;
    while (getline(plik, linia)) {
        if (linia.empty()) continue;
        stringstream ss(linia);
        string l, h, e;
        getline(ss, l, ';'); // pomiń login
        getline(ss, h, ';'); // pomiń hasło
        getline(ss, e, ';'); // pobierz email
        if (e == email) return true;
    }
    return false;
}

// rejestracja
void SystemLogowania::rejestracja() {
    string login, haslo, email, imie, nazwisko, adres;

    cout << "login: "; cin >> login;
    if (czyIstniejeTakiLogin(login)) {
        cout << "BLAD: Ten login jest juz zajety! Rejestracja przerwana.\n";
        return;
    }
    cout << "email: "; cin >> email;
    if (czyIstniejeTakiEmail(email)) {
        cout << "BLAD: Na ten adres e-mail zostalo juz zalozone konto!\n";
        return;
    }

    cout << "haslo: "; cin >> haslo;
    cout << "imie: "; cin >> imie;
    cout << "nazwisko: "; cin >> nazwisko;
    cout << "adres: "; cin >> adres;

    string nrTelStr;
    int telefon = 0;
    bool poprawnyTel = false;

    while (!poprawnyTel) {
        cout << "telefon (9 cyfr): ";
        cin >> nrTelStr;

        // Sprawdzenie czy sa tylko cyfry
        bool tylkoCyfry = true;
        for (char c : nrTelStr) {
            if (!isdigit(c)) {
                tylkoCyfry = false;
                break;
            }
        }

        if (!tylkoCyfry) {
            cout << "BLAD: Numer telefonu musi zawierac tylko cyfry!\n";
            continue;
        }

        // Sprawdzenie dlugosci
        if (nrTelStr.length() < 9) {
            cout << "BLAD: Numer telefonu jest za krotki!\n";
        }
        else if (nrTelStr.length() > 9) {
            cout << "BLAD: Numer telefonu jest za dlugi!\n";
        }
        else {
            telefon = stoi(nrTelStr); // Konwersja na int
            poprawnyTel = true;
        }
    }

    ofstream plik("klienci.txt", ios::app);
    if (plik) {
        plik << login << ";" << haslo << ";" << email << ";"
            << imie << ";" << nazwisko << ";" << adres << ";" << telefon << endl;
        plik.close();
        cout << "Konto utworzone! Teraz mozesz sie zalogowac.\n";
    }
    // Zapisujemy wszystkie dane rozdzielone średnikami
  /*  plik << login << ";"
        << haslo << ";"
        << email << ";"
        << imie << ";"
        << nazwisko << ";"
        << adres << ";"
        << telefon << endl;

    plik.close();
    cout << "rejestracja zakonczona\n";*/
}

// logowanie
Klient* SystemLogowania::logowanie() {
    string login, haslo;
    cout << "login: "; cin >> login;
    cout << "haslo: "; cin >> haslo;

    ifstream plik("klienci.txt");
    if (!plik) {
        cout << "brak pliku z klientami\n";
        return nullptr;
    }

    string linia;
    while (getline(plik, linia)) {
        // Tworzymy tymczasowy obiekt Klienta z pustymi danymi
        Klient tmp("", "", "", "", "", "", 0);

        if (sprawdzWLinii(linia, login, haslo, tmp)) {
            cout << "logowanie poprawne\n";
            plik.close();
            // Tworzymy kopię na stercie, którą obsłuży main.cpp
            return new Klient(tmp);
        }
    }

    plik.close();
    cout << "bledny login lub haslo\n";
    return nullptr;
}



// sprawdzenie z pliku txt
bool SystemLogowania::sprawdzWLinii(const string& linia,
    const string& login,
    const string& haslo,
    Klient& klientOut) {

    if (linia.empty()) return false;
    stringstream ss(linia);
    string l, h, e, i, n, a, t;
    

    getline(ss, l, ';');
    getline(ss, h, ';');
    getline(ss, e, ';');
    getline(ss, i, ';');
    getline(ss, n, ';');
    getline(ss, a, ';');
    getline(ss, t, ';');

    if (l == login && h == haslo) {
        // Jeśli telefon w pliku nie jest liczbą, stoi może rzucić błąd
        int telNum = 0;
        try {
            if (!t.empty()) telNum = stoi(t);
        }
        catch (...) {};//telNum = 0; }

        klientOut = Klient(l, h, e, i, n, a, telNum);
        return true;
    }

    return false;
}

// --- Zakomentowane metody Paradigm ---
/*
void StstemLogowania::sprawdzPoprawnosc() { throw "Not yet implemented"; }
void StstemLogowania::przejdzDoKonta() { throw "Not yet implemented"; }
void StstemLogowania::zatwierdzKonto() { throw "Not yet implemented"; }
void StstemLogowania::autoryzacja() { throw "Not yet implemented"; }
*/