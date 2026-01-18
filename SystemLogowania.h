#ifndef SYSTEMLOGOWANIA_H
#define SYSTEMLOGOWANIA_H

#include <string>


class Klient; // Informujemy, że klasa Klient istnieje

class SystemLogowania {
public:
    // menu glowne: rejestracja lub logowanie
    Klient* menu();

private:
    // rejestracja nowego klienta (zapis do pliku)
    void rejestracja();

    // logowanie istniejacego klienta (odczyt z pliku)
    Klient* logowanie();

    // sprawdzenie danych w pliku
    bool sprawdzWLinii(const std::string& linia,
        const std::string& login,
        const std::string& haslo,
        Klient& klientOut);
    bool czyIstniejeTakiLogin(const std::string& login);
    // Weryfikacja unikalności adresu e-mail
    bool czyIstniejeTakiEmail(const std::string& email);
};

// --- Zakomentowane struktury z Visual Paradigm ---
/*
class StstemLogowania_Paradigm {
    private: std::string _dane;
    private: std::string _haslo;
    public: Klient* _unnamed_Klient_;

    public: void sprawdzPoprawnosc();
    public: void przejdzDoKonta();
    public: void zatwierdzKonto();
    public: void autoryzacja();
};
*/

#endif