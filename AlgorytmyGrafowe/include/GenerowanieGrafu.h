#ifndef GENEROWANIEGRAFU_H
#define GENEROWANIEGRAFU_H

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>    // std::random_shuffle
#include <random>

using namespace std;

class GenerowanieGrafu
{
public:
    GenerowanieGrafu(int rozmiar);
    virtual ~GenerowanieGrafu();
    int dajRozmiarGrafu();
    void drukujMacierzSas();
    void drukujListaNast();
    void generujGraf();
    void drukujMacierzSasJedynki();
protected:
private:
    bool ** macierzSas;
    vector< vector<int> > listaNast;
    int rozmiarGrafu;
    void zerujMacierzSas();
    void ustawRozmiarMacierzSas();
    void usunMacierzSas();
    void usunListaNast();
    void ustawRozmiarListaNast();
    int liczbaKrawedziMacierzSas();
    void generujGrafMacierzSas();
    void generujGrafListaNast();

};

#endif // GENEROWANIEGRAFU_H
