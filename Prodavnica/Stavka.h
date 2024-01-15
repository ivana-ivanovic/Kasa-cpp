#pragma once
#include "Artikal.h"
class Stavka :
	public Artikal
{
private:
	double kolicina;

public:
	Stavka() {};
	//Stavka(int sifra, string naziv, double cena, TipArtikla tip, float kolicna);
	Stavka(Artikal artikal, double kolicna);

	double getKolicina();
	void setKolicina(double kolicina);
	void ispisi();
	bool isEqual(Stavka s);
	double cenaStavke();
	string toString();
};