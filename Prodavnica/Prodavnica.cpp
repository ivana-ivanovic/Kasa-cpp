

#include <iostream>
#include "Racun.h"
#include "Kasa.h"
#include <iomanip>


void racunF(Kasa* k) {
    int s; double f;
    Stavka stavka;
    Racun racun;
    cout << "******************************" << endl;
    cout << "   :0: za kraj racuna" << endl;
    while (true) {
        cout << "Unesite sifru artikla:" << endl;
        cin >> s;
        if (s == 0) {
            break;
        }
        cout << "Unesite kolicinu:" << endl;
        cin >> f;
        
        for (int i = 0; i < k->getBrArtikla(); i++) {
            if (k->getSviArtikli()[i].isEqual(s)) {               
                stavka = Stavka(k->getSviArtikli()[i], f);
                racun.dodajStavku(stavka);
                break;
            } 
        }
    };
    cout << "******************************" << endl;

    racun.ispisi();


    cout << "******************************" << endl;
    cout << "Izaberite opciju:" << endl;
    cout << "1. Naplata" << endl;
    cout << "2. Brisanje racuna" << endl;
    cout << "******************************" << endl;

    cin >> s;
    switch (s) {
    case 1:
        k->platiRacun(racun);
        cout << "Racun je placen." << endl;
        k->dodajRacun(racun);
        break;
    case 2:
        k->obrisiRacun(racun);
        cout << "Racun je obrisan." << endl;
        break;

    }


}

void izmenaArtikla(Kasa* k) {
    int s;
    Artikal a;
    cout << "******************************" << endl;
    cout << "Izaberite opciju:" << endl;
    cout << "1. Unos novog artikla" << endl;
    cout << "2. Brisanje artikla" << endl;
    cout << "3. Ispis artikla" << endl;
    cout << "******************************" << endl;
    cin >> s;
    string naziv;
    switch (s) {
    case 1:
        int sifra;  double cena; int tip;
        cout << "Unesite sifru artikla:" << endl;
        cin >> sifra;
        a.setSifra(sifra);
        cout << "Unesite naziv artikla:" << endl;
        cin >> naziv;
        a.setNaziv(naziv);
        cout << "Unesite cenu artikla:" << endl;
        cin >> cena;
        a.setCena(cena);
        cout << "Unesite tip artikla:" << endl;
        cout << "1. Mlecni Proizvod" << endl;
        cout << "2. Meso" << endl;
        cout << "3. Voce" << endl;
        cout << "4. Pecivo" << endl;
        cout << "5. Pice" << endl;
        cout << "6. Hrana" << endl;
        cin >> tip;
        switch (tip) {
        case 1:
            a.setTip(MlecniProizvod);
            break;
        case 2:
            a.setTip(Meso);
            break;
        case 3:
            a.setTip(Voce);
            break;
        case 4:
            a.setTip(Pecivo);
            break;
        case 5:
            a.setTip(Pice);
            break;
        case 6:
            a.setTip(Hrana);
            break;
        }

        k->dodajArtikal(a);
        cout << "Artikal je dodat." << endl;
        break;
    case 2:
        cout << "Unesite sifru artikla za brisanje:";
        int sif;
        cin >> sif;
        k->obrisiArtikal(sif);
        cout << "Artikal je obrisan." << endl;
        break;
    case 3:
        k->ispisSvihArtikla();
    }
}

void max(Kasa*  k) {
    Racun r = k->najveciRacun();
    double d = r.zaNaplatu();
    r.ispisi();
    cout << "Najveci iznos na racunu:" << setw(6) << setprecision(3) << d << endl;
}

void prosek(Kasa* k) {
    double r = k->prosecanRacun();
    cout << "Prosek racuna:" << setw(16) << setprecision(3) << r << endl;
    
}




int main()
{
    Kasa* k = new Kasa();
    Racun r;
    Artikal a1 = Artikal(1, "Hleb", 31.0, Pecivo);
    Artikal a2 = Artikal(2, "Mleko", 50.0, MlecniProizvod);
    Artikal a3 = Artikal(3, "Jogurt", 80.0, MlecniProizvod);
    Artikal a4 = Artikal(4, "Pivo", 50.0, Pice);
    Artikal a5 = Artikal(5, "Banane", 100.0, Voce);
    Artikal a6 = Artikal(6, "Jaja", 1.1234, Voce);

    
    k->dodajArtikal(a1);
    k->dodajArtikal(a2);
    k->dodajArtikal(a3);
    k->dodajArtikal(a4);
    k->dodajArtikal(a5);
    k->dodajArtikal(a6);

    Stavka s1 = Stavka(a1, 5.0);
    
    while (true) {
        cout << "******************************" << endl;
        cout << "Izaberite opciju:" << endl;
        cout << "1. Racun" << endl;
        cout << "2. Presek stanja" << endl;
        cout << "3. Dnevni izvestaj" << endl;
        cout << "4. Izmena artikla" << endl;
        cout << "5. Maksimalni racun" << endl;
        cout << "6. Prosek racuna" << endl;
        cout << "7. Izlaz" << endl;
        cout << "******************************" << endl;
        int c;
        cin >> c;

        switch (c) {
        case 1:
            racunF(k);
            break;
        case 2:
            k->presekStanja();
            break;
        case 3:
            k->dnevniIzvestaj();
            return 0;
            break;
        case 4:
            izmenaArtikla(k);
            break;
        case 5:
            max(k);
            break;
        case 6:
            prosek(k);
            break;
        case 7:
            return 0;
        }
    }
}


