#include "GenerowanieGrafu.h"

GenerowanieGrafu::GenerowanieGrafu(int rozmiar)
{
    macierzSas = new int *[rozmiar];
    for ( int i = 0; i < rozmiar; ++i )
    {
        macierzSas[i] = new int [rozmiar];
    }
    listaNast = new int[rozmiar];
}

GenerowanieGrafu::~GenerowanieGrafu()
{
    for ( int i(0); i < w; ++i )
        delete [] macierzSas[i];
    delete [] macierzSas;
    macierzSas = NULL;
    delete [] listaNast;
}



