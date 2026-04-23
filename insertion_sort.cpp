#include <iostream>
using namespace std;

int main() {
    // Number of pages in books on a messy shelf
    int books[] = {500, 200, 400, 100, 300}; 
    int n = 5;
    
    cout << "Messy Book Shelf: ";
    for(int i = 0; i < n; i++) cout << books[i] << " ";
    cout << "\n";
    
    // Insertion sort to arrange books by size
    for(int i = 1; i < n; i++) {
        int currentBook = books[i];
        int j = i - 1;
        
        // Move bigger books to the right to make room
        while(j >= 0 && books[j] > currentBook) {
            books[j+1] = books[j];
            j--;
        }
        books[j+1] = currentBook; // Insert the book in its right place
    }
    
    cout << "Organized Book Shelf: ";
    for(int i = 0; i < n; i++) cout << books[i] << " ";
    cout << "\n";
    
    return 0;
}
