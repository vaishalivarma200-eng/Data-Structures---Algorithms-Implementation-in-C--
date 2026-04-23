#include <iostream>
#include <string>
using namespace std;
struct CLLNode { string task; CLLNode* next; };
CLLNode* cll_head = NULL;

void insStart(string t) {
    CLLNode* n = new CLLNode{t, NULL};
    if(!cll_head) { n->next = n; cll_head = n; return; }
    CLLNode* temp = cll_head; while(temp->next != cll_head) temp = temp->next;
    n->next = cll_head; temp->next = n; cll_head = n;
}
void insEnd(string t) {
    if(!cll_head) { insStart(t); return; }
    CLLNode* n = new CLLNode{t, cll_head};
    CLLNode* temp = cll_head; while(temp->next != cll_head) temp = temp->next;
    temp->next = n;
}
void insMid(string t) { // inserts after the 1st task
    if(cll_head) { CLLNode* n = new CLLNode{t, cll_head->next}; cll_head->next = n; }
}
void delStart() {
    if(!cll_head) return;
    if(cll_head->next == cll_head) { delete cll_head; cll_head = NULL; return; }
    CLLNode* temp = cll_head; while(temp->next != cll_head) temp = temp->next;
    CLLNode* t = cll_head; temp->next = cll_head->next; cll_head = cll_head->next; delete t;
}
void delEnd() {
    if(!cll_head) return;
    if(cll_head->next == cll_head) { delete cll_head; cll_head = NULL; return; }
    CLLNode* temp = cll_head; CLLNode* prev = NULL;
    while(temp->next != cll_head) { prev = temp; temp = temp->next; }
    prev->next = cll_head; delete temp;
}
void delMid() { // deletes the 2nd task
    if(cll_head && cll_head->next != cll_head) { CLLNode* t = cll_head->next; cll_head->next = t->next; delete t; }
}
void show() {
    if(!cll_head) return;
    CLLNode* temp = cll_head;
    do { cout<<temp->task<<" -> "; temp=temp->next; } while(temp!=cll_head);
    cout<<"(Back to "<<cll_head->task<<")\n";
}
int main() {
    insStart("WakeUp"); insEnd("Study"); insMid("Breakfast"); 
    cout << "CLL Schedule: "; show();
    delMid(); delEnd(); delStart(); 
    cout << "After deletions: "; show();
    return 0;
}
