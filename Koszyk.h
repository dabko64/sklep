#include <exception>
using namespace std;

#ifndef __Koszyk_h__
#define __Koszyk_h__

// #include "Goœæ.h"
// #include "Klient.h"
// #include "Produkt.h"
// #include "Zamówienie.h"

class Goœæ;
class Klient;
class Produkt;
class Zamówienie;
class Koszyk;

class Koszyk
{
	private: int _idProduktu;
	private: String _nazwaProduktu;
	private: Bool _czyJestDostepny;
	public: Goœæ* _unnamed_Goœæ_;
	public: Klient* _unnamed_Klient_20;
	public: Produkt* _unnamed_Produkt_;
	public: Zamówienie* _unnamed_Zamówienie_;

	public: void usunZKoszyka();

	public: void zlozZamowienie();
};

#endif
