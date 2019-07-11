#include "pilha.hpp"

using namespace pilha;

No::No() {
    registro = NULL;
    proximo = NULL;
}

No::No(Registro* novo_registro) {
    registro = novo_registro;
    proximo = NULL;
}

Pilha::Pilha() {
    tamanho = 0;
}

bool Pilha::vazia() {
    return tamanho == 0;
}

Pilha::~Pilha() {
    Registro *registro;

    while (not vazia()) {
        registro = desempilha();
        delete registro;
    }
}

void Pilha::empilha(Registro* novo_registro) {
    No *novo_no = new No(novo_registro);

    novo_no->proximo = topo;
    topo = novo_no;
    tamanho++;
}

Registro* Pilha::desempilha() {
    if (vazia()) return NULL;
    No *no_removido;
    Registro *registro_removido;
    
    no_removido = topo;
    registro_removido = no_removido->registro;

    topo = no_removido->proximo;

    delete no_removido;
    tamanho--;

    return registro_removido;
}

std::ostream& operator<<(std::ostream& out, Pilha& pilha_impressa) {
    if (pilha_impressa.vazia()) return out;
    
    No *aux = pilha_impressa.topo;

    for (unsigned int i = 1; i < pilha_impressa.tamanho; i++) {
        out << *aux->registro << ' ';
        aux = aux->proximo;
    }
    out << *aux->registro;
    return out;
}
