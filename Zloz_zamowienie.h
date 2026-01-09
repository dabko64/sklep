#include <exception>
#include <string>
using namespace std;

#ifndef __Zloz_zamowienie_h__
#define __Zloz_zamowienie_h__

// #include "Zamówienie.h"

class Zamówienie;
class Zloz_zamowienie;

class Zloz_zamowienie
{
	private: int _numerTelefonu;
	private: string _adres;
	private: string _adresMailowy;
	private: string _imieINazwisko;
	private: IStrategiaPlatnosci _sposobPlatnosci;
	public: Zamowienie* _unnamed_Zamowienie_;

	public: void uzupelnijDane();

	public: void przejdzDoPlatnosci();

	public: IStrategiaPlatnosci wybierzPlatnosc();
};

#endif

