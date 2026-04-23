#include <iostream>
#include <string>
using namespace std;

#define MAX 5 // Maximum size of the queue
string q[MAX];
int qa_front = -1, qa_rear = -1;

void enqueue(string task) {
    if (qa_rear == MAX - 1) { cout << "Queue Overflow! Cannot add " << task << "\n"; return; }
    if (qa_front == -1) qa_front = 0; // First element added
    q[++qa_rear] = task;
}

void dequeue() {
    if (qa_front == -1) { cout << "Queue Underflow! Nothing to dequeue.\n"; return; }
    qa_front++;
    // Reset if queue becomes empty after dequeue
    if (qa_front > qa_rear) { qa_front = qa_rear = -1; }
}

string peek() {
    if (qa_front == -1) return "Empty";
    return q[qa_front];
}

void show() {
    if (qa_front == -1) { cout << "Queue is empty.\n"; return; }
    for (int i = qa_front; i <= qa_rear; i++) {
        cout << "[" << q[i] << "] ";
    }
    cout << "\n";
}

int main() {
    // Enqueueing elements
    enqueue("WakeUp");
    enqueue("Breakfast");
    enqueue("Study");
    
    cout << "Current Queue (qa_front to qa_rear): "; 
    show();
    
    cout << "qa_front element is: " << peek() << "\n";
    
    // Dequeueing elements (First In, First Out)
    dequeue();
    cout << "After 1 dequeue: "; 
    show();
    
    // Emptying the queue
    dequeue(); 
    dequeue(); 
    
    // Trying to dequeue from an empty queue
    dequeue(); 

    return 0;
}
