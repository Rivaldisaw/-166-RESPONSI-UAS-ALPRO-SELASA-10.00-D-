#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Tiket {
    char kode[10];
    char maskapai[30];
    char asal[30];
    char tujuan[30];
    char tanggal[15];
    char jam_berangkat[10];
    char jam_tiba[10];
    int harga;
};

Tiket tiket[100];
int jumlah = 0;

void bacaFile() {
    ifstream file("tiket.txt");
    if (file.is_open()) {
        file >> jumlah;
        for (int i = 0; i < jumlah; i++) {
            file >> tiket[i].kode >> tiket[i].maskapai >> tiket[i].asal >> tiket[i].tujuan;
            file >> tiket[i].tanggal >> tiket[i].jam_berangkat >> tiket[i].jam_tiba >> tiket[i].harga;
        }
        file.close();
    }
}

void tampilkanSemua() {
    cout << "\nDaftar Tiket:\n";
    for (int i = 0; i < jumlah; i++) {
        cout << i+1 << ". " << tiket[i].maskapai << " (" << tiket[i].kode << ") | ";
        cout << tiket[i].asal << " → " << tiket[i].tujuan << " | " << tiket[i].tanggal << " ";
        cout << tiket[i].jam_berangkat << " - " << tiket[i].jam_tiba << " | Rp" << tiket[i].harga << endl;
    }
}

void cariRute() {
    char asal[30], tujuan[30];
    cout << "Masukkan bandara asal: "; cin >> asal;
    cout << "Masukkan bandara tujuan: "; cin >> tujuan;
    for (int i = 0; i < jumlah; i++) {
        if (strcmp(tiket[i].asal, asal) == 0 && strcmp(tiket[i].tujuan, tujuan) == 0) {
            cout << tiket[i].maskapai << " | Rp" << tiket[i].harga << endl;
        }
    }
}

void cariMaskapai() {
    char nama[30];
    cout << "Masukkan nama maskapai: "; cin >> nama;
    for (int i = 0; i < jumlah; i++) {
        if (strcmp(tiket[i].maskapai, nama) == 0) {
            cout << tiket[i].kode << " | " << tiket[i].asal << " - " << tiket[i].tujuan << " | Rp" << tiket[i].harga << endl;
        }
    }
}

void cariHargaBawah() {
    int batas;
    cout << "Tampilkan tiket dengan harga di bawah: Rp"; cin >> batas;
    for (int i = 0; i < jumlah; i++) {
        if (tiket[i].harga < batas) {
            cout << tiket[i].maskapai << " | Rp" << tiket[i].harga << endl;
        }
    }
}

void sortHarga(bool ascending) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = i + 1; j < jumlah; j++) {
            if ((ascending && tiket[i].harga > tiket[j].harga) || (!ascending && tiket[i].harga < tiket[j].harga)) {
                Tiket temp = tiket[i];
                tiket[i] = tiket[j];
                tiket[j] = temp;
            }
        }
    }

    ofstream out("sorting_tiket.txt");
    out << jumlah << endl;
    for (int i = 0; i < jumlah; i++) {
        out << tiket[i].kode << " " << tiket[i].maskapai << " " << tiket[i].asal << " " << tiket[i].tujuan << " ";
        out << tiket[i].tanggal << " " << tiket[i].jam_berangkat << " " << tiket[i].jam_tiba << " " << tiket[i].harga << endl;
    }
    out.close();
}

void cariTermurahTermahal() {
    int min = 0, max = 0;
    for (int i = 1; i < jumlah; i++) {
        if (tiket[i].harga < tiket[min].harga) min = i;
        if (tiket[i].harga > tiket[max].harga) max = i;
    }
    cout << "Tiket Termurah: " << tiket[min].maskapai << " | Rp" << tiket[min].harga << endl;
    cout << "Tiket Termahal: " << tiket[max].maskapai << " | Rp" << tiket[max].harga << endl;
}

void pesanTiket() {
    int pilih;
    char nama[30];
    tampilkanSemua();
    cout << "Pilih nomor tiket yang ingin dipesan: "; cin >> pilih;
    if (pilih < 1 || pilih > jumlah) {
        cout << "Nomor tidak valid.\n";
        return;
    }
    cout << "Masukkan nama penumpang: "; cin >> nama;

    ofstream transaksi("transaksi.txt", ios::app);
    transaksi << nama << " " << tiket[pilih-1].maskapai << " ";
    transaksi << tiket[pilih-1].asal << "-" << tiket[pilih-1].tujuan << " ";
    transaksi << tiket[pilih-1].tanggal << " " << tiket[pilih-1].jam_berangkat << " Rp" << tiket[pilih-1].harga << endl;
    transaksi.close();

    cout << "Pemesanan berhasil disimpan.\n";
}

int main() {
    bacaFile();
    int menu;
    do {
        cout << "\n=== MENU TIKET PESAWAT ===\n";
        cout << "1. Tampilkan Semua Tiket\n";
        cout << "2. Cari Tiket Berdasarkan Rute\n";
        cout << "3. Cari Tiket Berdasarkan Maskapai\n";
        cout << "4. Cari Tiket Berdasarkan Harga Maksimal\n";
        cout << "5. Urutkan Harga (Termurah - Termahal)\n";
        cout << "6. Urutkan Harga (Termahal - Termurah)\n";
        cout << "7. Tampilkan Tiket Termurah & Termahal\n";
        cout << "8. Pesan Tiket\n";
        cout << "9. Keluar\n";
        cout << "Pilih menu: ";
        cin >> menu;

        switch (menu) {
            case 1: tampilkanSemua(); break;
            case 2: cariRute(); break;
            case 3: cariMaskapai(); break;
            case 4: cariHargaBawah(); break;
            case 5: sortHarga(true); cout << "Data sudah diurutkan naik.\n"; break;
            case 6: sortHarga(false); cout << "Data sudah diurutkan turun.\n"; break;
            case 7: cariTermurahTermahal(); break;
            case 8: pesanTiket(); break;
        }
    } while (menu != 9);
    return 0;
}
