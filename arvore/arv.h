#ifndef ARV_H
#define ARV_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

// Definição da estrutura do nó da árvore
typedef struct arvore {
    struct arvore *esq;
    int item;
    struct arvore *dir;
} *Arvore;

// Função para criar um novo nó da árvore
Arvore arvore(Arvore esq, int item, Arvore dir);

// Função para percorrer a árvore em pré-ordem (raiz, esquerda, direita)
void percorre_preordem(Arvore A);

// Função para percorrer a árvore em in-ordem (esquerda, raiz, direita)
void percorre_inordem(Arvore A);

// Função para percorrer a árvore em pós-ordem (esquerda, direita, raiz)
void percorre_posordem(Arvore A);

#endif // ARV_H