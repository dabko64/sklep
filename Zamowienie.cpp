#include <iostream>
#include <exception>
#include <string>
#include <vector>
using namespace std;

#include "Zamowienie.h"
#include "Koszyk.h"
#include "Zloz_zamowienie.h"
#include "Magazyn.h"

Zamowienie::Zamowienie(string login, double kwota) {
    _loginKlienta = login;
    _kwota = kwota;
    _dataZlozenia = "2026-01-18"; // Możesz wpisać na sztywno dla uproszczenia
    _status = "Nowe";
    _idZamowienia = 101; // Przykładowe ID
}

void Zamowienie::utworzZamowienie() {
	cout << "\n--- FINALIZACJA ZAMOWIENIA ---\n";
    cout << "Klient: " << _loginKlienta << endl;
    cout << "Kwota: " << _kwota << " zl" << endl;

    // Zapisujemy do pliku tak jak w SystemLogowania.cpp
    ofstream plik("zamowienia.txt", ios::app);
    if (plik) {
        plik << _loginKlienta << ";" << _kwota << ";" << _dataZlozenia << ";" << _status << endl;
        plik.close();
        cout << "Zamowienie zapisano poprawnie w pliku.\n";
    }
}

void Zamowienie::zmienStatus() {
	throw "Not yet implemented";
}

void Zamowienie::przekazDoMagazynu() {
	cout << "Zamowienie nr " << _idZamowienia << " przekazano do pakowania.\n";
}

void Zamowienie::sprawdzStatus() {
	_status = "Wyslane";
    cout << "Zmieniono status na: " << _status << endl;
}

void Zamowienie::wybierzMetodePlatnosci() {
	int m;
    cout << "Wybierz platnosc: 1-Karta, 2-Blik: ";
    cin >> m;
    cout << "Wybrano metode nr: " << m << ". Autoryzacja pomyslna!\n";
}

