#include "GenerowanieGrafu.h"
#include <vector>

using namespace std;
GenerowanieGrafu::GenerowanieGrafu(int p_rozmiar)
{
    rozmiarGrafu = p_rozmiar;
    liczbaPaczek = 3;
    ustawRozmiarMacierzSas();
    zerujMacierzSas();
    ustawRozmiarListaNast();
}

GenerowanieGrafu::~GenerowanieGrafu()
{
}

int GenerowanieGrafu::dajRozmiarGrafu()
{
    return this->rozmiarGrafu;
}

void GenerowanieGrafu::generujGraf()
{
    int rozmiarPaczki = (int) rozmiarGrafu / liczbaPaczek;
    int przesun = 0;

    cout << "rozmiarGrafu=" << rozmiarGrafu << endl;
    cout << "rozmiarPaczki=" << rozmiarPaczki << endl;

    for(int i = 0; i < rozmiarPaczki; i++)
        macierzSas[0][i + przesun * rozmiarPaczki + 1] = 1;

    while(true)
    {
        int rozmiarPrzesun = 0;
        przesun++;
        if((przesun + 1) * rozmiarPaczki < rozmiarGrafu)
            rozmiarPrzesun = rozmiarPaczki;
        else
        {
            rozmiarPrzesun = rozmiarPaczki - (przesun * rozmiarPaczki - rozmiarGrafu);
        }

        cout << "przesun * rozmiarPaczki=" << przesun * rozmiarPaczki << endl;
        cout << "rozmiarPrzesun=" << rozmiarPrzesun << endl;
        for(int i = 0; i < rozmiarPrzesun; i++)
        {
            macierzSas[i+ (przesun - 1)*rozmiarPaczki + 1][i + przesun*rozmiarPaczki + 1] = 1;
        }

        if((przesun + 1) * rozmiarPaczki < rozmiarGrafu)
            break;
    }
}

void GenerowanieGrafu::ustawRozmiarMacierzSas()
{
    macierzSas.resize(rozmiarGrafu);
    for(int i = 0; i < rozmiarGrafu; i++)
        macierzSas[i].resize(rozmiarGrafu);
}

void GenerowanieGrafu::ustawRozmiarListaNast()
{
    listaNast.resize(rozmiarGrafu);

}

void GenerowanieGrafu::zerujMacierzSas()
{
    for(int i = 0; i < rozmiarGrafu; i++)
        for(int j = 0; j < rozmiarGrafu; j++)
            macierzSas[i][j] = 0;
}


void GenerowanieGrafu::drukujMacierzSas()
{

    int licz = 0;
    // for(int i = 0; i < rozmiarGrafu; i++)
    //    for(int j = 0; j < rozmiarGrafu; j++)
    //        macierzSas[i][j] = licz++;

    // random_shuffle ( macierzSas[0].begin(), macierzSas[0].end() );
    cout << "Rozmiar grafu: " << dajRozmiarGrafu() << endl;
    for(int i = 0; i < rozmiarGrafu; i++)
        for(int j = 0; j < rozmiarGrafu; j++)
            cout << "macierzSas[" << i << "][" << j << "]=" << macierzSas[i][j] << endl;

}

void GenerowanieGrafu::drukujMacierzSasJedynki()
{

    int licz = 0;
    // for(int i = 0; i < rozmiarGrafu; i++)
    //    for(int j = 0; j < rozmiarGrafu; j++)
    //        macierzSas[i][j] = licz++;

    // random_shuffle ( macierzSas[0].begin(), macierzSas[0].end() );
    cout << "Rozmiar grafu: " << dajRozmiarGrafu() << endl;
    for(int i = 0; i < rozmiarGrafu; i++)
        for(int j = 0; j < rozmiarGrafu; j++)
            if(macierzSas[i][j] == 1)
                cout << "macierzSas[" << i << "][" << j << "]=" << macierzSas[i][j] << endl;

}
