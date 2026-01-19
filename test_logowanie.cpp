#include <iostream>
#include <fstream>
#include <string>
#include "StstemLogowania.h"
#include "Klient.h"

using namespace std;

void test_logowania() {
    cout << "--- TEST JEDNOSTKOWY: LOGOWANIE ---" << endl;
    int zaliczone = 0;
    int wszystkie = 3;

    // 1. PRZYGOTOWANIE ŚRODOWISKA (Plik tymczasowy)
    ofstream plik("klienci.txt");
    plik << "jan123;haslo1;jan@wp.pl;Jan;Kowalski;Krakow;123456789" << endl;
    plik.close();

    StstemLogowania system;

    // SCENARIUSZ 1: Poprawne logowanie
    cout << "Test 1: Poprawne dane... ";
    // Musimy użyć metody sprawdzWLinii, bo logowanie() używa 'cin'
    Klient tmp("","","","","","",0);
    if (system.sprawdzWLinii("jan123;haslo1;jan@wp.pl;Jan;Kowalski;Krakow;123456789", "jan123", "haslo1", tmp)) {
        cout << "[PASS]" << endl;
        zaliczone++;
    } else {
        cout << "[FAIL]" << endl;
    }

    // SCENARIUSZ 2: Błędne hasło
    cout << "Test 2: Bledne haslo... ";
    if (!system.sprawdzWLinii("jan123;haslo1;jan@wp.pl;Jan;Kowalski;Krakow;123456789", "jan123", "zle_haslo", tmp)) {
        cout << "[PASS]" << endl;
        zaliczone++;
    } else {
        cout << "[FAIL]" << endl;
    }

    // SCENARIUSZ 3: Nieistniejący login
    cout << "Test 3: Nieistniejacy login... ";
    if (system.czyIstniejeTakiLogin("nie_ma_mnie") == false) {
        cout << "[PASS]" << endl;
        zaliczone++;
    } else {
        cout << "[FAIL]" << endl;
    }

    // 2. PODSUMOWANIE I RAPORTOWANIE
    cout << "\n------------------------------------" << endl;
    cout << "WYNIK: " << zaliczone << "/" << wszystkie << " testow zaliczonych." << endl;

    if (zaliczone == wszystkie) {
        cout << "STATUS: KOMPLETNY SUKCES" << endl;
    } else {
        cout << "STATUS: WYKRYTO BLEDY W LOGICE" << endl;
    }

    // Sprzątanie po teście
    remove("klienci.txt");
}

int main() {
    test_logowania();
    return 0;
}