#include "Kasa.h"
#include <iostream>
#include <iomanip>
#include <ctime>

Racun* Kasa::getSviRacuni() {
	return this->sviRacuni;
}
Artikal* Kasa::getSviArtikli() {
	return this->sviArtikli;
}

void Kasa::platiRacun(Racun r) {
	double a;
	cout << "Za naplatu: " << setw(18) << setprecision(3) << r.zaNaplatu() << endl;
	cout << "Iznos:  " << endl;
	cin >> a;
	a = a - r.zaNaplatu();
	cout << "Povracaj: " << setw(20) << setprecision(3) << a << endl;
}
void Kasa::dnevniIzvestaj() {
	cout << "******************************" << endl;
	cout << "Dnevni izvestaj: " << endl;
	double suma = 0;
	for (int i = 0; i < this->brRacuna; i++)	{
		cout << "Racun " << setw(3) << i+1 << setw(21) << setprecision(3) << this->sviRacuni[i].zaNaplatu() << endl;
		suma = suma + this->sviRacuni[i].zaNaplatu();
	}
	cout << "Zaradjeno: " << setw(19) << suma << endl;
	cout << "PDV: " << setw(25) << suma*0.2 << endl;
	cout << "******************************" << endl;
}
void Kasa::presekStanja() {
	cout << "******************************" << endl;
	cout << "Presek stanja: " << endl;

	double suma = 0;
	for (int i = 0; i < this->brRacuna; i++) {
		cout << "Racun " << setw(3) << i + 1 << setw(21) << setprecision(3) << this->sviRacuni[i].zaNaplatu() << endl;
		suma = suma + this->sviRacuni[i].zaNaplatu();
	}
	cout << "Zaradjeno: " << setw(19) << suma << endl;
	cout << "PDV: " << setw(25) << suma * 0.2 << endl;
	cout << "******************************" << endl;
	
}
Racun Kasa::najveciRacun() {
	cout << "Najveci racun: " << endl;
	double max = this->sviRacuni[0].zaNaplatu();
	int j = 0;
	for (int i = 1; i < this->brRacuna; i++) {
		if (this->sviRacuni[i].toCompare(max)) {
			max = this->sviRacuni[i].zaNaplatu();
			j = i;
		}
	}
	return this->sviRacuni[j];
}
double Kasa::prosecanRacun() {
	double prosek = 0;
	for (int i = 0; i < this->brRacuna; i++) {
		prosek = prosek + this->sviRacuni[i].zaNaplatu();
	}
	prosek = prosek / this->brRacuna;
	return prosek;
}
void Kasa::dodajRacun(Racun r) {
	this->sviRacuni[this->brRacuna++] = r;
}
void Kasa::obrisiRacun(Racun r) {
	this->sviRacuni[this->brRacuna-1] = Racun();
	this->brRacuna--;
}
void Kasa::dodajArtikal(Artikal a) {
	this->sviArtikli[this->brArtikla++] = a;
}
void Kasa::obrisiArtikal(int a) {
	for (int i = 0; i < this->brArtikla; i++) {
		if (this->sviArtikli[i].isEqual(a)) {
			for (int j = i; j < this->brArtikla; j++) {
				this->sviArtikli[j] = this->sviArtikli[j + 1];
			}
			this->sviArtikli[this->brArtikla-1] = Artikal();
			this->brArtikla--;
		}
	}
}
int Kasa::getBrRacuna() {
	return this->brRacuna;
}
int Kasa::getBrArtikla() {
	return this->brArtikla;
}
void Kasa::ispisSvihArtikla() {
	cout << "******************************" << endl;
	cout << "Artikli u bazi:" << endl;
	cout << "Sifra|    Naziv|   Cena|   Tip" << endl;
	for (int i = 0; i < this->brArtikla; i++)	{
		this->sviArtikli[i].ispisi();
	}
	cout << "******************************" << endl;
}