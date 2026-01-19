#include "SystemLogowania.h"
#include "Klient.h"
#include "Zamowienie.h"
#include <iostream>
using namespace std;

int main() {
    SystemLogowania system;
    Klient* aktualnyUzytkownik = nullptr;

    cout << "--- WITAJ W SKLEPIE ---" <<endl;

    // Pętla logowania/rejestracji
    while (aktualnyUzytkownik == nullptr) {
        aktualnyUzytkownik = system.menu();
    }

    // Tutaj użytkownik jest już zalogowany
    aktualnyUzytkownik->zalogujSie();
    
    // Teraz możesz wywoływać metody Klienta
    aktualnyUzytkownik->przejdzDoKoszyka();

    //-------------------------------------------------
    char decyzja;
    cout << "\nCzy chcesz sfinalizowac zakupy i zlozyc zamowienie? (t/n): ";
    cin >> decyzja;

    if (decyzja == 't' || decyzja == 'T') {
        // Ponieważ nie wiem, jak wyciągnąć sumę z Koszyka (nie widzę kodu koleżanek),

     
        double kwotaDoZaplaty = 150.99; // <--- Tutaj wpisz np. aktualnyUzytkownik->pobierzSumeKoszyka() jeśli istnieje
        
        // Tworzymy obiekt Twojej klasy Zamowienie
        // Jako login podajemy "Klient" lub jeśli klasa Klient ma getLogin(), to użyj tego.
        Zamowienie* noweZamowienie = new Zamowienie("ObecnyKlient", kwotaDoZaplaty);

        // Wywołujemy Twoje metody po kolei
        noweZamowienie->wybierzMetodePlatnosci();
        noweZamowienie->utworzZamowienie();      // To zapisze plik txt
        noweZamowienie->przekazDoMagazynu();     // To zmieni status
        noweZamowienie->sprawdzStatus();         // Potwierdzenie na koniec

        cout << "\nDZIEKUJEMY ZA ZAKUPY!\n";
        
        // Sprzątamy pamięć po zamówieniu
        delete noweZamowienie;
    } else {
        cout << "Zapraszamy ponownie!\n";
    }
    //-------------------------------------------------
    
    // Na koniec sprzątamy pamięć!
    delete aktualnyUzytkownik;
    
    return 0;
}