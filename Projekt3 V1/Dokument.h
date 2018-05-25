//#pragma once
#ifndef DOKUMENT_H
#define DOKUMENT_H
#include "Widok.h"
#include <vector>
class Dokument {
protected:
	std::vector <Widok*> listaWidokow;
	bool odswiezWidoki(){
		for (unsigned i = 0; i < listaWidokow.size(); ++i) {
			listaWidokow[i]->wyswietl();
		}
		return true;
	}
public:
	friend class Widok;
	bool dodajWidok(Widok *w){
		//najpierw trzeba zaalowokac pamiec na widok i przekazac do tej funkcji juz wskaznik na zaalkowana pamiec
		//WidokTabela *wt = new WidokTabela;
		w->doc = this;
		listaWidokow.push_back(w);
		return true;
	}
	bool usunWidok(Widok *w){
		for (unsigned i = 0; i < listaWidokow.size(); ++i) {
			if (listaWidokow[i] == w) {
				delete listaWidokow[i];
				listaWidokow.erase(listaWidokow.begin() + i);
				return true;
			}
		}
		return false;
	}
	virtual ~Dokument(){
		for (unsigned i = 0; i < listaWidokow.size(); ++i) {
			delete listaWidokow[i];
		}
	}
};
#endif // !DOKUMENT_H
