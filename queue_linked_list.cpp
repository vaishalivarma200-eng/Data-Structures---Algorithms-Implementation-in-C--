#include <iostream>
#include <string>
using namespace std;

struct QueueNode { string task; QueueNode* next; };
QueueNode* q_front = NULL;
QueueNode* q_rear = NULL;

void enqueue(string t) {
    QueueNode* n = new QueueNode{t, NULL};
    if (!q_rear) { q_front = q_rear = n; return; }
    q_rear->next = n;
    q_rear = n;
}

void dequeue() {
    if (!q_front) { cout << "Queue Underflow! Nothing to dequeue.\n"; return; }
    QueueNode* t = q_front;
    q_front = q_front->next;
    if (!q_front) q_rear = NULL; // Reset q_rear if queue becomes empty
    delete t;
}

string peek() {
    if (!q_front) return "Empty";
    return q_front->task;
}

void show() {
    if (!q_front) { cout << "Queue is empty.\n"; return; }
    for (QueueNode* t = q_front; t; t = t->next) {
        cout << "[" << t->task << "] ";
    }
    cout << "\n";
}

int main() {
    // Enqueueing elements
    enqueue("WakeUp");
    enqueue("Breakfast");
    enqueue("Study");
    
    cout << "Current Queue (q_front to q_rear): "; 
    show();
    
    cout << "q_front element is: " << peek() << "\n";
    
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
