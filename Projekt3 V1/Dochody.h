//#pragma once
#ifndef DOCHODY_H
#define DOCHODY_H
#include "Dokument.h"
#include "WidokTabela.h"
#include "WidokWykres.h"
#include "DochodJednostkowy.h"
#include <vector>
#include <string>
#include <iostream>
class Dochody:public Dokument
{
	
	std::vector <DochodJednostkowy> TabelaDochodow;
	//std::vector <std::vector<double>> TabelaDochodow;


	//virtual bool odswiezWidoki();
	//virtual bool dodajWidok(Widok *w);
	//virtual bool usunWidok(Widok *w);
public:
	//friend class WidokTabela;
	Dochody();
	~Dochody();
	std::vector <DochodJednostkowy> const & getTabela()const;
	bool dodajDochod(DochodJednostkowy dochod);
};

#endif //DOCHODY_H
