#ifndef KLIENT_H
#define KLIENT_H

#include <string>
#include "Gosc.h"
#include "IObserwatorPromocji.h"

// Klient dziedziczy po Gosc, a Gosc już dziedziczy po IObserwatorPromocji.
// Dlatego wystarczy: class Klient : public Gosc
class Klient : public Gosc {
private:
    // std::string login;  // Zakomentowane: Klient dziedziczy login z klasy Gosc
    // std::string haslo;  // Zakomentowane: Klient dziedziczy haslo z klasy Gosc
    std::string email;
    std::string imie;
    std::string nazwisko;
    std::string adres;
    int nrTelefonu;

public:
    // destruktor
    ~Klient() noexcept override = default;

    // konstruktor
    Klient(const std::string& l,
        const std::string& h,
        const std::string& e,
        const std::string& i,
        const std::string& n,
        const std::string& a,
        int nrTel);

    // metody dostępu
    std::string getLogin() const;
    bool sprawdzHaslo(const std::string& h) const;

    // akcje klienta
    void zalogujSie();
    void wylogujSie();
    void przejdzDoKoszyka();
    void przejdzDoZamowienia();

    // Nadpisanie metody z interfejsu (poprzez Gosc)
    void aktualizuj(const std::string& promocja) override;
};

#endif