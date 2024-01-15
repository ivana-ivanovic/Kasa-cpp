#pragma once
#include "Racun.h"
class Kasa
{
private:
	Artikal* sviArtikli = new Artikal[100];
	Racun* sviRacuni = new Racun[100];
	int brRacuna;
	int brArtikla;

public:
	Kasa() {};
	Racun* getSviRacuni();
	Artikal* getSviArtikli();

	void platiRacun(Racun r);
	void dnevniIzvestaj();
	void presekStanja();
	Racun najveciRacun();
	double prosecanRacun();
	void dodajRacun(Racun r);
	void obrisiRacun(Racun r);
	void dodajArtikal(Artikal a);
	void obrisiArtikal(int a);
	int getBrRacuna();
	int getBrArtikla();
	void ispisSvihArtikla();


};

