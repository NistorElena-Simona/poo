#ifndef NIVEL_H
#define NIVEL_H
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//aceasta clasa va afisa spanzuratoarea cuvantul si decriptia acestuia si va citii literele introduse de utilizator
class Nivel
{
    private:
        vector<char> litereAleseCurrent;
        string cuvantCurent;
        string descriptieCuvantCurent;

        int numarNivel;
        int numarLitereAleseGresit;
        int litereGhicie[100]; // un vector cu numere, 0 = litera la intex nu e ghicita

    public:
        Nivel();
        virtual ~Nivel();
        void AfisareSpanzuratoare(); // Afiseaza spanzuratoareas
        void AfisareCuvant();  // Afiseaza cuvantul si descriptia acestuia
        void AfiseazInfoNivel(); // Afiseaza informatii despre nivelul curent

        void AlegereCuvantRandom(int nrNivel); // Alege un cuvant la intamplare din fiserele cu cuvinte
        bool IsWordCompleted(); // Returneaza true daca utilizatorul a ghicit tot cuvanul corect
        bool PlayerLost(); // Decide daca jucatorul a pierdu nivelul
        void ResetNrGreseli(); // Reseteaza numarul de litere alese gresit
        void SetNrNivel(int); // Seteaza numerul nivelului
        void HandleInput(); // Citeste o litera de la tasaura, si veifica daca este in cuvant
        void HandleWinning(); // Face ce se intampla cand castigi un nivel
        void HandleLosing(); // Face ce se intampla cand pierzi un nivel
};

#endif // NIVEL_H


