#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;

struct Hewan {
    int id;
    char nama[50];
    char jenis[30];
    int umur; 
    double harga;
};

struct Pasien {
    int idHewan;
    char namaHewan[50];
    char jenisHewan[30];
    char keluhan[100];
    char waktuDaftar[30];
};

struct TindakanMedis {
    int idPasien;
    char namaHewan[50];
    char tindakan[100];
    char obat[100];
    char waktuTindakan[30];
};

const int MAX_ANTRIAN = 20;
const int MAX_RIWAYAT = 50;

struct Queue {
    Pasien antrian[MAX_ANTRIAN];
    int front;
    int rear;
    int jumlah;
};

struct Stack {
    TindakanMedis riwayat[MAX_RIWAYAT];
    int top;
};

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->jumlah = 0;
}

bool isQueueEmpty(Queue *q) {
    return q->jumlah == 0;
}

bool isQueueFull(Queue *q) {
    return q->jumlah == MAX_ANTRIAN;
}

void enqueue(Queue *q, Pasien p) {
    if (isQueueFull(q)) {
        cout << "\n[ERROR] Antrian penuh! Tidak dapat menambahkan pasien.\n";
        return;
    }
    
    q->rear = (q->rear + 1) % MAX_ANTRIAN;
    q->antrian[q->rear] = p;
    q->jumlah++;
    
    cout << "\n[SUKSES] Pasien \"" << p.namaHewan << "\" (ID: " << p.idHewan 
         << ") telah ditambahkan ke antrian.\n";
    cout << "Posisi antrian: " << q->jumlah << "/" << MAX_ANTRIAN << endl;
}

Pasien dequeue(Queue *q) {
    Pasien kosong = {-1, "", "", "", ""};
    
    if (isQueueEmpty(q)) {
        cout << "\n[ERROR] Antrian kosong! Tidak ada pasien yang bisa dipanggil.\n";
        return kosong;
    }
    
    Pasien p = q->antrian[q->front];
    q->front = (q->front + 1) % MAX_ANTRIAN;
    q->jumlah--;
    
    cout << "\n[PANGGILAN] Pasien terdepan:\n";
    cout << "  Nama: " << p.namaHewan << endl;
    cout << "  ID: " << p.idHewan << endl;
    cout << "  Jenis: " << p.jenisHewan << endl;
    cout << "  Keluhan: " << p.keluhan << endl;
    
    return p;
}

void peekQueue(Queue *q) {
    if (isQueueEmpty(q)) {
        cout << "\n[INFO] Antrian kosong.\n";
        return;
    }
    
    cout << "\n=== PASIEN TERDEPAN ===\n";
    Pasien *ptr = &q->antrian[q->front];
    cout << "ID: " << ptr->idHewan << endl;
    cout << "Nama: " << ptr->namaHewan << endl;
    cout << "Jenis: " << ptr->jenisHewan << endl;
    cout << "Keluhan: " << ptr->keluhan << endl;
    cout << "Waktu Daftar: " << ptr->waktuDaftar << endl;
}

void tampilkanSemuaAntrian(Queue *q) {
    if (isQueueEmpty(q)) {
        cout << "\n[INFO] Antrian kosong.\n";
        return;
    }
    
    cout << "\n=== DAFTAR ANTRIAN PASIEN ===\n";
    cout << left;
    cout << setw(5) << "No" 
         << setw(5) << "ID" 
         << setw(25) << "Nama Hewan" 
         << setw(15) << "Jenis" 
         << setw(30) << "Keluhan" << endl;
    cout << string(80, '-') << endl;
    
    int index = q->front;
    for (int i = 0; i < q->jumlah; i++) {
        Pasien *ptr = q->antrian + index;
        cout << setw(5) << i + 1
             << setw(5) << ptr->idHewan
             << setw(25) << ptr->namaHewan
             << setw(15) << ptr->jenisHewan
             << setw(30) << ptr->keluhan << endl;
        index = (index + 1) % MAX_ANTRIAN;
    }
    cout << endl;
}

void initStack(Stack *s) {
    s->top = -1;
}

bool isStackEmpty(Stack *s) {
    return s->top == -1;
}

bool isStackFull(Stack *s) {
    return s->top == MAX_RIWAYAT - 1;
}

