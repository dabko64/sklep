#include <exception>
#include <string>
using namespace std;

#ifndef __SystemP³atniczy_h__
#define __SystemP³atniczy_h__

// #include "Magazyn.h"
// #include "SystemKurierski.h"
#include "IStrategiaP³atnoœæ.h"

class Magazyn;
class SystemKurierski;
// __interface IStrategiaP³atnoœæ;
class SystemP³atniczy;

class SystemP³atniczy: public IStrategiaP³atnoœæ
{
	private: int _id_systemu;
	private: String _nazwa_systemu;
	private: String _adres_API;
	private: string _typ_platnosci;
	private: String _status_platnosci;
	private: double _kwota_transakcji;
	private: date _data_platnosci;
	private: String _id_transakcji;
	public: Magazyn* _unnamed_Magazyn_;
	public: SystemKurierski* _unnamed_SystemKurierski_;

	public: void przekazaniePlatnosci();

	public: void autoryzacjaPlatnosci();

	public: void aktualizacjaStatusuP();

	public: void wyslijDoBanku();

	public: void wyslijPowiadomienieP();

	public: void œledzenie();

	public: void zrealizujP³atnoœæ(double aKwota);
};

#endif
