#include <exception>
#include <string>
using namespace std;

#ifndef __SystemLogowania_h__
#define __SystemLogowania_h__

// #include "Klient.h"

class Klient;
class SystemLogowania;

class SystemLogowania
{
	private: string _dane;
	private: string _haslo;
	public: Klient* _unnamed_Klient_;

	public: void sprawdzPoprawnosc();

	public: void przejdzDoKonta();

	public: void zatwierdzKonto();

	public: void autoryzacja();
};

#endif

