#include <iostream>
#include <string>
using namespace std;

struct CQNode {
  string task;
  CQNode *next;
};
CQNode *cq_front = NULL;
CQNode *cq_rear = NULL;

void enqueue(string t) {
  CQNode *n = new CQNode{t, NULL};
  if (!cq_front) {
    cq_front = cq_rear = n;
    cq_rear->next = cq_front; // Circular link to itself
  } else {
    cq_rear->next = n;
    cq_rear = n;
    cq_rear->next = cq_front; // Link the new cq_rear back to cq_front
  }
}

void dequeue() {
  if (!cq_front) {
    cout << "Queue Underflow! Nothing to dequeue.\n";
    return;
  }

  CQNode *t = cq_front;
  if (cq_front == cq_rear) { // Only one element in the queue
    cq_front = cq_rear = NULL;
  } else {
    cq_front = cq_front->next;
    cq_rear->next = cq_front; // Update the cq_rear's link to the new cq_front
  }
  delete t;
}

string peek() {
  if (!cq_front)
    return "Empty";
  return cq_front->task;
}

void show() {
  if (!cq_front) {
    cout << "Queue is empty.\n";
    return;
  }

  CQNode *temp = cq_front;
  do {
    cout << "[" << temp->task << "] ";
    temp = temp->next;
  } while (temp != cq_front);

  // Visually indicate the circular nature
  cout << "(points back to " << cq_front->task << ")\n";
}

int main() {
  // Enqueueing elements
  enqueue("WakeUp");
  enqueue("Breakfast");
  enqueue("Study");

  cout << "Current Circular Queue: ";
  show();

  cout << "cq_front element is: " << peek() << "\n";

  // Dequeueing elements
  dequeue();
  cout << "After 1 dequeue: ";
  show();

  // Adding more elements
  enqueue("Lunch");
  enqueue("Play");
  cout << "After enqueueing 2 more tasks: ";
  show();

  // Emptying the queue completely
  dequeue();
  dequeue();
  dequeue();
  dequeue();
  cout << "After emptying: ";
  show();

  return 0;
}
