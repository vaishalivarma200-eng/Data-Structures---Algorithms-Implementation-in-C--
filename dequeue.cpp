#include <iostream>
#include <string>
using namespace std;

class Deque {
  string tasks[20];
  int f = 10, r = 9; // Start in the middle to easily grow both ways
public:
  void insertFront(string t) { tasks[--f] = t; }
  void insertRear(string t) { tasks[++r] = t; }

  void deleteFront() {
    if (f <= r)
      cout << "Completed: " << tasks[f++] << "\n";
  }
  void deleteRear() {
    if (f <= r)
      cout << "Canceled: " << tasks[r--] << "\n";
  }

  void show() {
    cout << "Tasks: ";
    for (int i = f; i <= r; i++)
      cout << "[" << tasks[i] << "] ";
    cout << "\n";
  }
};

int main() {
  Deque d;
  d.insertRear("Math HW");
  d.insertRear("Read Book");
  d.insertFront("Attend Class"); // Urgent task

  d.show();
  d.deleteFront(); // Do urgent task
  d.deleteRear();  // Cancel last task
  d.show();

  return 0;
}
