#include <exception>
using namespace std;

#ifndef __Magazyn_h__
#define __Magazyn_h__

// #include "Sprzedawca.h"
// #include "Zamówienie.h"
// #include "Produkt.h"
// #include "SystemKurierski.h"
// #include "SystemP³atniczy.h"

class Sprzedawca;
class Zamówienie;
class Produkt;
class SystemKurierski;
class SystemP³atniczy;
class Magazyn;

class Magazyn
{
	private: int _kodWejscia;
	private: int _liczbaDostepnychProduktow;
	public: Sprzedawca* _unnamed_Sprzedawca_;
	public: Zamówienie* _unnamed_Zamówienie_;
	public: Produkt* _unnamed_Produkt_;
	public: SystemKurierski* _unnamed_SystemKurierski_;
	public: SystemP³atniczy* _unnamed_SystemP³atniczy_;

	public: void przekazanieZamowieniaK();

	public: void przekazanieZamowieniaP();

	public: void czyDostepne();

	public: void dodajProdukt();

	public: void potwierdzZmiane();

	public: void aktualizacjaProduktów();
};

#endif
