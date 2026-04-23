#include <iostream>
using namespace std;

int main() {
    // Textbook chapters ordered by starting page number
    int pages[] = {10, 25, 45, 60, 80, 110}; 
    int numChapters = 6;
    int targetPage = 60; // Chapter we need to read
    
    int left = 0, right = numChapters - 1;
    bool found = false;
    
    cout << "Opening textbook to find the chapter starting at page " << targetPage << "...\n";
    
    while(left <= right) {
        int mid = left + (right - left) / 2;
        
        if(pages[mid] == targetPage) {
            cout << "Chapter found at index " << mid << "!\n";
            found = true;
            break;
        }
        
        if(pages[mid] < targetPage) left = mid + 1; // Look in second half
        else right = mid - 1; // Look in first half
    }
    
    if(!found) cout << "Chapter not found.\n";
    return 0;
}
