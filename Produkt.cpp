#include "Produkt.h"
#include <iostream>

using namespace std;

// Implementacja konstruktora
Produkt::Produkt(string nazwa, double cena, int ilosc) 
    : _nazwa(nazwa), _cena(cena), _iloscWMagazynie(ilosc) 
{
    // Lista inicjalizacyjna powyżej przypisuje wartości do zmiennych prywatnych
}

// Implementacja getterów
string Produkt::getNazwa() const {
    return _nazwa;
}

double Produkt::getCena() const {
    return _cena;
}

int Produkt::getIlosc() const {
    return _iloscWMagazynie;
}

// Implementacja metody zmieniającej stan magazynowy
void Produkt::zmniejszStan(int ile) {
    if (ile > 0 && _iloscWMagazynie >= ile) {
        _iloscWMagazynie -= ile;
    } else {
        // Opcjonalnie: obsługa błędu, jeśli próbujemy odjąć więcej niż mamy
        // cerr << "Blad: Nie mozna zmniejszyc stanu o " << ile << endl;
    }
}