// Arnold Gavrael - 539797 - Kelas B

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Mendefinisikan struct
struct studentType {
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

// Prototip fungsi
void readStudentData(studentType students[], int size); 
void assignGrades(studentType students[], int size); 
int findHighestScore(studentType students[], int size); 
void printAllStudents(studentType students[], int size); 
void printHighestScorers(studentType students[], int size, int highestScore); 

int main() {

    // Set array buat 20 siswa
    studentType students[20];  

    // Call fungsi
    readStudentData(students, 20);
    assignGrades(students, 20);
    printAllStudents(students, 20);
    int highestScore = findHighestScore(students, 20);
    printHighestScorers(students, 20, highestScore);

    return 0;
}

// Fungsi untuk menginput data siswa
void readStudentData(studentType students[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter first name, last name, and test score for student " << i + 1 << ": ";
        cin >> students[i].studentFName >> students[i].studentLName >> students[i].testScore;
        // Kamu menginput data seperti berikut: Nama depan, nama belakang, skor
    }
}

// Fungsi untuk memberikan nilai huruf berdasarkan nilai angka
void assignGrades(studentType students[], int size) {
    for (int i = 0; i < size; i++) {
        if (students[i].testScore >= 90) {students[i].grade = 'A';} // 90-100 dapat A
        else if (students[i].testScore >= 80) {students[i].grade = 'B';} // 80-89 dapat B
        else if (students[i].testScore >= 70) {students[i].grade = 'C';} // 70-79 dapat C
        else if (students[i].testScore >= 60) {students[i].grade = 'D';} // 60-69 dapat D
        else if (students[i].testScore >= 50) {students[i].grade = 'E';} // 50-59 dapat E
        else {students[i].grade = 'F';} // 0-49 dapat F
    }
}

// Fungsi untuk menampilkan data siswa dan nilai dalam bentuk tabel
void printAllStudents(studentType students[], int size) {
    cout << "\nAll Students' Scores:\n\n";
    cout << left << setw(20) << "Name" << setw(10) << "Score" << "Grade\n";
    cout << "------------------------------------\n";
    for (int i = 0; i < size; i++) {
        cout << left << setw(20) << (students[i].studentLName + ", " + students[i].studentFName)
             << setw(10) << students[i].testScore 
             << students[i].grade << '\n';
        // "setw" akan mengatur panjang spasi dari awal kata sehingga kata selanjutnya akan justified
    }
}

// Fungsi untuk menemukan skor terbesar dari semua siswa (bubble sort)
int findHighestScore(studentType students[], int size) {
    int highest = students[0].testScore;
    for (int i = 1; i < size; i++) {
        if (students[i].testScore > highest) {
            highest = students[i].testScore;
        }
    }
    return highest;
    // Skor siswa pertama diset sebagai highest dan dibandingkan dengan nilai siswa selanjutnya
    // Jika siswa itu lebih tinggi, nilainya akan diset sebagai highest
    // Di akhir, akan ditemukan nilai tertinggi dari semua siswa
}

// Fungsi untuk menampilkan siswa dengan nilai tertinggi dan nilainya sendiri
void printHighestScorers(studentType students[], int size, int highestScore) {
    cout << "\nStudents with the highest score:\n";
    for (int i = 0; i < size; i++) {
        if (students[i].testScore == highestScore) {
            cout << students[i].studentLName << ", "
                 << students[i].studentFName << " - " 
                 << students[i].testScore << " (" << students[i].grade << ")\n";
            // Formatnya adalah: Nama depan, nama belakang - skor (huruf)
        }
    }
}
