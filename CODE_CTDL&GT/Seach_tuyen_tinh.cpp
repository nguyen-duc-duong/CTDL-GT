#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) { // So s�nh t?ng ph?n t? v?i x
            return i; // T�m th?y, tr? v? v? tr�
        }
    }
    return -1; // Kh�ng t�m th?y
}

int main() {
    int n, x;
    cout << "Nhap so luong phan tu trong mang: ";
    cin >> n;

    int arr[n];
    cout << "Nhap cac phan tu trong mang:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Nhap gia tri can tim: ";
    cin >> x;

    int result = linearSearch(arr, n, x);

    if (result != -1) {
        cout << "Tim thay " << x << " o vi tri: " << result << endl;
    } else {
        cout << "Khong tim thay " << x << endl;
    }

    return 0;
}

