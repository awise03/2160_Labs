/**********************************
* Alexander Wise, 002907473
* Jason Lei, 002113242
**********************************/

#include <iostream>
using namespace std;

void Initialize();
void Finalize();
// Declaring variables
double *v;
int size = 0;
int capacity = 0;

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
        cout << "You selected ";
        // Takes selected option into switch statmenet to process selection
        switch(selection){
            case 1:
                cout << "\"List vector's contents\"\n";
                break;
            case 2:
                cout << " \"Append element at the end\"\n";
                break;
            case 3:
                cout << " \"Remove last element\"\n";
                break;
            case 4:
                cout << " \"Insert one element\"\n";
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

void Initialize() {
    // Initializes variables for use in functions

    capacity = 2;
    size = 0;
}

void Finalize() {

}