#include "SystemLogowania.h"
#include "Klient.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

//menu glowne
Klient* SystemLogowania::menu() {
    int wybor;

    cout << "1 - rejestracja\n";
    cout << "2 - logowanie\n";
    cout << "wybor: ";
    cin >> wybor;

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









//rejestracja

void SystemLogowania::rejestracja() {
    string login, haslo, email, imie, nazwisko, adres;
    int telefon;

    cout << "login: ";
    cin >> login;

    cout << "haslo: ";
    cin >> haslo;

    cout << "email: ";
    cin >> email;

    cout << "imie: ";
    cin >> imie;

    cout << "nazwisko: ";
    cin >> nazwisko;

    cout << "adres: ";
    cin >> adres;

    cout << "telefon: ";
    cin >> telefon;

    ofstream plik("klienci.txt", ios::app);

    if (!plik) {
        cout << "blad otwarcia pliku\n";
        return;
    }

    plik << login << ";"
         << haslo << ";"
         << email << ";"
         << imie << ";"
         << nazwisko << ";"
         << adres << ";"
         << telefon << endl;

    plik.close();

    cout << "rejestracja zakonczona\n";
}











//logowanie

Klient* SystemLogowania::logowanie() {
    string login, haslo;

    cout << "login: ";
    cin >> login;

    cout << "haslo: ";
    cin >> haslo;

    ifstream plik("klienci.txt");

    if (!plik) {
        cout << "brak pliku z klientami\n";
        return nullptr;
    }

    string linia;

    while (getline(plik, linia)) {
        Klient* k = nullptr;
        Klient tmp("", "", "", "", "", "", 0);

        if (sprawdzWLinii(linia, login, haslo, tmp)) {
            cout << "logowanie poprawne\n";
            plik.close();
            return new Klient(tmp); //zwraca zalogowanego klienta
        }
    }

    plik.close();
    cout << "bledny login lub haslo\n";
    return nullptr;
}


//sprawdzenie z ploku txt

bool SystemLogowania::sprawdzWLinii(const string& linia,
                                   const string& login,
                                   const string& haslo,
                                   Klient& klientOut) {
    string l, h, e, i, n, a, t;
    stringstream ss(linia);

    getline(ss, l, ';');
    getline(ss, h, ';');
    getline(ss, e, ';');
    getline(ss, i, ';');
    getline(ss, n, ';');
    getline(ss, a, ';');
    getline(ss, t, ';');

    if (l == login && h == haslo) {
        klientOut = Klient(l, h, e, i, n, a, stoi(t));
        return true;
    }

    return false;
}













// #include <exception>
// #include <string>
// using namespace std;

// #include "SystemLogowania.h"
// #include "Klient.h"

// void SystemLogowania::sprawdzPoprawnosc() {
// 	throw "Not yet implemented";
// }

// void SystemLogowania::przejdzDoKonta() {
// 	throw "Not yet implemented";
// }

// void SystemLogowania::zatwierdzKonto() {
// 	throw "Not yet implemented";
// }

// void SystemLogowania::autoryzacja() {
// 	throw "Not yet implemented";
// }



