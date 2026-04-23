#include <iostream>
using namespace std;

struct BSTNode { 
    int score; 
    BSTNode *left, *right; 
};

BSTNode* insertBST(BSTNode* r, int s) {
    if(!r) return new BSTNode{s, NULL, NULL};
    if(s < r->score) r->left = insertBST(r->left, s);
    else r->right = insertBST(r->right, s);
    return r;
}

void inorderBST(BSTNode* r) {
    if(r) { 
        inorderBST(r->left); 
        cout << r->score << " "; 
        inorderBST(r->right); 
    }
}

int main() {
    BSTNode* root = NULL;
    cout << "Adding student exam scores into BST...\n";
    root = insertBST(root, 85); 
    insertBST(root, 92);        
    insertBST(root, 78);        
    insertBST(root, 88);        

    cout << "Sorted Scores (Inorder Traversal): "; 
    inorderBST(root); 
    cout << "\n";
    return 0;
}
