#include <iostream>
#include <string>
using namespace std;
struct SLLNode { string task; SLLNode* next; };
SLLNode* sll_head = NULL;
void insStart(string t) { SLLNode* n = new SLLNode(); n->task = t; n->next = sll_head; sll_head = n; }
void insEnd(string t) {
    if(!sll_head) { insStart(t); return; }
    SLLNode* temp = sll_head; while(temp->next) temp = temp->next;
    SLLNode* n = new SLLNode(); n->task = t; n->next = NULL; temp->next = n;
}
void insMid(string t) { // inserts after the 1st task
    if(sll_head) { SLLNode* n = new SLLNode(); n->task = t; n->next = sll_head->next; sll_head->next = n; }
}
void delStart() { if(sll_head) { SLLNode* t = sll_head; sll_head = sll_head->next; delete t; } }
void delEnd() {
    if(!sll_head) return;
    if(!sll_head->next) { delete sll_head; sll_head = NULL; return; }
    SLLNode* t = sll_head; while(t->next->next) t = t->next;
    delete t->next; t->next = NULL;
}
void delMid() { // deletes the 2nd task
    if(sll_head && sll_head->next) { SLLNode* t = sll_head->next; sll_head->next = t->next; delete t; }
}
void show() { for(SLLNode* t=sll_head; t; t=t->next) cout<<t->task<<" -> "; cout<<"Done\n"; }
int main() {
    insStart("WakeUp"); insEnd("Study"); insMid("Breakfast"); 
    cout << "Schedule: "; show();
    delMid(); delEnd(); delStart(); 
    cout << "After deletions: "; show();
    return 0;
}