void push(Stack *s, TindakanMedis t) {
    if (isStackFull(s)) {
        cout << "\n[ERROR] Riwayat penuh! Tidak dapat menambahkan tindakan.\n";
        return;
    }
    
    s->top++;
    s->riwayat[s->top] = t;
    
    cout << "\n[SUKSES] Tindakan medis untuk \"" << t.namaHewan 
         << "\" telah dicatat ke riwayat.\n";
    cout << "Total riwayat: " << (s->top + 1) << "/" << MAX_RIWAYAT << endl;
}

TindakanMedis pop(Stack *s) {
    TindakanMedis kosong = {-1, "", "", "", ""};
    
    if (isStackEmpty(s)) {
        cout << "\n[ERROR] Riwayat kosong! Tidak ada tindakan yang bisa dihapus.\n";
        return kosong;
    }
    
    TindakanMedis t = s->riwayat[s->top];
    s->top--;
    
    cout << "\n[BATAL] Tindakan terakhir telah dihapus dari riwayat:\n";
    cout << "  Pasien: " << t.namaHewan << " (ID: " << t.idPasien << ")\n";
    cout << "  Tindakan: " << t.tindakan << endl;
    
    return t;
}

void peekStack(Stack *s) {
    if (isStackEmpty(s)) {
        cout << "\n[INFO] Riwayat kosong.\n";
        return;
    }
    
    cout << "\n=== TINDAKAN TERAKHIR ===\n";
    TindakanMedis *ptr = &s->riwayat[s->top];
    cout << "ID Pasien: " << ptr->idPasien << endl;
    cout << "Nama Hewan: " << ptr->namaHewan << endl;
    cout << "Tindakan: " << ptr->tindakan << endl;
    cout << "Obat: " << ptr->obat << endl;
    cout << "Waktu: " << ptr->waktuTindakan << endl;
}

void tampilkanSemuaRiwayat(Stack *s) {
    if (isStackEmpty(s)) {
        cout << "\n[INFO] Riwayat kosong.\n";
        return;
    }
    
    cout << "\n=== RIWAYAT TINDAKAN MEDIS ===\n";
    cout << left;
    cout << setw(5) << "No" 
         << setw(5) << "ID" 
         << setw(25) << "Nama Hewan" 
         << setw(25) << "Tindakan" 
         << setw(25) << "Obat" << endl;
    cout << string(85, '-') << endl;
    
    for (int i = 0; i <= s->top; i++) {
        TindakanMedis *ptr = s->riwayat + i;
        cout << setw(5) << i + 1
             << setw(5) << ptr->idPasien
             << setw(25) << ptr->namaHewan
             << setw(25) << ptr->tindakan
             << setw(25) << ptr->obat << endl;
    }
    cout << endl;
}

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

