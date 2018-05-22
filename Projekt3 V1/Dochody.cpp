#include "Dochody.h"



Dochody::Dochody()
{
}

Dochody::~Dochody()
{
	for (unsigned i = 0; i < listaWidokow.size(); ++i) {
		delete listaWidokow[i];
	}
}
bool Dochody::odswiezWidoki()
{
	for (unsigned i = 0; i < listaWidokow.size(); ++i) {
		listaWidokow[i]->wyswietl();
	}
	return true;
}
bool Dochody::dodajWidok(Widok *w)
{ //najpierw trzeba zaalowokac pamiec na widok i przekazac do tej funkcji juz wskaznik na zaalkowana pamiec
	//WidokTabela *wt = new WidokTabela;
	listaWidokow.push_back(w);
	return true;
}
bool Dochody::usunWidok(Widok *w)
{
	for (unsigned i = 0; i < listaWidokow.size(); ++i) {
		if (listaWidokow[i] == w) {
			delete listaWidokow[i];
			listaWidokow.erase(listaWidokow.begin() + i);
			return true;
		}
	}
	return false;
}