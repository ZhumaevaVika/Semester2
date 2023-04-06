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
void remove_key(Node*& head_ref, int key) {
    Node* current = head_ref;
    Node* prev = nullptr;
    while (current != nullptr) {
        if (current->key == key) {
            if (prev == nullptr) {
                head_ref = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}
using std::cout;
using std::endl;

int main() {
  Node* HEAD = nullptr;
  push_back(HEAD, 0);
  push_back(HEAD, 1);
  push_back(HEAD, 2);
  remove_key(HEAD, 0);
  remove_key(HEAD, 1);
  remove_key(HEAD, 2);
  remove_key(HEAD, 3);
  if (HEAD == nullptr) {
    cout << "OK" << endl;
  }
  return 0;
}