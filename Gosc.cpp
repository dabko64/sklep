#include <exception>
using namespace std;

#include "Gosc.h"
#include "Koszyk.h"
#include "Promocje.h"
#include "IObserwatorPromocji.h"

#include <fstream>

// konstruktor – ustawia wartosci poczatkowe
Gosc::Gosc()
    : akceptacjaCookies(false) {}

	// glowna metoda tworzenia konta
void Gosc::stworzKonto() {
	wybierzLogin();
    wybierzHaslo();
 // otwarcie pliku do zapisu (dopisywanie)
    ofstream plik("klienci.txt", ios::app);
    if (!plik) {
        cout << "Blad zapisu do pliku\n";
        return;
    }
  // zapis danych do pliku
    plik << login << ";" << haslo << endl;
    cout << "Konto utworzone poprawnie\n";
}
// metoda pobiera haslo od uzytkownika
void Gosc::wybierzHaslo() {
	cout << "Podaj haslo: ";
    cin >> haslo;
}
// metoda pobiera login od uzytkownika
void Gosc::wybierzLogin() {
	cout << "Podaj login: ";
    cin >> login;
// sprawdzenie czy login juz istnieje
    if (czyIstniejeTakiLogin(login)) {
        cout << "Login juz istnieje. Wybierz inny.\n";
        wybierzLogin(); // ponowne wpisanie loginu
    }
}

// sprawdzenie czy login znajduje sie w pliku klienci.txt
bool Gosc::czyIstniejeTakiLogin(const string& login) const {
	ifstream plik("klienci.txt");
    if (!plik) return false;// jezeli plik nie istnieje, login na pewno jest wolny
    string linia;
	// czytanie pliku linia po linii
    while (getline(plik, linia)) {
		// sprawdzamy czy linia zaczyna sie od "login;"
        if (linia.find(login + ";") == 0) {
            return true;
        }
    }
    return false;
}
// metoda wywolywana po otrzymaniu promocji
void Gosc::aktualizuj(Promocje aPromocja) {
	  cout << "Gosc otrzymal promocje: " << aPromocja << endl;
}


