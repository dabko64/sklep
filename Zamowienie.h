#include <exception>
#include <string>
#include <vector>
using namespace std;

#ifndef __Zamowienie_h__
#define __Zamowienie_h__

// #include "Koszyk.h"
// #include "Zloz_zamowienie.h"
#include "Magazyn.h"

class Koszyk;
class Zloz_zamowienie;
class Magazyn;
class Zamowienie;

class Zamowienie
{
	private: double _idZamowienia;
	private: date _dataZlozenia;
	private: string _status;
	private: double _kwota;
	public: Koszyk* _unnamed_Koszyk_;
	public: Złóż_zamowienie* _unnamed_Złóż_zamowienie_;
	public: std::vector<Magazyn*> _unnamed_Magazyn_;

	public: void utworzZamowienie();

	public: void zmienStatus();

	public: void przekazDoMagazynu();

	public: void sprawdzStatus();

	public: void wybierzMetodePlatnosci();
};

#endif

