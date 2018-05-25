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
	doch.dodajWidok(new WidokTabela);
	doch.dodajWidok(new WidokWykres);
	while (opcja) {
		cout << "Wybor opcji:" << endl;
		cout << "1 Pokaz widoki." << endl;
		while (!(cin >> opcja)) {
			cout << "Blad podaj jeszcze raz!" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
	}
}