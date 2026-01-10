#ifndef KLIENT_H
#define KLIENT_H

#include <string>
#include "Gosc.h"
#include "IObserwatorPromocji.h"

class Klient : public Gosc, public IObserwatorPromocji {
private:
    std::string login;
    std::string haslo;
    std::string email;
    std::string imie;
    std::string nazwisko;
    std::string adres;
    int nrTelefonu;

public:
    //destruktor (dziedziczenie)
    ~Klient() noexcept override = default;

    //konstruktor
    Klient(const std::string& l,
           const std::string& h,
           const std::string& e,
           const std::string& i,
           const std::string& n,
           const std::string& a,
           int nrTel);

    //logowanie
    std::string getLogin() const;
    bool sprawdzHaslo(const std::string& h) const;

    //akcje klienta
    void zalogujSie();
    void wylogujSie();
    void przejdzDoKoszyka();
    void przejdzDoZamowienia();

    //obserwator promocji (Observer pattern)
    void aktualizuj(const std::string& promocja) override;
};

#endif


