#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
using namespace std;


struct Hewan {
    int id;
    char nama[50];
    char jenis[30];
    int umur; 
    double harga;
};


void tampilkanHeader() {
    cout << left;
    cout << setw(5) << "ID" 
         << setw(25) << "Nama Hewan" 
         << setw(15) << "Jenis" 
         << setw(10) << "Umur (bln)" 
         << setw(15) << "Harga (Rp)" << endl;
    cout << string(70, '-') << endl;
}


void tampilkanSemuaData(Hewan* arr, int jumlah) {
    if (jumlah == 0) {
        cout << "\nBelum ada data hewan.\n";
        return;
    }
    
    cout << "\n=== DAFTAR HEWAN PELIHARAAN ===\n";
    tampilkanHeader();
    
   
    for (int i = 0; i < jumlah; i++) {
        Hewan* ptr = arr + i;  
        cout << setw(5) << ptr->id
             << setw(25) << ptr->nama
             << setw(15) << ptr->jenis
             << setw(10) << ptr->umur
             << setw(15) << fixed << setprecision(0) << ptr->harga << endl;
    }
    cout << endl;
}


void tambahDataHewan(Hewan* &arr, int &jumlah, int &kapasitas) {
    if (jumlah >= kapasitas) {
   
        kapasitas += 10;
        Hewan* arrBaru = new Hewan[kapasitas];
        
        
        for (int i = 0; i < jumlah; i++) {
            arrBaru[i] = arr[i];
        }
        
        delete[] arr;
        arr = arrBaru;
        
    }
    
    Hewan* hewanBaru = &arr[jumlah]; 
    hewanBaru->id = jumlah + 1;  
    
    cout << "\n=== TAMBAH DATA HEWAN ===\n";
    cout << "Masukkan nama hewan: ";
    cin.ignore();
    cin.getline(hewanBaru->nama, 50);
    
    cout << "Masukkan jenis hewan: ";
    cin.getline(hewanBaru->jenis, 30);
    
    cout << "Masukkan umur (bulan): ";
    cin >> hewanBaru->umur;
    
    cout << "Masukkan harga (Rp): ";
    cin >> hewanBaru->harga;
    
    jumlah++;
    cout << "\nData berhasil ditambahkan! ID hewan: " << hewanBaru->id << endl;
}


int linearSearch(Hewan* arr, int jumlah, const char* cariNama) {
    cout << "\n=== PROSES LINEAR SEARCH ===\n";
    cout << "Mencari nama: " << cariNama << endl;
    cout << "Iterasi ke-\tID\tNama\t\tKeterangan\n";
    cout << string(55, '-') << endl;
    
    for (int i = 0; i < jumlah; i++) {
        cout << i + 1 << "\t\t" << arr[i].id << "\t" << arr[i].nama << "\t";
        
        if (strcmp(arr[i].nama, cariNama) == 0) {
            cout << "DITEMUKAN!" << endl;
            return i;
        } else {
            cout << "Bukan target" << endl;
        }
    }
    
    cout << "\nNama hewan \"" << cariNama << "\" tidak ditemukan.\n";
    return -1;
}

int fibonacci(Hewan* arr, int jumlah, int cariId) {
    cout << "\n=== PROSES FIBONACCI SEARCH ===\n";
    cout << "Mencari ID: " << cariId << endl;
    cout << "Iterasi\t\tIndex\t\tNilai ID\tKeterangan\n";
    cout << string(55, '-') << endl;
    
    int fibMMm2 = 0;  
    int fibMMm1 = 1;  
    int fibM = fibMMm2 + fibMMm1;  
    
  
    while (fibM < jumlah) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }
    
    int offset = -1;
    int iterasi = 0;
    
    while (fibM > 1) {
        iterasi++;
        int i = min(offset + fibMMm2, jumlah - 1);
        
        cout << iterasi << "\t\t" << i << "\t\t";
      
        Hewan* ptr = arr + i;
        cout << ptr->id << "\t\t";
        
        if (ptr->id < cariId) {
            cout << "ID lebih kecil, geser ke kanan" << endl;
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        } 
        else if (ptr->id > cariId) {
            cout << "ID lebih besar, geser ke kiri" << endl;
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        else {
            cout << "DITEMUKAN!" << endl;
            return i;
        }
    }
    
    if (fibMMm1 && (offset + 1) < jumlah) {
        iterasi++;
        cout << iterasi << "\t\t" << (offset + 1) << "\t\t";
        Hewan* ptr = arr + (offset + 1);
        cout << ptr->id << "\t\t";
        
        if (ptr->id == cariId) {
            cout << "DITEMUKAN!" << endl;
            return offset + 1;
        }
        cout << "Bukan target" << endl;
    }
    
    cout << "\nID hewan " << cariId << " tidak ditemukan.\n";
    return -1;
}

void swapHewan(Hewan* a, Hewan* b) {
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}


void Nama(Hewan* arr, int jumlah) {
    if (jumlah <= 1) return;
    
    cout << "\n=== PROSES BUBBLE SORT  ===\n";
    
    for (int i = 0; i < jumlah - 1; i++) {
        bool swapped = false;
        cout << "\nIterasi ke-" << i + 1 << ":\n";
        
        for (int j = 0; j < jumlah - i - 1; j++) {
            
            Hewan* current = arr + j;
            Hewan* next = arr + (j + 1);
            
            if (strcmp(current->nama, next->nama) > 0) {
                swapHewan(current, next);  
                swapped = true;
                cout << "  Menukar: \"" << current->nama << "\" dengan \"" << next->nama << "\"\n";
            }
        }
        
        if (!swapped) break;
    }
    
    cout << "\nPengurutan selesai!\n";
}


