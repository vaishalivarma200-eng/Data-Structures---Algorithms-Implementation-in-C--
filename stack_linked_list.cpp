#include <iostream>
#include <string>
using namespace std;

struct StackNode { string task; StackNode* next; };
StackNode* stack_top = NULL;

void push(string t) {
    StackNode* n = new StackNode{t, stack_top};
    stack_top = n;
}

void pop() {
    if (!stack_top) { cout << "Stack Underflow! Nothing to pop.\n"; return; }
    StackNode* t = stack_top;
    stack_top = stack_top->next;
    delete t;
}

string peek() {
    if (!stack_top) return "Empty";
    return stack_top->task;
}

void show() {
    if (!stack_top) { cout << "Stack is empty.\n"; return; }
    for (StackNode* t = stack_top; t; t = t->next) {
        cout << "[" << t->task << "] ";
    }
    cout << "\n";
}

int main() {
    // Pushing elements onto the stack
    push("WakeUp");
    push("Breakfast");
    push("Study");
    
    cout << "Current Stack (stack_top to Bottom): "; 
    show();
    
    cout << "stack_top element is: " << peek() << "\n";
    
    // Popping elements
    pop();
    cout << "After 1 pop: "; 
    show();
    
    // Emptying the stack
    pop(); 
    pop(); 
    
    // Trying to pop from an empty stack
    pop(); 

    return 0;
}
