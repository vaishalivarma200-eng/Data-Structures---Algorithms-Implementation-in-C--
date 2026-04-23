#include <iostream>
#include <string>
using namespace std;

int main() {
    string backpack[] = {"Books", "Laptop", "Pen", "Lunchbox", "Keys"};
    int numItems = 5;
    string missingItem = "Pen";
    
    cout << "Looking for " << missingItem << " in the backpack...\n";
    
    bool found = false;
    for(int i = 0; i < numItems; i++) {
        if(backpack[i] == missingItem) {
            cout << "Found " << missingItem << " in pocket number " << i+1 << "!\n";
            found = true;
            break;
        }
    }
    
    if(!found) {
        cout << missingItem << " is not in the backpack.\n";
    }
    return 0;
}
