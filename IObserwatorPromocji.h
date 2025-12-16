#include <exception>
using namespace std;

#ifndef __IObserwatorPromocji_h__
#define __IObserwatorPromocji_h__

#include "Promocje.h"

class Promocje;
__interface IObserwatorPromocji;

__interface IObserwatorPromocji
{

	public: virtual void() aktualizuj(Promocje aPromocja) = 0;
};

#endif
