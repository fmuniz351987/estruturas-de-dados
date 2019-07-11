#include <iostream>
#include "fila.hpp"

int main() {
    fila::Fila fila_de_testes;
    int erros = 0;

    if (fila_de_testes.tamanho) {
        std::cout << "A fila não foi inicializada com tamanho 0.\n";
        erros++;
    }

    if (not fila_de_testes.vazia()) {
        std::cout << "A fila foi inicializada não vazia.\n";
        erros++;
    }

    std::cout << "Testes concluidos com " << erros << " erros.\n";
    return 0;
}