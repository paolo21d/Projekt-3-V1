#include "WidokTabela.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <typeinfo>
using namespace std;

WidokTabela::WidokTabela()
{
}

WidokTabela::~WidokTabela()
{
}

void WidokTabela::wyswietl()
{
	const int SZEROKOSC_WYK1 = 15;
	const int SZEROKOSC_WYK2 = 10;
	const int SZEROKOSC_WYK3 = 20;
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
	cout << endl << "########## Widok tabeli:" << endl;
	cout << setw(SZEROKOSC_WYK1) << "Imie" << setw(SZEROKOSC_WYK1) << "Nazwisko" << setw(SZEROKOSC_WYK2) << "Data" << setw(SZEROKOSC_WYK3) << "Kwota" << endl;
	for (unsigned i = 0; i < t.size(); ++i) {
		//cout << t[i];
		//cout <<setw(10)<< t[i].imie << " " << t[i].nazwisko << "\tData: " << t[i].data << "\tKwota:" << t[i].kwota << endl;
		cout << setw(SZEROKOSC_WYK1) << t[i].imie << setw(SZEROKOSC_WYK1) << t[i].nazwisko <<  setw(SZEROKOSC_WYK2) << t[i].data << setw(SZEROKOSC_WYK3) << t[i].kwota << endl;
	}
}

void WidokTabela::wczytaj()
{
	string imie, nazwisko, data;
	double kwota;
	cout << "Podaj imie: ";
	cin >> imie;
	cout << "Podaj nazwisko: ";
	cin >> nazwisko;
	cout << "Podaj date (format MM.RRRR): ";
	cin >> data;
	if (data.size() != 7) {
		cout << "Blad danych!" << endl;
		return;
	}
	if (data[2] != '.') {
		cout << "Blad danych!" << endl;
		return;
	}
	if (!isdigit(data[0]) || !isdigit(data[1]) || !isdigit(data[3]) || !isdigit(data[4]) || !isdigit(data[5]) || !isdigit(data[6])) {
		cout << "Blad danych!" << endl;
		return;
	}
	int m, r;
	stringstream s;
	s << data.substr(0, 2);
	s >> m;
	stringstream s2;
	s2 << data.substr(3, 4);
	s2 >> r;
	if (m < 1 || m>12 || r < 1) {
		cout << "Blad danych!" << endl;
		return;
	}
	cout << "Podaj kwote dochodu: ";
	if (! (cin >> kwota)) {
		cout << "Blad danych!" << endl;
		return;
	}
	if (kwota < 0) {
		cout << "Blad danych!" << endl;
		return;
	}
	Dochody * wsk;
	try {
		wsk = dynamic_cast<Dochody*> (doc);
	}
	catch (bad_cast& bc) {
		cerr << "bad_cast: " << bc.what() << endl;
		cout << "Blad rzutowania!" << endl;
		return;
	}
	DochodJednostkowy dj(imie, nazwisko, data, kwota);
	if (wsk->dodajDochod(dj) == false) {
		cout << "Juz zostaj dodany dochod dla podanego pracownika w danym miesiacu!" << endl;
		return;
	}
}
