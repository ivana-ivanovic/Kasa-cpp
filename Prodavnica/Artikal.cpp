#include "Artikal.h"
#include <iostream>
#include <iomanip>

Artikal::Artikal(int sifra, string naziv, double cena, TipArtikla tip) {
	this->sifra = sifra;
	this->naziv = naziv;
	this->cena = cena;
	this->tip = tip;
}

int Artikal::getSifra() {
	return this->sifra;
}
string Artikal::getNaziv() {
	return this->naziv;
}
double Artikal::getCena() {
	return this->cena;
}
TipArtikla Artikal::getTip() {
	return this->tip;
}
void Artikal::setSifra(int sifra) {
	this->sifra = sifra;
}
void Artikal::setNaziv(string naziv) {
	this->naziv = naziv;
}
void Artikal::setCena(double cena) {
	this->cena = cena;
}
void Artikal::setTip(TipArtikla tip) {
	this->tip = tip;
}
void Artikal::ispisi() {
	cout << setw(5) << this->getSifra() << setw(10) << this->naziv << setw(8) << setprecision(3) << this->getCena() << setw(7) << this->getTip ()<< endl;
}
bool Artikal::isEqual(int sifra) {
	if (sifra == this->getSifra()) {
		return true;
	}
	else {
		return false;
	}
}

string Artikal::toString() {
	char nizChar[31];
	int n;
	n = sprintf_s(nizChar, "%2d. %-15s%11.2f", this->getSifra(), this->getNaziv().c_str(), this->getCena());
	string s = nizChar;
	return s;
}