#include <iostream>
#include <string>

using namespace std;

// function to get the grade point value for a letter grade
double getGradePoint(char letterGrade) {
    switch (letterGrade) {
        case 'A':
            return 4.0;
        case 'B':
            return 3.0;
        case 'C':
            return 2.0;
        case 'D':
            return 1.0;
        default:
            return 0.0;
    }
}

int main() {
    int numCourses;
    double totalCredits = 0.0;
    double totalGradePoints = 0.0;

    cout << "Enter the number of courses: ";
    cin >> numCourses;

    for (int i = 1; i <= numCourses; i++) {
        double credits;
        char letterGrade;

        cout << "Enter the credits for course " << i << ": ";
        cin >> credits;

        cout << "Enter the letter grade for course " << i << ": ";
        cin >> letterGrade;

        // calculate the grade point value for the letter grade
        double gradePoint = getGradePoint(letterGrade);

        // calculate the grade points for the course
        double courseGradePoints = gradePoint * credits;

        // add the course grade points and credits to the total
        totalGradePoints += courseGradePoints;
        totalCredits += credits;
    }

    // calculate the GPA
    double gpa = totalGradePoints / totalCredits;

    cout << "Your GPA is: " << gpa << endl;

    return 0;
}