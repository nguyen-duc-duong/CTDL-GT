#include <iostream>
using namespace std;

// Ham de quy giai bai toan thap Ha Noi
void thapHaNoi(int n, char cotNguon, char cotDich, char cotTrungGian) {
    if (n == 1) {
        // Dieu kien dung: Di chuyen dia duy nhat
        cout << "Di chuyen dia 1 tu cot " << cotNguon << " sang cot " << cotDich << endl;
        return;
    }
    
    // Di chuyen n-1 dia tu cot nguon sang cot trung gian
    thapHaNoi(n - 1, cotNguon, cotTrungGian, cotDich);

    // Di chuyen dia lon nhat tu cot nguon sang cot dich
    cout << "Di chuyen dia " << n << " tu cot " << cotNguon << " sang cot " << cotDich << endl;

    // Di chuyen n-1 dia tu cot trung gian sang cot dich
    thapHaNoi(n - 1, cotTrungGian, cotDich, cotNguon);
}

int main() {
    int n;
    cout << "Nhap so luong dia: ";
    cin >> n;

    if (n <= 0) {
        cout << "So luong dia phai lon hon 0!" << endl;
    } else {
        cout << "Cac buoc di chuyen nhu sau:" << endl;
        thapHaNoi(n, 'A', 'C', 'B'); // A: cot nguon, C: cot dich, B: cot trung gian
    }

    return 0;
}

