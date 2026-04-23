#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int marks[] = {45, 88, 72, 90, 55};
    int n = 5;
    
    cout << "Original Marks: ";
    for(int i = 0; i < n; i++) cout << marks[i] << " ";
    cout << "\n";
    
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(marks[j] > marks[j+1]) {
                swap(marks[j], marks[j+1]); 
            }
        }
    }
    
    cout << "Sorted Exam Marks: ";
    for(int i = 0; i < n; i++) cout << marks[i] << " ";
    cout << "\n";
    
    return 0;
}
