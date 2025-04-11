#include <iostream>

// Estrutura do nó da árvore binária
struct No {
    int valor;
    No* esquerdo;
    No* direito;

    // Construtor
    No(int val) : valor(val), esquerdo(nullptr), direito(nullptr) {}
};

// Função recursiva para calcular a altura de uma árvore binária
int altura(No* raiz) {
    if (raiz == nullptr) {
        return -1; // Retorna -1 se a árvore estiver vazia (altura de uma folha é 0)
    }

    // Calcula a altura das subárvores esquerda e direita
    int alturaEsquerda = altura(raiz->esquerdo);
    int alturaDireita = altura(raiz->direito);

    // Retorna o maior entre as duas alturas, somando 1 para incluir o nível atual
    return 1 + std::max(alturaEsquerda, alturaDireita);
}

int main() {
    // Exemplo de criação de uma árvore binária
    No* raiz = new No(10);
    raiz->esquerdo = new No(5);
    raiz->direito = new No(15);
    raiz->esquerdo->esquerdo = new No(3);
    raiz->esquerdo->direito = new No(7);

    // Calculando a altura da árvore
    std::cout << "Altura da árvore: " << altura(raiz) << std::endl;

    return 0;
}
