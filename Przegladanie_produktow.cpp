#include "Przegladanie_produktow.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;



void Przegladanie_produktow::wyswietlWszystkie() {
    ifstream plik("produkty.txt");
    if (!plik) {
        cout << "Obecnie brak produktow w sklepie.\n";
        return;
    }

    string linia;
    cout << "\n--- LISTA PRODUKTOW ---\n";
    cout << "Nazwa\t\tCena\tIlosc\n";
    cout << "------------------------------------\n";

    while (getline(plik, linia)) {
        if (linia.empty()) continue;
        stringstream ss(linia);
        string nazwa, cena, ilosc;

        getline(ss, nazwa, ';');
        getline(ss, cena, ';');
        getline(ss, ilosc, ';');
        cout << nazwa << "\t\t" << cena << " zl\t" << ilosc << " szt.\n";
    }
    plik.close();
}

void Przegladanie_produktow::wyszukajProdukt() {
    string szukanaNazwa;
    cout << "Podaj nazwe produktu do sprawdzenia: ";
    cin.ignore(1000, '\n');
    getline(cin, szukanaNazwa);

    ifstream plik("produkty.txt");
    if (!plik) {
        cout << "Blad: Nie mozna otworzyc bazy produktow." << endl;
        return;
    }

    string linia;
    bool znaleziono = false;

    while (getline(plik, linia)) {
        if (linia.empty()) continue;
        stringstream ss(linia);
        string nazwa, cena, iloscStr;

        getline(ss, nazwa, ';');
        getline(ss, cena, ';');
        getline(ss, iloscStr, ';');

        if (nazwa == szukanaNazwa) {
            znaleziono = true;
            int ilosc = 0;
            try {
                ilosc = stoi(iloscStr);
            }
            catch (...) { ilosc = 0; }

            if (ilosc > 0) {
                cout << "Tak, produkt jest dostepny! Cena: " << cena << " zl. (Dostepna ilosc: " << ilosc << ")\n" << endl;
            }
            else {
                cout << "Produkt jest w naszej bazie, ale obecnie jest NIEDOSTEPNY (brak na magazynie).\n" << endl;
            }
			
        }

    }

    if (!znaleziono) {
        cout << "Nie, przykro nam, obecnie nie mamy takiego produktu w ofercie." << endl;
    }
    plik.close();
}



//void Przeglądanie_produktów::dodajDoKoszyka() {

// throw "Not yet implemented";

//}



//void Przeglądanie_produktów::przejdzDoKoszyka() {

// throw "Not yet implemented";

//}