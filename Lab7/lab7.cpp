/**********************************
* Alexander Wise, 002907473
* Jason Lei, 002113242
**********************************/

#include <iostream>
#include <string>

void Initialize();
void Finalize();
void Grow();
void AddElement();
void PrintVector();
void RemoveElement();
void InsertElement();
void Shrink();

// Declaring variables
double *v;
int size;
int capacity;

using namespace std;

int main() {
    Initialize();
    bool exit = false;
    // Loops until user selects option 5
    while(!exit){
        int selection;
        // Prompts user with options
        cout << "Main menu:\n ";
        cout << "\t1. List vector's contents\n";
        cout << "\t2. Append element at the end\n";
        cout << "\t3. Remove last element\n";
        cout << "\t4. Insert one element\n";
        cout << "\t5. Exit\n";
        cout << "Select an option: ";

        cin >> selection;
        cout << "\nYou selected ";
        // Takes selected option into switch statmenet to process selection
        switch(selection){
            case 1:
                cout << "\"List vector's contents\"\n";
                PrintVector();
                break;
            case 2:
                cout << " \"Append element at the end\"\n";
		        AddElement();
                break;
            case 3:
                cout << " \"Remove last element\"\n";
                RemoveElement();
		break;
            case 4:
                cout << " \"Insert one element\"\n";
                InsertElement();
		break;
            case 5:
            // Sets the boolean exit to false so program exits loop
                cout << "\"Exit\"";
                exit = true;
                break;
            // Declares an error if inputed selection is not valid
            default:
                cout << "Error\nNot a valid selection\n";
        }
    }
    Finalize();
    return 0;
}

// Adds an element to the array
void AddElement() {
    // Checks to see if the array is full. If so, will double size of array
    if(size == capacity) {
        Grow();
     }
  	
    cout << "Enter the new element: ";
    double newElement;
    cin >> newElement;
    // Sets v at the max index = to the input then increases size
    v[size] = newElement;
    size++;
}

// Prints the contents of the array/vector to the console
void PrintVector(){
    cout << "Current content of the vector: ";
    // Iterates through the vector and prints each element
    for(int i = 0; i < size; i++){
      cout << v[i] << " ";
    }
    cout << endl;
}

// Increases the capacity of the array/vector when it is full
void Grow() {
    cout << "Vector grown\n";
    cout << "Previous Capacity: " << capacity << " elements\n";
    // Creates a temporary array of size capacity*2
    double *nv;
    nv = new double[capacity * 2];

    //Copies all elements from v to nv
    for(int i = 0; i < size; i++) {
	    nv[i] = v[i];
    }
    
    // Deletes v to free up memory
    delete[] v;
    // Sets V equal to the temporary array
    v = nv;
    capacity *= 2;
    cout << "New Capacity: " << capacity << " elements\n";
}

// Inserts an element at the inputted index 
void InsertElement(){
    // Checks to see if vector is full then grows it 
    if(size == capacity){
	    Grow();
    }
	
    int index;
    double newElement;
    
    // Prompts user for desired index
    cout << "\nEnter index where you would like to insert new element: ";
    cin >> index;
    // Checks to see if the desired index exists within the bounds
    if(index < 0 || index > size){
	    cout << "\nError. Invalid index\n";
	    return;
    }
    cout << "\nEnter the new value: ";
    cin >> newElement;
    // Shifts everything to the right of the index (inclusive) over by 1
    for(int i = size; i > index; i--){
	    v[i] = v[i-1];
    }
    // Places the new value at the freed up index
    v[index] = newElement;
    size++;
}

// Removes the last element from the vector
void RemoveElement(){
    // Checks to see if there is anything in the vector before removing it
    if(size > 0){
	    size--;
	    cout << "Removed last element\n";
    } else {
	    cout << "Vector is empty with no elements\n";
    }
    // Shrinks the vector in half when it is 30% full
   if (size < capacity * 0.3){
       Shrink();
   }

}

// Shrinks the vactor in half
void Shrink(){
    // Creates a temporary vector of length capacity/2
    double *nv = new double[capacity / 2];
    // Iterates through the main vector and copies the data over
    for(int i = 0; i < size; i++){
	    nv[i] = v[i];
    }
    // Deletes v to free up memory and then sets v equal to the temporary array
    delete[] v;
    v = nv;
    // Changes capacity to its new value
    capacity /= 2;
    cout << "Vector capacity reduced to: " << capacity << endl;
}

// Initializes variables for use in functions
void Initialize() {
    v = new double[capacity];
    size = 0;
    capacity = 2;
}

// Frees up the used memory
void Finalize() {
    // Deletes v to free up the used memory at the end of the progam
    delete[] v;
}
