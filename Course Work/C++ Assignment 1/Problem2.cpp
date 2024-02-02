/******************************
* Alexander Wise, 002907473
******************************/

# include <iostream>
using namespace std;

void PointerSwap(int*&, int*&);

int main () {
    int x = 1, y = 9;
    int *p1, *p2;
    p1 = &x;
    p2 = &y;

    cout << *p1 << " and " << *p2 << endl; //displays "1 and 9"
    cout << x << " and " << y << endl; //displays "1 and 9"

    PointerSwap(p1, p2);

    cout << *p1 << " and " << *p2 << endl; //displays "9 and 1"
    cout << x << " and " << y << endl; //displays "1 and 9"

    return 0;
}

// Function definition for swapping two integer pointers by reference
void PointerSwap(int* &p1, int* &p2) {
    int* temp;
    // Store the memory address of p1 in a temporary variable
    temp = p1; 
    // Assign the address of p2 to p1
    p1 = p2;  
    // Assign the memory address from the temporary variable to p2 
    p2 = temp; 
}