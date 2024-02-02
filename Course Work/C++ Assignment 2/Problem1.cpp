/******************************
* Alexander Wise, 002907473
******************************/

#include <iostream>
using namespace std;

class Student {
    private:
        string name;
        string major;
        float gpa;

    public:
        // Function to return the student gpa
        float getGPA() {
            return gpa;
        }

        // Function to read and set student information
        void readStudentInfo(string name, string major, float gpa) {
            this->name = name;
            this->major = major;
            this->gpa = gpa;
        }

        // Function to print student information
        void printStudentInfo() {
            cout << "Name: " << name << endl;
            cout << "Major: " << major << endl;
            cout << "GPA: " << gpa << endl << endl;
        }
};

class CourseSection {
    private:
        int sectionSize;
        Student *roster;

    public:
        // Constructor to initialize the CourseSection with a given size
        CourseSection(int classSize){
            sectionSize = classSize;
            roster = new Student[sectionSize];
        }

        // Function to read information for all students in the section
        void readAllInfo() {
            for (int i = 0; i < sectionSize; i++) {
                string name, major;
                float gpa;
                cout << "Enter student name, major, and GPA separated by a space: \n";
                cin >> name >> major >> gpa;
                roster[i].readStudentInfo(name, major, gpa);
            }
        }

        // Function to print information for all students in the section
        void printAllInfo() {
            for (int i = 0; i < sectionSize; i++) {
                roster[i].printStudentInfo();
            }
        }

        // Function to print information for the student with the highest GPA
        void printTopGPAStudent() {
            float topGPA = -1;
            int topGPAIndex = -1;

            // Finding the student with the highest GPA
            for (int i = 0; i < sectionSize; i++) {
                if (topGPA < roster[i].getGPA()) {
                    topGPA = roster[i].getGPA();
                    topGPAIndex = i;
                }
            }

            // Printing information for the student with the highest GPA
            if (topGPAIndex != -1) {
                roster[topGPAIndex].printStudentInfo();
            } else {
                cout << "No students in the section.\n";
            }
        }

        // Destructor to release dynamically allocated memory
        ~CourseSection() {
            delete[] roster;
        }
};

int main() {
    // Prompt user for the number of students in the course section
    int num;
    cout << "How many students in the course section? ";
    cin >> num;

    // Create a CourseSection object with the specified number of students
    CourseSection cs(num);

    // Input information for all students in the section
    cout << "Input the info of all students in the section:\n";
    cs.readAllInfo();

    // Display the information for all students in the section
    cout << "The following are the students in the section:\n";
    cs.printAllInfo();

    // Display the information for the student with the highest GPA
    cout << "The info of the student with the highest GPA:\n";
    cs.printTopGPAStudent();

    return 0;
}

