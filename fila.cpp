#include "fila.hpp"

using namespace fila;

No::No() {
    registro = NULL;
    tras = NULL;
    frente = NULL;
}

No::No(Registro* novo_registro) {
    registro = novo_registro;
    tras = NULL;
    frente = NULL;
}

Fila::Fila() {
    tamanho = 0;
    cabeca = new No;

    cabeca->frente = cabeca;
    cabeca->tras = cabeca;
}

Fila::~Fila() {
    Registro *aux;

    while (not vazia()) {
        aux = desenfileira();
        delete aux;
    }
    delete cabeca;
}

bool Fila::vazia() {
    return not tamanho;
}

void Fila::enfileira(Registro* novo_registro) {
    No *novo_no = new No(novo_registro);
    No *ultimo = cabeca->frente;

    novo_no->tras = cabeca;
    novo_no->frente = ultimo;
    
    cabeca->frente = novo_no;
    ultimo->tras = novo_no;

    tamanho++;
}

Registro* Fila::desenfileira() {
    if (vazia()) return NULL;

    No *primeiro = cabeca->tras;
    No *novo_primeiro = primeiro->tras;
    Registro *reg;

    cabeca->tras = novo_primeiro;
    novo_primeiro->frente = cabeca;

    reg = primeiro->registro;
    delete primeiro;

    tamanho--;

    return reg;
}

std::ostream& operator<<(std::ostream& out, fila::Fila& fila_impressa) {
    if (fila_impressa.vazia()) return out;

    No* aux = fila_impressa.cabeca->tras;
    for (unsigned int i = 1; i < fila_impressa.tamanho; i++) {
        out << *aux->registro << ' ';
        aux = aux->tras;
    }
    out << *aux->registro;

    return out;
}

