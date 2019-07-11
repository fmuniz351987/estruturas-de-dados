#include <iostream>
#include "pilha.hpp"

int main() {
    pilha::Pilha pilha_de_testes;
    int erros = 0;

    if (pilha_de_testes.tamanho) {
        std::cout << "A pilha não foi iniciada com tamanho 0.\n";
        erros++;
    }

    if (not pilha_de_testes.vazia()) {
        std::cout << "A pilha foi iniciada não vazia.\n";
        erros++;
    }

    for (int i = 0; i < 100; i++) {
        pilha_de_testes.empilha(new int(i));
    }    

    if (pilha_de_testes.tamanho != 100) {
        std::cout << "A pilha nao tem tamanho 100 depois de 100 itens empilhados.\n";
        erros++;
    }

    std::cout << pilha_de_testes << '\n';

    std::cout << "Foram encontrados " << erros << " erros.\n";
    return 0;
}
