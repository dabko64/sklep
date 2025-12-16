#include <exception>
using namespace std;

#ifndef __IStrategiaP³atnoœæ_h__
#define __IStrategiaP³atnoœæ_h__

#include "IP³atnoœæPrzelew.h"
#include "IP³atnoœæBlik.h"

// class IP³atnoœæPrzelew;
// class IP³atnoœæBlik;
__interface IStrategiaP³atnoœæ;

__interface IStrategiaP³atnoœæ: public IP³atnoœæPrzelew, public IP³atnoœæBlik
{

	public: virtual void zrealizujP³atnoœæ(double aKwota) = 0;
};

#endif
