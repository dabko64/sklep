#include <exception>
using namespace std;

#ifndef __Klient_h__
#define __Klient_h__

// #include "StstemLogowania.h"
// #include "Koszyk.h"
// #include "Produkt.h"
#include "Promocje.h"
#include "Goœæ.h"
#include "IObserwatorPromocji.h"

class StstemLogowania;
class Koszyk;
class Produkt;
// class Promocje;
// class Goœæ;
// __interface IObserwatorPromocji;
class Klient;

class Klient: public Goœæ, public IObserwatorPromocji, public Promocje
{
	private: String _imie;
	private: String _nazwisko;
	private: String _email;
	private: String _adres;
	private: int _nrTelefonu;
	private: String _haslo;
	private: double _id;
	public: StstemLogowania* _unnamed_StstemLogowania_;
	public: Koszyk* _unnamed_Koszyk_21;
	public: Produkt* _unnamed_Produkt_;

	public: void zalogujSie();

	public: void wylogujSie();

	public: void przejdzDoKoszyka();

	public: void przejdzDoZamowienia();

	public: void aktualizu(Promocje aPromocja);

	public: void() aktualizuj(Promocje aPromocja);
};

#endif
