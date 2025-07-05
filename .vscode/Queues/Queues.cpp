#include <iostream>
using namespace std;

#define MAX 6
int intArray[MAX];
int front = 0;
int rear = -1;
int itemCount = 0;

// Function declarations
bool isEmpty();
bool isFull();
int peek();
int size();
void enqueue(int data);
int dequeue();
void displayQueue();

// Function to return the front element of the queue
int peek() {
    if (!isEmpty()) {
        return intArray[front];
    }
    cout << "Queue is empty, no front element." << endl;
    return -1;
}

// Check if the queue is empty
bool isEmpty() {
    return itemCount == 0;
}

// Check if the queue is full
bool isFull() {
    return itemCount == MAX;
}

// Get the current size of the queue
int size() {
    return itemCount;
}

// Insert an element into the queue
void enqueue(int data) {
    if (isFull()) {
        cout << "Queue is full. Cannot insert " << data << endl;
    } else {
        if (rear == MAX - 1)
            rear = -1; // Wrap around
        intArray[++rear] = data;
        itemCount++;
        cout << "Enqueued: " << data << endl;
    }
}

// Remove and return the front element of the queue
int dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return -1;
    } else {
        int data = intArray[front++];
        if (front == MAX)
            front = 0; // Wrap around
        itemCount--;
        cout << "Dequeued: " << data << endl;
        return data;
    }
}

// Print the queue elements
void displayQueue() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "Queue contents: ";
    int count = itemCount;
    int i = front;
    while (count > 0) {
        cout << intArray[i] << " ";
        i = (i + 1) % MAX;
        count--;
    }
    cout << endl;
}

int main() {
    // Enqueue elements
    enqueue(6);
    enqueue(8);
    enqueue(9);
    enqueue(13);
    enqueue(12);
    enqueue(15);

    // Try to enqueue when full
    enqueue(99);

    // Display status
    cout << "Queue size: " << size() << endl;
    displayQueue();

    // Check if full
    if (isFull()) cout << "Queue is full!" << endl;

    // Dequeue two elements
    dequeue();
    dequeue();

    // Display status
    cout << "Queue size after dequeuing 2 elements: " << size() << endl;
    displayQueue();

    // Peek at the front
    cout << "Element at front: " << peek() << endl;

    // Check empty
    cout << "Is queue empty? " << (isEmpty() ? "Yes" : "No") << endl;

    // Enqueue again to test wrap-around
    enqueue(21);
    enqueue(22);

    // Final display
    cout << "Final queue state:" << endl;
    displayQueue();
    cout << "Queue size: " << size() << endl;
    cout << "Is queue full? " << (isFull() ? "Yes" : "No") << endl;
    cout << "Is queue empty? " << (isEmpty() ? "Yes" : "No") << endl;

    return 0;
}

