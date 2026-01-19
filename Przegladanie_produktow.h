#ifndef __Przegladanie_produktow_h__
#define __Przegladanie_produktow_h__
#include <string>

class Przegldanie_produktow;

class Przegladanie_produktow
{
	private: 
		double _id_produktu;
		bool _dostepnosc_produktu;
	public: 
		// Metoda wyświetlająca wszystkie produkty z pliku produkty.txt
		void wyswietlWszystkie();
		void wyszukajProdukt();
		//void dodajDoKoszyka();
		//*void przejdzDoKoszyka();
};

#endif
