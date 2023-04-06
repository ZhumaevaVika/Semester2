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

void destroy_list(Node*& head_ref) {
    Node* current = head_ref;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head_ref = nullptr;
}

void print_list(Node* head_ref){
    Node* current = head_ref;
    while (current != nullptr) {
        Node* next = current->next;
        std::cout << current->key << " ";
        current = next;
    }
    std::cout << std::endl;
}

using std::cout;
using std::endl;

int main() {
  Node* HEAD = nullptr;
  push_back(HEAD, 0);
  push_back(HEAD, 1);
  push_back(HEAD, 2);
  print_list(HEAD);
  return 0;
}