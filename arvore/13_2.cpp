#include <iostream>
using namespace std;

struct No {
    int valor;
    No* esquerda;
    No* direita;

    //construtor
    No(int val) : valor(val), esquerda(NULL), direita(NULL) {}
};

int nos(No* raiz) {
    if (raiz == NULL) {
        return 0; // Se a árvore estiver vazia, retorna 0
    }
    return 1 + nos(raiz->esquerda) + nos(raiz->direita); // Conta o nó atual e soma os nós da subárvore esquerda e direita
}

// Criando uma árvore de exemplo
int main() {
    No* raiz = new No(10);
    raiz->esquerda = new No(5);
    raiz->direita = new No(15);
    raiz->esquerda->esquerda = new No(3);
    raiz->esquerda->direita = new No(7);

    int totalNos = nos(raiz); // Chama a função para contar os nós
    std::cout << "Total de nós na árvore: " << totalNos << std::endl;

    return 0;
};