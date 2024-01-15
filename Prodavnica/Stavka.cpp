#include "Stavka.h"
#include <iomanip>
#include <iostream>

Stavka::Stavka(Artikal artikal, double kolicina) : Artikal(artikal.getSifra(), artikal.getNaziv(), artikal.getCena(), artikal.getTip()) {
	this->kolicina = kolicina;
}

void Stavka::setKolicina(double kolicina) {
	this->kolicina = kolicina;
}

double Stavka::getKolicina() {
	return this->kolicina;
}

void Stavka::ispisi() {
	 cout << setw(10) << this->getNaziv() << setw(5) << setprecision(3) << this->getKolicina() << setw(15) << setprecision(3) << this->cenaStavke() << endl ;
}

double Stavka::cenaStavke() {
	return this->getCena() * this->getKolicina();
}

bool Stavka::isEqual(Stavka s) {
	if (this->getSifra() == s.getSifra()) {
		return true;
	} else {
		return false;
	}
}
string Stavka::toString() {
	char nizChar[31];
	int n;
	n = sprintf_s(nizChar, "%2d. %-15s%11.2f",this->getSifra(), this->getNaziv().c_str(), this->cenaStavke());
	string s = nizChar;
	return s;
}


