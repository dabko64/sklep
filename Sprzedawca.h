#include <exception>
#include <vector>
using namespace std;

#ifndef __Sprzedawca_h__
#define __Sprzedawca_h__

// #include "Magazyn.h"
#include "Promocje.h"

class Magazyn;
class Promocje;
class Sprzedawca;

class Sprzedawca
{
	private: string _email;
	private: string _haslo;
	private: int _kodWeryfikacyjny;
	public: Magazyn* _unnamed_Magazyn_;
	public: std::vector<Promocje*> _unnamed_Promocje_;

	public: void zarzadzanieProduktami();

	public: void zarzadaniePromocjami();

	public: void usuwanieProduktow();

	public: void dodawanieProduktow();

	public: void modyfikacjaCen();

	public: void autoryzuj();
};

#endif
