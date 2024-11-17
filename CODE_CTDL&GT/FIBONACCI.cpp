#include <iostream>
using namespace std;

// Ham de quy tinh so Fibonacci
int fibonacci(int n) {
    if (n <= 1) {
        return n; // Dieu kien dung: F(0) = 0, F(1) = 1
    }
    return fibonacci(n - 1) + fibonacci(n - 2); // Goi de quy
}

int main() {
    int n;
    cout << "Nhap so nguyen duong n: ";
    cin >> n;

    if (n < 0) {
        cout << "Khong the tinh Fibonacci cho so am!" << endl;
    } else {
        cout << "So Fibonacci thu " << n << " la: " << fibonacci(n) << endl;
    }

    return 0;
}

