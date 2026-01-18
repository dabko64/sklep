#include "SystemLogowania.h"
#include "Klient.h"
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
    
    // Na koniec sprzątamy pamięć!
    delete aktualnyUzytkownik;
    
    return 0;
}