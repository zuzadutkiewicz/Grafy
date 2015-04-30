#include <iostream>
#include <GenerowanieGrafu.h>
using namespace std;

int main()
{
    GenerowanieGrafu generGraf = GenerowanieGrafu(1000);
    // generGraf.drukujMacierzSas();
    cout << "Poczatek generowania grafu" << endl;
    generGraf.generujGraf();
    cout << "Koniec generowania grafu " << endl;
    // generGraf.drukujMacierzSasJedynki();

    return 0;
}
