// Arnold Gavrael - 539797 - Kelas B

#include <iostream>
#include <cmath>
using namespace std;
const double pi = 3.1416; // Set pi agar konstan


// Fungsi jarak
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)); }


// Fungsi jari-jari
double radius(double x1, double y1, double x2, double y2) {
    return distance(x1, y1, x2, y2); }


// Fungsi keliling
double circumference(double radius) { 
    return 2 * pi * radius; }


// Fungsi luas
double area(double radius) { 
    return pi * radius * radius; }


// Fungsi utama
int main() {

    // Deklarasi variabel
    double x1, y1, x2, y2, x3, y3;
    char pilihan;

    // Input dari pengguna
    cout << "Masukkan koordinat titik pusat lingkaran (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Masukkan koordinat titik ujung lingkaran (x2 y2): ";
    cin >> x2 >> y2;

    // Mendefinisikan jari-jari
    double r2 = radius(x1, y1, x2, y2);

    // Output hasil
    cout << "\nJari-jari: " << r2 << '\n';
    cout << "Diameter: " << 2 * r2 << '\n';
    cout << "Keliling: " << circumference(r2) << '\n';
    cout << "Luas: " << area(r2) << '\n';

    // Input titik ketiga (opsional)
    cout << "\nMasukkan titik ketiga? (y/n): ";
    cin >> pilihan;

    while (pilihan == 'Y' || pilihan == 'y') {

        cout << "\nMasukkan titik yang akan dicek (x3 y3): ";
        cin >> x3 >> y3;

        // Mendefinisikan jarak antara titik pusat dengan titik ketiga
        double r3 = radius(x1, y1, x3, y3);

        // Jika r3 < r2, titik di dalam lingkaran
        if (r3 < r2) { cout << "Titik berada di dalam lingkaran.\n"; }  

        // Jika r3 = r2, titik di ujung lingkaran
        else if (r3 == r2) { cout << "Titik berada di ujung lingkaran.\n"; } 
        
        // Jika r3 > r2, titik di luar lingkaran
        else { cout << "Titik berada di luar lingkaran.\n"; }

        // Tanyakan lagi apakah ingin memasukkan titik lain
        cout << "\nIngin memeriksa titik lain? (y/n): ";
        cin >> pilihan;
    }
    return 0;
}
