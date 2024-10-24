/*

Arnold Gavrael - 539797 - Kelas B

How it works:
1. Program reads student data (first name, last name, test score) from input.
2. Program assigns a grade based on the student's score:
    'A' for 90 and above,
    'B' for 80-89,
    'C' for 70-79,
    'D' for 60-69,
    'F' for below 60.

3. Program finds the highest score among all students.
4. Program pints the names of the students who have the highest score.

*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Defining struct for studentType
struct studentType {
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

// Function prototypes
void readStudentData(studentType students[], int size);
void assignGrades(studentType students[], int size);
int findHighestScore(studentType students[], int size);
void printHighestScorers(studentType students[], int size, int highestScore);

int main() {
    studentType students[20];  // Array for 20 students

    // Function calls
    readStudentData(students, 20);
    assignGrades(students, 20);
    int highestScore = findHighestScore(students, 20);
    printHighestScorers(students, 20, highestScore);

    return 0;
}

// Function to read students' data
void readStudentData(studentType students[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter first name, last name, and test score for student " << i + 1 << ": ";
        cin >> students[i].studentFName >> students[i].studentLName >> students[i].testScore;
    }
}

// Function to assign grades based on score
void assignGrades(studentType students[], int size) {
    for (int i = 0; i < size; i++) {
        if (students[i].testScore >= 90) students[i].grade = 'A';
        else if (students[i].testScore >= 80) students[i].grade = 'B';
        else if (students[i].testScore >= 70) students[i].grade = 'C';
        else if (students[i].testScore >= 60) students[i].grade = 'D';
        else students[i].grade = 'F';
    }
}

// Function to find the highest score
int findHighestScore(studentType students[], int size) {
    int highest = students[0].testScore;
    for (int i = 1; i < size; i++) {
        if (students[i].testScore > highest) {
            highest = students[i].testScore;
        }
    }
    return highest;
}

// Function to print names of students with the highest score
void printHighestScorers(studentType students[], int size, int highestScore) {
    cout << "Students with the highest score (" << highestScore << "):" << endl;
    for (int i = 0; i < size; i++) {
        if (students[i].testScore == highestScore) {
            cout << left << setw(10) << students[i].studentLName << ", " 
                 << students[i].studentFName << " - " 
                 << students[i].testScore << " (" << students[i].grade << ")" << endl;
        }
    }
}

/*

Validity of Statements:

a. student.course.callNum = "CSC230";
Invalid
Reason: callNum is of type int, but you're trying to assign a string to it, which will result in a type mismatch.

b. cin >> student.name;
Invalid
Reason: name is a structure of type nameType, and cin cannot be used directly for a struct. You would need to access individual members like cin >> student.name.first >> student.name.last.

c. classList[0] = name;
Invalid
Reason: classList[0] is of type studentType, but name is of type nameType. These types are not compatible, so this assignment is invalid.

d. classList[1].gpa = 3.45;
Valid
Reason: The gpa field exists in studentType as a double, and assigning a double value is valid.

e. name = classList[15].name;
Valid
Reason: Both name and classList[15].name are of type nameType, so this assignment is valid.

f. student.name = name;
Valid
Reason: Both student.name and name are of type nameType, so this assignment is valid.

g. cout << classList[10] << endl;
Invalid
Reason: You cannot output an entire struct directly to cout. You need to access individual members of classList[10].

h. for (int j = 0; j < 100; j++) classList[j].name = name;
Valid
Reason: Each element in classList is of type studentType, and name is of type nameType. Assigning the nameType object to the name field is valid.

i. classList.course.credits = 3;
Invalid
Reason: The classList array contains studentType objects, which have a course field, but the correct syntax would be classList[i].course.credits to access the credits field for a specific student.

j. course = studentType.course;
Invalid
Reason: The correct way would be to access studentType via an instance like course = student.course.

*/
