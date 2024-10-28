// Arnold Gavrael - 539797 - Kelas B

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
void printAllStudents(studentType students[], int size); 
void printHighestScorers(studentType students[], int size, int highestScore); 

int main() {

    // Set an array for 20 students
    studentType students[20];  

    // Function calls
    readStudentData(students, 20);
    assignGrades(students, 20);
    printAllStudents(students, 20);
    int highestScore = findHighestScore(students, 20);
    printHighestScorers(students, 20, highestScore);

    return 0;
}

// Function to input student data and their number grades
void readStudentData(studentType students[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter first name, last name, and test score for student " << i + 1 << ": ";
        cin >> students[i].studentFName >> students[i].studentLName >> students[i].testScore;
        // You enter the data as follows: First name, Last name, Score
    }
}

// Function to assign alphabetical grades based on number grades
void assignGrades(studentType students[], int size) {
    for (int i = 0; i < size; i++) {
        if (students[i].testScore >= 90) {students[i].grade = 'A';} // 90-100 gets an A
        else if (students[i].testScore >= 80) {students[i].grade = 'B';} // 80-89 gets a B
        else if (students[i].testScore >= 70) {students[i].grade = 'C';} // 70-79 gets a C
        else if (students[i].testScore >= 60) {students[i].grade = 'D';} // 60-69 gets a D
        else if (students[i].testScore >= 50) {students[i].grade = 'E';} // 50-59 gets an E
        else {students[i].grade = 'F';} // 0-49 gets an F
    }
}

// Function to print all the students name and grades
void printAllStudents(studentType students[], int size) {
    cout << "\nAll Students' Scores:\n\n";
    cout << left << setw(20) << "Name" << setw(10) << "Score" << "Grade\n";
    cout << "------------------------------------\n";
    for (int i = 0; i < size; i++) {
        cout << left << setw(20) << (students[i].studentLName + ", " + students[i].studentFName)
             << setw(10) << students[i].testScore 
             << students[i].grade << '\n';
        // "setw" sets a width at the start of a word, so that any word typed after is justified
    }
}

// Function to find the highest score from all of the student
int findHighestScore(studentType students[], int size) {
    int highest = students[0].testScore;
    for (int i = 1; i < size; i++) {
        if (students[i].testScore > highest) {
            highest = students[i].testScore;
        }
    }
    return highest;
    // It sets the first student's grade as the highest and compares it to the next
    // If it is higher, it sets that as the highest.
    // In the end, the highest score will be foung (bubble sort).
}

// Function to print the highest scoring student's name and their grades
void printHighestScorers(studentType students[], int size, int highestScore) {
    cout << "\nStudents with the highest score:\n";
    for (int i = 0; i < size; i++) {
        if (students[i].testScore == highestScore) {
            cout << students[i].studentLName << ", "
                 << students[i].studentFName << " - " 
                 << students[i].testScore << " (" << students[i].grade << ")\n";
        }
    }
}
