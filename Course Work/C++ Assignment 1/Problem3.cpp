/******************************
* Alexander Wise, 002907473
******************************/

#include <iostream>
using namespace std;

void mirror(int*, int);

int main() {
    // Declare array
    int v[] = {5, 6, 7, 8, 2, 1};
    // Mirror it
    mirror(v, 6);
    // Print array
    for (int i = 0; i < 6; i++) cout << v[i] << '\n';
    return 0;
}

void mirror(int* v, int n) {
    // Makes a copy of n to count backwards
    int reverseCounter = n - 1;
    int temp;
    // Loops through the first half of the array
    for(int i = 0; i < n/2; i++, reverseCounter--){
        // Stores the front element in a temporary variable
        temp = v[i];
        // Replaces front element with rear element
        v[i] = v[reverseCounter];
        // Replaces rear element with front element
        v[reverseCounter] = temp;
    }
}

