#include "WidokTabela.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

WidokTabela::WidokTabela()
{
}

WidokTabela::~WidokTabela()
{
}

void WidokTabela::wyswietl()
{
	Dochody * wsk = dynamic_cast<Dochody*> (doc);
	vector<DochodJednostkowy> const &t = wsk->getTabela();
	for (unsigned i = 0; i < t.size(); ++i) {
		//cout << t[i];
		cout << t[i].nazwisko << " " << t[i].imie << "\tData: " << t[i].data << "\tKwota:" << t[i].kwota << endl;
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
	s << data.substr(4, 4);
	s >> r;
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
	Dochody * wsk = dynamic_cast<Dochody*> (doc);
	DochodJednostkowy dj(imie, nazwisko, data, kwota);
	if (wsk->dodajDochod(dj) == false) {
		cout << "Juz zostaj dodany dochod dla podanego pracownika w danym miesiacu!" << endl;
		return;
	}
}
