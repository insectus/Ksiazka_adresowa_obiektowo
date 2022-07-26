#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika(){
    uzytkownikMenedzer.logowanieUzytkownika();
    int noweId = uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika();
    adresatMenedzer.ustawIdZalogowanegoUzytkownika(noweId);

}

void KsiazkaAdresowa::wylogowanieUzytkownika(){
    uzytkownikMenedzer.wylogowanieUzytkownika();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika(){
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::dodajAdresata(){
    adresatMenedzer.dodajAdresata();
}


void KsiazkaAdresowa::wypiszWszystkichAdresatow(){
    adresatMenedzer.wypiszWszystkichAdresatow();
}

void KsiazkaAdresowa::wczytajWszystkichAdresatowZalogowanegoUzytkownika(){
    adresatMenedzer.wczytajAdresatow();
}
