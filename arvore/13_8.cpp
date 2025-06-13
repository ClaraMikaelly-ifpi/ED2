#include <iostream>
#include <string>
using namespace std;

struct No {
    string valor;
    No* esq;
    No* dir;

    No(string val) : valor(val), esq(nullptr), dir(nullptr) {}
};

// Função que avalia a árvore de expressão
int valor(No* raiz) {
    if (!raiz->esq && !raiz->dir) {
        // Nó folha (operando)
        return stoi(raiz->valor);
    }

    // Avalia as subárvores esquerda e direita
    int val_esq = valor(raiz->esq);
    int val_dir = valor(raiz->dir);

    // Aplica o operador
    if (raiz->valor == "+") return val_esq + val_dir;
    if (raiz->valor == "-") return val_esq - val_dir;
    if (raiz->valor == "*") return val_esq * val_dir;
    if (raiz->valor == "/") return val_esq / val_dir;

    throw runtime_error("Operador inválido: " + raiz->valor);
}

// Função para montar a árvore do exemplo ((5+3)/4)*(6-1)
No* montar_arvore_exemplo() {
    No* n1 = new No("5");
    No* n2 = new No("3");
    No* soma = new No("+"); soma->esq = n1; soma->dir = n2;

    No* n4 = new No("4");
    No* div = new No("/"); div->esq = soma; div->dir = n4;

    No* n6 = new No("6");
    No* n1b = new No("1");
    No* sub = new No("-"); sub->esq = n6; sub->dir = n1b;

    No* mult = new No("*"); mult->esq = div; mult->dir = sub;

    return mult;
}

int main() {
    No* raiz = montar_arvore_exemplo();
    cout << "Resultado da expressão: " << valor(raiz) << endl; // Saída esperada: 10
    return 0;
}