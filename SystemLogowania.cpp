#include "SystemLogowania.h"
#include "Klient.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Sprzedawca.h"
#include "Przegladanie_produktow.h"

using namespace std;

// menu glowne
Klient* SystemLogowania::menu() {
    int wybor;
    cout << "1 - rejestracja\n";
    cout << "2 - logowanie (klient)\n";
    cout << "3 - logowanie (sprzedawca)\n"; // NOWA OPCJA
    cout << "4 - przegladaj bez logowania (gosc)\n";
    cout << "wybor: ";
    // Zabezpieczenie przed wpisaniem litery w menu
    if (!(cin >> wybor)) {
        cin.clear(); // czysci stan bledu
        cin.ignore(1000, '\n'); // usuwa bledne znaki
        cout << "Blad: Wpisz cyfre 1, 2 lub 3!\n";
        return nullptr;
    }

    if (wybor == 1) {
        rejestracja();
        return nullptr;
    }

    if (wybor == 2) {
        return logowanie();// zwraca Klient*
    }

    if (wybor == 3) {
        Sprzedawca* s = logowanieSprzedawcy(); // Wywołuje nową metodę
        if (s) {
            int opcjaS = 0;
            while (opcjaS != 5) { // Petla menu sprzedawcy
                cout << "\n--- PANEL ZARZADZANIA ---" << endl;
                cout << "1 - Dodaj produkt" << endl;
                cout << "2 - Usun produkt" << endl;
                cout << "3 - Zmien cene" << endl;       // NOWE
                cout << "4 - Zmien ilosc (magazyn)" << endl; // NOWE
                cout << "5 - Wyloguj" << endl;
                cout << "Wybor: ";

                if (!(cin >> opcjaS)) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }

                if (opcjaS == 1) {
                    s->dodawanieProduktow();
                }
                else if (opcjaS == 2) {
                    s->usuwanieProduktow();
                }
                else if (opcjaS == 3) {
                    s->modyfikacjaCen();
                }
                else if (opcjaS == 4) {
                    s->zarzadzanieProduktami();
                }
                else if (opcjaS == 5 ) {
                    cout << "Wylogowywanie..." << endl;
                }
                else {
                    cout << "Niepoprawna opcja!" << endl;
                }
            }
            delete s; // Sprzatanie pamieci po wylogowaniu
        }
        return nullptr; // Powrot do glownego menu (1-rejestracja, 2-logowanie...)
    }
	if (wybor == 4) {
		Przegladanie_produktow przegladanie;
        int akcja = 0; // Zmieniona nazwa, żeby nie było konfliktu
        cout << "\n--- TRYB GOSCIA ---\n";
        cout << "1 - Wyswietl wszystko, 2 - Szukaj produktu: ";

        if (!(cin >> akcja)) {
            cin.clear();
            cin.ignore(1000, '\n');
            return nullptr;
        }

        if (akcja == 1) {
            przegladanie.wyswietlWszystkie();
        }
        else if (akcja == 2) {
            przegladanie.wyszukajProdukt();
        }
        return nullptr;
    }
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

Sprzedawca* SystemLogowania::logowanieSprzedawcy() {
    string login, haslo;
    cout << "--- LOGOWANIE SPRZEDAWCY ---\n";
    cout << "login: "; cin >> login;
    cout << "haslo: "; cin >> haslo;

    ifstream plik("sprzedawcy.txt");
    if (!plik) {
        cout << "Brak pliku sprzedawcy.txt\n";
        return nullptr;
    }

    string linia;
    while (getline(plik, linia)) {
        Sprzedawca tmp("", "", "", 0);
        if (sprawdzWLiniiSprzedawcy(linia, login, haslo, tmp)) {
            cout << "Zalogowano jako sprzedawca: " << tmp.getLogin() << endl;
            plik.close();
            return new Sprzedawca(tmp);
        }
    }
    plik.close();
    cout << "Bledny login lub haslo sprzedawcy!\n";
    return nullptr;
}

bool SystemLogowania::sprawdzWLiniiSprzedawcy(const string& linia, const string& login, const string& haslo, Sprzedawca& sprzedawcaOut) {
    if (linia.empty()) return false;
    stringstream ss(linia);
    string l, h, e, k;

    getline(ss, l, ';');
    getline(ss, h, ';');
    getline(ss, e, ';');
    getline(ss, k, ';');

    if (l == login && h == haslo) {
        int kod = 0;
        try { if (!k.empty()) kod = stoi(k); }
        catch (...) {}
        sprzedawcaOut = Sprzedawca(l, h, e, kod);
        return true;
    }
    return false;
}
// --- Zakomentowane metody Paradigm ---
/*
void SystemLogowania::sprawdzPoprawnosc() { throw "Not yet implemented"; }
void SystemLogowania::przejdzDoKonta() { throw "Not yet implemented"; }
void SystemLogowania::zatwierdzKonto() { throw "Not yet implemented"; }
void SystemLogowania::autoryzacja() { throw "Not yet implemented"; }
*/