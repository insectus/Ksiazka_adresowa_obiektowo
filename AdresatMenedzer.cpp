#include "AdresatMenedzer.h"

void AdresatMenedzer::dodajAdresata() {
    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<\n\n";
    Adresat adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);

    plikZAdresatami.dopiszAdresataDoPliku(adresat);
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata() {
    Adresat adresat;

    adresat.ustawId(plikZAdresatami.pobierzIdOstatniegoAdresata() + 1);
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Podaj imie: ";
    adresat.ustawImie(MetodyPomocnicze::wczytajLinie());
    adresat.ustawImie(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzImie()));

    cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko(MetodyPomocnicze::wczytajLinie());
    adresat.ustawNazwisko(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzNazwisko()));

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres(MetodyPomocnicze::wczytajLinie());

    return adresat;
}

void AdresatMenedzer::wypiszWszystkichAdresatow() {
    if(!adresaci.empty()) {
        for (long long unsigned int i = 0; i < adresaci.size(); i++) {

            wyswietlDaneAdresata(adresaci[i]);

        }
    } else {
        cout << "\nKsiazka adresowa jest pusta.\n\n";
    }

    system("pause");
}

void AdresatMenedzer::wyszukajPoImieniu(){

    string imiePoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty()) {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        imiePoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        imiePoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imiePoszukiwanegoAdresata);

        for (long long unsigned int i = 0; i < adresaci.size(); i++) {
            if (imiePoszukiwanegoAdresata == adresaci[i].pobierzImie()) {
                wyswietlDaneAdresata(adresaci[i]);
                iloscAdresatow++;
            }
        }
        wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    } else {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AdresatMenedzer::wyszukajPoNazwisku(){

    string nazwiskoPoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty()) {
        cout << ">>> WYSZUKIWANIE ADRESATOW O NAZWISKU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o nazwisku: ";
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwiskoPoszukiwanegoAdresata);

        for (long long unsigned int i = 0; i < adresaci.size(); i++) {
            if (nazwiskoPoszukiwanegoAdresata == adresaci[i].pobierzNazwisko()) {
                wyswietlDaneAdresata(adresaci[i]);
                iloscAdresatow++;
            }
        }
        wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    } else {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat) {
    cout << "\nId: \t\t\t" << adresat.pobierzId() << endl;
    cout << "Id Uzytkownika: \t" << adresat.pobierzIdUzytkownika() << endl;
    cout << "Imie: \t\t\t" << adresat.pobierzImie() << endl;
    cout << "Nazwisko: \t\t" << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu: \t" << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email: \t\t\t" << adresat.pobierzEmail() << endl;
    cout << "Adres: \t\t\t" << adresat.pobierzAdres() << endl;
}

void AdresatMenedzer::wyswietlIloscWyszukanychAdresatow(int iloscAdresatow) {
    if (iloscAdresatow == 0)
        cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl;
    else
        cout << endl << "Ilosc adresatow w ksiazce adresowej wynosi: " << iloscAdresatow << endl << endl;
}
