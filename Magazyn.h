#include <exception>
using namespace std;

#ifndef __Magazyn_h__
#define __Magazyn_h__

// #include "Sprzedawca.h"
// #include "Zamowienie.h"
// #include "Produkt.h"
// #include "SystemKurierski.h"
// #include "SystemPlatniczy.h"

class Sprzedawca;
class Zamowienie;
class Produkt;
class SystemKurierski;
class SystemPlatniczy;
class Magazyn;

class Magazyn
{
	private: int _kodWejscia;
	private: int _liczbaDostepnychProduktow;
	public: Sprzedawca* _unnamed_Sprzedawca_;
	public: Zamowienie* _unnamed_Zamowienie_;
	public: Produkt* _unnamed_Produkt_;
	public: SystemKurierski* _unnamed_SystemKurierski_;
	public: SystemPlatniczy* _unnamed_SystemPlatniczy_;

	public: void przekazanieZamowieniaK();

	public: void przekazanieZamowieniaP();

	public: void czyDostepne();

	public: void dodajProdukt();

	public: void potwierdzZmiane();

	public: void aktualizacjaProduktow();
};

#endif

