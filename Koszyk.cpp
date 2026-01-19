#include "Koszyk.h"
#include <iomanip> // Potrzebne do std::setw i std::setprecision
#include "Produkt.h"
#include<iostream>

using namespace std;

// Konstruktor
Koszyk::Koszyk(Klient* wlasciciel) : _wlasciciel(wlasciciel) {
}



// Destruktor (jeśli produkty są dynamiczne i należą tylko do koszyka, tu trzeba je usunąć. 
// Zakładamy jednak, że Produkty istnieją w "Magazynie", a tu trzymamy tylko wskaźniki)
Koszyk::~Koszyk() {
    for (auto& pozycja : _pozycje) {
        // Usuwamy produkty, które koszyk sam sobie stworzył
        delete pozycja.produkt; 
    }
    _pozycje.clear();
}

void Koszyk::dodajProdukt(Produkt* wzorzecProduktu, int ilosc) {
    if (wzorzecProduktu == nullptr || ilosc <= 0) return;

    for (auto& pozycja : _pozycje) {
        // Porównujemy po nazwie
        if (pozycja.produkt->getNazwa() == wzorzecProduktu->getNazwa()) {
            pozycja.ilosc += ilosc;
            cout << ">> Zaktualizowano ilosc: " << wzorzecProduktu->getNazwa() << endl;
            return;
        }
    }

    Produkt* kopia = new Produkt(
        wzorzecProduktu->getNazwa(), 
        wzorzecProduktu->getCena(), 
        wzorzecProduktu->getIlosc()
    );

    Pozycja nowa;
    nowa.produkt = kopia; // Przypisujemy naszą bezpieczną kopię
    nowa.ilosc = ilosc;
    
    _pozycje.push_back(nowa);
    cout << ">> Dodano do koszyka: " << kopia->getNazwa() << endl;
}

void Koszyk::usunZKoszyka(string nazwaProduktu) {
    for (auto it = _pozycje.begin(); it != _pozycje.end(); ) {
        if (it->produkt->getNazwa() == nazwaProduktu) {
            
            delete it->produkt; 
            
            it = _pozycje.erase(it);
            cout << ">> Usunieto produkt: " << nazwaProduktu << endl;
            return;
        } else {
            ++it;
        }
    }
    cout << ">> Nie znaleziono produktu w koszyku." << endl;
}

void Koszyk::wyczysc() {
    _pozycje.clear();
    cout << ">> Koszyk zostal oprozniony." << endl;
}

double Koszyk::pobierzWartoscCalkowita() const {
    double suma = 0.0;
    for (const auto& poz : _pozycje) {
        // --- ZABEZPIECZENIE (DODAJ TO) ---
        if (poz.produkt != nullptr) {
            suma += (poz.produkt->getCena() * poz.ilosc);
        }
        // ---------------------------------
    }
    return suma;
}
bool Koszyk::czyPusty() const {
    return _pozycje.empty();
}

void Koszyk::wyswietlZawartosc() const {
    if (_pozycje.empty()) {
        cout << "\n[ KOSZYK ] Twoj koszyk jest pusty.\n";
        return;
    }

    cout << "\n================== TWOJ KOSZYK ==================\n";
    cout << left << setw(20) << "Nazwa" 
         << right << setw(10) << "Cena" 
         << right << setw(10) << "Ilosc" 
         << right << setw(12) << "Wartosc" << endl;
    cout << "-----------------------------------------------------\n";

    for (const auto& poz : _pozycje) {
        if (poz.produkt == nullptr) {
            cout << ">> BLAD: Znaleziono pusty wpis w koszyku (pomijam).\n";
            continue; // Przejdź do następnego elementu pętli
        }
        double wartoscPozycji = poz.produkt->getCena() * poz.ilosc;
        
        cout << left << setw(20) << poz.produkt->getNazwa()
             << right << setw(7) << fixed << setprecision(2) << poz.produkt->getCena() << " zl"
             << right << setw(8) << poz.ilosc << " szt"
             << right << setw(9) << fixed << setprecision(2) << wartoscPozycji << " zl" << endl;
    }
    cout << "-----------------------------------------------------\n";
    cout << right << setw(40) << "RAZEM DO ZAPLATY: " 
         << setw(9) << pobierzWartoscCalkowita() << " zl" << endl;
    cout << "=====================================================\n";
}