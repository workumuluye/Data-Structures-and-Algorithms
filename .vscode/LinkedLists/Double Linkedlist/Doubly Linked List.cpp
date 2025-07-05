#include <iostream>                 
using namespace std;            

// Node structure definition
struct Node {
    int data;//hold the data of the node
    Node* next;//pointer to the next node
    Node* prev;//pointer to the previous node
};

//global head and tail pointers for the doubly linked list
Node* head = NULL;//point to the first node
Node* tail = NULL;//point to the last node

bool isEmpty() { //function to check if the list is empty
    return head == NULL;  
}

void displayForward() { //function to display list from head to tail
    Node* ptr = head;//start from the head
    cout << "\nForward: [ ";
    while (ptr != NULL) { //traverse until end
        cout << ptr->data << " ";//print node data
        ptr = ptr->next;//move to next node
    }
    cout << "]";
}

void displayBackward() { //function to display list from tail to head
    Node* ptr = tail;  // Start from the tail
    cout << "\nBackward: [ ";
    while (ptr != NULL) { //traverse backward
        cout << ptr->data << " ";  
        ptr = ptr->prev; //move to previous node
    }
    cout << "]";
}

void insertAtBeginning(int data) { //insert a new node at the beginning of the list
    Node* newNode = new Node{data, head, NULL}; //create new node, next=head, prev=NULL
    if (isEmpty()) {
        tail = newNode;//if list is empty, tail = new node
    } else {
        head->prev = newNode;//otherwise, set current head's prev to new node
    }
    head = newNode;//set new node as the new head
}

void insertAtEnd(int data) { //insert a new node at the end of the list
    Node* newNode = new Node{data, NULL, tail}; //create new node, next=NULL, prev=tail
    if (isEmpty()) {
        head = newNode; //if list is empty, head = new node           
    } else {
        tail->next = newNode; //otherwise, set current tail's next to new node     
    }
    tail = newNode;     
}

void insertAtAnyPosition(int pos, int data) { //insert a new node at a specific position (0-based index)
    if (pos == 0) { //if position is 0
        insertAtBeginning(data);//call insert at beginning
        return;
    }

    Node* current = head; //start from head
    int i = 0;
    while (current != NULL && i < pos - 1) { //traverse to the (pos - 1)th node
        current = current->next;
        i++;
    }

    if (current == NULL || current == tail) { //if reached end or last node
        insertAtEnd(data);//insert at end
        return;
    }

    Node* newNode = new Node{data, current->next, current}; //insert new node between current and current->next
    current->next->prev = newNode;
    current->next = newNode;
}

void deleteAtBeginning() { //delete node from the beginning of the list
    if (isEmpty()) return;//if list is empty, do nothing         

    Node* temp = head;//save current head
    if (head == tail) { //if only one node exists
        head = tail = NULL;//set both to NULL
    } else {
        head = head->next;//move head to next node
        head->prev = NULL; //remove backward link
    }
    delete temp;//delete the original head
}

// Delete node from the end of the list
void deleteAtEnd() {
    if (isEmpty()) return;         

    Node* temp = tail;//save current tail           
    if (head == tail) {        
        head = tail = NULL;       
    } else {
        tail = tail->prev;        
        tail->next = NULL; //remove forward link
    }
    delete temp;//delete the original tail
}

void deleteAtAnyPosition(int pos) { //delete node from a specific position (0-based index)
    if (isEmpty()) return;//if list is empty, do nothing
    if (pos == 0) {
        deleteAtBeginning();//delete from beginning
        return;
    }

    Node* current = head;//start from head
    int i = 0;
    while (current != NULL && i < pos) { //traverse to the target node
        current = current->next;
        i++;
    }

    if (current == NULL) return;//if position out of range, return

    if (current == tail) { //if it's the last node
        deleteAtEnd(); //delete from end
        return;
    }

     current->prev->next = current->next;//bypass the current node
    current->next->prev = current->prev;
    delete current;//delete the node
}

int main() {
    insertAtBeginning(10);         
    insertAtBeginning(20);        
    insertAtEnd(30);               
    insertAtEnd(40);               
    insertAtAnyPosition(2, 25);      

    cout << "\nAfter insertions:";
    displayForward();//output list forward
    displayBackward();//output list backward

    deleteAtBeginning();
    deleteAtEnd();
    deleteAtAnyPosition(1);

    cout << "\nAfter deletions:";
    displayForward(); 
    displayBackward();

    cout << endl;
    return 0;
}