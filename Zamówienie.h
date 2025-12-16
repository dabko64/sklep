#include <exception>
#include <string>
#include <vector>
using namespace std;

#ifndef __Zamówienie_h__
#define __Zamówienie_h__

// #include "Koszyk.h"
// #include "Z³ó¿_zamówienie.h"
#include "Magazyn.h"

class Koszyk;
class Z³ó¿_zamówienie;
class Magazyn;
class Zamówienie;

class Zamówienie
{
	private: double _idZamowienia;
	private: date _dataZlozenia;
	private: string _status;
	private: double _kwota;
	public: Koszyk* _unnamed_Koszyk_;
	public: Z³ó¿_zamówienie* _unnamed_Z³ó¿_zamówienie_;
	public: std::vector<Magazyn*> _unnamed_Magazyn_;

	public: void utworzZamowienie();

	public: void zmienStatus();

	public: void przekazDoMagazynu();

	public: void sprawdzStatus();

	public: void wybierzMetodePlatnosci();
};

#endif
