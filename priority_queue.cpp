#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Task {
    string name;
    int priority; 
};

class PriorityQueue {
    Task t[20];
    int size = 0;
public:
    void push(string name, int p) {
        t[size++] = {name, p};
        for(int i = 0; i < size-1; i++) {
            for(int j = 0; j < size-i-1; j++) {
                if(t[j].priority > t[j+1].priority) {
                    swap(t[j], t[j+1]);
                }
            }
        }
    }
    
    void pop() {
        if(size == 0) return;
        cout << "Finished task: " << t[0].name << "\n";
        for(int i = 0; i < size-1; i++) t[i] = t[i+1];
        size--;
    }
    
    void show() {
        cout << "To-Do List: ";
        for(int i = 0; i < size; i++) 
            cout << "[" << t[i].name << " (P" << t[i].priority << ")] ";
        cout << "\n";
    }
};

int main() {
    PriorityQueue pq;
    pq.push("Do Math HW", 2);
    pq.push("Play Video Games", 3);
    pq.push("Study for Exam", 1); 
    
    pq.show();
    pq.pop(); 
    pq.show();

    return 0;
}
