#include <iostream>
using namespace std;
class Queue {
private:
    int front;  
    int rear;   
    int capacity;
    int* arr;   
public:
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }
    ~Queue() {
        delete[] arr;
    }
    bool isEmpty() {
        return front == -1;
    }
    bool isFull() {
        return (rear + 1) % capacity == front;
    }
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue da day. Khong the them phan tu " << value << "." << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        cout << "Them phan tu " << value << " vao queue." << endl;
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue rong. Khong the xoa phan tu." << endl;
            return;
        }
        cout << "Xoa phan tu " << arr[front] << " khoi queue." << endl;
        if (front == rear) { // Chi con mot phan tu
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue dang rong." << endl;
            return;
        }
        cout << "Cac phan tu trong queue: ";
        for (int i = front; i != rear; i = (i + 1) % capacity) {
            cout << arr[i] << " ";
        }
        cout << arr[rear] << endl;
    }
};
int main() {
    int size;
    cout << "Nhap kich thuoc queue: ";
    cin >> size;
    Queue q(size);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); 
    q.display();
    return 0;
}

