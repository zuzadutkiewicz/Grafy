#include <iostream>
#include <GenerowanieGrafu.h>
using namespace std;

int main()
{
    GenerowanieGrafu generGraf = GenerowanieGrafu(44);
    // generGraf.drukujMacierzSas();
    generGraf.generujGraf();
    generGraf.drukujMacierzSasJedynki();

    return 0;
}
