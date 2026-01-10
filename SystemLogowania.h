#ifndef SYSTEMLOGOWANIA_H
#define SYSTEMLOGOWANIA_H

#include <string>

class Klient;

class SystemLogowania {
public:
    //menu glowne: rejestracja lub logowanie
    Klient* menu();

private:
    //rejestracja nowego klienta (zapis do pliku)
    void rejestracja();

    //logowanie istniejacego klienta (odczyt z pliku)
    Klient* logowanie();

    //sprawdzenie danych w pliku
    bool sprawdzWLinii(const std::string& linia,
                       const std::string& login,
                       const std::string& haslo,
                       Klient& klientOut);
};

#endif










// #include <exception>
// #include <string>
// using namespace std;

// #ifndef __SystemLogowania_h__
// #define __SystemLogowania_h__

// // #include "Klient.h"

// class Klient;
// class SystemLogowania;

// class SystemLogowania
// {
// 	private: string _dane;
// 	private: string _haslo;
// 	public: Klient* _unnamed_Klient_;

// 	public: void sprawdzPoprawnosc();

// 	public: void przejdzDoKonta();

// 	public: void zatwierdzKonto();

// 	public: void autoryzacja();
// };

// #endif


