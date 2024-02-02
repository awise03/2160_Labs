/******************************
* Alexander Wise, 002907473
******************************/

#include <iostream>
using namespace std;

void SwapP(int*, int*);
void SwapR(int&, int&);


int main(){
    // Initialize initial values
    int a = 1;
    int b = 5;
    
    cout << "Before Swap\na = " << a << " b = " << b;
    // Calls the SwapP function
    SwapP(&a, &b);
    cout << "\nAfter Swap by Pointer\na = " << a << " b = " << b;
    
    // Reset initial values
    a = 15;
    b = 25;

    cout << "\n\nBefore Swap\na = " << a << " b = " << b;
    // Calls the SwapR function
    SwapR(a, b);
    cout << "\nAfter Swap by Reference\na = " << a << " b = " << b;
}

// Swaps numbers through pass-by-pointer
void SwapP(int* num1, int* num2){
    // Temporary value to store num 1
    int temp = *num1;
    // Replace num1 with num2
    *num1 = *num2;
    // Replace num2 with temp value
    *num2 = temp;
}

// Swaps numbers through pass-by-reference
void SwapR(int& num1, int& num2){
    // Temporary value to store num1
    int temp = num1;
    // Replaces num1 with num2
    num1 = num2;
    // Replaces num2 with temp value
    num2 = temp;
}