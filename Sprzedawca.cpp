#include "Sprzedawca.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
//#include "Magazyn.h"
//#include "Promocje.h"
//

Sprzedawca::Sprzedawca(string l, string h, string e, int kod)
    : login(l), haslo(h), email(e), kodWeryfikacyjny(kod) {}

string Sprzedawca::getLogin() const { 
    return login; 
}

bool Sprzedawca::sprawdzHaslo(const string& h) const { 
    return haslo == h; }

void Sprzedawca::dodawanieProduktow() {
    char decyzja;
    do {
        string nazwa;
        double cena;
        int ilosc;

        cout << "\n--- DODAWANIE NOWEGO PRODUKTU ---" << endl;
        cout << "Nazwa produktu: ";
        cin.ignore(1000, '\n'); // Skuteczniejsze czyszczenie bufora
        getline(cin, nazwa);

        cout << "Cena: ";
        while (!(cin >> cena)) {
            cout << "Blad! Podaj poprawna liczbe dla ceny: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        cout << "Ilosc na magazynie: ";
        while (!(cin >> ilosc)) {
            cout << "Blad! Podaj poprawna liczbe dla ilosci: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        // Zapis do pliku
        ofstream plik("produkty.txt", ios::app);
        if (plik) {
            plik << nazwa << ";" << cena << ";" << ilosc << ";" << endl;
            plik.close();
            cout << "Produkt dodany pomyslnie!" << endl;
        }
        else {
            cout << "Blad otwarcia pliku produkty.txt!" << endl;
        }

        // PYTANIE O KONTYNUACJE
        cout << "\nCzy chcesz dodac kolejny produkt? (t/n): ";
        cin >> decyzja;

    } while (decyzja == 't' || decyzja == 'T');

    cout << "Zakonczono dodawanie produktow. Powrot do menu...\n";
}

void Sprzedawca::usuwanieProduktow() {
    ifstream plikOryginalny("produkty.txt");
    if (!plikOryginalny) {
        cout << "Blad: Nie mozna otworzyc pliku produkty.txt lub plik nie istnieje." << endl;
        return;
    }

    // 1. Wyswietlenie listy produktów, aby sprzedawca wiedzial co usuwa
    cout << "\n--- LISTA PRODUKTOW DO USUNIECIA ---" << endl;
    string linia;
    int licznik = 1;
    while (getline(plikOryginalny, linia)) {
        if (linia.empty()) continue;
        cout << licznik << ". " << linia << endl;
        licznik++;
    }

    if (licznik == 1) {
        cout << "Brak produktow na liscie." << endl;
        plikOryginalny.close();
        return;
    }

    // 2. Wybor produktu
    int numerDoUsuniecia;
    cout << "\nPodaj numer produktu do usuniecia (0 aby anulowac): ";
    if (!(cin >> numerDoUsuniecia) || numerDoUsuniecia == 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        plikOryginalny.close();
        return;
    }

    // 3. Przepisanie pliku z pominieciem wybranej linii
    plikOryginalny.clear(); // Powrot na poczatek pliku
    plikOryginalny.seekg(0);

    ofstream plikTymczasowy("temp.txt");
    int aktualnyNumer = 1;
    bool usunieto = false;

    while (getline(plikOryginalny, linia)) {
        if (linia.empty()) continue;
        if (aktualnyNumer != numerDoUsuniecia) {
            plikTymczasowy << linia << endl;
        }
        else {
            usunieto = true;
        }
        aktualnyNumer++;
    }

    plikOryginalny.close();
    plikTymczasowy.close();

    // 4. Zamiana plikow
    if (usunieto) {
        remove("produkty.txt");        // Usuwa stary plik
        rename("temp.txt", "produkty.txt"); // Zmienia nazwe tymczasowego na oryginalna
        cout << "Produkt zostal pomyslnie usuniety!" << endl;
    }
    else {
        remove("temp.txt");
        cout << "Nie znaleziono produktu o takim numerze." << endl;
    }
}

void Sprzedawca::zarzadzanieProduktami() {
    ifstream plikIn("produkty.txt");
    if (!plikIn) return;

    cout << "\n--- ZARZADZANIE ILOSCIA (MAGAZYN) ---" << endl;
    string linia;
    int licznik = 1;
    while (getline(plikIn, linia)) {
        if (!linia.empty()) cout << licznik++ << ". " << linia << endl;
    }
    plikIn.close();

    int numer;
    cout << "Wybierz produkt: ";
    cin >> numer;
    if (numer <= 0) return;

    int zmiana;
    cout << "O ile zmienic ilosc? (np. 5 aby dodac, -3 aby zmniejszyc): ";
    cin >> zmiana;

    plikIn.open("produkty.txt");
    ofstream plikOut("temp.txt");
    int aktualny = 1;

    while (getline(plikIn, linia)) {
        if (aktualny == numer) {
            stringstream ss(linia);
            string nazwa, cenaS, iloscS;
            getline(ss, nazwa, ';');
            getline(ss, cenaS, ';');
            getline(ss, iloscS, ';');

            int staraIlosc = stoi(iloscS);
            int nowaIlosc = staraIlosc + zmiana;
            if (nowaIlosc < 0) nowaIlosc = 0; // zabezpieczenie przed ujemnym stanem

            plikOut << nazwa << ";" << cenaS << ";" << nowaIlosc << ";" << endl;
        }
        else {
            plikOut << linia << endl;
        }
        aktualny++;
    }
    plikIn.close();
    plikOut.close();
    remove("produkty.txt");
    rename("temp.txt", "produkty.txt");
    cout << "Stan magazynowy zostal zaktualizowany." << endl;
}



void Sprzedawca::modyfikacjaCen() {
    ifstream plikIn("produkty.txt");
    if (!plikIn) return;

    cout << "\n--- MODYFIKACJA CEN ---" << endl;
    string linia;
    int licznik = 1;
    while (getline(plikIn, linia)) {
        if (!linia.empty()) cout << licznik++ << ". " << linia << endl;
    }
    plikIn.close();

    int numer;
    cout << "Wybierz numer produktu do zmiany ceny (0 - powrot): ";
    cin >> numer;
    if (numer <= 0) return;

    double nowaCena;
    cout << "Podaj nowa cene: ";
    cin >> nowaCena;

    plikIn.open("produkty.txt");
    ofstream plikOut("temp.txt");
    int aktualny = 1;

    while (getline(plikIn, linia)) {
        if (aktualny == numer) {
            stringstream ss(linia);
            string nazwa, cenaS, ilosc;
            getline(ss, nazwa, ';');
            getline(ss, cenaS, ';'); // pomijamy stara cene
            getline(ss, ilosc, ';');
            plikOut << nazwa << ";" << nowaCena << ";" << ilosc << ";" << endl;
        }
        else {
            plikOut << linia << endl;
        }
        aktualny++;
    }
    plikIn.close();
    plikOut.close();
    remove("produkty.txt");
    rename("temp.txt", "produkty.txt");
    cout << "Cena zostala zmieniona." << endl;
}

//void Sprzedawca::autoryzuj() {
//	throw "Not yet implemented";
//}
//
//void Sprzedawca::zarzadaniePromocjami() {
//	throw "Not yet implemented";
//}
