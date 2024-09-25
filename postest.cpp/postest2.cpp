#include <iostream>
#include <string>

using namespace std;

// Struct untuk menyimpan data penerima beasiswa
struct PenerimaBeasiswa {
    string nama;
    string nim;
    float ipk;
};

// Deklarasi variabel array dan pointer
PenerimaBeasiswa daftarPenerima[100]; // Array untuk menyimpan data penerima beasiswa
int jumlahPenerima = 0; // Jumlah penerima beasiswa

// Fungsi untuk menambah data penerima beasiswa
void tambahPenerima() {
    if (jumlahPenerima < 100) {
        PenerimaBeasiswa *penerima = &daftarPenerima[jumlahPenerima];
        
        cout << "Masukkan nama: ";
        cin.ignore();
        getline(cin, penerima->nama);
        cout << "Masukkan NIM: ";
        cin >> penerima->nim;
        cout << "Masukkan IPK: ";
        cin >> penerima->ipk;

        jumlahPenerima++;
        cout << "Data penerima berhasil ditambahkan.\n";
    } else {
        cout << "Kapasitas maksimal penerima beasiswa telah tercapai.\n";
    }
}

// Fungsi untuk menampilkan data penerima beasiswa
void tampilkanPenerima() {
    if (jumlahPenerima > 0) {
        cout << "Daftar Penerima Beasiswa:\n";
        for (int i = 0; i < jumlahPenerima; i++) {
            PenerimaBeasiswa *penerima = &daftarPenerima[i];
            cout << "Penerima ke-" << (i+1) << endl;
            cout << "Nama: " << penerima->nama << endl;
            cout << "NIM: " << penerima->nim << endl;
            cout << "IPK: " << penerima->ipk << endl;
            cout << "--------------------------\n";
        }
    } else {
        cout << "Belum ada data penerima beasiswa.\n";
    }
}

// Fungsi untuk mengubah data penerima beasiswa berdasarkan indeks
void ubahPenerima() {
    int indeks;
    cout << "Masukkan nomor penerima yang ingin diubah: ";
    cin >> indeks;

    if (indeks > 0 && indeks <= jumlahPenerima) {
        PenerimaBeasiswa *penerima = &daftarPenerima[indeks - 1];
        
        cout << "Masukkan nama baru: ";
        cin.ignore();
        getline(cin, penerima->nama);
        cout << "Masukkan NIM baru: ";
        cin >> penerima->nim;
        cout << "Masukkan IPK baru: ";
        cin >> penerima->ipk;

        cout << "Data penerima berhasil diubah.\n";
    } else {
        cout << "Nomor penerima tidak valid.\n";
    }
}

// Fungsi untuk menghapus data penerima beasiswa berdasarkan indeks
void hapusPenerima() {
    int indeks;
    cout << "Masukkan nomor penerima yang ingin dihapus: ";
    cin >> indeks;

    if (indeks > 0 && indeks <= jumlahPenerima) {
        for (int i = indeks - 1; i < jumlahPenerima - 1; i++) {
            daftarPenerima[i] = daftarPenerima[i + 1];
        }
        jumlahPenerima--;
        cout << "Data penerima berhasil dihapus.\n";
    } else {
        cout << "Nomor penerima tidak valid.\n";
    }
}

// Fungsi utama untuk menampilkan menu dan mengelola data penerima
int main() {
    int pilihan;
    do {
        cout << "==========================\n";
        cout << "Menu Pendataan Penerima Beasiswa:\n";
        cout << "1. Tambah Data Penerima\n";
        cout << "2. Tampilkan Data Penerima\n";
        cout << "3. Ubah Data Penerima\n";
        cout << "4. Hapus Data Penerima\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahPenerima();
                break;
            case 2:
                tampilkanPenerima();
                break;
            case 3:
                ubahPenerima();
                break;
            case 4:
                hapusPenerima();
                break;
            case 5:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 5);

    return 0;
}
