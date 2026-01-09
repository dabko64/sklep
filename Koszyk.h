#include <exception>
using namespace std;

#ifndef __Koszyk_h__
#define __Koszyk_h__

// #include "Gosc.h"
// #include "Klient.h"
// #include "Produkt.h"
// #include "Zamowienie.h"

class Gosc;
class Klient;
class Produkt;
class Zamowienie;
class Koszyk;

class Koszyk
{
	private: int _idProduktu;
	private: String _nazwaProduktu;
	private: Bool _czyJestDostepny;
	public: Gosc* _unnamed_Gosc_;
	public: Klient* _unnamed_Klient_20;
	public: Produkt* _unnamed_Produkt_;
	public: Zamowienie* _unnamed_Zamowienie_;

	public: void usunZKoszyka();

	public: void zlozZamowienie();
};

#endif

