#ifndef JOC_H
#define JOC_H
#include "Spanzura.h"
#include "Cuvant.h"

class Joc
{
    Spanzura spanzuratoarea;
    Cuvant cuvant;
    int nr_greseli=0;
    public:
        Joc();
        virtual ~Joc();
        void alege_litera();
        void start_joc();

};

#endif // JOC_H
