#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            return mid; // Tìm th?y, tr? v? v? trí
        } else if (arr[mid] < x) {
            low = mid + 1; // Tìm ? n?a ph?i
        } else {
            high = mid - 1; // Tìm ? n?a trái
        }
    }
    return -1; // Không tìm th?y
}

int main() {
    vector<int> arr; 
    arr.push_back(4);
    arr.push_back(6);
    arr.push_back(8);
    arr.push_back(11);
    arr.push_back(13);
    arr.push_back(15);
    int x = 8;
    cout << "Mang: ";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int result = binarySearch(arr, x);

    if (result != -1) {
        cout << "Tim thay " << x << " o vi tri: " << result << endl;
    } else {
        cout << "Khong tim thay " << x << endl;
    }

    return 0;
}

