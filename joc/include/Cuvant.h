#ifndef CUVANT_H
#define CUVANT_H


class Cuvant
{
    char word[100];
    int ghicire[100];
    char alese[100];

    public:
        Cuvant();
        virtual ~Cuvant();
        void afisare_cuv();
        void seteaza_cuv(char *cuv);
        char operator[] (int index);
        void seteaza_nr_poz(int pozitia,int valoare);
};

#endif // CUVANT_H
