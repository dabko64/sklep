#include <iostream>
#include <exception>
#include <string>
#include <fstream>
using namespace std;

#include "Zamowienie.h"
#include "Koszyk.h"
//#include "Zloz_zamowienie.h"
#include "Magazyn.h"

Zamowienie::Zamowienie(string login, double kwota) {
    _loginKlienta = login;
    _kwota = kwota;
    _dataZlozenia = "2026-01-18";
    _status = "Nowe";
    _idZamowienia = 101; // Przykładowe ID
}

void Zamowienie::utworzZamowienie() {
	cout << "\n--- FINALIZACJA ZAMOWIENIA ---\n";
    cout << "Klient: " << _loginKlienta << endl;
    cout << "Kwota: " << _kwota << " zl" << endl;

    // Zapisujemy do pliku
    ofstream plik("zamowienia.txt", ios::app);
    if (plik) {
        plik << _loginKlienta << ";" << _kwota << ";" << _dataZlozenia << ";" << _status << endl;
        plik.close();
        cout << "Zamowienie zapisano poprawnie w pliku.\n";
    }
    else{
        cout << "[Blad] Nie udalo sie otworzyc pliku do zapisu!\n";
    }
}

void Zamowienie::zmienStatus() {
	if (_status == "Nowe") {
        _status = "W trakcie realizacji";
    } else if (_status == "W trakcie realizacji") {
        _status = "Wyslane";
    } else {
        _status = "Zakonczone";
    }
    cout << "[Status] Zmieniono status zamowienia na: " << _status << endl;
}

void Zamowienie::przekazDoMagazynu() {
	cout << "Zamowienie nr " << _idZamowienia << " przekazano do pakowania.\n";
    zmienStatus();
}

void Zamowienie::sprawdzStatus() {
	cout << "Aktualny status: " << _status << endl;
}

void Zamowienie::wybierzMetodePlatnosci() {
	int m;
    cout << "\n--- PLATNOSC ---\n";
    cout << "Wybierz platnosc: 1-Karta, 2-Blik, 3-Gotowka przy odbiorze: ";
    if (cin >> m) {
        cout << "Wybrano metode nr: " << m << ". Platnosc przyjeta.\n";
        _status = "Oplacone"; // Ręczna zmiana statusu
    } else {
        cout << "Niepoprawny wybor.\n";
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

