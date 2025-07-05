#include <iostream>
using namespace std;

struct node {
   int data;
   int key;
   struct node *next;
};

struct node *head = NULL;

// Check if the list is empty
bool isEmpty() {
   return head == NULL;
}

// Insert a node at the beginning of the circular linked list
void insertFirst(int key, int data) {
   struct node *link = new node; // Using 'new' instead of 'malloc'
   link->key = key;
   link->data = data;

   if (isEmpty()) {
      head = link;
      head->next  // Points to itself (circular)
   } else {= head;
      struct node *temp = head;

      // Find the last node
      while (temp->next != head) {
         temp = temp->next;
      }

      // Insert at the beginning
      link->next = head;
      temp->next = link;
      head = link; // Update the head
   }
}

// Delete the first node
struct node* deleteFirst() {
   if (isEmpty()) return NULL;

   struct node *temp = head;

   // Only one node
   if (head->next == head) {
      head = NULL;
      return temp;
   }

   // More than one node
   struct node *last = head;
   while (last->next != head) {
      last = last->next;
   }

   last->next = head->next;
   head = head->next;

   return temp;
}

// Display the circular linked list
void printList() {
   if (isEmpty()) {
      cout << "List is empty." << endl;
      return;
   }

   struct node *ptr = head;
   cout << "[ ";
   do {
      cout << "(" << ptr->key << "," << ptr->data << ") ";
      ptr = ptr->next;
   } while (ptr != head);
   cout << "]" << endl;
}

int main() {
   insertFirst(1, 10);
   insertFirst(2, 20);
   insertFirst(3, 30);
   insertFirst(4, 1);
   insertFirst(5, 40);
   insertFirst(6, 56);

   cout << "Circular Linked List: ";
   printList();

   deleteFirst();  // Deleting the first node
   cout << "\nList after deleting the first item: ";
   printList();

   return 0;
}
