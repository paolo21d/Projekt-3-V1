//#pragma once
#ifndef WYJATEK_H
#define WYJATEK_H

#include <string>
class Wyjatek : public std::exception {
	std::string tresc;
	int id;
public:
	Wyjatek(std::string tr, int i) : tresc(tr), id(i) {};
	std::string getTresc()const {
		return tresc;
	}
	int getId()const {
		return id;
	}
};

#endif // !WYJATEK_H
