/********

Projekt 3 PROI -> model Dokument-Widok
Autor: Pawel Swiatkowski

********/

#include <iostream>
#include "Dochody.h"
#include "WidokTabela.h"
#include "WidokWykres.h"
using namespace std;

int main() {
	int opcja=1;
	Dochody doch;
	/*WidokTabela widtab;
	WidokWykres widwyk;*/
	WidokTabela *wt = new WidokTabela();
	WidokWykres *ww = new WidokWykres();
	if (!doch.dodajWidok(wt))
		cout << "Blad!" << endl;
	if (!doch.dodajWidok(ww))
		cout << "Blad!" << endl;
	while (opcja) {
		cout << "Wybor opcji:" << endl;
		cout << "1 Pokaz widoki." << endl;
		cout << "2 Dodaj dane." << endl;
		cout << "0 Wyjscie." << endl;

		while (!(cin >> opcja)) {
			cout << "Blad podaj jeszcze raz!" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
		if (opcja == 1) {
			
		}
		else if (opcja == 2) {
			wt->wczytaj();
		}
	}
}