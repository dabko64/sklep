#include <iostream>
#include "Zamowienie.h"

using namespace std;

int main() {
    cout << "--- TEST MODULU ZAMOWIENIE ---" << endl;

    // 1. Tworzymy zamowienie "na sztywno"
    cout << "Tworzenie obiektu..." << endl;
    Zamowienie* z = new Zamowienie("Tester", 250.00);

    // 2. Symulujemy proces
    z->wybierzMetodePlatnosci();  // Zapyta o platnosc
    z->utworzZamowienie();        // Powinien utworzyc plik txt
    z->przekazDoMagazynu();       // Zmieni status
    z->sprawdzStatus();           // Wyswietli status

    // 3. Sprzatanie
    delete z;
    
    cout << "\n--- TEST ZAKONCZONY SUKCESEM ---" << endl;
    return 0;
}