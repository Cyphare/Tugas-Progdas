/*

Arnold Gavrael - 539797 - Kelas B

Cara Kerja:
1. Pengguna akan memasukkan koordinat titik pusat (x1 dan y2) serta titik ujung lingkaran (x2 y2).
2. Program akan menghitung jarak antara dua titik tersebut dan mendefinisikannya sebagai jari-jari lingkaran.
3. Program akan menghitung diameter, keliling, dan luas lingkaran menggunakan jari-jari tersebut.
4. Program akan menampilkan semua data yang telah dihitung di terminal.

Opsional:
1. Pengguna akan memasukkan koordinat titk ketiga (x3 dan y3).
2. Program akan membandingkan jarak antara titik pertama dan kedua (j2) dan jarak anatara titik pertama dan ketiga (j3).
3. Jika j3 kurang dari j2, titik ada di dalam lingkaran.
4. Jika j3 sama dengan dari j2, titik ada di ujung lingkaran.
5. Jika j3 lebih dari j2, titik ada di luar lingkaran.

*/

#include <iostream>
#include <cmath>
using namespace std;
const double pi = 3.1416;

// Fungsi jarak
double jarak(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)); }

// Fungsi jari-jari
double jari(double x1, double y1, double x2, double y2) {
    return jarak(x1, y1, x2, y2); }

// Fungsi keliling
double keliling(double jari) { 
    return 2 * pi * jari; }

// Fungsi luas
double luas(double jari) { 
    return pi * jari * jari; }

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
    double j2 = jari(x1, y1, x2, y2);

    // Hasil
    cout << "\nJari-jari: " << j2 << "\n";
    cout << "Diameter: " << 2 * j2 << "\n";
    cout << "Keliling: " << keliling(j2) << "\n";
    cout << "Luas: " << luas(j2) << "\n";

    // Input titik ketiga (opsional)
    cout << "\nMasukkan titik ketiga? (y/n): ";
    cin >> pilihan;

    while (pilihan == 'Y' || pilihan == 'y') {

        cout << "\nMasukkan titik yang akan dicek (x3 y3): ";
        cin >> x3 >> y3;

        // Mendefinisikan jarak anatar titik pusat dengan titik ketiga
        double j3 = jari(x1, y1, x3, y3);

        // Cek apakah titik ada di dalam lingkaran
        if (j3 < j2) { cout << "Titik berada di dalam lingkaran.\n"; } 
        else if (j3 == j2) { cout << "Titik berada di ujung lingkaran.\n"; }
        else { cout << "Titik berada di luar lingkaran.\n"; }

        // Tanyakan lagi apakah ingin memasukkan titik ketiga
        cout << "\nIngin memeriksa titik lain? (y/n): ";
        cin >> pilihan;
    }
    return 0;
}

/*

1. Formal parameter adalah variabel yang dideklarasikan dalam definisi fungsi.
    Line 34 | double keliling(double jari)
        Fungsi "keliling" mempunyai formal parameter "jari" dengan tipe "double".

2. Actual parameter adalah nilai-nilai yang diberikan saat kita memanggil fungsi.
    Line 55 | double j2 = jari(x1, y1, x2, y2)
        Actual parameter "x1, y1, x2, y2" akan diberikan saat memanggil fungsi "jari".

3. Function signature adalah nama fungsi, tipe pengembalian, dan daftar parameter yang diperlukan oleh fungsi tersebut.
    Line 38 | double luas(double jari)
        Function signaturenya mengandung nama (luas). tipe pengembalian (double), dan parameter (double jari).

*/
