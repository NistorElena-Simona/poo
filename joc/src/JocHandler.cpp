#include "JocHandler.h"
#include <iostream>
#include <fstream>


using namespace std;

// Constructor
JocHandler::JocHandler()
{
    this->meniu = MeniuNivele();
    this->nivelHandler = Nivel();
}

// Deconstrucotr, nu avem nimic de pus in el, deoarce nu alocam memorie dinamic
JocHandler::~JocHandler()
{
    //dtor
}


// Punctul de inrare in program
int JocHandler::Start()
{

    // Stocheaza optiune utilizatorului in meniu
    int optiuneMeniu = 0;

    string buffer;

    while(true) // ruleaza pana la alegerea optinii EXIT
    {
        this->meniu.AfisareMeniu(this->nivelCurent);

        optiuneMeniu = this->meniu.CitireOptiuneTastatura();

        // Verifica daca citirea de la tastatura a esuat
        if (std::cin.fail())
        {
            std::cout << "Optiune invalida. Va rugam sa introduceti un numar. Apasati orice pentru a continua." << std::endl;

            // Curatam eroarea (failbit-ul)
            std::cin.clear();

            // Ignora input-ul invalid
            std::cin.ignore(1000, '\n');

            // Citeste orice si curata ecranul
            cin >> buffer;
            this->meniu.ClearScreen();

            continue;
        }

        switch(optiuneMeniu)
        {
        case 1:
            this->PlayCurrentLevel();
            break;

        case 2:
            break;

        case 3:
            this->SaveStateToFile();
            break;


        case 4:
            this->LoadStateFromFile();
            break;
        case 5:
            exit(0);

        // Daca utilizatorul nu itroduce o optiune din meniu, afiseaza eroare
        default:
            cout << "Optiune necunoscuta!\n\n";
            break;

        }

        this->meniu.ClearScreen();

    } // end while
} // end func


// Logica de jucat nivelul
int JocHandler::PlayCurrentLevel()
{
    this->meniu.ClearScreen();
    this->nivelHandler.ResetNrGreseli();
    this->nivelHandler.SetNrNivel(this->nivelCurent);
    this->nivelHandler.AlegereCuvantRandom(this->nivelCurent);

    string literaAleasa;

    while(true)
    {

        this->nivelHandler.AfiseazInfoNivel();
        this->nivelHandler.AfisareSpanzuratoare();
        this->nivelHandler.AfisareCuvant();

        // Daca jucatorul pierde:
        // Afisam mesajul de pierdut, resetam nivelul la 1
        if (this->nivelHandler.PlayerLost())
        {
            this->nivelHandler.HandleLosing();
            this->nivelCurent = 1;
            this->meniu.ClearScreen();
            return 0;
        }
        // daca cuvantul curent a fost ghicitm schimbal
        if(this->nivelHandler.IsWordCompleted())
        {
            this->nivelHandler.HandleWinning();
            this->nivelCurent++;
            this->meniu.ClearScreen();
            return 0;
        }

        this->nivelHandler.HandleInput();
        this->meniu.ClearScreen();
    }
}

// Saveaza starea jocului in fiser
int JocHandler::SaveStateToFile()
{
    std::ofstream file("saves/save1.txt");

    if (file.is_open()) {
        file << this->nivelCurent;
        file.close();
    } else {
        std::cout << "Unable to open file to save the game!\n";
        exit(0);
    }
    cout << "Jocul a fost salvat!\nApasati orice tasta pentru a continua!";
    string _;
    cin >> _;
}

// Incarca jocul din nivel
int JocHandler::LoadStateFromFile()
{
    std::ifstream file("saves/save1.txt");

    if (file.is_open()) {
        file >> this->nivelCurent;
        file.close();
    } else {
        std::cout << "Unable to open file to load the game!\n";
        exit(0);
    }

    cout << "Ati incarcat salvarea jocului!\nApasati orice tasta pentru a continua!";
    string _;
    cin >> _;
}

