#pragma once

#include <iostream>

#ifndef NULL
    #define NULL 0
#endif

namespace fila {
    typedef int Registro;

    struct No {
        Registro *registro;
        No *frente, *tras;

        No();

        No(Registro*);
    };

    struct Fila {
        No *cabeca;
        unsigned int tamanho;

        Fila();

        ~Fila();

        void enfileira(Registro*);

        Registro* desenfileira();

        bool vazia();
    };
}

std::ostream& operator<<(std::ostream&, fila::Fila&);
