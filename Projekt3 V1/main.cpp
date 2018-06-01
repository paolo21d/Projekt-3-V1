/********
Projekt 3 PROI -> model Dokument-Widok
Autor: Pawel Swiatkowski
********/

#include <iostream>
#include <vector>
#include "Dochody.h"
#include "WidokTabela.h"
#include "WidokWykres.h"
using namespace std;

int main() {
	int opcja=1;
	Dochody doch;	
	/*WidokTabela *wt = new WidokTabela();
	WidokWykres *ww = new WidokWykres();
	if (!doch.dodajWidok(wt))
		cout << "Blad!" << endl;
	if (!doch.dodajWidok(ww))
		cout << "Blad!" << endl;*/

	WidokTabela *wt;
	WidokWykres *ww;
	try {
		wt = new WidokTabela();
		ww = new WidokWykres();
	}
	catch (bad_alloc &ba) {
		cerr << "bad_alloc: " << ba.what() << endl;
		cout << "Blad alokacji pamieci!";
		return 1;
	}
	if (!doch.dodajWidok(wt))
		cout << "Blad!" << endl;
	if (!doch.dodajWidok(ww))
		cout << "Blad!" << endl;
	while (opcja) {
		cout << "Wybor opcji:" << endl;
		/*cout << "1 Pokaz widoki." << endl;
		cout << "2 Dodaj dane." << endl;*/
		cout << "1 Dodaj dane. " << endl;
		cout << "0 Wyjscie." << endl;

		while (!(cin >> opcja)) {
			cout << "Blad podaj jeszcze raz!" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
		/*if (opcja == 1) {
			
		}*/
		 if (opcja == 1) {
			//wt->wczytaj();
			 try {
				 wt->wczytaj();
			 }
			 catch (string info) {
				 cout << info;
			 }
		}
	}
	return 0;
}