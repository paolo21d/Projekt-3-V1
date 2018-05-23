//#pragma once
#ifndef DOCHODY_H
#define DOCHODY_H
#include "Dokument.h"
#include "WidokTabela.h"
#include "WidokWykres.h"
#include <vector>
#include <string>
#include <iostream>
class Dochody:public Dokument
{
	struct DochodJednostkowy {
		std::string imie, nazwisko;
		std::string data;
		double kwota;
	};
	std::vector <DochodJednostkowy> TabelaDochodow;
	//std::vector <std::vector<double>> TabelaDochodow;


	//virtual bool odswiezWidoki();
	//virtual bool dodajWidok(Widok *w);
	//virtual bool usunWidok(Widok *w);
public:
	Dochody();
	~Dochody();
};

#endif //DOCHODY_H
