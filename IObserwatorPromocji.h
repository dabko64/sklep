//#include <exception>
//using namespace std;
//
//#ifndef __IObserwatorPromocji_h__
//#define __IObserwatorPromocji_h__
//
//#include "Promocje.h"
//
//class Promocje;
//__interface IObserwatorPromocji;
//
//__interface IObserwatorPromocji
//{
//
//	public: virtual void() aktualizuj(Promocje aPromocja) = 0;
//};
//
//#endif
#ifndef IOBSERWATORPROMOCJI_H
#define IOBSERWATORPROMOCJI_H

#include <string>

class IObserwatorPromocji {
public:
    virtual ~IObserwatorPromocji() = default;
    // Ta metoda musi istnieć, aby 'override' w Gosc i Klient działało
    virtual void aktualizuj(const std::string& promocja) = 0;
};

#endif