/******************************
* Alexander Wise, 002907473
******************************/

#include <string>
#include <iostream>
using namespace std;

// NEPerson class definition
class NEPerson {
    private:
        int id;
        string pname; // Only first name as one word
        string address; // Only the city as one word
    public:
        // Default constructor
        NEPerson(){
            id = 0;
            pname = "";
            address = "";
        }

        // Constructor with parameters
        NEPerson(int d, string n, string a)
            { id = d;  pname = n; address = a;}

        // Function to print information
        void printInfo() {  
            cout << "Name: " << pname;
            cout << "\t ID: " << id;
            cout << "\t Address: " << address << endl;
        }

        // Question 1
        bool operator < (const NEPerson &p2) {
            return this->pname < p2.pname;
        }

        // Function to get person information from user input
        void GetPersonInfo() {
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> pname;
            cout << "Enter Address: ";
            cin >> address;
        }

};

// NEStudent class definition, inherits from NEPerson
class NEStudent : public NEPerson {
    private:
        string major; // As one word with no spaces
        float gpa;
        int CurCoursesNum; // Number of courses in which the student is currently enrolled
        string* CurEnrolledCourses; // The course codes with no spaces (e.g., EECE2160)

    public:
        // Default constructor
        NEStudent(){
            CurCoursesNum = 0;
            major = "";
            gpa = 0.0;
            CurEnrolledCourses = NULL;
        }
        
        // Constructor with parameters
        NEStudent(int d, string n, string a, string m, float g, int cnum) : NEPerson(d, n, a)
            { major = m; gpa = g; CurCoursesNum = cnum; CurEnrolledCourses = NULL;}

        // Function to add enrolled courses
        void addEnrolledCourses() {
            CurEnrolledCourses = new string[CurCoursesNum];

            cout << "Enter the code of " << CurCoursesNum;
            cout << " course(s) for the student:\n";

            for (int i = 0; i < CurCoursesNum; i++) 
                cin >> CurEnrolledCourses[i];  
        }

        // Virtual Function to print student information
        virtual void printInfo() {
            NEPerson::printInfo();
            
            cout << "\t Student Major: " << major;
            cout << "\t GPA = " << gpa;
            cout << "\n\t Taking Courses (enter only the course code with no spaces):\n";
            
            for (int i = 0; i < CurCoursesNum; i++)   
                cout << "\t   " << CurEnrolledCourses[i] << endl;   
        }

        // Function to get student information from user input
        void GetStudentInfo() {
            NEPerson::GetPersonInfo();
            cout << "Enter Major: ";
            cin >> major;
            cout << "Enter GPA: ";
            cin >> gpa;
            cout << "Enter number of current courses: ";
            cin >> CurCoursesNum;
            addEnrolledCourses();
        }

        // Question 2
        bool operator < (const NEStudent &s2){
            return this->gpa < s2.gpa;
        }

        // Destructor to free memory
        ~NEStudent() {
            if(CurEnrolledCourses) delete[] CurEnrolledCourses;
        }
};

// NETeacher class definition, inherits from NEPerson
class NETeacher : public NEPerson {
    private:
        string rank; // As one word with no spaces
        string department; // As one word with no spaces
        int CurCoursesLoad; // Number of courses the teacher is currently teaching
        string* CurCoursesTeaching; // The course codes with no spaces (e.g., EECE2160)
    public:
        // Default constructor
        NETeacher(){
            CurCoursesLoad = 0;
            CurCoursesTeaching = NULL;
            rank = "";
            department = "";
        }

        // Constructor with parameters
        NETeacher(int d, string n, string a, string r, string p, int cnum) : NEPerson(d, n, a)
        { rank = r; department = p; CurCoursesLoad = cnum; CurCoursesTeaching = NULL;}
        
        // Virtual Function to print teacher information
        virtual void printInfo() {
            NEPerson::printInfo();
            cout << "\t Teacher Rank: " << rank;
            cout << "\t Department = " << department;
            cout << "\n\t Teaching Courses:\n";
            for (int i = 0; i < CurCoursesLoad; i++)  
                cout << "\t   " << CurCoursesTeaching[i] << endl;
        }

        // Function to add courses being taught
        void addCoursesTeaching() {
            CurCoursesTeaching = new string[CurCoursesLoad];
            cout << "Enter the code of the " << CurCoursesLoad;
            cout << " course(s) the teacher is teaching (code with no spaces):\n";
            for (int i = 0; i < CurCoursesLoad; i++)
                cin >> CurCoursesTeaching[i]; 
        }

