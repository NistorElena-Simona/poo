#include "Cuvant.h"
#include <iostream>
#include <string.h>
using std::cout;


Cuvant::Cuvant()
{

}

Cuvant::~Cuvant()
{
    //dtor
}
void Cuvant::afisare_cuv()
{
    for(int i=0; this->word[i]; i++)
    {
        if (this->ghicire[i]==1)
        {
            cout<<this->word[i];
        }
        else
        {
            cout<<"_";

        }
    }
}
void Cuvant::seteaza_cuv(char *cuv)
{
    strcpy(this->word, cuv);
}
char Cuvant::operator[] (int index)
{

    return this->word[index];

}
void Cuvant::seteaza_nr_poz(int pozitia,int valoare)
{
     this->ghicire[pozitia]=valoare;
}
