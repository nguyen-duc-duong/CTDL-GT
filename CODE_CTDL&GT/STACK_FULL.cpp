#include <iostream>
#define MAX 100 // Kich thuoc toi da cua stack
using namespace std;

// Dinh nghia mot stack
struct Stack {
    int arr[MAX]; // Mang luu cac phan tu cua stack
    int top;      // Chi so dinh cua stack
};

// Khoi tao stack rong
void initStack(Stack &s) {
    s.top = -1; // Dinh stack duoc gan la -1, bieu thi stack rong
}

// Kiem tra stack rong
bool isEmpty(Stack s) {
    return s.top == -1;
}

// Kiem tra stack day
bool isFull(Stack s) {
    return s.top == MAX - 1;
}

// Thao tac push: Them mot phan tu vao dinh stack
bool push(Stack &s, int value) {
    if (isFull(s)) {
        cout << "Stack day! Khong the them phan tu." << endl;
        return false;
    }
    s.arr[++s.top] = value; // Tang chi so dinh va them phan tu
    return true;
}

// Thao tac pop: Lay phan tu tu dinh stack
bool pop(Stack &s, int &value) {
    if (isEmpty(s)) {
        cout << "Stack rong! Khong co phan tu de lay." << endl;
        return false;
    }
    value = s.arr[s.top--]; // Lay phan tu dinh va giam chi so dinh
    return true;
}

// Ham hien thi cac phan tu trong stack
void display(Stack s) {
    if (isEmpty(s)) {
        cout << "Stack rong." << endl;
        return;
    }
    cout << "Cac phan tu trong stack: ";
    for (int i = 0; i <= s.top; i++) {
        cout << s.arr[i] << " ";
    }
    cout << endl;
}

int main() {
    Stack s;
    initStack(s); // Khoi tao stack rong

    // Kiem tra stack co rong khong
    if (isEmpty(s)) {
        cout << "Stack dang rong." << endl;
    }

    // Them cac phan tu vao stack
    push(s, 10);
    push(s, 20);
    push(s, 30);

    // Hien thi cac phan tu trong stack
    display(s);

    // Lay phan tu tu dinh stack
    int value;
    if (pop(s, value)) {
        cout << "Da lay phan tu: " << value << endl;
    }

    // Hien thi stack sau khi pop
    display(s);

    // Kiem tra stack day (neu them MAX phan tu)
    if (isFull(s)) {
        cout << "Stack day." << endl;
    } else {
        cout << "Stack chua day." << endl;
    }

    return 0;
}

