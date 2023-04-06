#include <iostream>

struct Node{
    Node* prev;
    Node* next;
    int key;

    Node() {
        key = 0;
        next = nullptr;
        prev = nullptr;
    }
};

struct List{
    Node* HEAD;
    Node* TAIL;
    Node* NIL;
    size_t size;

    List() {
        HEAD = nullptr;
        TAIL = nullptr;
        NIL = NULL;
        size = 0;
    }
};

using std::cout;
using std::endl;

int main() {
  List* list = new List;
  if ((list->HEAD == nullptr) and (list->TAIL == nullptr) and (list->NIL == nullptr)) {
    cout << "OK" << endl;
  }
  list->HEAD = new Node;
  if ((list->HEAD->key == 0) and (list->HEAD->next == nullptr) and (list->HEAD->prev == nullptr)) {
    cout << "OK" << endl;
  }
  delete list->HEAD;
  delete list;
  return 0;
}