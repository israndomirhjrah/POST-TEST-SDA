#include <iostream>
using namespace std;

// Pseudocode dengan analisis cost dan jumlah eksekusi:

//  procedure FindMin(A : array of n elements)
//  min ← A[0]                 // c1     : 1 kali
//     for i ← 1 to n − 1 do      // c2     : n kali
//     if A[i] < min then       // c3     : n-1 kali
//         min ← A[i]             // c4     : tergantung kondisi (0 sampai n-1 kali)
//       end if
//       end for
//    return min                 // c5     : 1 kali
//    end procedure
//   Fungsi kompleksitas waktu:
//   T(n) = c1 + c2*n + c3*(n-1) + c4*x + c5
//   dimana x adalah jumlah eksekusi min ← A[i] (0 ≤ x ≤ n-1) 
//   BEST CASE (Tmin):
//   Terjadi ketika elemen terkecil sudah berada di A[0]
//   Maka kondisi if A[i] < min tidak pernah terpenuhi untuk semua i
//   x = 0
//   Tmin(n) = c1 + c2*n + c3*(n-1) + c5
//   Tmin(n) = (c2 + c3)n + (c1 - c3 + c5)
//   Kompleksitas: O(n) - Linear 
//   WORST CASE (Tmax):
//   Terjadi ketika elemen terbesar di A[0] dan elemen semakin mengecil
//   (array terurut menurun/descending)
//   Maka kondisi if A[i] < min selalu terpenuhi untuk semua i
//   x = n-1
//   Tmax(n) = c1 + c2*n + c3*(n-1) + c4*(n-1) + c5
//   Tmax(n) = (c2 + c3 + c4)n + (c1 - c3 - c4 + c5)
//   Kompleksitas: O(n) - Linear
//   Kesimpulan: Algoritma FindMin memiliki kompleksitas waktu O(n) 
//   untuk semua kasus (best, average, worst case)

int Findmin(int A[], int n, int &minIndex) {
    int min = A[0];
    minIndex = 0;
    
    for (int i = 1; i < n; i++) {
        if (A[i] < min) {
            min = A[i]; 
            minIndex = i;
        }
    }
    
    return min;
}

int main() {
    int fibo[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    int n = 8;
    int index;
    
    cout << "Array bilangan Fibonacci: ";
    for (int i = 0; i < n; i++) {
        cout << fibo[i] << " ";
    }
    cout << endl;
    
    int minvalue = Findmin(fibo, n, index);
    
    cout << "\nHASIL PENCARIAN:" << endl;
    cout << "nilai minimum: " << minvalue << endl;
    cout << "berada indeks ke-" << index << endl;
    
    return 0;
}