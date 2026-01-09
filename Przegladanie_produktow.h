#include <exception>
using namespace std;

#ifndef __Przegladanie_produktow_h__
#define __Przegladanie_produktow_h__

class Przegladanie_produktow;

class Przegladanie_produktow
{
	private: double _id_produktu;
	private: bool _dostepnosc_produktu;

	public: void dodajDoKoszyka();

	public: void wyszukajProdukt();

	public: void przejdzDoKoszyka();
};

#endif

