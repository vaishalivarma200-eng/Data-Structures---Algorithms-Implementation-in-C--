#include <iostream>
#include <string>
using namespace std;

#define MAX 5 // Maximum size of the stack
string stack[MAX];
int sa_top = -1;

void push(string task) {
    if (sa_top >= MAX - 1) { cout << "Stack Overflow! Cannot add " << task << "\n"; return; }
    stack[++sa_top] = task;
}

void pop() {
    if (sa_top < 0) { cout << "Stack Underflow! Nothing to pop.\n"; return; }
    sa_top--;
}

string peek() {
    if (sa_top < 0) return "Empty";
    return stack[sa_top];
}

void show() {
    if (sa_top < 0) { cout << "Stack is empty.\n"; return; }
    for (int i = sa_top; i >= 0; i--) {
        cout << "[" << stack[i] << "] ";
    }
    cout << "\n";
}

int main() {
    // Pushing elements onto the stack
    push("WakeUp");
    push("Breakfast");
    push("Study");
    
    cout << "Current Stack (sa_top to Bottom): "; 
    show();
    
    cout << "sa_top element is: " << peek() << "\n";
    
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
