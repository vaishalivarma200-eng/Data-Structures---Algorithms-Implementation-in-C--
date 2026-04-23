#include <iostream>
#include <string>
using namespace std;
struct DLLNode { string task; DLLNode* next; DLLNode* prev; };
DLLNode* dll_head = NULL;
void insStart(string t) {
    DLLNode* n = new DLLNode(); n->task = t; n->next = dll_head; n->prev = NULL;
    if(dll_head) dll_head->prev = n;
    dll_head = n;
}
void insEnd(string t) {
    if(!dll_head) { insStart(t); return; }
    DLLNode* temp = dll_head; while(temp->next) temp = temp->next;
    DLLNode* n = new DLLNode(); n->task = t; n->next = NULL; n->prev = temp; temp->next = n;
}
void insMid(string t) { // inserts after the 1st task
    if(!dll_head) return;
    DLLNode* n = new DLLNode(); n->task = t; n->next = dll_head->next; n->prev = dll_head;
    if(dll_head->next) dll_head->next->prev = n;
    dll_head->next = n;
}
void delStart() {
    if(!dll_head) return;
    DLLNode* t = dll_head; dll_head = dll_head->next;
    if(dll_head) dll_head->prev = NULL;
    delete t;
}
void delEnd() {
    if(!dll_head) return;
    if(!dll_head->next) { delete dll_head; dll_head = NULL; return; }
    DLLNode* t = dll_head; while(t->next) t = t->next;
    t->prev->next = NULL; delete t;
}
void delMid() { // deletes the 2nd task
    if(!dll_head || !dll_head->next) return;
    DLLNode* t = dll_head->next; dll_head->next = t->next;
    if(t->next) t->next->prev = dll_head;
    delete t;
}
void show() {
    for(DLLNode* t=dll_head; t; t=t->next) cout<<t->task<<" <-> "; cout<<"Done\n";
}
int main() {
    insStart("WakeUp"); insEnd("Study"); insMid("Breakfast");
    cout << "DLL Schedule: "; show();
    delMid(); delEnd(); delStart();
    cout << "After deletions: "; show();
    return 0;
}
