#include <iostream>
#include <algorithm>
using namespace std;

struct AVLNode { int hours, height; AVLNode *left, *right; };

int heightAVL(AVLNode *N) { return N ? N->height : 0; }

AVLNode* rightRotateAVL(AVLNode* y) {
    AVLNode* x = y->left; AVLNode* T2 = x->right;
    x->right = y; y->left = T2;
    y->height = max(heightAVL(y->left), heightAVL(y->right)) + 1;
    x->height = max(heightAVL(x->left), heightAVL(x->right)) + 1;
    return x;
}

AVLNode* leftRotateAVL(AVLNode* x) {
    AVLNode* y = x->right; AVLNode* T2 = y->left;
    y->left = x; x->right = T2;
    x->height = max(heightAVL(x->left), heightAVL(x->right)) + 1;
    y->height = max(heightAVL(y->left), heightAVL(y->right)) + 1;
    return y;
}

int getBalAVL(AVLNode* N) { return N ? heightAVL(N->left) - heightAVL(N->right) : 0; }

AVLNode* insertAVL(AVLNode* node, int h) {
    if(!node) return new AVLNode{h, 1, NULL, NULL};
    if(h < node->hours) node->left = insertAVL(node->left, h);
    else node->right = insertAVL(node->right, h);
    
    node->height = 1 + max(heightAVL(node->left), heightAVL(node->right));
    int bal = getBalAVL(node);
    
    if(bal > 1 && h < node->left->hours) return rightRotateAVL(node);
    if(bal < -1 && h > node->right->hours) return leftRotateAVL(node);
    if(bal > 1 && h > node->left->hours) { node->left = leftRotateAVL(node->left); return rightRotateAVL(node); }
    if(bal < -1 && h < node->right->hours) { node->right = rightRotateAVL(node->right); return leftRotateAVL(node); }
    return node;
}

void preOrderAVL(AVLNode* r) {
    if(r){ cout << r->hours << "hrs "; preOrderAVL(r->left); preOrderAVL(r->right); }
}

int main() {
    AVLNode* root = NULL;
    cout << "Balancing weekly study hours using AVL Tree...\n";
    root = insertAVL(root, 10); 
    root = insertAVL(root, 20);
    root = insertAVL(root, 30); 
    
    cout << "Balanced Tree Structure (Preorder): "; 
    preOrderAVL(root); cout << "\n";
    return 0;
}
