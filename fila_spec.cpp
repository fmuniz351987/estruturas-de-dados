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

    for (int i = 0; i < 100; i++) {
        fila_de_testes.enfileira(new int(i));
    }

    if (fila_de_testes.tamanho != 100) {
        std::cout << "A fila recebeu 100 itens mas nao possui tamanho 100.\n";
        erros++;
    }

    for (int i = 0; i < 10; i++) {
        fila_de_testes.desenfileira();
    }

    if (fila_de_testes.tamanho != 90) {
        std::cout << "Desenfileira produz fila de tamanho inesperado.\n";
        erros++;
    }

    std::cout << fila_de_testes << '\n';

    std::cout << "Testes concluidos com " << erros << " erros.\n";
    return 0;
}