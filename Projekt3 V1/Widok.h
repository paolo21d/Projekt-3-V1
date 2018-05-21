#pragma once
#ifndef WIDOK_H
#define WIDOK_H
#include "Dokument.h"
class Widok {
protected:
	Dokument * dokument;

	virtual void wyswietl() = 0;
};

#endif // !WIDOK_H
