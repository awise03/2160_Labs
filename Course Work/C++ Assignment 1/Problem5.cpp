/******************************
* Alexander Wise, 002907473
******************************/

#include <iostream>
using namespace std;

// Defines struct for Students
struct Students{
    string Name;
    int Grade;
};

void printClass(Students*, int);
void averageGrade(Students*, int);
void maxGrade(Students*, int);
void minGrade(Students*, int);
void sortGrades(Students*, int);

int main() {
    int classSize;
    int i = 0;

    // Prompts user to input class size
    cout << "Enter the size of the class: ";
    cin >> classSize;

    // Creates a new dynamic array of length ClassSize
    Students *classData = new Students[classSize];
    
    // Loops thorugh each index to input student name and grade
    for(int i = 0; i < classSize; i++){
        int grade;

        cout << "\nEnter student name: ";
        // Assigns student name to associated value within the struct
        cin >> classData[i].Name;

        // Checks to see if the inputed student grade is valid. Loops until valid input
        do {
            cout << "Enter student grade (0 to 100): ";
            cin >> grade;
        } while(grade > 100 || grade < 0);
        // Assigns grade to associated value within the struct
        classData[i].Grade = grade;
    }
    // Calls all functions
    printClass(classData, classSize);
    averageGrade(classData, classSize);
    minGrade(classData, classSize);
    maxGrade(classData, classSize);
}

// Prints the class' information
void printClass(Students *classData, int classSize) {
    sortGrades(classData, classSize);
    cout << "\nStudent:\tGrade:\n";
    // Iterates through each student within the array and prints their grade and name
    for(int i = 0; i < classSize; i++) {
        cout << classData[i].Name << "\t\t" << classData[i].Grade << endl;
    }
}

// Sorts student grades into descending order
void sortGrades(Students *classData, int classSize) {
    for (int i = 0; i < classSize - 1; i++) {
        int max = i; 

        // Find the maximum element
        for (int j = i + 1; j < classSize; j++) {
            // Compare to see if grade is greater than current max
            if (classData[j].Grade > classData[max].Grade) { 
                max = j;
            }
        }
        // Swap if a greater element is found
        if (max != i) {
            swap(classData[i], classData[max]);
        }
    }
}

// Finds and prints the mean and median grades
void averageGrade(Students *classData, int classSize){
    int sum = 0;
    
    // Calculates the sum of all the grades
    for(int i = 0; i < classSize; i++){
        sum += classData[i].Grade;
    }
    // Calculates the average
    float average = sum/classSize;
    float median;

    // Checks if there are an odd or even number of students in the class
    if(classSize % 2 == 0){
        // Calculates median based on an even number of students
        median = (classData[(classSize-1)/2].Grade + classData[((classSize-1)/2) + 1].Grade)/2.0;
    } else {
        // Calculates median based on an odd number of students
        median = classData[classSize/2].Grade;
    }
    cout << "\nThe average grade is " << average << endl;
    cout << "The median grade is " << median << endl;
}

// Displays the max grade and student
void maxGrade(Students *classData, int classSize){
    // the max grade will be the first index after sorting
    cout << "The max grade is " << classData[0].Grade << " by " << classData[0].Name << endl;
}

// Displays the min grade and student
void minGrade(Students *classData, int classSize){
    // The min grade will be the last index after sorting
    cout << "The min grade is " << classData[classSize - 1].Grade << " by " << classData[classSize - 1].Name << endl;
}