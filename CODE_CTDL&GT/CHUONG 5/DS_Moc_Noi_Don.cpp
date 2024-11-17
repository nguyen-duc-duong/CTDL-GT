#include <iostream>
using namespace std;

// Dinh nghia cau truc cua mot nut trong danh sach
struct Node {
    int data;        // Gia tri cua nut
    Node* next;      // Con tro tro toi nut tiep theo
};

// Ham tao mot nut moi
Node* taoNode(int data) {
    Node* newNode = new Node();  // Tao mot nut moi
    newNode->data = data;        // Gan gia tri cho nut
    newNode->next = NULL;         // Dinh gia tri cho con tro next la NULL
    return newNode;               // Tra ve nut moi
}

// Ham them mot nut vao dau danh sach
void themVaoDau(Node*& head, int data) {
    Node* newNode = taoNode(data);  // Tao nut moi
    newNode->next = head;           // Nut moi tro toi nut dau hien tai
    head = newNode;                 // Cap nhat nut dau danh sach
}

// Ham them mot nut vao cuoi danh sach
void themVaoCuoi(Node*& head, int data) {
    Node* newNode = taoNode(data);  // Tao nut moi
    if (head == NULL) {             // Neu danh sach rong
        head = newNode;             // Cap nhat nut dau danh sach
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {    // Di den nut cuoi
        temp = temp->next;
    }
    temp->next = newNode;            // Ghi de nut cuoi bang nut moi
}

// Ham xoa nut o dau danh sach
void xoaDau(Node*& head) {
    if (head == NULL) {
        cout << "Danh sach rong, khong co gi de xoa." << endl;
        return;
    }
    Node* temp = head;    // Luu lai nut dau
    head = head->next;    // Cap nhat nut dau moi
    delete temp;          // Giai phong bo nho nut cu
}

// Ham xoa nut o cuoi danh sach
void xoaCuoi(Node*& head) {
    if (head == NULL) {
        cout << "Danh sach rong, khong co gi de xoa." << endl;
        return;
    }
    if (head->next == NULL) {  // Chi co mot nut
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->next != NULL) {
        temp = temp->next;  // Di den nut ke nut cuoi
    }
    delete temp->next;     // Giai phong bo nho nut cuoi
    temp->next = NULL;     // Cap nhat nut cuoi moi
}

// Ham xoa nut dau tien co gia tri x
void xoaGiaTri(Node*& head, int x) {
    if (head == NULL) {
        cout << "Danh sach rong, khong co gi de xoa." << endl;
        return;
    }
    if (head->data == x) {  // Neu nut dau chua gia tri x
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != x) {
        temp = temp->next;  // Di chuyen den nut co gia tri x
    }
    if (temp->next == NULL) {
        cout << "Khong tim thay gia tri " << x << " trong danh sach." << endl;
        return;
    }
    Node* delNode = temp->next;  // Luu nut can xoa
    temp->next = temp->next->next;  // Bo qua nut can xoa
    delete delNode;  // Giai phong bo nho nut
}

// Ham in danh sach
void inDanhSach(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;  // Khoi tao danh sach rong

    // Them nut vao dau danh sach
    themVaoDau(head, 10);
    themVaoDau(head, 20);
    themVaoDau(head, 30);
    cout << "Danh sach sau khi them vao dau: ";
    inDanhSach(head);

    // Them nut vao cuoi danh sach
    themVaoCuoi(head, 40);
    themVaoCuoi(head, 50);
    cout << "Danh sach sau khi them vao cuoi: ";
    inDanhSach(head);

    // Xoa nut o dau danh sach
    xoaDau(head);
    cout << "Danh sach sau khi xoa dau: ";
    inDanhSach(head);

    // Xoa nut o cuoi danh sach
    xoaCuoi(head);
    cout << "Danh sach sau khi xoa cuoi: ";
    inDanhSach(head);

    // Xoa nut dau tien co gia tri x
    xoaGiaTri(head, 20);
    cout << "Danh sach sau khi xoa gia tri 20: ";
    inDanhSach(head);

    return 0;
}

