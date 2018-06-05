#include "WidokWykres.h"
#include "Wyjatek.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <typeinfo>
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
	const int SZEROKOSC_WYK1 = 15;
	const int SZEROKOSC_WYK2 = 10;
	Dochody * wsk;
	try {
		wsk = dynamic_cast<Dochody*> (doc);
	}
	catch (bad_cast& bc) {
		cerr << "bad_cast: " << bc.what() << endl;
		cout << "Blad rzutowania!" << endl;
		return;
	}
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
	cout << setw(SZEROKOSC_WYK1) << "Imie" << setw(SZEROKOSC_WYK1) << "Nazwisko" << setw(SZEROKOSC_WYK2) << "Data" << setw(max(SZEROKOSC_WYKRESU/2, 8)) << "Kwota (" << SZEROKOSC_WYKRESU << "* = " << kwmax << ")" << endl;
	for (unsigned i = 0; i < t.size(); ++i) {
		unsigned ile = (t[i].kwota / kwmax) * SZEROKOSC_WYKRESU;
		if (ile == 0) ile = 1;
		//cout << setw(10) << t[i].imie << "\t" << t[i].nazwisko << "\t" << t[i].data << "\t";
		cout << setw(SZEROKOSC_WYK1) << t[i].imie << setw(SZEROKOSC_WYK1) << t[i].nazwisko << setw(SZEROKOSC_WYK1) << t[i].data<<" ";
		for (unsigned j = 0; j < ile; ++j) { cout << "*"; }
		cout << endl;
	}
}

void WidokWykres::wczytaj()
{
	//throw "Dla tego widoku nie ma mozliwosci wczytywania danych!";
	throw Wyjatek("Dla tego widoku nie ma mozliwosci wczytywania danych", 1);
	//cout << "Dla tego widoku nie ma mozliwosci wczytywania danych." << endl;
}
