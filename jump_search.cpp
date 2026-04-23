#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int pages[] = {10, 20, 30, 40, 50, 60, 70, 80, 90}; 
    int n = 9;
    int target = 70;
    
    cout << "Jumping through textbook to find page " << target << "...\n";
    
    int step = sqrt(n); 
    int prev = 0;
    
    while(pages[min(step, n)-1] < target) {
        prev = step;
        step += sqrt(n);
        if(prev >= n) { cout << "Not found.\n"; return 0; }
    }
    
    while(pages[prev] < target) {
        prev++;
        if(prev == min(step, n)) { cout << "Not found.\n"; return 0; }
    }
    
    if(pages[prev] == target) 
        cout << "Topic found at array index " << prev << "!\n";
    else 
        cout << "Topic not found.\n";
        
    return 0;
}
