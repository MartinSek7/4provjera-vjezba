#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

bool neg_broj(double broj)

{

    if(broj<0)

        return true;

    return false;

}


bool tekuci_racun(unsigned long long int broj)

{

    if(broj/100000000 == 32)

        return true;

    return false;

}


bool ispis_podataka(string prezime_i_ime[],

                    unsigned long long int br_racuna[],

                    double saldo[],

                    int br_klijenata,

                    string pretraga)

{

    int br = 0;

    for(int i = 0; i < br_klijenata; i++)

    {

        if(prezime_i_ime[i] == pretraga)

        {

            cout << br_racuna[i] << ", " << saldo[i] << endl;

            br++;

        }

    }

    if(br==0)

        return false;

    return true;

}

int main()
{
    int br_klijenata = 0;

    unsigned long long int *br_racuna = new unsigned long long int[1000];

    string *prezime_i_ime = new string[1000];

    double *saldo = new double[1000];

    int izbor;

    while(1)

    {

        system("cls");

        cout << "1.unos novog racuna" << endl;

        cout << "2.ispisi sve podatke" << endl;

        cout << "3.pretraga prema prezimenu i imenu" << endl;

        cout << "4.brisanje racuna" << endl;

        cout << "5.izmjena podataka prema broju racuna" << endl;

        cout << "6.ispisi sortirano po prezimenu i imenu" << endl;

        cout << "7.izlaz iz programa" << endl;

        cout << "Unesite broj opcije: ";

        cin >> izbor;

        cout << endl;

        if(izbor == 1)

        {

            unsigned long long unos;

            while(1)

            {

                try

                {

                    cout << "Unesite broj racuna: ";

                    cin >> unos;

                    if(unos < 1000000000 || unos > 9999999999)

                        throw "Broj racuna mora imati 10 znamenki";

                    break;

                }

                catch(const char* msg)

                {

                    cout << msg << endl;

                }

            }

            br_racuna[br_klijenata] = unos;

            cout << "Unesite prezime i ime: ";

            cin.ignore();

            getline(cin, prezime_i_ime[br_klijenata]);

            cout << "Unesite saldo: ";

            cin >> saldo[br_klijenata];

            br_klijenata++;

        }

        else if(izbor == 2)

        {

            for(int i = 0; i < br_klijenata; i++)

            {

                cout << br_racuna[i] << ", " << prezime_i_ime[i] << ", " << saldo[i] << "kn" << endl;

            }

            cout << "Suma svih salda iznosi " << accumulate(saldo, saldo+br_klijenata, 0.0) << "kn" << endl;

            int max_indeks = max_element(saldo, saldo+br_klijenata) - saldo;

            cout << "Klijent s najvecim saldom je " << prezime_i_ime[max_indeks] << endl;

            cout << "Broj racuna s negativnim saldom: " << count_if(saldo, saldo+br_klijenata, neg_broj) << endl;

            cout << "Broj tekucih racuna: " << count_if(br_racuna, br_racuna+br_klijenata, tekuci_racun) << endl;

        }

        else if(izbor == 3)

        {

            cout << "Unesite ime i prezime koje zelite pretraziti: " << endl;

            string pretraga;

            cin.ignore();

            getline(cin, pretraga);

            if(ispis_podataka(prezime_i_ime,br_racuna,saldo,br_klijenata,pretraga)==false)

            {

                cout << "Takvi klijenti ne postoje!" << endl;

            }

        }

        else if(izbor == 4)

        {

            unsigned long long int broj;

            cout << "Unesite broj racuna kojeg zelite izbrisati: ";

            cin >> broj;

            int i;

            for(i = 0; i < br_klijenata; i++)

            {

                if(br_racuna[i] == broj)

                {

                    for(int j = i; j < br_klijenata - 1; j++)

                    {

                        br_racuna[j] = br_racuna[j+1];

                        prezime_i_ime[j] = prezime_i_ime[j+1];

                        saldo[j] = saldo[j+1];

                    }

                    br_klijenata--;

                    break;

                }

            }

            if(i==br_klijenata)

                cout << "Trazeni racun ne postoji!" << endl;


        }

        else

        {

            cout << "Krivi unos!" << endl;

        }

        cout << endl;

        system("pause");

    }

    return 0;
}
