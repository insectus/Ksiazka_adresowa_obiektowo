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

    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    int idOstatniegoAdresata;
    vector <Adresat> adresaci;

    PlikZAdresatami plikZAdresatami;
    Adresat podajDaneNowegoAdresata();

public:
    AdresatMenedzer(string NAZWA_PLIKU_Z_ADRESATAMI, int idZalogowanegoUzytkownika)
    : plikZAdresatami(NAZWA_PLIKU_Z_ADRESATAMI), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika){
        adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };

    void dodajAdresata();
    void wypiszWszystkichAdresatow();
};

#endif
