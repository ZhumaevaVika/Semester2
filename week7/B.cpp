#include <iostream>
using namespace std;

struct Node{
    int key;
    Node* next;

    Node() {
        key = 0;
        next = nullptr;
    }
};

void push_front(Node*& head_ref, int new_key) {
    Node* new_node = new Node;
    new_node->key = new_key;
    new_node->next = head_ref;
    head_ref = new_node;
}


int main() {
  Node* HEAD = nullptr;
  push_front(HEAD, 2);
  push_front(HEAD, 1);
  push_front(HEAD, 0);
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