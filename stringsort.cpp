/**********************************
Alexander Wise, 002907473
Jason Lei, 002113242
**********************************/

// Setting up libary for code functionality
#include <iostream>
// Namespace to remove the need for the std:: prefix
using namespace std;

// Provides the prototypes for the functions used in this program
void SortArray(string w[], int size);
void PrintArray(string w[], int size);

// Main function
int main(){
    // Initialize variables for the program
    string words[10];
    string input = "";
    int size = 10;
    // Iterates through all indexes in the array words
    for(int i = 0; i < size; i++){
        // Calls for an input in the console from the user
        cin >> input;
        // Sets words[i] = to the user input
        words[i] = input;
    }
    // Calls the SortArray function
    SortArray(words, size);
}
// Sorts the words through selection sort
void SortArray(string w[], int size) {
    // Iterates through every value in w from index 0 to index size-2
    for (int i = 0; i < size - 1; i++) {
         // Sets the min index to the current index
        int minIndex = i;
        // Iterates through each element in the array from index i to size-1
        for (int j = i + 1; j < size; j++) {
            // Checks to see if the string value of w[j] is < string value of w[minIndex]
            if (w[j] < w[minIndex]) {
                // Sets the new min index to the current index in the inner loop
                minIndex = j;
            }
        }
        // Checks to see if the min value is already in the correct position
        if (minIndex != i) {
            // Swaps the value of w[i] with the smallest value found in the loop above
            swap(w[i], w[minIndex]);
        }
    }
    // Calls the PrintArray function
    PrintArray(w, size);
}
// Prints the array to the console
void PrintArray(string w[], int size) {
    // Iterates through each value in w and prints it to the console
    for(int n = 0; n < size; n++){
        cout << w[n] << " ";
    }
}