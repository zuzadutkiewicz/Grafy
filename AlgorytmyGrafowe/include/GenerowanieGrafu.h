#ifndef GENEROWANIEGRAFU_H
#define GENEROWANIEGRAFU_H


class GenerowanieGrafu
{
    public:
        GenerowanieGrafu(int rozmiar);
        virtual ~GenerowanieGrafu();
    protected:
    private:
        int **macierzSas;
        int *listaNast;
};

#endif // GENEROWANIEGRAFU_H
