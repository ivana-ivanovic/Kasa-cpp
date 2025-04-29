#include "Racun.h"
#include <iostream>

void Racun::dodajStavku(Stavka stavka) {
	bool postoji = false;
	for (int i = 0; i < this->brStavki; i++)	{
		if (this->getRacun()[i].isEqual(stavka)) {
			this->getRacun()[i].setKolicina(
				this->getRacun()[i].getKolicina() + stavka.getKolicina());
			postoji = true;
		}
	}
	if (!postoji) {
		this->racun[this->brStavki++] = stavka;
	}
}
void Racun::oduzmiStavku(Stavka stavka) {
	for (int i = 0; i < this->brStavki; i++)	{
		if (this->racun[i].isEqual(stavka)) {
			for (int j = i; j < this->brStavki; j++)			{
				this->racun[j] = this->racun[j + 1];
			}
			this->racun[this->brStavki-1] = Stavka();
			this->brStavki-- ;
		}
	}
}
void Racun::ispisi() {
	cout << "******************************" << endl;
	cout << "Racun stampa:" << endl;
	for (int i = 0; i < this->brStavki; i++)	{
		this->racun[i].ispisi();
	}
	cout << "******************************" << endl;
}
Stavka * Racun::getRacun() {
	return this->racun;
}
double Racun::zaNaplatu() {
	double suma = 0.0;
	for (int i = 0; i < this->brStavki; i++)	{
		suma = suma + this->racun[i].cenaStavke();
	}
	return suma;
}
double Racun::pdv() {
	return this->zaNaplatu() * 0.2;
}

bool Racun::toCompare(double max) {
	if (max < this->zaNaplatu()) {
		return true;
	}
	else {
		return false;
	}
}
int Racun::getBrStavki() {
	return this->brStavki;
}


