//#pragma once
#ifndef WIDOK_TABELA_H
#define WIDOK_TABELA_H
#include "Dochody.h"
#include "Widok.h"
#include "DochodJednostkowy.h"
#include <iostream>
#include <vector>
class WidokTabela: public Widok
{
public:
	WidokTabela();
	~WidokTabela();
	void wyswietl();
	void wczytaj();
};

#endif //WIDOK_TABELA_H
