#include "GenerowanieGrafu.h"


using namespace std;
GenerowanieGrafu::GenerowanieGrafu(int p_rozmiar)
{
    rozmiarGrafu = p_rozmiar;
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

    cout << "rozmiarGrafu=" << rozmiarGrafu << endl;
    for(int i = 0; i < rozmiarGrafu - 1; i++)
    {
        macierzSas[i][i + 1] = 1;
    }

    // ostatni element wskazuje na element zerowy - tworzy sie petla
    macierzSas[rozmiarGrafu - 1][0] = 1;

    // ustalenie skoku do przeciecia grafu
    int skok = 0;
    if(rozmiarGrafu > 10000)
        skok = 150;
    if(rozmiarGrafu > 1000)
        skok = 90;
    if(rozmiarGrafu > 50)
        skok = 10;
    else
        skok = -1;

    for(int i = 1; i < (rozmiarGrafu/skok); i++)
    {
        macierzSas[(int) i * skok] [(int) i * skok + 1] = 0;
        macierzSas[(int) i * skok] [0]                  = 1;
        macierzSas[0]              [(int) i * skok + 1] = 1;
    }

    cout << "wspolczynnik nasycenia poczatkowy: " << (double) ((double)liczbaKrawedziMacierzSas() * 2 * 100) / (rozmiarGrafu * rozmiarGrafu)  << " %" << endl;

    // uzupelnienie grafu do wspolczynnika nasycenia 50% ( dzielenie przez 4, poniewa¿ jedno poloczenie zawiera w sobie dwa - w jedna i druga strone)
    int doUzup = (int) (rozmiarGrafu * rozmiarGrafu / 4 - liczbaKrawedziMacierzSas());

    uniform_int_distribution<int> distribution(0, rozmiarGrafu - 1);
    mt19937 engine;

    for(int i = 0; i < doUzup; i++)
    {
        int l1 = distribution(engine);
        int l2 = distribution(engine);

        while(true)
        {
            // graf nie moze byc multigrafem
            // - nie moze istniec juz to polaczenie
            // - nie moze istniec polaczenie przeciwne
            // - nie moze odwolywac sie sam do siebie
            if(macierzSas[l1][l2] != 1 && macierzSas[l2][l1] != 1 && l1 != l2 )
            {
                macierzSas[l1][l2] = 1;
                break;
            }
            else
            {
                l1 = distribution(engine);
                l2 = distribution(engine);
            }
        }

    }
    cout.setf( ios::showpoint );
    cout << "wspolczynnik nasycenia koncowy: " << (double) ((double)liczbaKrawedziMacierzSas() * 2 * 100) / (rozmiarGrafu * rozmiarGrafu)  << " %" << endl;
}

void GenerowanieGrafu::ustawRozmiarMacierzSas()
{
    macierzSas = new int*[rozmiarGrafu];
    for(int i = 0; i < rozmiarGrafu; ++i)
    {
        macierzSas[i] = new int[rozmiarGrafu];
    }

}

void GenerowanieGrafu::usunMacierzSas()
{

    if(macierzSas != NULL)
    {

        for(int i = 0; i < rozmiarGrafu; i++)
        {
            delete macierzSas[i];
        }
        delete macierzSas;
        macierzSas = NULL;
    }


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

    // int licz = 0;
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

    // int licz = 0;
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

int GenerowanieGrafu::liczbaKrawedziMacierzSas()
{
    int liczbaKrawedzi = 0;
    for(int i = 0; i < rozmiarGrafu; i++)
        for(int j = 0; j < rozmiarGrafu; j++)
                liczbaKrawedzi = liczbaKrawedzi + macierzSas[i][j];

    return liczbaKrawedzi;
}
