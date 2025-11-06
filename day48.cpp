#include <iostream>
using namespace std;

// -------------------- Regular Queue --------------------
class Queue {
    int *arr;
    int front, rear, size, capacity;

public:
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        rear++;
        arr[rear] = data;
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return;
        }
        front++;
        size--;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// -------------------- Circular Queue --------------------
class CircularQueue {
    int *arr;
    int front, rear, size, capacity;

public:
    CircularQueue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = rear = -1;
        size = 0;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool isFull() {
        return (front == 0 && rear == capacity - 1) || (rear == (front - 1) % (capacity - 1));
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Circular Queue Overflow!" << endl;
            return;
        }

        if (front == -1) // first element
            front = rear = 0;
        else if (rear == capacity - 1 && front != 0)
            rear = 0; // wrap around
        else
            rear++;

        arr[rear] = data;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Circular Queue Underflow!" << endl;
            return;
        }

        cout << "Deleted: " << arr[front] << endl;

        if (front == rear) { // only one element left
            front = rear = -1;
        } else if (front == capacity - 1)
            front = 0;
        else
            front++;
    }

    void display() {
        if (isEmpty()) {
            cout << "Circular Queue is Empty!" << endl;
            return;
        }

        cout << "Circular Queue: ";
        if (rear >= front) {
            for (int i = front; i <= rear; i++)
                cout << arr[i] << " ";
        } else {
            for (int i = front; i < capacity; i++)
                cout << arr[i] << " ";
            for (int i = 0; i <= rear; i++)
                cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// -------------------- Main Function --------------------
int main() {
    cout << "=== Regular Queue Demo ===" << endl;
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();

    cout << "\n=== Circular Queue Demo ===" << endl;
    CircularQueue cq(5);
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.display();
    cq.dequeue();
    cq.enqueue(50);
    cq.display();

    return 0;
}
