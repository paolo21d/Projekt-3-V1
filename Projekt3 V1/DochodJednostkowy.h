#ifndef DOCHOD_JEDNOSTKOWY
#define DOCHOD_JEDNOSTKOWY

#include <string>
#include <iostream>

class DochodJednostkowy {
public:
	std::string imie, nazwisko;
	std::string data;
	double kwota;
	bool operator<(DochodJednostkowy const &d) {
		std::string id1 = this->nazwisko + this->imie;
		std::string id2 = d.nazwisko + d.imie;
		return id1 < id2;
	}
	DochodJednostkowy(std::string i, std::string n, std::string d, double k) : imie(i), nazwisko(n), data(d), kwota(k) {};
	/*std::ostream & operator<< (std::ostream &out) const {
		return out << nazwisko << " " << imie << "\tData: " << data << "\tKwota: " << kwota;
	}*/
	//friend std::ostream &operator<<(std::ostream &out, const DochodJednostkowy  & d);
};

/*std::ostream &operator<<(std::ostream &out, DochodJednostkowy const & d) {
	return out << d.nazwisko << " " << d.imie << "\tData: " << d.data << "\tKwota: " << d.kwota;
}*/
#endif // !DOCHOD_JEDNOSTKOWY