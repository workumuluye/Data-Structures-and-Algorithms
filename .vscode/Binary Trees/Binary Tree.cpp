#include <iostream>
using namespace std;

struct Node {
   int data;
   Node* leftChild;
   Node* rightChild;
};

Node* root = nullptr;

void insert(int data) {
   Node* tempNode = new Node;
   tempNode->data = data;
   tempNode->leftChild = nullptr;
   tempNode->rightChild = nullptr;

   if (root == nullptr) {
      root = tempNode;
   } else {
      Node* current = root;
      Node* parent = nullptr;

      while (true) {
         parent = current;
         if (data < current->data) {
            current = current->leftChild;
            if (current == nullptr) {
               parent->leftChild = tempNode;
               return;
            }
         } else {
            current = current->rightChild;
            if (current == nullptr) {
               parent->rightChild = tempNode;
               return;
            }
         }
      }
   }
}
void preOrderTraversal(Node* root) { //PLR
   if (root != nullptr) {
      cout << root->data << " ";
      preOrderTraversal(root->leftChild);
      preOrderTraversal(root->rightChild);
   }
}

void inOrderTraversal(Node* root) { //LPR
   if (root != nullptr) {
      inOrderTraversal(root->leftChild);
      cout << root->data << " ";
      inOrderTraversal(root->rightChild);
   }
}

void postOrderTraversal(Node* root) { //LRP
   if (root != nullptr) {
      postOrderTraversal(root->leftChild);
      postOrderTraversal(root->rightChild);
      cout << root->data << " ";
   }
}

int main() {
   int array[7] = { 27, 14, 35, 10, 19, 31, 42 };
   for (int i = 0; i < 7; ++i) {
      insert(array[i]);
   }

   cout << "Pre-order traversal: ";
   preOrderTraversal(root);
   cout << endl;

   cout << "In-order traversal: ";
   inOrderTraversal(root);
   cout << endl;

   cout << "Post-order traversal: ";
   postOrderTraversal(root);
   cout << endl;

   return 0;
}
