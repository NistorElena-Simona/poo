#include "Nivel.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "console_text.h"

Nivel::Nivel()
{
    for (int i = 0; i < 100; i++)
    {
        this->litereGhicie[i] = 1;
    }

}


Nivel::~Nivel()
{
    //dtor
}


// Afiseaza spanzuratoareas
void Nivel::AfisareSpanzuratoare()
{

    switch(this->numarLitereAleseGresit)
    {
    case 0:
        cout<<"##############################\n"
            "#   #                        #\n"
            "#  #                         #\n"
            "# #                           \n"
            "#                             \n"
            "#                             \n"
            "#                             \n"
            "#                             \n"
            "#                             \n"
            "#                             \n"
            "###########                   \n";
        break;

    case 1:
        cout<<"##############################\n"
            "#   #                      #\n"
            "#  #                       #\n"
            "# #                       ###\n"
            "#                         ###\n"
            "#                         ###\n"
            "#                           \n"
            "#                           \n"
            "#                           \n"
            "#                           \n"
            "###########                 \n";
        break;

    case 2:
        cout<<"##############################\n"
            "#   #                      #\n"
            "#  #                       #\n"
            "# #                       ###\n"
            "#                         ###\n"
            "#                         ###\n"
            "#                          #  \n"
            "#                          # \n"
            "#                          #  \n"
            "#                           \n"
            "###########                 \n";
        break;

    case 3:
        cout<<"##############################\n"
            "#   #                      #\n"
            "#  #                       #\n"
            "# #                       ###\n"
            "#                         ###\n"
            "#                         ###\n"
            "#                          #  \n"
            "#                          # \n"
            "#                          #  \n"
            "#                        #   \n"
            "###########             #    \n";
        break;

    case 4:
        cout<<"##############################\n"
            "#   #                      #\n"
            "#  #                       #\n"
            "# #                       ###\n"
            "#                         ###\n"
            "#                         ###\n"
            "#                          #  \n"
            "#                          # \n"
            "#                          #  \n"
            "#                        #   #\n"
            "###########             #     #\n";
        break;

    case 5:
        cout<<"##############################\n"
            "#   #                      #\n"
            "#  #                       #\n"
            "# #                       ###\n"
            "#                         ###\n"
            "#                         ###\n"
            "#                      #   #  \n"
            "#                        # # \n"
            "#                          #  \n"
            "#                        #   #\n"
            "###########             #     #\n";
        break;

    case 6:
        cout<<"##############################\n"
            "#   #                      #\n"
            "#  #                       #\n"
            "# #                       ###\n"
            "#                         ###\n"
            "#                         ###\n"
            "#                      #   #   #\n"
            "#                        # # #\n"
            "#                          #  \n"
            "#                        #   #\n"
            "#                       #     #\n"
            "#                               \n"
            "#                                \n"
            "###########                       \n";
        break;

    }

}


// Afiseaza cuvantul si descriptia acestuia
void Nivel::AfisareCuvant()
{
    cout << "Cuvantul: ";

    for(int i = 0; i < this->cuvantCurent.length(); i++)
    {
        // In matricea de litere ghicite, 1 inseamna litera ghicita, si 0 ne-ghicita
        if (this->litereGhicie[i] == 1)
        {
            cout << this->cuvantCurent[i];
        }

        // Daca litera nu este ghicita, afiseaza un spatiu gol
        else
        {
            cout << "_";
        }

        cout << " ";
    }
    cout << "\n";
    cout << "Descriptie: " << this->descriptieCuvantCurent << "\n";
}


// Alege un cuvant la intamplare din fiserele cu cuvinte
void Nivel::AlegereCuvantRandom(int nrNivel)
{
    // Creem numele fisierului in functie de ce nivel suntem
    // Exemplu, nivelul 1 trebuie sa aiba cuvinte de 3 litere
    string filename = "cuvinte/cuvinte_" + std::to_string(nrNivel + 2) + "_litere.txt";

    std::ifstream file(filename);

    // Daca este vreo problema, iesi din program
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file " << filename << std::endl;
        exit(1);
    }

    // Citeste toate liniile din fisier, dupa alege un index random si ia cuvantul de la acea linie
    std::vector<std::string> lines;
    std::string line;

    while (std::getline(file, line))
    {
        lines.push_back(line);
    }

    std::srand(std::time(nullptr)); // alege un seed

    int random_index = std::rand() % lines.size(); // pick a random index

    string linieFisier = lines[random_index];

    std::string word, description;

    // Extrage cuvantul si descriptia din fisier
    // find the position of the first space character
    size_t space_pos = linieFisier.find(" ");

    this->cuvantCurent = linieFisier.substr(0, space_pos);
    this->descriptieCuvantCurent = linieFisier.substr(space_pos + 1);

    // Curata vectorul cu liter ghicite
    for (int i = 0; i < 100; i++)
    {
        this->litereGhicie[i] = 0;
    }
}


// Returneaza true daca utilizatorul a ghicit tot cuvanul corect
bool Nivel::IsWordCompleted()
{
    for (int i = 0; i < this->cuvantCurent.length(); i++)
    {
        if(this->litereGhicie[i] == 0)
            return false;
    }

    return true;
}


// Reseteaza numarul de litere alese gresit
void Nivel::ResetNrGreseli()
{
    this->numarLitereAleseGresit = 0;
    this->litereAleseCurrent.clear();
}

// Seteaza numerul nivelului
void Nivel::SetNrNivel(int numar)
{
    this->numarNivel = numar;
}



// Afiseaza informatii despre nivelul curent
void Nivel::AfiseazInfoNivel()
{
    cout << BLUE << char(1) << " Nivelul " << this->numarNivel << RESET << endl;
    cout << RED << CHAR_INIMA << " Vieti: " << 6 - this->numarLitereAleseGresit << RESET << "\n";
    cout << YELLOW << "> Litere alese: ";

    for(auto letter : this->litereAleseCurrent)
    {
        cout << letter << ", ";
    }
    cout << RESET << endl << endl;


}


// Citeste o litera de la tasaura, si veifica daca este in cuvant
void Nivel::HandleInput()
{
    char letter;

    cout << "\nAlegeti o litera: ";

    while(true)
    {
        cin >> letter;

        if (std::find(this->litereAleseCurrent.begin(),
                       this->litereAleseCurrent.end(),
                       letter) != this->litereAleseCurrent.end())
        {
            std::cout << "Ai ales deja acea literea! Alege alta!\n> ";
            continue;
        }
        break;
    }

    this->litereAleseCurrent.push_back(letter);

    bool celPutinUna = false;

    for(int i = 0; i < this->cuvantCurent.length(); i++)
    {
        if (this->cuvantCurent[i] == letter)
        {
            this->litereGhicie[i] = 1;
            celPutinUna = true;
        }
    }

    if (!celPutinUna)
        this->numarLitereAleseGresit++;
}

void Nivel::HandleWinning()
{
    cout << "\nAi ghicit cuvantul!!!\nApasa o tasta pentru a reveni la meniu.";

    string _;

    cin >> _;
}


void Nivel::HandleLosing()
{
    cout << "\nAi pierdut nivelul :(" << endl;
    cout << "Cuvanul era: " << this->cuvantCurent << endl;
    cout << "Apasa o tasta pentru a reveni la meniu." << endl;

    string _;

    cin >> _;
}


// Decide daca jucatorul a pierdu nivelul
bool Nivel::PlayerLost()
{
    return this->numarLitereAleseGresit >= 6 ? true : false;
}

