#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Student {
private:
    int student_id;
    string name;
    int age;
    int grade;
    string department;

public:
    Student(int sid, string name, int age, int grade, string dep)
        : student_id(sid), name(name), age(age), grade(grade), department(dep) {}

    // Getter methods
    int getStudentID() const { return student_id; }
    string getName() const { return name; }
    int getAge() const { return age; }
    int getGrade() const { return grade; }
    string getDepartment() const { return department; }

    // Function to display student details
    void displayStudentDetails() const {
        cout << "Student ID: " << student_id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Grade: " << grade << endl;
        cout << "Department: " << department << endl;
    }
};

// Global variable to hold student records
vector<Student> students;

// Function prototypes
void displayMenu();
void addStudent(vector<Student>& students);
void displayAllStudents();
Student* searchStudentByID(int student_id);
void editStudent(vector<Student>& students);
void deleteStudent(vector<Student>& students);

void displayMenu() {
    cout << "===== Student Database Management System =====" << endl;
    cout << "1. Add New Student" << endl;
    cout << "2. Display All Students" << endl;
    cout << "3. Search Student by ID" << endl;
    cout << "4. Edit Student Information" << endl;
    cout << "5. Delete Student Record" << endl;
    cout << "6. Exit" << endl;
}

void addStudent(vector<Student>& students) {
    int id, age, grade;
    string name, department;

    // Collect student information from the user
    cout << "Enter Student ID: ";
    cin >> id;
    cin.ignore();  // Ignore the newline character left in the input buffer

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Age: ";
    cin >> age;

    cout << "Enter Grade: ";
    cin >> grade;
    cin.ignore();  // Ignore the newline character left in the input buffer

    cout << "Enter Department: ";
    getline(cin, department);

    // Create a Student object using the collected information
    Student newStudent(id, name, age, grade, department);

    // Add the newly created Student object to the vector
    students.push_back(newStudent);
}

void displayAllStudents() {
    cout << "All Students:" << endl;
    for (const auto& student : students) {
        student.displayStudentDetails();
        cout << "---------------------------------" << endl;
    }
}

Student* searchStudentByID(int student_id) {
    for (auto& student : students) {
        if (student.getStudentID() == student_id) {
            return &student;  // Return a pointer to the found student
        }
    }
    return nullptr;  // Return nullptr if the student is not found
}

void editStudent(vector<Student>& students) {
    int id;
    cout << "Enter Student ID to edit: ";
    cin >> id;
    cin.ignore();  // Ignore the newline character left in the input buffer

    // Find the student by ID using searchStudentByID
    Student* student = searchStudentByID(id);

    if (student) {
        // Student found, update their details
        cout << "Editing details for Student ID " << id << endl;

        string name, department;
        int age, grade;

        cout << "Enter new Name: ";
        getline(cin, name);

        cout << "Enter new Age: ";
        cin >> age;

        cout << "Enter new Grade: ";
        cin >> grade;
        cin.ignore();  // Ignore the newline character left in the input buffer

        cout << "Enter new Department: ";
        getline(cin, department);

        // Update the student object
        *student = Student(id, name, age, grade, department);
        cout << "Student details updated successfully." << endl;
    } else {
        cout << "Student ID not found." << endl;
    }
}

void deleteStudent(vector<Student>& students) {
    int id;
    cout << "Enter Student ID to delete: ";
    cin >> id;
    cin.ignore();  // Ignore the newline character left in the input buffer

    // Find the student by ID using searchStudentByID
    Student* student = searchStudentByID(id);

    if (student) {
        // Remove the student from the vector
        auto it = remove_if(students.begin(), students.end(), [id](const Student& s) {
            return s.getStudentID() == id;
        });

        // Check if any element was actually removed
        if (it != students.end()) {
            students.erase(it, students.end());  // Erase the removed elements
            cout << "Student ID " << id << " has been deleted." << endl;
        } else {
            cout << "Error in removing student. Please try again." << endl;
        }
    } else {
        cout << "Student ID not found." << endl;
    }
}

int main() {
    int choice;

    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addStudent(students);
            break;
        case 2:
            displayAllStudents();
            break;
        case 3: {
            // Prompt for student ID
            int id;
            cout << "Enter Student ID to search: ";
            cin >> id;
            cin.ignore();  // Ignore the newline character left in the input buffer

            // Search for the student by ID
            Student* student = searchStudentByID(id);
            if (student) {
                student->displayStudentDetails();
            } else {
                cout << "Student ID not found." << endl;
            }
            break;
        }
        case 4:
            editStudent(students);
            break;
        case 5:
            deleteStudent(students);
            break;
        case 6:
            cout << "Exiting the program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
