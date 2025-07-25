#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // untuk transform
#include <cctype>    // untuk tolower()

using namespace std;

// Struktur data lokasi kelas
struct Kelas {
    string nama_kelas;
    string deskripsi;
};

// Fungsi bantu untuk mengubah string menjadi lowercase
string toLower(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

// Fungsi pencarian lokasi kelas berdasarkan nama kelas
Kelas* cariLokasiKelas(vector<Kelas>& daftar_kelas, string input_kelas) {
    string input_lower = toLower(input_kelas);

    for (int i = 0; i < daftar_kelas.size(); i++) {
        if (toLower(daftar_kelas[i].nama_kelas) == input_lower) {
            return &daftar_kelas[i];
        }
    }

    return NULL;
}

int main() {
    // Data lokasi kelas
    vector<Kelas> daftar_kelas;

    daftar_kelas.push_back({"Habibi", "Gedung Teknik, Lantai 3, atas aula Djuanda"});
    daftar_kelas.push_back({"Al-Biruni", "Gedung Teknik, Lantai 2, sebelah aula Djuanda"});
    daftar_kelas.push_back({"Al-Battani", "Gedung Teknik, Lantai 1, sebelah pintu masjid perempuan"});
    daftar_kelas.push_back({"Ar-Razi", "Gedung Teknik Kimia, Lantai 3, depan tangga, sebelah toilet"});
    daftar_kelas.push_back({"Al-Khawarizmi", "Gedung Teknik Sipil, Lantai 3, depan tangga"});
    daftar_kelas.push_back({"Perpustakaan", "Gedung Teknik Informatika, Lantai 2, dipojok lorong informatika"});
    daftar_kelas.push_back({"Ibnu-Firnas", "Gedung Teknik Informatika, Lantai 2, sebelah ruang himpunan"});

    string input_nama_kelas;
    char lanjut;

    cout << "\n--------------------------------------------------------------------------------";
    cout << "\n|                             Cari Kelas UMJ Yuk!                              |";
    cout << "\n--------------------------------------------------------------------------------";
    cout << "\nDaftar Kelas : \nHabibi\nAl-Biruni\nAl-Battani\nAr-Razi\nAl-Khawarizmi\nIbnu-Firnas\nPerpustakaan\n";
    cout << "--------------------------------------------------------------------------------";

    do {
        cout << "\nMasukkan nama kelas yang ingin dicari (contoh: Habibi, Al-Battani): ";
        getline(cin, input_nama_kelas);
        cout << "\n--------------------------------------------------------------------------------";
        cout << "\nMencari lokasi untuk kelas: " << input_nama_kelas << "\n" << endl;

        Kelas* hasil = cariLokasiKelas(daftar_kelas, input_nama_kelas);

        if (hasil != NULL) {
            cout << "Lokasi Ditemukan:\n";
            cout << "Nama Kelas : " << hasil->nama_kelas << endl;
            cout << "Deskripsi  : " << hasil->deskripsi << endl;
        } else {
            cout << "Maaf, lokasi kelas tidak ditemukan." << endl;
        }

        cout << "\n--------------------------------------------------------------------------------";
        cout << "\nApakah ingin mencari kelas lain? (y/n): ";
        cin >> lanjut;
        cin.ignore(); // Membersihkan newline di buffer agar getline selanjutnya tetap berjalan dengan benar

        cout << endl;

    } while (tolower(lanjut) == 'y');

    cout << "Terima kasih telah menggunakan pencarian lokasi kelas." << endl;

    return 0;
}
