#include <exception>
using namespace std;

#ifndef __Goœæ_h__
#define __Goœæ_h__

// #include "Koszyk.h"
#include "Promocje.h"
#include "IObserwatorPromocji.h"

class Koszyk;
// class Promocje;
// __interface IObserwatorPromocji;
class Goœæ;

class Goœæ: public IObserwatorPromocji, public Promocje
{
	private: Bool _akceptacjaCookies;
	private: int _idSesji;
	private: String _adresIP;
	private: String _zdrodloOdwiedzin;
	private: date _dataWejscia;
	public: Koszyk* _unnamed_Koszyk_;

	public: void stworzKonto();

	public: void wybierzHaslo();

	public: void wybierzLogin();

	public: void czyIstniejeTakiLogin();

	public: void() aktualizuj(Promocje aPromocja);
};

#endif
