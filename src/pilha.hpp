#pragma once

#include <iostream>

#ifndef NULL
    #define NULL 0
#endif

namespace pilha {
    typedef int Registro;

    struct No {
        Registro *registro;
        No *proximo;

        No();

        No(Registro*);
    };

    struct Pilha {
        No *topo;
        unsigned int tamanho;

        Pilha();

        ~Pilha();

        void empilha(Registro*);

        Registro* desempilha();

        bool vazia();
        
    };
}

std::ostream& operator<<(std::ostream&, pilha::Pilha&);
