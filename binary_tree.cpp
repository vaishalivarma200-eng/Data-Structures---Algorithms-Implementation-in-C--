#include <iostream>
#include <string>
using namespace std;

struct BTNode { string d; BTNode *l, *r; };

void in(BTNode* r) { if(r) { in(r->l); cout<<r->d<<" "; in(r->r); } }
void pre(BTNode* r) { if(r) { cout<<r->d<<" "; pre(r->l); pre(r->r); } }
void post(BTNode* r) { if(r) { post(r->l); post(r->r); cout<<r->d<<" "; } }

int main() {
    // Weekend decision tree: WakeUp -> Study / Play
    BTNode* r = new BTNode{"WakeUp", new BTNode{"Study", 0, 0}, new BTNode{"Play", 0, 0}};
    
    cout << "Preorder: "; pre(r); cout << "\n";
    cout << "Inorder: "; in(r); cout << "\n";
    cout << "Postorder: "; post(r); cout << "\n";
    
    return 0;
}
