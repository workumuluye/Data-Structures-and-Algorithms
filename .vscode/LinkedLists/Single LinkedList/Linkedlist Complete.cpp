#include <iostream>  
using namespace std;     

struct Node { //define a Node structure for singly linked list
    int data;//data held by the node (an integer)                   
    Node* next;//pointer to the next node in the list
};
Node* head = NULL;//global pointer to the head (first node) of the list, initially NULL

void printList() { //function to print all nodes in the list
    Node* current = head;//start from the head node
    cout << "[";
    while (current != NULL) { 
        cout << " " << current->data << " ";
        current = current->next; //move to the next node
    }
    cout << "]\n";
}

void insertAtBegin(int data) { //insert a new node at the beginning of the list
    Node* newNode = new Node{data, head}; //create a new node, next points to current head
    head = newNode;//update head to new node                        
}

void insertAtEnd(int data) { //insert a new node at the end of the list
    Node* newNode = new Node{data, NULL};//create new node with next = NULL (end)
    if (head == NULL) {  
        head = newNode;
        return;
    }
    Node* current = head;//otherwise start from head                   
    while (current->next != NULL) //traverse till the last node           
        current = current->next;
    current->next = newNode;//link last node to new node                
}

void insertAfterNode(Node* prevNode, int data) {// insert at any position
    if (prevNode == NULL) { //if previous node is NULL, cannot insert
        cout << "Previous node cannot be null.\n";
        return;                          
    }
    Node* newNode = new Node{data, prevNode->next}; //create new node pointing to prevNode's next
    prevNode->next = newNode;//update prevNode to point to new node
}

void deleteAtBegin() {
    if (head == NULL) return;
    Node* temp = head;//store current head in temp                      
    head = head->next;//move head to next node                      
    delete temp;//delete old head to free memory                          
}

void deleteAtEnd() {
    if (head == NULL) return;

    if (head->next == NULL) {
        delete head;
        head = NULL; 
        return;
    }

    Node* current = head;
    while (current->next->next != NULL) //traverse till second last node   
        current = current->next;

    delete current->next;//delete the last node
    current->next = NULL;//update second last node's next to NULL
}

void deleteNode(int key) {
    Node* temp = head; 
    Node* prev = NULL;

    if (temp != NULL && temp->data == key) { //if head holds the key
        head = temp->next; //change head to next node                  
        delete temp;
        return;
    }

    while (temp != NULL && temp->data != key) { //search for the node with the key
        prev = temp;//move prev to current node
        temp = temp->next;//move to next node               
    }

    if (temp == NULL) return;//if key not found, exit

    prev->next = temp->next;//unlink the node to delete
    delete temp;//delete the node to free memory
}

bool searchList(int key) { //search the list for a value, return true if found
    Node* temp = head;
    while (temp != NULL) {              
        if (temp->data == key)
            return true;                    
        temp = temp->next;                
    }
    return false;                       
}

int main() {
    insertAtBegin(12);                     
    insertAtBegin(22);                   
    insertAtEnd(30);                       
    insertAtEnd(44);                     
    insertAtBegin(50);                      
    insertAfterNode(head->next->next, 33); 

    cout << "Linked List: ";                
    printList();                         

    deleteAtBegin();                       
    deleteAtEnd();                         
    deleteNode(44);//delete node with value 44

    cout << "Linked List after deletion: "; 
    printList();

    insertAtBegin(4); 
    insertAtBegin(16); 

    cout << "Updated Linked List: "; 
    printList(); 

    int key = 16; 
    if (searchList(key))
        cout << "Element " << key << " is found.\n";
    else
        cout << "Element " << key << " is not present in the list.\n";

    return 0;
}