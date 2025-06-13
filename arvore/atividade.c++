#include <stdio.h>
#include <stdlib.h>
#define fmt "%d "

typedef struct Arv {
    int valor;
    struct Arv* esquerda;
    struct Arv* direita;
} Arv;

Arv* criarNo(int valor) {
    Arv* novoNo = (Arv*)malloc(sizeof(Arv));
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

Arv* inserir(Arv* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }
    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else {
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}

Arv* balancear(int vetor[], int first, int last) {
    if (first > last) return NULL;

    int middle = (first + last) / 2;
    Arv* raiz = criarNo(vetor[middle]);

    raiz->esquerda = balancear(vetor, first, middle - 1);
    raiz->direita = balancear(vetor, middle + 1, last);

    return raiz;
}

int altura(Arv* A) {
    if (A == NULL) return -1;

    int alt_esq = altura(A->esquerda);
    int alt_dir = altura(A->direita);

    return 1 + (alt_esq > alt_dir ? alt_esq : alt_dir);
}

void emordem(Arv* A) {
    if (A == NULL) return;
    emordem(A->esquerda);
    printf(fmt, A->valor);
    emordem(A->direita);
}

int estaBalanceada(Arv* A) {
    if (A == NULL) return 1;

    int alt_esq = altura(A->esquerda);
    int alt_dir = altura(A->direita);

    if (abs(alt_esq - alt_dir) > 1) return 0;

    return estaBalanceada(A->esquerda) && estaBalanceada(A->direita);
}

int contarNos(Arv* A) {
    if (A == NULL) return 0;
    return 1 + contarNos(A->esquerda) + contarNos(A->direita);
}

void preencherVetorEmOrdem(Arv* A, int vetor[], int *index) {
    if (A == NULL) return;

    preencherVetorEmOrdem(A->esquerda, vetor, index);
    vetor[*index] = A->valor;
    (*index)++;
    preencherVetorEmOrdem(A->direita, vetor, index);
}

int main() {
    Arv* raiz = NULL;

    raiz = inserir(raiz, 7);
    raiz = inserir(raiz, 6);
    raiz = inserir(raiz, 22);
    raiz = inserir(raiz, 14);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 63);

    printf("Em ordem (árvore original): ");
    emordem(raiz);
    printf("\n");

    printf("Altura da árvore original: %d\n", altura(raiz));

    if (estaBalanceada(raiz)) {
        printf("A árvore está balanceada.\n");
    } else {
        printf("A árvore NÃO está balanceada.\n");

        int tamanho = contarNos(raiz);
        int* vetorOrdenado = (int*) malloc(tamanho * sizeof(int));
        int index = 0;

        preencherVetorEmOrdem(raiz, vetorOrdenado, &index);

        printf("Vetor ordenado gerado da árvore: ");
        for (int i = 0; i < tamanho; i++) {
            printf(fmt, vetorOrdenado[i]);
        }
        printf("\n");

        Arv* raizBalanceada = balancear(vetorOrdenado, 0, tamanho - 1);

        printf("Em ordem (árvore balanceada): ");
        emordem(raizBalanceada);
        printf("\n");

        printf("Altura da árvore balanceada: %d\n", altura(raizBalanceada));
        printf("A árvore está balanceada.\n");

        free(vetorOrdenado);
    }

    return 0;
}