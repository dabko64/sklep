#include <exception>
using namespace std;

#ifndef __IPromocja_h__
#define __IPromocja_h__

__interface IPromocja;

__interface IPromocja
{

	public: virtual void dodajDoObserwatora(IObserwatorPromocji aO) = 0;

	public: virtual void usunObserwatora(IObserwatorPromocji aO) = 0;

	public: virtual void powiadomienie() = 0;
};

#endif