void getWaktuSekarang(char *waktu, int size) {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    sprintf(waktu, "%02d/%02d/%04d %02d:%02d:%02d", 
            ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900,
            ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
}

void daftarPasien(Queue *q, Hewan* arrHewan, int jumlahHewan) {
    if (jumlahHewan == 0) {
        cout << "\n[ERROR] Belum ada data hewan! Silakan tambah data hewan terlebih dahulu.\n";
        return;
    }
    
    cout << "\n=== PENDAFTARAN PASIEN ===\n";
    tampilkanSemuaData(arrHewan, jumlahHewan);
    
    int idCari;
    cout << "Masukkan ID hewan yang akan didaftarkan: ";
    cin >> idCari;
    
    Hewan *hewanDitemukan = nullptr;
    for (int i = 0; i < jumlahHewan; i++) {
        Hewan *ptr = arrHewan + i;
        if (ptr->id == idCari) {
            hewanDitemukan = ptr;
            break;
        }
    }
    
    if (hewanDitemukan == nullptr) {
        cout << "\n[ERROR] Hewan dengan ID " << idCari << " tidak ditemukan!\n";
        return;
    }
    
    Pasien p;
    p.idHewan = hewanDitemukan->id;
    strcpy(p.namaHewan, hewanDitemukan->nama);
    strcpy(p.jenisHewan, hewanDitemukan->jenis);
    
    cout << "Masukkan keluhan: ";
    cin.ignore();
    cin.getline(p.keluhan, 100);
    
    getWaktuSekarang(p.waktuDaftar, sizeof(p.waktuDaftar));
    
    enqueue(q, p);
}

void periksaPasien(Queue *q, Stack *s) {
    if (isQueueEmpty(q)) {
        cout << "\n[INFO] Tidak ada pasien dalam antrian.\n";
        return;
    }
    
    Pasien p = dequeue(q);
    
    if (p.idHewan == -1) return;
    
    TindakanMedis t;
    t.idPasien = p.idHewan;
    strcpy(t.namaHewan, p.namaHewan);
    
    cout << "\n=== INPUT TINDAKAN MEDIS ===\n";
    cout << "Masukkan tindakan yang dilakukan: ";
    cin.ignore();
    cin.getline(t.tindakan, 100);
    
    cout << "Masukkan obat yang diberikan: ";
    cin.getline(t.obat, 100);
    
    getWaktuSekarang(t.waktuTindakan, sizeof(t.waktuTindakan));
    
    push(s, t);
}

Hewan* linearSearch(Hewan* arr, int jumlah, const char* cariNama) {
    cout << "\n=== PROSES LINEAR SEARCH ===\n";
    cout << "Mencari nama: " << cariNama << endl;
    cout << "Iterasi ke-\tID\tNama\t\tAlamat\t\tKeterangan\n";
    cout << string(75, '-') << endl;
    
    for (int i = 0; i < jumlah; i++) {
        Hewan* ptr = arr + i;
        cout << i + 1 << "\t\t" << ptr->id << "\t" << ptr->nama << "\t" << ptr << "\t";
        
        if (strcmp(ptr->nama, cariNama) == 0) {
            cout << "DITEMUKAN!" << endl;
            return ptr;
        } else {
            cout << "Bukan target" << endl;
        }
    }
    
    cout << "\nNama hewan \"" << cariNama << "\" tidak ditemukan.\n";
    return nullptr;
}

void swapHewan(Hewan* a, Hewan* b) {
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

void sortById(Hewan* arr, int jumlah) {
    if (jumlah <= 1) return;
    
    cout << "\n=== SORTING DATA BERDASARKAN ID UNTUK FIBONACCI SEARCH ===\n";
    
    for (int i = 0; i < jumlah - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < jumlah; j++) {
            if ((arr + j)->id < (arr + minIndex)->id) {
                minIndex = j;
            }
        }
        
        if (minIndex != i) {
            swapHewan(arr + i, arr + minIndex);
            cout << "  Menukar ID " << (arr + i)->id << " dengan " << (arr + minIndex)->id << endl;
        }
    }
    
    cout << "Pengurutan berdasarkan ID selesai!\n";
}

Hewan* fibonacciSearch(Hewan* arr, int jumlah, int cariId) {
    sortById(arr, jumlah);
    
    cout << "\n=== PROSES FIBONACCI SEARCH ===\n";
    cout << "Mencari ID: " << cariId << " (setelah sorting)" << endl;
    cout << "Iterasi\t\tIndex\t\tNilai ID\tAlamat\t\tKeterangan\n";
    cout << string(75, '-') << endl;
    
    int fibMMm2 = 0, fibMMm1 = 1, fibM = fibMMm2 + fibMMm1;
    
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
        cout << ptr->id << "\t\t" << ptr << "\t";
        
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
            return ptr;
        }
    }
    
    if (fibMMm1 && (offset + 1) < jumlah) {
        iterasi++;
        cout << iterasi << "\t\t" << (offset + 1) << "\t\t";
        Hewan* ptr = arr + (offset + 1);
        cout << ptr->id << "\t\t" << ptr << "\t";
        
        if (ptr->id == cariId) {
            cout << "DITEMUKAN!" << endl;
            return ptr;
        }
        cout << "Bukan target" << endl;
    }
    
    cout << "\nID hewan " << cariId << " tidak ditemukan.\n";
    return nullptr;
}

