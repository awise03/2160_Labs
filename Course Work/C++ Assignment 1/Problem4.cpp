/******************************
* Alexander Wise, 002907473
******************************/

#include <iostream>

using namespace std;

int main() {
    char myChar;
    cout << "Enter letter to convert to upper-case: ";
    cin >> myChar;
    // AND operation with the binary number of 11011111 (223)
    // This makes the 6th bit a 0 which converts it to upper case
    myChar = myChar & 223;

    cout << myChar << endl;

    cout << "Enter letter to convert to lower-case: ";
    cin >> myChar;
    // OR operation with the binary number 00100000 (32)
    // This makes the 6th bit a 1 which converts it to lower case
    myChar = myChar | 32;
    cout << myChar << endl;
}