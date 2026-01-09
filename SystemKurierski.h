#include <exception>
using namespace std;

#ifndef __SystemKurierski_h__
#define __SystemKurierski_h__

// #include "Magazyn.h"
// #include "SystemPlatniczy.h"

class Magazyn;
class SystemPlatniczy;
class SystemKurierski;

class SystemKurierski
{
	private: String _nazwa_firmy;
	private: String _adres;
	private: int _id_systemu;
	private: String _status_Dostawy;
	private: int _numer_przesyłki;
	private: date _data_nadania;
	private: date _data_dostarczenia;
	public: Magazyn* _unnamed_Magazyn_;
	public: SystemPlatniczy* _unnamed_SystemPlatniczy_;

	public: void utworzeniePrzesylki();

	public: void przypiszNrSledzenia();

	public: void aktualizacjaStatusu(String aNowyStatus);

	public: void wyslijPowiadomienieK();

	public: void przekazanieZamówienia();
};

#endif

