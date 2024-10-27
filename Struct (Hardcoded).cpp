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
4. Program prints all of the students' name and score.
4. Program prints the names of the students who have the highest score.

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
void readStudentData(studentType students[], int size); // Function to input student data and their number grades
void assignGrades(studentType students[], int size); // Function to assign alphabetical grades based on number grades
int findHighestScore(studentType students[], int size); // Function to find the highest score from all the student's grades
void printHighestScorers(studentType students[], int size, int highestScore); // Function to print the highest scoring student's name and their grades
void printAllStudents(studentType students[], int size); // Function to print all the students name and grades

int main() {
    studentType students[20];  // Array for 20 students

    // Function calls
    readStudentData(students, 20);
    assignGrades(students, 20);
    printAllStudents(students, 20);
    int highestScore = findHighestScore(students, 20);
    printHighestScorers(students, 20, highestScore);

    return 0;
}

// Function to read students' data
void readStudentData(studentType students[], int size) {
    // Hardcoded data for 20 students
    students[0] = {"John", "Doe", 85};
    students[1] = {"Jane", "Smith", 92};
    students[2] = {"Alice", "Johnson", 78};
    students[3] = {"Bob", "Brown", 88};
    students[4] = {"Charlie", "Davis", 90};
    students[5] = {"Eva", "Garcia", 76};
    students[6] = {"Frank", "Harris", 65};
    students[7] = {"Grace", "Martin", 95};
    students[8] = {"Hannah", "Lee", 82};
    students[9] = {"Ian", "Walker", 89};
    students[10] = {"Jack", "Hall", 70};
    students[11] = {"Kathy", "Young", 73};
    students[12] = {"Larry", "King", 92};
    students[13] = {"Mona", "Scott", 84};
    students[14] = {"Nina", "Green", 91};
    students[15] = {"Oscar", "Adams", 80};
    students[16] = {"Paul", "Baker", 63};
    students[17] = {"Quinn", "Nelson", 58};
    students[18] = {"Rachel", "Carter", 94};
    students[19] = {"Sam", "Mitchell", 67};
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

// New function to print all students' scores
void printAllStudents(studentType students[], int size) {
    cout << "\nAll Students' Scores:\n\n";
    cout << left << setw(15) << "Last Name" << setw(15) << "First Name" << setw(10) << "Score" << "Grade\n";
    cout << "---------------------------------------------\n";
    for (int i = 0; i < size; i++) {
        cout << left << setw(15) << (students[i].studentLName + ",")  // Add comma after last name
             << setw(15) << students[i].studentFName 
             << setw(10) << students[i].testScore 
             << students[i].grade << '\n';
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
    cout << "\nStudents with the highest score:\n";
    for (int i = 0; i < size; i++) {
        if (students[i].testScore == highestScore) {
            cout << students[i].studentLName << ", "
                 << students[i].studentFName << " - " 
                 << students[i].testScore << " (" << students[i].grade << ")\n";
        }
    }
}
