#include "WidokTabela.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
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
	if (t.size() == 0) {
		cout << "Brak danych." << endl;
		return;
	}
	cout << endl << "########## Widok tabeli:" << endl;
	cout << setw(15) << "Imie" << setw(15) << "Nazwisko" << setw(10) << "Data" << setw(20) << "Kwota" << endl;
	for (unsigned i = 0; i < t.size(); ++i) {
		//cout << t[i];
		//cout <<setw(10)<< t[i].imie << " " << t[i].nazwisko << "\tData: " << t[i].data << "\tKwota:" << t[i].kwota << endl;
		cout << setw(15) << t[i].imie << setw(15) << t[i].nazwisko <<  setw(10) << t[i].data << setw(20) << t[i].kwota << endl;
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
	Dochody * wsk = dynamic_cast<Dochody*> (doc);
	DochodJednostkowy dj(imie, nazwisko, data, kwota);
	if (wsk->dodajDochod(dj) == false) {
		cout << "Juz zostaj dodany dochod dla podanego pracownika w danym miesiacu!" << endl;
		return;
	}
}
