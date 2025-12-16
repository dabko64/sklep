#include <exception>
#include <string>
using namespace std;

#ifndef __Produkt_h__
#define __Produkt_h__

// #include "Klient.h"
// #include "Koszyk.h"
// #include "Magazyn.h"

class Klient;
class Koszyk;
class Magazyn;
class Produkt;

class Produkt
{
	private: int _id;
	private: string _nazwa;
	private: bool _dostepnosc;
	public: Klient* _unnamed_Klient_;
	public: Koszyk* _unnamed_Koszyk_;
	public: Magazyn* _unnamed_Magazyn_;

	public: void dodajDoKoszyka();

	public: void usunZKoszyka();

	public: void sprawdzDostepnosc();

	public: void przegladaj();
};

#endif
