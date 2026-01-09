#include <exception>
#include <string>
using namespace std;

#ifndef __Promocje_h__
#define __Promocje_h__

#include "IObserwatorPromocji.h"
// #include "Sprzedawca.h"
#include "IPromocja.h"

__interface IObserwatorPromocji;
class Sprzedawca;
// __interface IPromocja;
class Promocje;

class Promocje: public IPromocja
{
	private: int _id;
	private: int _procentZnizki;
	private: string _nazwa;
	private: date _dataRozpoczecia;
	private: List<IObserwatorPromocji> _listaObserwatorow;
	public: Sprzedawca* _unnamed_Sprzedawca_;

	public: void aktywujPromocje();

	public: void dezaktywujPromocje();

	public: void() zmienPromocjê();

	public: void powiadom();

	public: void dodajDoObserwatora(IObserwatorPromocji aO);

	public: void usunObserwatora(IObserwatorPromocji aO);

	public: void powiadomienie();
};

#endif

