#include <iostream>
#include <string>
#include <limits>
using namespace std;


struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};


void delay() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void mahasiswa1(Mahasiswa mhs[], int jumlah) {
    for (int i = 0; i < jumlah; i++) {
        cout << "\n=== Input Data Mahasiswa ke-" << i+1 << " ===" << endl;
        
        cout << "Nama: ";
        getline(cin, mhs[i].nama);
        
        cout << "NIM: ";
        getline(cin, mhs[i].nim);
        
        cout << "IPK: ";
        cin >> mhs[i].ipk;
        
    
        while (mhs[i].ipk < 0.0 || mhs[i].ipk > 4.0) {
            cout << "IPK harus antara 0.0 - 4.0. Masukkan ulang: ";
            cin >> mhs[i].ipk;
        }
        
        delay(); 
    }
}


Mahasiswa caritertinggi(Mahasiswa mhs[], int jumlah) {
    Mahasiswa tertinggi = mhs[0]; 
    
    for (int i = 1; i < jumlah; i++) {
        if (mhs[i].ipk > tertinggi.ipk) {
            tertinggi = mhs[i];
        }
    }
    
    return tertinggi;
}


void semuamahasiswa(Mahasiswa mhs[], int jumlah) {
    cout << "\n\n=== DAFTAR SEMUA MAHASISWA ===" << endl;
    cout << "----------------------------------------" << endl;
    
    for (int i = 0; i < jumlah; i++) {
        cout << "Mahasiswa ke-" << i+1 << ":" << endl;
        cout << "  Nama: " << mhs[i].nama << endl;
        cout << "  NIM : " << mhs[i].nim << endl;
        cout << "  IPK : " << mhs[i].ipk << endl;
        cout << "----------------------------------------" << endl;
    }
}


void ipktertinggi(Mahasiswa mhs) {
    cout << "\n\n=== MAHASISWA DENGAN IPK TERTINGGI ===" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Nama: " << mhs.nama << endl;
    cout << "NIM : " << mhs.nim << endl;
    cout << "IPK : " << mhs.ipk << endl;
    cout << "----------------------------------------" << endl;
}

int main() {
    const int JUMLAH_MAHASISWA = 5;
    Mahasiswa mahasiswa[JUMLAH_MAHASISWA];
    
    cout << "PROGRAM DATA MAHASISWA" << endl;
    cout << "======================" << endl;
    cout << "Masukkan data untuk " << JUMLAH_MAHASISWA << " mahasiswa:" << endl;
    mahasiswa1(mahasiswa, JUMLAH_MAHASISWA);
    semuamahasiswa(mahasiswa, JUMLAH_MAHASISWA);
    Mahasiswa ipkTertinggi = caritertinggi(mahasiswa, JUMLAH_MAHASISWA);
    ipktertinggi(ipkTertinggi);
    
    return 0;
}