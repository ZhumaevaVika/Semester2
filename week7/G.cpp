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
// void remove(Node*& head_ptr)
Node* find(Node* head_ref, int key) {
    Node* current = head_ref;
    while (current != nullptr) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}
using std::cout;
using std::endl;

int main() {
  Node* HEAD = nullptr, *current = nullptr;
  push_back(HEAD, 0);
  push_back(HEAD, 1);
  push_back(HEAD, 2);
  current = find(HEAD, 2);
  if (current->key == 2) {
    cout << "OK" << endl;
  }
  return 0;
}
