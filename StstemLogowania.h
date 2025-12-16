#include <exception>
#include <string>
using namespace std;

#ifndef __StstemLogowania_h__
#define __StstemLogowania_h__

// #include "Klient.h"

class Klient;
class StstemLogowania;

class StstemLogowania
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
