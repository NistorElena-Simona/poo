#ifndef MENIUNIVELE_H
#define MENIUNIVELE_H

///clasa asta va afisa harta cu nivele si va citi optiunea din mneiu a utilizatorului
class MeniuNivele
{


    public:
        MeniuNivele();
        virtual ~MeniuNivele();
        void AfisareMeniu(int nivelCurent);
        int CitireOptiuneTastatura();
        void ClearScreen();

};

#endif // MENIUNIVELE_H
