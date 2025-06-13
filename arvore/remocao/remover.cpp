#include <stdio.h>
#include <stdlib.h>
#include <iostream> // Para usar cout e endl

// Definição do tipo Item
typedef int Item;

// Definição da estrutura do nó da árvore (Arv)
typedef struct arv {
    Item item;
    struct arv *esq;
    struct arv *dir;
} Arv;

// Função para criar um novo nó da árvore
Arv* arv_nova(Item item) {
    Arv* novo_no = (Arv*)malloc(sizeof(Arv));
    if (novo_no == NULL) {
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }
    novo_no->item = item;
    novo_no->esq = NULL;
    novo_no->dir = NULL;
    return novo_no;
}

// Função para inserir um novo item na árvore (mantendo a propriedade BST)
Arv* arv_inserir(Arv* raiz, Item item) {
    if (raiz == NULL) {
        return arv_nova(item);
    }

    if (item < raiz->item) {
        raiz->esq = arv_inserir(raiz->esq, item);
    } else if (item > raiz->item) {
        raiz->dir = arv_inserir(raiz->dir, item);
    }

    return raiz;
}

// Função para remover o máximo elemento da árvore
Item remmax(Arv **A) {
    if (*A == NULL) {
        fprintf(stderr, "Erro: Árvore vazia ao tentar remover o máximo.\n");
        exit(EXIT_FAILURE);
    }

    while ((*A)->dir != NULL) {
        A = &((*A)->dir);
    }

    Arv *n = *A;
    Item x = n->item;
    *A = n->esq;
    free(n);
    return x;
}

// Função para percorrer a árvore em pré-ordem
void percorre_preordem(Arv *A) {
    if (A != NULL) {
        std::cout << A->item << std::endl;
        percorre_preordem(A->esq);
        percorre_preordem(A->dir);
    }
}

// Função auxiliar para imprimir a árvore (para teste)
void arv_imprimir(Arv* raiz, int nivel) {
    if (raiz != NULL) {
        arv_imprimir(raiz->dir, nivel + 1);
        for (int i = 0; i < nivel; i++) {
            printf("    ");
        }
        printf("%d\n", raiz->item);
        arv_imprimir(raiz->esq, nivel + 1);
    }
}

// Função para liberar a memória da árvore
void arv_liberar(Arv* raiz) {
    if (raiz != NULL) {
        arv_liberar(raiz->esq);
        arv_liberar(raiz->dir);
        free(raiz);
    }
}

int main() {
    Arv *raiz = NULL;

    // Inserindo alguns elementos na árvore
    raiz = arv_inserir(raiz, 50);
    raiz = arv_inserir(raiz, 30);
    raiz = arv_inserir(raiz, 70);
    raiz = arv_inserir(raiz, 20);
    raiz = arv_inserir(raiz, 40);
    raiz = arv_inserir(raiz, 60);
    raiz = arv_inserir(raiz, 80);

    printf("Árvore:\n");
    arv_imprimir(raiz, 0);
    printf("\n");

    printf("Percorrimento em pré-ordem:\n");
    percorre_preordem(raiz);
    printf("\n");

    Item maximo_removido = remmax(&raiz);
    printf("Máximo removido: %d\n", maximo_removido);

    printf("\nÁrvore depois da remoção do máximo:\n");
    arv_imprimir(raiz, 0);
    printf("\n");

    printf("Percorrimento em pré-ordem após remoção:\n");
    percorre_preordem(raiz);
    printf("\n");

    arv_liberar(raiz); 

    return 0;
}