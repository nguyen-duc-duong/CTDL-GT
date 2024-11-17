#include <iostream>
using namespace std;
struct Node {
    int data;           
    Node* next;         
    Node* prev;         
    Node(int val) : data(val), next(NULL), prev(NULL) {}
};
void themVaoDau(Node*& head, int val) {
    Node* newNode = new Node(val); 
    if (head == NULL) {
        head = newNode;  
    } else {
        newNode->next = head;  
        head->prev = newNode;  
        head = newNode;        
    }
}
void xoaNode(Node*& head, int val) {
    if (head == NULL) {
        cout << "Danh sach rong!" << endl;
        return;
    }
    Node* current = head;
    while (current != NULL && current->data != val) {
        current = current->next;
    }
    if (current == NULL) {
        cout << "Khong tim thay node voi gia tri " << val << endl;
        return;
    }
    if (current == head) {
        head = head->next;  
        if (head != NULL) {
            head->prev = NULL;  
        }
    } else {
        current->prev->next = current->next;  
        if (current->next != NULL) {
            current->next->prev = current->prev; 
        }
    }
    delete current;
}
void inDanhSach(Node* head) {
    if (head == NULL) {
        cout << "Danh sach rong!" << endl;
        return;
    }
    Node* current = head;
    cout << "Danh sach: ";
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
void xoaDanhSach(Node*& head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
int main() {
    Node* head = NULL; 
    themVaoDau(head, 10);
    themVaoDau(head, 20);
    themVaoDau(head, 30);
    inDanhSach(head);
    xoaNode(head, 20);
    inDanhSach(head);
    xoaNode(head, 100);
    xoaNode(head, 30);
    inDanhSach(head);
    xoaDanhSach(head);

    return 0;
}

