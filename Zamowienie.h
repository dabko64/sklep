#include <exception>
#include <string>
#include <vector>
using namespace std;

#ifndef __Zamówienie_h__
#define __Zamówienie_h__

// #include "Koszyk.h"
// #include "Złóż_zamówienie.h"
#include "Magazyn.h"

class Koszyk;
class Złóż_zamówienie;
class Magazyn;
class Zamówienie;

class Zamówienie
{
	private: double _idZamowienia;
	private: date _dataZlozenia;
	private: string _status;
	private: double _kwota;
	public: Koszyk* _unnamed_Koszyk_;
	public: Złóż_zamówienie* _unnamed_Złóż_zamówienie_;
	public: std::vector<Magazyn*> _unnamed_Magazyn_;

	public: void utworzZamowienie();

	public: void zmienStatus();

	public: void przekazDoMagazynu();

	public: void sprawdzStatus();

	public: void wybierzMetodePlatnosci();
};

#endif
