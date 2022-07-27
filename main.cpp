#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main() {
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt","Adresaci.txt");

    char wybor;
    while (true) {
        if(ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika()==0) {

            wybor = ksiazkaAdresowa.wybierzOpcjeZMenuGlownego();

            switch(wybor) {
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                ksiazkaAdresowa.logowanieUzytkownika();
                break;
            case '9':
                exit(0);
            default:
                cout << "\nNie ma takiej opcji w menu.\n\n";
                system("pause");
                break;
            }
        } else {

            wybor = ksiazkaAdresowa.wybierzOpcjeZMenuUzytkownika();

            switch(wybor) {
            case '1':
                ksiazkaAdresowa.dodajAdresata();
                break;
            case '2': //wyszukaj po imieniu
                ksiazkaAdresowa.wyszukajPoImieniu();
                break;
            case '3': //wyszukaj po nazwisku
                break;
            case '4':
                ksiazkaAdresowa.wypiszWszystkichAdresatow();
                break;
            case '5': // usun
                break;
            case '6': //edutyj
                break;
            case '7': //zmien haslo
                break;
            case '8':
                ksiazkaAdresowa.wylogowanieUzytkownika();
                break;
            }
        }
    }
    return 0;
}

/*
#include "AdresatMenedzer.h"
int main() {

    AdresatMenedzer adresatMenedzer("Adresaci.txt",1);
    adresatMenedzer.wypiszWszystkichAdresatow();
}
*/
