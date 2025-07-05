#include <iostream>
using namespace std;

const int MAXSIZE = 7;
int stack[MAXSIZE];
int top = -1;
//check if the stack is empty
bool isEmpty() {
    return top == -1;
}
//check if the stack is full
bool isFull() {
    return top == MAXSIZE - 1;
}
//function to return the topmost element in the stack
int peek() {
    if (!isEmpty())
        return stack[top];
    else {
        cout << "Stack is empty.\n";
        return -1; //sentinel value or consider throwing an exception
    }
}
//function to delete from the stack
int pop() {
    if (!isEmpty()) {
        return stack[top--];
    } else {
        cout << "Could not retrieve data, Stack is empty." << endl;
        return -1;
    }
}

//Function to insert into the stack
bool push(int data) {
    if (!isFull()) {
        stack[++top] = data;
        return true;
    } else {
        cout << "Could not insert data, Stack is full." << endl;
        return false;
    }
}
int main() {
    push(44);
    push(90);
    push(100);
    push(10);
    push(62);
    push(123);
    push(15);

    cout << "Element at top of the stack: " << peek() << endl;
    cout << "Elements in the stack:\n";

    //print stack data by popping
    while (!isEmpty()) {
        int data = pop();
        cout << data << endl;
    }

    cout << "Stack full: " << (isFull() ? "true" : "false") << endl;
    cout << "Stack empty: " << (isEmpty() ? "true" : "false") << endl;

    return 0;
}