void bubbleSortByName(Hewan* arr, int jumlah) {
    if (jumlah <= 1) return;
    
    cout << "\n=== PROSES BUBBLE SORT ===\n";
    
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

void selectionSortByPrice(Hewan* arr, int jumlah) {
    if (jumlah <= 1) return;
    
    cout << "\n=== PROSES SELECTION SORT ===\n";
    
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

void tampilkanHasilPencarian(Hewan* ptr) {
    if (ptr != nullptr) {
        cout << "\n=== HASIL PENCARIAN ===\n";
        cout << "Alamat memori: " << ptr << endl;
        tampilkanHeader();
        cout << setw(5) << ptr->id
             << setw(25) << ptr->nama
             << setw(15) << ptr->jenis
             << setw(10) << ptr->umur
             << setw(15) << fixed << setprecision(0) << ptr->harga << endl;
    } else {
        cout << "\nData tidak ditemukan!\n";
    }
}

void tampilkanMenu() {
    cout << "\n=== PAWCARE PETSHOP & DOKTER HEWAN ===\n";
    cout << "1. Tampilkan semua data hewan\n";
    cout << "2. Tambah data hewan baru\n";
    cout << "3. Cari hewan berdasarkan nama\n";
    cout << "4. Cari hewan berdasarkan ID\n";
    cout << "5. Urutkan data berdasarkan nama\n";
    cout << "6. Urutkan data berdasarkan harga\n";
    cout << "7. Daftar pasien baru\n";
    cout << "8. Panggil pasien & periksa\n";
    cout << "9. Tampilkan semua antrian\n";
    cout << "10. Tampilkan semua riwayat tindakan\n";
    cout << "11. Lihat pasien terdepan & tindakan terakhir\n";
    cout << "12. Batalkan tindakan terakhir\n";
    cout << "13. Keluar\n";
    cout << "Pilih menu (1-13): ";
}

int main() {
    int kapasitas = 10;
    int jumlah = 0;
    Hewan* dataHewan = new Hewan[kapasitas];
    
    Hewan dataAwal[] = {
        {1, "Luna", "Kucing", 12, 2500000},
        {2, "Rizkul", "Anjing", 8, 3500000},
        {3, "Juned", "Kelinci", 5, 1500000},
        {4, "Erwin", "Burung", 3, 750000},
        {5, "Dina", "Kucing", 15, 2800000}
    };
    
    for (int i = 0; i < 5; i++) {
        dataHewan[i] = dataAwal[i];
        jumlah++;
    }
    
    Queue antrian;
    Stack riwayat;
    initQueue(&antrian);
    initStack(&riwayat);
    
    int pilihan;
    char cariNama[50];
    int cariId;
    Hewan* hasilPencarian;
    
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
                    hasilPencarian = linearSearch(dataHewan, jumlah, cariNama);
                    tampilkanHasilPencarian(hasilPencarian);
                } else {
                    cout << "\nBelum ada data hewan!\n";
                }
                break;
                
            case 4:
                if (jumlah > 0) {
                    cout << "\nMasukkan ID hewan yang dicari: ";
                    cin >> cariId;
                    hasilPencarian = fibonacciSearch(dataHewan, jumlah, cariId);
                    tampilkanHasilPencarian(hasilPencarian);
                } else {
                    cout << "\nBelum ada data hewan!\n";
                }
                break;
                
            case 5:
                if (jumlah > 0) {
                    bubbleSortByName(dataHewan, jumlah);
                    cout << "\nData setelah diurutkan berdasarkan nama:\n";
                    tampilkanSemuaData(dataHewan, jumlah);
                } else {
                    cout << "\nBelum ada data hewan!\n";
                }
                break;
                
            case 6:
                if (jumlah > 0) {
                    selectionSortByPrice(dataHewan, jumlah);
                    cout << "\nData setelah diurutkan berdasarkan harga:\n";
                    tampilkanSemuaData(dataHewan, jumlah);
                } else {
                    cout << "\nBelum ada data hewan!\n";
                }
                break;
                
            case 7:
                daftarPasien(&antrian, dataHewan, jumlah);
                break;
                
            case 8:
                periksaPasien(&antrian, &riwayat);
                break;
                
            case 9:
                tampilkanSemuaAntrian(&antrian);
                break;
                
            case 10:
                tampilkanSemuaRiwayat(&riwayat);
                break;
                
            case 11:
                cout << "\n=== PEEK QUEUE & STACK ===\n";
                peekQueue(&antrian);
                peekStack(&riwayat);
                break;
                
            case 12:
                pop(&riwayat);
                break;
                
            case 13:
                cout << "\nTerima kasih telah menggunakan program Pawcare Petshop!\n";
                break;
                
            default:
                cout << "\nPilihan tidak valid! Silakan pilih 1-13.\n";
        }
        
    } while(pilihan != 13);
    
    delete[] dataHewan;
    return 0;
}