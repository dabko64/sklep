#include <exception>
using namespace std;

#ifndef __Gosc_h__
#define __Gosc_h__

// #include "Koszyk.h"
#include "Promocje.h"
#include "IObserwatorPromocji.h"

class Koszyk;
// class Promocje;
// __interface IObserwatorPromocji;
class Gosc;

// prosty interfejs obserwatora (minimalny)
// class IObserwatorPromocji {
// public:
//     virtual ~IObserwatorPromocji() = default;
//     virtual void aktualizuj(const string& promocja) = 0;
// };

class Gosc: public IObserwatorPromocji, public Promocje
{
	protected:
    bool akceptacjaCookies;
    int idSesji;
    string adresIP;
    string zrodloOdwiedzin;
	private: Bool _akceptacjaCookies;
	string login;  
	string haslo;
	private: int _idSesji;
	private: String _adresIP;
	private: String _zdrodloOdwiedzin;
	private: date _dataWejscia;
	public: Koszyk* _unnamed_Koszyk_;

	public: Gosc();
	public: void stworzKonto();

	public: void wybierzHaslo();

	public: void wybierzLogin();

	public: void czyIstniejeTakiLogin();

	public: void() aktualizuj(Promocje aPromocja);
	//void aktualizuj(const std::string& promocja) override;
};

#endif

