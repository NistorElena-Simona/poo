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
             cout<<"Bine ati venit in acest joc!";
        cout<<"Jocul Spanzurătoarea este un joc clasic de cuvinte în care  jucătorul încearcă să ghicească un cuvânt, literă cu literă, înainte aparitiei. Acest joc este proiectat pentru a ghici cuvantul asles random intr-o lista de x cuvinte conform nivelului la care se afla utilizatorul(de exemplu nivel 1 se alege un cuvant random de 3 litere dintr-o lista creata de proiectantul aplicatiei alaturi de o scurta descriptie).\n";

        cout<<"Iată modul de funcționare a jocului Spanzurătoarea:\n";

    cout<<"Va aparea scris mare denumirea jocului proiectat, dupa care mai jos meniul cu cele 5 optiuni: 1. care este folosit pentru inceperea jocului\n 2. O scurta decriere a jocului si modul de utilizare\n 3.va salva nivelul la care se afla utilizatorul\n 4. va reincarca nivelul la care a ramas utilizatorul la alegerea optiunii 3\n 5.optiunea de iesire din joc\n;";
    cout<<" jucătorul va primi un  cuvântul random alaturi de o mica desciptie , de asemenea sus in partea stanga se va afisa o lista cu literele alese, care nu vor mai putea fi alese pana la urmatorul nivel.\n";
    cout<<"Dupa ce jucatorul va alege optiunea 1 acesta va intra in joc , in partea de sus stanga fiind afisate numarul de vieti care este echivalent cu numarul de incercari, de asemenea va aparea si o lista de litere alese, literele alese care apar in acea lista nu vor mai putea fi alese pana la nivelul urmator\n";
    cout<<"Jucatorul va avea doar 6 vieti , ceea ce inseamna 6 incercari la fiecare nivel";
    cout<<"Daca jucatorul va introduce o litera gresita , se va desena spanzuratoarea si cate o partea a omului ";
    cout<<"Dupa ce jucatorul greseste de 6 ori se va afisa desenul cu spanzuratoarea , iar jocul se va relua de la nivelul 1";
    cout<<"jocul are 6 nivele ,iar la fiecare nivel dificultatea va consta in cresterea dimensiunii cuvantului cu o litera, de exemplu la primul nivel avem cuvinte cu 3 litere, la al doilea cu 4 litere si tot asa pana la nivelul 6 unde avem 9 litere";
    cin>>buffer;
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

