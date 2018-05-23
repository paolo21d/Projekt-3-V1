//#pragma once
#ifndef WIDOK_H
#define WIDOK_H
//#include "Dokument.h"
class Dokument;
class Widok {
protected:
	Dokument * doc;
public:
	virtual void wyswietl() = 0;
	virtual ~Widok(){};
	virtual void wczytaj() = 0;
};

#endif // !WIDOK_H
