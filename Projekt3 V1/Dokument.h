#pragma once
#ifndef DOKUMENT_H
#define DOKUMENT_H
#include "Widok.h"
#include <vector>
class Dokument {
protected:
	std::vector <Widok*> listaWidokow;
	virtual bool odswiezWidoki() = 0;
public:
	virtual bool dodajWidok(Widok *w) = 0; //arg popraw
	virtual bool usunWidok(Widok *w) = 0;//arg popraw
	virtual ~Dokument() = 0;
};
#endif // !DOKUMENT_H
