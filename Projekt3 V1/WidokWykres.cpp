#include "WidokWykres.h"
#include <iostream>
#include <vector>
using namespace std;


WidokWykres::WidokWykres()
{
}


WidokWykres::~WidokWykres()
{
}

void WidokWykres::wyswietl()
{
	Dochody * wsk = dynamic_cast<Dochody*> (doc);
	vector<DochodJednostkowy> const &t = wsk->getTabela();
	double kwmax = 0;
	for (unsigned i = 0; i < t.size(); ++i) {
		if (t[i].kwota > kwmax)
			kwmax = t[i].kwota;
	}
	cout << "20* = " << kwmax << endl;
	cout << "Imie\tNazwisko\tData\tKwota" << endl;
	for (unsigned i = 0; i < t.size(); ++i) {
		int ile = t[i].kwota / kwmax * 20;
		cout << t[i].imie << "\t" << t[i].nazwisko << "\t" << t[i].data << "\t";
		for (unsigned j = 0; j < ile; ++j) { cout << "*"; }
		cout << endl;
	}
}

void WidokWykres::wczytaj()
{
	cout << "Dla tego widoku nie ma mozliwosci wczytywania danych." << endl;
}
