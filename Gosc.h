
#ifndef __Gosc_h__
#define __Gosc_h__

#include <string>
#include <iostream>
#include "IObserwatorPromocji.h"
// prosty interfejs obserwatora (minimalny)
// class IObserwatorPromocji {
// public:
//     virtual ~IObserwatorPromocji() = default;
//     virtual void aktualizuj(const string& promocja) = 0;
// };
class Gosc : public IObserwatorPromocji {
protected: // Zmieniono z private na protected!
    bool akceptacjaCookies;
    std::string login;
    std::string haslo;

    // Poniższe linie zostawiam jako komentarz, bo C++ nie zna tych typów:
   /*
   private: int _idSesji;
   private: String _adresIP;
   private: String _zdrodloOdwiedzin;
   private: date _dataWejscia;
   */
public:
    Gosc();
    void stworzKonto();
    void wybierzHaslo();
    void wybierzLogin();
    bool czyIstniejeTakiLogin(const std::string& login) const;
    void aktualizuj(const std::string& promocja) override;
};

#endif