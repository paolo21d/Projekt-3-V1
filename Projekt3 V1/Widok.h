#pragma once
#ifndef WIDOK_H
#define WIDOK_H
#include "Dokument.h"
class Widok {
protected:
	Dokument * doc;
public:
	virtual void wyswietl() = 0;
	virtual ~Widok() = 0;
	//virtual void wczytaj() = 0;
};

#endif // !WIDOK_H
