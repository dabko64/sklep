#include <exception>
using namespace std;

#ifndef __IStrategiaPlatnosc_h__
#define __IStrategiaPlatnosc_h__

#include "IPlatnoscPrzelew.h"
#include "IPlatnoscBlik.h"

// class IPlatnoscPrzelew;
// class IPlatnoscBlik;
__interface IStrategiaPlatnosc;

__interface IStrategiaPlatnosc: public IPlatnoscPrzelew, public IPlatnoscBlik
{

	public: virtual void zrealizujPlatnosc(double aKwota) = 0;
};

#endif

