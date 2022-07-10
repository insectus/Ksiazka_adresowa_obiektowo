#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Adresat.h"
#include "PlikZAdresatami.h"
#include "PlikZUzytkownikami.h"

using namespace std;

class AdresatMenedzer {

    int idOstatniegoAdresata;
    int idUsunietegoAdresata;
    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;
    //Adresat podajDaneNowegoAdresata()

public:
    AdresatMenedzer(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami){};
    int dodajAdresata();
    void wypiszWszystkichAdresatow();
    void wczytajAdresatowZPliku();
};

#endif