void selectionSort(Hewan* arr, int jumlah) {
    if (jumlah <= 1) return;
    
    cout << "\n=== PROSES SELECTION SORT (Berdasarkan Harga Termurah-Termahal) ===\n";
    
    for (int i = 0; i < jumlah - 1; i++) {
        int minIndex = i;
        cout << "\nIterasi ke-" << i + 1 << ": Mencari harga terkecil dari index " << i << " ke " << jumlah - 1 << endl;
        
        for (int j = i + 1; j < jumlah; j++) {
            if ((arr + j)->harga < (arr + minIndex)->harga) {
                minIndex = j;
            }
        }
        
        if (minIndex != i) {
            cout << "  Menemukan harga terkecil Rp " << fixed << setprecision(0) 
                 << (arr + minIndex)->harga << " di index " << minIndex << endl;
            cout << "  Menukar data index " << i << " dengan index " << minIndex << endl;
            
            swapHewan(arr + i, arr + minIndex);
        } else {
            cout << "  Data sudah terurut dengan benar" << endl;
        }
    }
    
    cout << "\nPengurutan selesai!\n";
}

void tampilkanHasilPencarian(Hewan* &ptr, int index) {
    if (index != -1 && ptr != nullptr) {
        cout << "\n=== HASIL PENCARIAN ===\n";
        tampilkanHeader();
        Hewan* hasil = ptr + index; 
        cout << setw(5) << hasil->id
             << setw(25) << hasil->nama
             << setw(15) << hasil->jenis
             << setw(10) << hasil->umur
             << setw(15) << fixed << setprecision(0) << hasil->harga << endl;
    } else {
        cout << "\nData tidak ditemukan!\n";
    }
}


void tampilkanMenu() {
    cout << "\n=== PAWCARE PETSHOP & DOKTER HEWAN ===\n";
    cout << "1. Tampilkan semua data hewan\n";
    cout << "2. Tambah data hewan baru\n";
    cout << "3. Cari hewan berdasarkan nama \n";
    cout << "4. Cari hewan berdasarkan ID \n";
    cout << "5. Urutkan data berdasarkan nama \n";
    cout << "6. Urutkan data berdasarkan harga \n";
    cout << "7. Keluar\n";
    cout << "Pilih menu (1-7): ";
}

int main() {
    int kapasitas = 10;
    int jumlah = 0;
    Hewan* dataHewan = new Hewan[kapasitas];
    
    
    Hewan dataAwal[] = {
        {1, "Luna", "Kucing", 12, 2500000},
        {2, "rizkul", "Anjing", 8, 3500000},
        {3, "juned", "Kelinci", 5, 1500000},
        {4, "erwin", "Burung", 3, 750000},
        {5, "dina", "Kucing", 15, 2800000}
    };
    
    for (int i = 0; i < 5; i++) {
        dataHewan[i] = dataAwal[i];
        jumlah++;
    }
    
    int pilihan;
    char cariNama[50];
    int cariId;
    int index;
    
    do {
        tampilkanMenu();
        cin >> pilihan;
        
        switch(pilihan) {
            case 1:
                tampilkanSemuaData(dataHewan, jumlah);
                break;
                
            case 2:
                tambahDataHewan(dataHewan, jumlah, kapasitas);
                break;
                
            case 3:
                if (jumlah > 0) {
                    cout << "\nMasukkan nama hewan yang dicari: ";
                    cin.ignore();
                    cin.getline(cariNama, 50);
                    index = linearSearch(dataHewan, jumlah, cariNama);
                    tampilkanHasilPencarian(dataHewan, index);
                } else {
                    cout << "\nBelum ada data hewan!\n";
                }
                break;
                
            case 4:
                if (jumlah > 0) {
                    cout << "\nMasukkan ID hewan yang dicari: ";
                    cin >> cariId;
                    index = fibonacci(dataHewan, jumlah, cariId);
                    tampilkanHasilPencarian(dataHewan, index);
                } else {
                    cout << "\nBelum ada data hewan!\n";
                }
                break;
                
            case 5:
                if (jumlah > 0) {
                    Nama(dataHewan, jumlah);
                    cout << "\nData setelah diurutkan berdasarkan nama:\n";
                    tampilkanSemuaData(dataHewan, jumlah);
                } else {
                    cout << "\nBelum ada data hewan!\n";
                }
                break;
                
            case 6:
                if (jumlah > 0) {
                    selectionSort(dataHewan, jumlah);
                    cout << "\nData setelah diurutkan berdasarkan harga:\n";
                    tampilkanSemuaData(dataHewan, jumlah);
                } else {
                    cout << "\nBelum ada data hewan!\n";
                }
                break;
                
            case 7:
                cout << "\nTerima kasih telah menggunakan program Pawcare Petshop!\n";
                break;
                
            default:
                cout << "\nPilihan tidak valid! Silakan pilih 1-7.\n";
        }
        
    } while(pilihan != 7);
    
    delete[] dataHewan;
    return 0;
}