/**********************************
Alexander Wise, 002907473
Jason Lei, 002113242
**********************************/


// Setting up libaries for code functionality
#include <iostream>
#include <string>

// Provides the prototypes for the functions used in this program
void SortArray(int v[], int size);
void RandomArray(int v[], int size);
void PrintArray(int v[], int size);

// Namespace to remove the need for the std:: prefix
using namespace std;

// Main function
int main(){
    // Creates an array of length 10 full of 0's
    int v[10] = {0};
    int size = 10;
    // Calls the RandomArray function with the array and size variable
    RandomArray(v, size);
}

// Generates an array full of random values
void RandomArray(int v[], int size){
    // Iterates through the loop until j = size which is when it breaks from the loop
    
    for(int j = 0; j < size; j++){
        // Generates a random number from 0 to 100
        v[j] = rand() % 100;

        // Prints the values of v on a new line once a random number is generated
    }   
    PrintArray(v, size);
    cout << endl;
    // Calls the SortArray function with the array, v, and the size variable
    SortArray(v, size);
}

// Function that sorts the array using selection sort
void SortArray(int v[], int size){
    // Iterates through every value in v from index 0 to index size-2
    for(int k = 0; k < size - 1; k++){
        // Sets the min index to the current index
        int min = k;
        // Iterates through each element in the array from index k to size-1
        for(int n = k + 1; n < size; n++){
            // Checks to see if the value of v[n] is < value of v[min]
            if(v[n] < v[min]){
                // Sets the new min index to the current index in the inner loop
                min = n;
            }
        }
        // Checks to see if the min value is already in the correct position
        if(min != k){
            // Swaps the value of v[k] with the smallest value found in the loop above
            swap(v[k], v[min]);
        }
    }
    // Calls the PrintArray function
    PrintArray(v, size);
}

// Prints the array to the console
void PrintArray(int v[], int size){
    // Iterates through each value in v and prints it to the console
    for(int i = 0; i < size; i++){
        cout << v[i] << endl;
    }
}

