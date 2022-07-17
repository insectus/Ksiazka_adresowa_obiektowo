#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Adresat.h"
#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"
#include "Uzytkownik.h"

using namespace std;

class AdresatMenedzer {

    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;
    vector <Adresat> adresaci;

    int pobierzIdNowegoAdresata();
    PlikZAdresatami plikZAdresatami;
    Uzytkownik uzytkownik;
    Adresat podajDaneNowegoAdresata();


public:
    AdresatMenedzer(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami){
        adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
    };
    void dodajAdresata();
    void wypiszWszystkichAdresatow();
    void ustawIdZalogowanegoUzytkownika(int noweId);
};

#endif
