#pragma once
#ifndef DOKUMENT_H
#define DOKUMENT_H
#include "Widok.h"
#include <vector>
class Dokument {
protected:
	std::vector <Widok*> listaWidokow;
	virtual bool odswiezWidoki() = 0;
	//virtual 
};
#endif // !DOKUMENT_H
