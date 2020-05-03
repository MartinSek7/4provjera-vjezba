#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

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

                cout << "Unesite prezime i ime: " << endl;

                cin.ignore();

                getline(cin, prezime_i_ime[br_klijenata]);

                cout << "Unesite saldo: ";

                cin >> saldo[br_klijenata];

                br_klijenata++;

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
