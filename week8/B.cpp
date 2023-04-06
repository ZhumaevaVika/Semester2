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

List* create_empty_list() {
    List* list = new List;
    list->NIL = new Node;
    list->NIL->next = nullptr;
    list->HEAD = list->TAIL = list->NIL;
    return list;
}

using std::cout;
using std::endl;


int main() {
  List* list = create_empty_list();
  if ((list->HEAD != nullptr) and (list->TAIL != nullptr) and (list->NIL != nullptr)) {
    cout << "OK" << endl;
  }
  delete list->NIL;
  delete list;
  return 0;
}
