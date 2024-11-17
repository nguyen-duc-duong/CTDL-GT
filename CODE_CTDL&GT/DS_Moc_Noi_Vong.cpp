#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = NULL;
    }
};

Node* createEmptyList() {
    return NULL;
}

void insertAtHead(Node*& head, int data) {
    Node* newNode = new Node(data);
    
    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}

void insertAtTail(Node*& head, int data) {
    Node* newNode = new Node(data);
    
    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void deleteHead(Node*& head) {
    if (head == NULL) return;

    if (head->next == head) {
        delete head;
        head = NULL;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        Node* toDelete = head;
        temp->next = head->next;
        head = head->next;
        delete toDelete;
    }
}

void deleteTail(Node*& head) {
    if (head == NULL) return;

    if (head->next == head) {
        delete head;
        head = NULL;
    } else {
        Node* temp = head;
        while (temp->next->next != head) {
            temp = temp->next;
        }
        Node* toDelete = temp->next;
        temp->next = head;
        delete toDelete;
    }
}

void traverse(Node* head) {
    if (head == NULL) return;

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

bool search(Node* head, int key) {
    if (head == NULL) return false;

    Node* temp = head;
    do {
        if (temp->data == key) return true;
        temp = temp->next;
    } while (temp != head);
    return false;
}

void deleteList(Node*& head) {
    if (head == NULL) return;

    Node* temp = head;
    while (temp->next != head) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
    delete temp;
    head = NULL;
}

int main() {
    Node* head = createEmptyList();
    
    insertAtHead(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    
    cout << "Danh sach sau khi chen: ";
    traverse(head);

    cout << "Tim kiem gia tri 20 trong danh sach: ";
    cout << (search(head, 20) ? "Tim thay" : "Khong tim thay") << endl;
    
    deleteHead(head);
    cout << "Danh sach sau khi xoa dau: ";
    traverse(head);

    deleteTail(head);
    cout << "Danh sach sau khi xoa cuoi: ";
    traverse(head);

    deleteList(head);
    cout << "Danh sach sau khi xoa toan bo: ";
    traverse(head);

    return 0;
}

