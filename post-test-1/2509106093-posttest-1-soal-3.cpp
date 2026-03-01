#include <iostream>
#include <iomanip>
using namespace std;


void reverse(int* arr, int n) {
    int* kiri = arr;          
    int* kanan = arr + n - 1;  

    while (kiri < kanan) {
      
        int temp = *kiri;
        *kiri = *kanan;
        *kanan = temp;
        kiri++;  
        kanan--; 
    }
}


void tampilkanArray(int* arr, int n) {
    int* ptr = arr;
    cout << left << setw(10) << "Indeks"
         << setw(15) << "Nilai"
         << "Alamat Memori" << endl;
    cout << string(45, '-') << endl;

    for (int i = 0; i < n; i++) {
        cout << left << setw(10) << i
             << setw(15) << *ptr
             << ptr << endl;
        ptr++;  
    }
}

int main() {
   
    int prima[7] = {2, 3, 5, 7, 11, 13, 17};
    int n = 7;

    
    cout << "\n[SEBELUM DIBALIK]" << endl;
    tampilkanArray(prima, n);
    reverse(prima, n);
    cout << "\n[SESUDAH DIBALIK]" << endl;
    tampilkanArray(prima, n);

    cout << "\n[INFO POINTER]" << endl;
    cout << "Alamat awal array (prima)     : " << prima << endl;
    cout << "Alamat elemen terakhir        : " << (prima + n - 1) << endl;
    cout << "Ukuran satu elemen (int)      : " << sizeof(int) << " bytes" << endl;
    cout << "Total ukuran array            : " << sizeof(prima) << " bytes" << endl;

    return 0;
}