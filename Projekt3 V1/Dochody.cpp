#include "Dochody.h"
#include <algorithm>
#include <iostream>

Dochody::Dochody()
{
}

Dochody::~Dochody()
{
	for (unsigned i = 0; i < listaWidokow.size(); ++i) {
		delete listaWidokow[i];
	}
}
std::vector<DochodJednostkowy> const & Dochody::getTabela() const
{
	return tabelaDochodow;
}
bool Dochody::dodajDochod(DochodJednostkowy dochod)
{
	for (unsigned i = 0; i < tabelaDochodow.size(); ++i) {
		if (tabelaDochodow[i].imie == dochod.imie && tabelaDochodow[i].nazwisko == dochod.nazwisko && tabelaDochodow[i].data == dochod.data)
			return false; //juz jest dochod dla danego pracownika w podanym miesiacu
	}
	tabelaDochodow.push_back(dochod);
	sort(tabelaDochodow.begin(), tabelaDochodow.end());
	odswiezWidoki();
	return true;
}
std::ostream& operator<<(std::ostream &os, const Dochody & d) {
	for (unsigned i = 0; i < d.tabelaDochodow.size(); ++i) {
		const DochodJednostkowy & dj = d.tabelaDochodow[i];
		os << dj.nazwisko << " " << dj.imie << " " << dj.data << " " << dj.kwota << std::endl;
	}
	return os;
}
/*bool Dochody::odswiezWidoki()
{
	for (unsigned i = 0; i < listaWidokow.size(); ++i) {
		listaWidokow[i]->wyswietl();
	}
	return true;
}*/
/*bool Dochody::dodajWidok(Widok *w)
{ //najpierw trzeba zaalowokac pamiec na widok i przekazac do tej funkcji juz wskaznik na zaalkowana pamiec
	//WidokTabela *wt = new WidokTabela;
	listaWidokow.push_back(w);
	return true;
}*/
/*bool Dochody::usunWidok(Widok *w)
{
	for (unsigned i = 0; i < listaWidokow.size(); ++i) {
		if (listaWidokow[i] == w) {
			delete listaWidokow[i];
			listaWidokow.erase(listaWidokow.begin() + i);
			return true;
		}
	}
	return false;
}*/