        // Function to get teacher information from user input
        void GetTeacherInfo() {
            NEPerson::GetPersonInfo();
            cout << "Enter Rank: ";
            cin >> rank;
            cout << "Enter Department: ";
            cin >> department;
            cout << "Enter Number of Courses: ";
            cin >> CurCoursesLoad;
            addCoursesTeaching();
        }

        // Destructor to free memory
        ~NETeacher() { 
            if (CurCoursesTeaching) delete[] CurCoursesTeaching; 
        }

};

// NEGradStudent class definition, inherits from NEStudent and NETeacher
class NEGradStudent : public NEStudent, public NETeacher {
    private:
        string gradLevel;
    public:
        // Constructor with initialization of gradLevel
        NEGradStudent(string gl){ gradLevel = gl; }

        // Function to get information for a grad student
        void GetGradInfo() {
            NEStudent::GetStudentInfo();
            NETeacher::GetTeacherInfo();
        }

        // Virtual Function to print information for a grad student
        virtual void printInfo(){
            NEStudent::printInfo();
            NETeacher::printInfo();
        }

};

// Template function to print info of two objects in a specific order
template <class T>   
    void PrintOrdered(T &v1, T &v2) {
        if (v1 < v2) { 
            v1.printInfo(); 
            v2.printInfo(); 
        } else { 
            v2.printInfo(); 
            v1.printInfo(); 
        }
    }

// Template function to print info of two objects in reverse order of the template above
template <class T>
    void PrintReverseOrdered(T &v1, T &v2) {
        if(v1 < v2) {
            v2.printInfo();
            v1.printInfo();
        } else {
            v1.printInfo();
            v2.printInfo();
        }
    }

// Main function
int main() {
    // Create instances of NEStudent and NETeacher
    NEStudent s1(111, "John", "Boston", "CE", 3.2, 2);
    NEStudent s2(222, "Emily", "Cambridge", "CS", 3.6, 3);
    NETeacher t1(888, "Mary", "Dedham", "Assistant Professor", "EECE", 3);
    NETeacher t2(999, "Adam", "Foxboro", "Associate Professor", "CS", 2);

    // Add enrolled courses and courses being taught
    s1.addEnrolledCourses();
    s2.addEnrolledCourses();
    t1.addCoursesTeaching();
    t2.addCoursesTeaching();

    // Create pointers to NEPerson 
    NEPerson* ps1 = &s1;
    NEPerson* ps2 = &s2;
    NEPerson* pt1 = &t1;
    NEPerson* pt2 = &t2;
    
    // Print information for individuals
    ps1 -> printInfo();
    ps2 -> printInfo();

    // Question 3
    cout << "\n Students ordered by GPA (Ascending):\n";
    PrintOrdered(s1, s2);

    // Print teachers ordered alphabetically (Ascending)
    cout << "\n Teachers ordered alphabetically (Ascending):\n";
    PrintOrdered(t1, t2);

    // Question 4
    cout << "\n Students ordered alphabetically:\n";
    PrintOrdered(*ps1, *ps2);

    // Question 5
    cout << "\n Students ordered by GPA (Descending):\n";
    PrintReverseOrdered(s1, s2);

    // Print teachers ordered alphabetically (Descending)
    cout << "\n Teachers ordered alphabetically (Descending):\n";
    PrintReverseOrdered(t1, t2);

    // Question 8
    NEStudent s3;
    NETeacher t3;
    
    cout << "\n Input information for Student s3:\n";
    s3.GetStudentInfo();
    cout << "\n Input information for Teacher t3:\n";
    t3.GetTeacherInfo();

    // Print information for Student s3 and Teacher t3
    cout << "\n Information for Student s3:\n";
    s3.printInfo();
    cout << "\n Information for Teacher t3:\n";
    t3.printInfo();

    // Create instance of NEGradStudent using user input
    NEGradStudent g1("PhD");
    cout << "\n Input information for Grad Student g1:\n";
    g1.GetGradInfo();

    // Print information for Grad Student g1
    cout << "\n Information for Grad Student g1";
    g1.printInfo();

    // Question 6
    delete ps1;
    delete ps2;
    delete pt1;
    delete pt2;
    
    return 0;
}
