#include <iostream>
#include <vector>
#include <stdexcept>
#include "Koszyk.h"
#include "Klient.h"
#include "Produkt.h"

using namespace std;

// Prosta funkcja pomocnicza do wyświetlania wyniku testu
void assertTest(bool condition, string testName) {
    if (condition) {
        cout << "[OK] " << testName << endl;
    } else {
        cout << "[BLAD] " << testName << " - warunek nie spelniony!" << endl;
    }
}

int main() {
    cout << "--- ROZPOCZYNAM TESTOWANIE KOSZYKA ---\n" << endl;

    // 1. Przygotowanie danych (Symulacja Klienta i Produktów)
    // UWAGA: Tworzymy obiekty dynamicznie (new), bo Koszyk operuje na wskaźnikach
    Klient* klientTestowy = new Klient("Tester", "test", "test", "Jan", "Kowalski", "Adres 1", "123");
    
    // Zakładam, że konstruktor produktu to (id, nazwa, kategoria, cena) lub podobnie.
    // Dostosuj te linijki do tego, jak wygląda konstruktor w Produkt.h!
    Produkt* chleb = new Produkt(1, "Chleb", "Pieczywo", 5.00);
    Produkt* maslo = new Produkt(2, "Maslo", "Nabial", 8.50);

    // 2. Test tworzenia koszyka
    Koszyk* koszyk = nullptr;
    try {
        koszyk = new Koszyk(klientTestowy);
        assertTest(koszyk != nullptr, "Tworzenie koszyka dla klienta");
    } catch (...) {
        cout << "[BLAD] Wyjatek przy tworzeniu koszyka!" << endl;
        return -1;
    }

    // 3. Test pustego koszyka
    assertTest(koszyk->ilePozycji() == 0, "Nowy koszyk jest pusty");

    // 4. Test dodawania produktow
    try {
        koszyk->dodajProdukt(chleb, 2); // 2 chleby
        koszyk->dodajProdukt(maslo, 1); // 1 masło
        
        assertTest(koszyk->ilePozycji() == 2, "Dodano dwa rozne produkty");
        
        // Dodajemy ten sam produkt ponownie (powinna zwiększyć się ilość, a nie liczba pozycji)
        koszyk->dodajProdukt(chleb, 3); // +3 chleby (razem 5)
        
        assertTest(koszyk->ilePozycji() == 2, "Liczba pozycji bez zmian po dodaniu tego samego produktu");
        
        // UWAGA: Żeby sprawdzić ilość, musielibyśmy mieć metodę w Koszyku np. pobierzIlosc(Produkt*).
        // Skoro jej nie ma, ufamy metodzie ilePozycji().
    } catch (const exception& e) {
        cout << "[BLAD] Wyjatek podczas dodawania: " << e.what() << endl;
    }

    // 5. Test usuwania produktow
    try {
        koszyk->usunZKoszyka(chleb, 4); // Mieliśmy 5, usuwamy 4 -> zostaje 1
        assertTest(koszyk->ilePozycji() == 2, "Po czesciowym usunieciu nadal sa 2 pozycje");
        
        koszyk->usunZKoszyka(maslo, 1); // Mieliśmy 1, usuwamy 1 -> znika z listy
        assertTest(koszyk->ilePozycji() == 1, "Po calkowitym usunieciu masla zostala 1 pozycja");

        koszyk->usunZKoszyka(chleb, 1); // Usuwamy ostatni chleb -> koszyk pusty
        assertTest(koszyk->ilePozycji() == 0, "Po usunieciu reszty chleba koszyk jest pusty");

    } catch (const exception& e) {
        cout << "[BLAD] Wyjatek podczas usuwania: " << e.what() << endl;
    }

    // 6. Test czyszczenia
    koszyk->dodajProdukt(maslo, 5);
    koszyk->wyczysc();
    assertTest(koszyk->ilePozycji() == 0, "Metoda wyczysc() dziala poprawnie");

    // 7. Testy negatywne (Obsługa błędów)
    cout << "\n--- Testy odpornosci na bledy ---\n";
    
    try {
        koszyk->dodajProdukt(nullptr, 1);
        cout << "[BLAD] Nie zlapano bledu dodania nullptr!" << endl;
    } catch (const std::invalid_argument& e) {
        assertTest(true, "Poprawnie zablokowano dodanie nullptr");
    }

    try {
        koszyk->dodajProdukt(chleb, -5);
        cout << "[BLAD] Nie zlapano bledu ujemnej ilosci!" << endl;
    } catch (const std::invalid_argument& e) {
        assertTest(true, "Poprawnie zablokowano ujemna ilosc");
    }

    // Sprzątanie pamięci
    delete koszyk;
    delete chleb;
    delete maslo;
    delete klientTestowy; // W C++ usuwamy wskaźniki ręcznie

    cout << "\n--- KONIEC TESTU ---" << endl;
    return 0;
}