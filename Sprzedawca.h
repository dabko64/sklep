#ifndef __Sprzedawca_h__
#define __Sprzedawca_h__

#include <string>
//#include <vector>

// #include "Magazyn.h"
//#include "Promocje.h"
//
//class Magazyn;
//class Promocje;
//class Sprzedawca;
//
class Sprzedawca
{
	private: 
		std::string login; // dodalam login, żeby system logowania był spójny
		std::string haslo;
		std::string email;
		int kodWeryfikacyjny;

	public: // Konstruktor do tworzenia sprzedawcy po wczytaniu z pliku
        Sprzedawca(std::string l, std::string h, std::string e, int kod);

        // Metody dostępowe
        std::string getLogin() const;// { return login; }
        bool sprawdzHaslo(const std::string& h) const;// { return haslo == h; }

        // Główne funkcjonalności (do zaimplementowania później)
        void dodawanieProduktow();
        void usuwanieProduktow();
        void modyfikacjaCen();
        void zarzadzanieProduktami();
        /* 
        public: void zarzadaniePromocjami();
        public: void autoryzuj();
        */
};
#endif
