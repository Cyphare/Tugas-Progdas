/*

Arnold Gavrael - 539797 - Kelas B

Cara Kerja:
1. Pengguna akan memasukkan koordinat titik pusat (x1 dan x2) serta titik ujung lingkaran (x2 y2).
2. Program akan menghitung jarak antara dua titik tersebut dan mendefinisikannya sebagai jari-jari lingkaran.
3. Program akan menghitung diameter, keliling, dan luas lingkaran menggunakan jari-jari tersebut.
4. Program akan menampilkan semua data yang telah dihitung di terminal.

*/

#include <iostream>
#include <cmath>
using namespace std;
const double pi = 3.1416;

// Fungsi jarak
double jarak(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)); }

// Fungsi jari-jari
double jari(double jarak) {
    return jarak; }

// Fungsi keliling
double keliling(double jari) {
    return 2 * pi * jari; }

// Fungsi luas
double luas(double jari) {
    return pi * jari * jari; }

// Fungsi utama
int main() {
    double x1, y1, x2, y2;

    // Input dari pengguna
    cout << "Masukkan koordinat titik pusat lingkaran (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Masukkan koordinat titik ujung lingkaran (x2 y2): ";
    cin >> x2 >> y2;
    
    // Mendefinisikan jari-jari
    double j = jari(x1, y1, x2, y2);

    // Hasil
    cout << "Jari-jari: " << j << "\n";
    cout << "Diameter: " << 2 * j << "\n";
    cout << "Keliling: " << keliling(j) << "\n";
    cout << "Luas: " << luas(j) << "\n";

    return 0; }

/*

Formal parameter adalah variabel yang dideklarasikan dalam definisi fungsi.
    Line 27 | double keliling(double jari)
        Fungsi "keliling" mempunyai formal parameter "jari" dengan tipe "double".

Actual parameter adalah nilai-nilai yang diberikan saat kita memanggil fungsi.
    Line 45 | double j = jari(x1, y1, x2, y2)
        Actual parameter "x1, y1, x2, y2" akan diberikan saat memanggil fungsi "jari".

Function signature adalah nama fungsi, tipe pengembalian, dan daftar parameter yang diperlukan oleh fungsi tersebut.
    Line 31 | double luas(double jari)
        Function signaturenya mengandung nama (luas). tipe pengembalian (double), dan parameter (double jari).

*/
