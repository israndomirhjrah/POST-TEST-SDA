#include <iostream>
using namespace std;

void tukar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x, y;
    
    cout << "Masukkan nilai pertama: ";
    cin >> x;
    cout << "Masukkan nilai kedua: ";
    cin >> y;
    
    cout << "\nSebelum ditukar:" << endl;
    cout << "Nilai pertama: " << x << endl;
    cout << "Nilai kedua: " << y << endl;


    tukar(x, y);
    cout << "\nSetelah ditukar:" << endl;
    cout << "Nilai pertama: " << x << endl;
    cout << "Nilai kedua: " << y << endl;
    
    return 0;
}