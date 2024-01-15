#pragma once
#include <string>
using namespace std;
enum TipArtikla { MlecniProizvod, Meso, Voce, Pecivo, Pice, Hrana };

class Artikal
{
	private: 
		int sifra; 
		string naziv;
		double cena;
		TipArtikla tip;

	public:
		Artikal() {};
		Artikal(int sifra,	string naziv, double cena,    TipArtikla tip);
		void ispisi();


		void setSifra(int sifra);
		int getSifra();
		void setNaziv(string naziv);
		string getNaziv();
		void setCena(double cena);
		double getCena();
		void setTip(TipArtikla tip);
		TipArtikla getTip();
		bool isEqual(int sifra);
		string toString();



};

