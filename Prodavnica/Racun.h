#pragma once
#include "Stavka.h"
class Racun
{
private:
	Stavka * racun = new Stavka[100];
	int brStavki = 0;

public:

	Racun() {};

	void dodajStavku(Stavka stavka);
	void oduzmiStavku(Stavka stavka);
	void ispisi();
	Stavka * getRacun();
	int getBrStavki();
	double zaNaplatu();
	double pdv();
	bool toCompare(double max);
};

