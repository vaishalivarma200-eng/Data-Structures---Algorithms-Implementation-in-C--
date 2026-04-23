#include <iostream>
#include <string>
using namespace std;

#define MAX 5 // Maximum size of the circular queue
string q[MAX];
int cqa_front = -1, cqa_rear = -1;

void enqueue(string task) {
    // Check for overflow (if the next position of cqa_rear is cqa_front)
    if ((cqa_rear + 1) % MAX == cqa_front) {
        cout << "Queue Overflow! Cannot add " << task << "\n";
        return;
    }
    if (cqa_front == -1) {
        cqa_front = cqa_rear = 0; // First element
    } else {
        cqa_rear = (cqa_rear + 1) % MAX; // Circularly increment cqa_rear
    }
    q[cqa_rear] = task;
}

void dequeue() {
    if (cqa_front == -1) { cout << "Queue Underflow! Nothing to dequeue.\n"; return; }
    
    // If there was only one element, reset the queue
    if (cqa_front == cqa_rear) {
        cqa_front = cqa_rear = -1;
    } else {
        cqa_front = (cqa_front + 1) % MAX; // Circularly increment cqa_front
    }
}

string peek() {
    if (cqa_front == -1) return "Empty";
    return q[cqa_front];
}

void show() {
    if (cqa_front == -1) { cout << "Queue is empty.\n"; return; }
    
    int i = cqa_front;
    while (true) {
        cout << "[" << q[i] << "] ";
        if (i == cqa_rear) break;
        i = (i + 1) % MAX; // Move forward circularly
    }
    cout << "\n";
}

int main() {
    // Fill the circular queue
    enqueue("WakeUp"); enqueue("Breakfast"); 
    enqueue("Study"); enqueue("Lunch"); enqueue("Play");
    
    cout << "Queue after 5 enqueues: "; show();
    
    // Trying to add to a full queue
    enqueue("ExtraTask"); 
    
    // Dequeue 2 items to make space
    dequeue(); dequeue();
    cout << "Queue after 2 dequeues: "; show();
    
    // Add 2 more items to show wrap-around logic!
    enqueue("Dinner"); enqueue("Sleep");
    cout << "Queue after wrapping around: "; show();
    
    return 0;
}
