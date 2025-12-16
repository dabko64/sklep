#include <exception>
using namespace std;

#ifndef __Przegl¹danie_produktów_h__
#define __Przegl¹danie_produktów_h__

class Przegl¹danie_produktów;

class Przegl¹danie_produktów
{
	private: double _id_produktu;
	private: bool _dostepnosc_produktu;

	public: void dodajDoKoszyka();

	public: void wyszukajProdukt();

	public: void przejdzDoKoszyka();
};

#endif
