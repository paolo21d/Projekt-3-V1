//#pragma once
#ifndef WIDOK_WYKRES_H
#define WIDOK_WYKRES_H
#include "Dochody.h"
#include "Widok.h"
#include "DochodJednostkowy.h"
#include <iostream>
#include <vector>
class WidokWykres: public Widok
{
public:
	WidokWykres();
	~WidokWykres();
	void wyswietl();
	void wczytaj();
};
#endif //WIDOK_WYKRES_H
