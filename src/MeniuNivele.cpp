#include "MeniuNivele.h"
#include <iostream>
#include "console_text.h"

// Pentru functia de curatare a ecranului
// Include libraria corecta pentru sistemul de operare
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif


using std::cout;
using std::cin;


MeniuNivele::MeniuNivele()
{
    //ctor
}

MeniuNivele::~MeniuNivele()
{
    //dtor
}


/// Functia pentru afisarea meniului principal, cu nivelele
void MeniuNivele::AfisareMeniu(int nivelCurent)
{
    this->ClearScreen();
    cout << YELLOW <<  R"DELIM(
   _____                                       _
  / ____|                                     | |
 | (___  _ __   __ _ _ __  _____   _ _ __ __ _| |_ ___   __ _ _ __ ___  __ _
  \___ \| '_ \ / _` | '_ \|_  / | | | '__/ _` | __/ _ \ / _` | '__/ _ \/ _` |
  ____) | |_) | (_| | | | |/ /| |_| | | | (_| | || (_) | (_| | | |  __/ (_| |
 |_____/| .__/ \__,_|_| |_/___|\__,_|_|  \__,_|\__\___/ \__,_|_|  \___|\__,_|
        | |
        |_|                                                                     )DELIM" << "\n" << RESET;
    cout << "\
##########      ##########      ##########\n\
#        #      #        #      #        #\n\
#   1    ########   2    ########   3    #\n\
#        #      #        #      #        #\n\
##########      ##########      ##########\n\
                                    #\n\
                                    #\n\
##########      ##########      ##########\n\
#        #      #        #      #        #\n\
#   6    ########   5    ########   4    #\n\
#        #      #        #      #        #\n\
##########      ##########      ##########\n\
\n\
Alegeti o optiune:\n\
\n\
1. Start nivelul " << nivelCurent <<"\n\
2. Help\n\
3. Save\n\
4. Load\n\
5. Exit\n\
\n\
>>> ";

}


int MeniuNivele::CitireOptiuneTastatura()
{
    // Citim optiunea din meiu a utilizatorului
    int optinue = 0;

    cin >> optinue;

    return optinue;

}


// Ruleaza comanda de clear a terminalulu
void MeniuNivele::ClearScreen()
{
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}


