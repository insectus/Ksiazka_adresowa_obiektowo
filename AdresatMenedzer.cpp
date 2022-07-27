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

            cout << "Id: \t\t\t" << adresaci[i].pobierzId() << endl;
            cout << "Id Uzytkownika: \t" << adresaci[i].pobierzIdUzytkownika() << endl;
            cout << "Imie: \t\t\t" << adresaci[i].pobierzImie() << endl;
            cout << "Nazwisko: \t\t" << adresaci[i].pobierzNazwisko() << endl;
            cout << "Numer telefonu: \t" << adresaci[i].pobierzNumerTelefonu() << endl;
            cout << "Email: \t\t\t" << adresaci[i].pobierzEmail() << endl;
            cout << "Adres: \t\t\t" << adresaci[i].pobierzAdres() << endl << endl;
        }
    } else {
        cout << "\nKsiazka adresowa jest pusta.\n\n";
    }

    system("pause");
}
