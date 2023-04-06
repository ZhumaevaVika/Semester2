#include <iostream>

struct Node{
    int key;
    Node* next;

    Node() {
        key = 0;
        next = nullptr;
    }
};

void push_back(Node*& head_ref, int new_data){
    Node* new_node = new Node;
    new_node->key = new_data;
    new_node->next = nullptr;
    Node* current = head_ref;
    if (head_ref == nullptr) {
        head_ref = new_node;
        return;
    }
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = new_node;
}

using std::cout;
using std::endl;

int main() {
  Node* HEAD = nullptr;
  push_back(HEAD, 0);
  push_back(HEAD, 1);
  push_back(HEAD, 2);
  Node* ptr = HEAD;
  while (ptr->next != nullptr) {
    cout << ptr->key << ' ';
    ptr = ptr->next;
  }
  cout << ptr->key << endl;
  ptr = HEAD;
  while (ptr->next != nullptr) {
    ptr = HEAD->next;
    delete HEAD;
    HEAD = ptr;
  }
  delete HEAD;
  return 0;
}