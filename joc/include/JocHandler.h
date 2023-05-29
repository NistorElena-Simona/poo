#ifndef JOCHANDLER_H
#define JOCHANDLER_H

#include "Nivel.h"
#include "MeniuNivele.h"

/// Clasa pentru mentinerea meniului, jocului, setarilor, statusului nivelului, etc
class JocHandler
{
    MeniuNivele meniu; // Meniul
    Nivel nivelHandler; // Clasa care ruleaza logica jocului

    // Status joc
    int nivelCurent = 1; // La intrarea in program, nivelul de start este 1

    public:
        JocHandler();
        virtual ~JocHandler();

        int Start(); // Punctul de intrare in program, returneaza int, 0 = good, other = erori
        int PlayCurrentLevel(); // Logica de jucat nivelul
        int SaveStateToFile(); // Saveaza starea jocului in fiser
        int LoadStateFromFile(); // Incarca jocul din nivel
};

#endif // JOCHANDLER_H
