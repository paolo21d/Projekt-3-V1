#include "WidokWykres.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;


WidokWykres::WidokWykres()
{
}


WidokWykres::~WidokWykres()
{
}

void WidokWykres::wyswietl()
{
	const int SZEROKOSC_WYKRESU = 70;
	Dochody * wsk = dynamic_cast<Dochody*> (doc);
	vector<DochodJednostkowy> const &t = wsk->getTabela();
	if (t.size() == 0) {
		cout << "Brak danych." << endl;
		return;
	}
	double kwmax = 0;
	for (unsigned i = 0; i < t.size(); ++i) {
		if (t[i].kwota > kwmax)
			kwmax = t[i].kwota;
	}
	cout << endl << "########## Widok wykresu: " << endl;
	//cout << SZEROKOSC_WYKRESU << "* = " << kwmax << endl;
	//cout << "Imie\tNazwisko\tData\tKwota" << endl;
	cout << setw(15) << "Imie" << setw(15) << "Nazwisko" << setw(10) << "Data" << setw(max(SZEROKOSC_WYKRESU/2, 8)) << "Kwota (" << SZEROKOSC_WYKRESU << "* = " << kwmax << ")" << endl;
	for (unsigned i = 0; i < t.size(); ++i) {
		int ile = (t[i].kwota / kwmax) * SZEROKOSC_WYKRESU;
		if (ile == 0) ile = 1;
		//cout << setw(10) << t[i].imie << "\t" << t[i].nazwisko << "\t" << t[i].data << "\t";
		cout << setw(15) << t[i].imie << setw(15) << t[i].nazwisko << setw(10) << t[i].data<<" ";
		for (unsigned j = 0; j < ile; ++j) { cout << "*"; }
		cout << endl;
	}
}

void WidokWykres::wczytaj()
{
	cout << "Dla tego widoku nie ma mozliwosci wczytywania danych." << endl;
}
