#include <exception>
#include <string>
using namespace std;

#ifndef __Z³ó¿_zamówienie_h__
#define __Z³ó¿_zamówienie_h__

// #include "Zamówienie.h"

class Zamówienie;
class Z³ó¿_zamówienie;

class Z³ó¿_zamówienie
{
	private: int _numerTelefonu;
	private: string _adres;
	private: string _adresMailowy;
	private: string _imieINazwisko;
	private: IStrategiaP³atnosci _sposóbP³atnoœci;
	public: Zamówienie* _unnamed_Zamówienie_;

	public: void uzupelnijDane();

	public: void przejdzDoPlatnosci();

	public: IStrategiaP³atnoœci wybierzP³atnoœæ();
};

#endif
