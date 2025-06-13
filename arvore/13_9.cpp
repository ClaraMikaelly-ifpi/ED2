#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da árvore
typedef struct No {
    int valor;
    struct No *esq, *dir;
} No;

// Função para criar um novo nó
No* novo_no(int valor) {
    No* no = (No*) malloc(sizeof(No));
    no->valor = valor;
    no->esq = no->dir = NULL;
    return no;
}

// Função para inserir um valor na BST
No* inserir(No* raiz, int valor) {
    if (raiz == NULL) return novo_no(valor);
    if (valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor);
    else
        raiz->dir = inserir(raiz->dir, valor);
    return raiz;
}

// Função que exibe a árvore em ordem decrescente
void exibe_dec(No* raiz) {
    if (raiz == NULL) return;
    exibe_dec(raiz->dir);       // Visita a subárvore direita
    printf("%d ", raiz->valor); // Visita o nó atual
    exibe_dec(raiz->esq);       // Visita a subárvore esquerda
}

// Exemplo de uso
int main() {
    No* raiz = NULL;
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);

    printf("Itens da BST em ordem decrescente:\n");
    exibe_dec(raiz);
    printf("\n");

    return 0;
}