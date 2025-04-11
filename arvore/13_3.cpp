#include <iostream>

struct No {
    int valor;
    No* esquerda;
    No* direita;

    // Construtor
    No(int val) : valor(val), esquerda(NULL), direita(NULL) {}
};

int contarFolhas(No* raiz) {
    if (raiz == NULL) {
        return 0; // Se a árvore estiver vazia, retorna 0
    }
    if (raiz->esquerda == NULL && raiz->direita == NULL) {
        return 1; // Se o nó for uma folha, retorna 1
    }
    return contarFolhas(raiz->esquerda) + contarFolhas(raiz->direita); // Soma as folhas da subárvore esquerda e direita
};

int main() {
    No* raiz = new No(10);
    raiz->esquerda = new No(5);
    raiz->direita = new No(15);
    raiz->esquerda->esquerda = new No(3);
    raiz->esquerda->direita = new No(7);
    raiz->direita->esquerda = new No(12);
    raiz->direita->direita = new No(18);

    int totalFolhas = contarFolhas(raiz); // Chama a função para contar as folhas
    std::cout << "Total de folhas na árvore: " << totalFolhas << std::endl;

    return 0;
}