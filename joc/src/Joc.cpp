#include "Joc.h"
#include "Spanzura.h"
#include "Cuvant.h"
#include <iostream>
using std::cout;
using std::cin;
Joc::Joc() : spanzuratoarea(), cuvant()
{


}

Joc::~Joc()
{
    //dtor
}
void Joc::alege_litera()
{
    char litera_aleasa;
    int litera_era=0;
    cout<<"\n Alegeti litera:";
    cin>>litera_aleasa;
    for(int i=0; this->cuvant[i] ; i++)
    {


        if(this->cuvant[i]==litera_aleasa)
        {
            this->cuvant.seteaza_nr_poz(i,1);
            litera_era=1;
        }

    }
    if (litera_era ==0)
    {
        nr_greseli++;
    }
    system ("cls");
}
void Joc::start_joc()
{
    this->cuvant.seteaza_cuv("sternocleidomastodoidian");
    while (true)
    {
        this->spanzuratoarea.afiseaza_span(this->nr_greseli);
        this->cuvant.afisare_cuv();
        this->alege_litera();
    }
}
