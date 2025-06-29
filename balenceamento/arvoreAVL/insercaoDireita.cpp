#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

int height(Node* N) {
    return N ? N->height : 0;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = node->right = nullptr;
    node->height = 1;
    return node;
}

// ---------- Rotações ----------
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

int getBalance(Node* N) {
    return N ? height(N->left) - height(N->right) : 0;
}

// ---------- Inserção AVL ----------
Node* insert(Node* node, int key) {
    if (!node) return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    // Rotação simples à direita
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    return node;
}

// ---------- Remoção AVL ----------
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            if (!temp) {
                delete root;
                return nullptr;
            } else {
                Node* newRoot = new Node();
                *newRoot = *temp;
                delete temp;
                return newRoot;
            }
        } else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    // Rotação simples à direita após remoção
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    return root;
}


void preOrder(Node* root) {
    if (root) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}


int main() {
    // Inserção 
    Node* root1 = nullptr;
    root1 = insert(root1, 30);
    root1 = insert(root1, 20);
    root1 = insert(root1, 10); // Rotação simples à direita

    cout << "Árvore 1 (inserção com rotação simples à direita): ";
    preOrder(root1);
    cout << "\n";

    // Remoção 
    Node* root2 = nullptr;
    root2 = insert(root2, 50);
    root2 = insert(root2, 40);
    root2 = insert(root2, 30);
    root2 = insert(root2, 60);

    cout << "Árvore 2 antes da remoção: ";
    preOrder(root2); // Esperado: 50 40 30 60
    cout << "\n";

    root2 = deleteNode(root2, 60); // Gera rotação simples à direita

    cout << "Árvore 2 após remoção de 60 (rotação simples à direita): ";
    preOrder(root2); // Esperado: 40 30 50
    cout << "\n";

    return 0;
}