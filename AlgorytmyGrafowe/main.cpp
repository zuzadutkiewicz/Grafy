#include <iostream>
#include <GenerowanieGrafu.h>
using namespace std;

int main()
{
    GenerowanieGrafu generGraf = GenerowanieGrafu(10000);
    // generGraf.drukujMacierzSas();
    cout << "Poczatek generowania grafu" << endl;
    generGraf.generujGraf();
    cout << "Koniec generowania grafu " << endl;
    generGraf.drukujMacierzSasJedynki();
    // generGraf.drukujMacierzSasJedynki();
    // generGraf.drukujListaNast();

    return 0;
}
