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
List* create_empty_list(){
    List* list = new List;
    list->NIL = new Node;
    list->HEAD = new Node;
    list->TAIL = new Node;
    return list;
}
List *push_back(List *list_ptr, int new_key)
{
    if (list_ptr == nullptr)
    {
        list_ptr = new List;
        list_ptr->HEAD = new Node;
        list_ptr->HEAD->key = new_key;
        list_ptr->HEAD->next = list_ptr->NIL;
        list_ptr->HEAD->prev = list_ptr->NIL;
        list_ptr->TAIL = list_ptr->HEAD;
        list_ptr->size = 1;
        return list_ptr;
    }
    else if (list_ptr->size == 0)
    {
        list_ptr->HEAD = new Node;
        list_ptr->HEAD->key = new_key;
        list_ptr->HEAD->next = list_ptr->NIL;
        list_ptr->HEAD->prev = list_ptr->NIL;
        list_ptr->TAIL = list_ptr->HEAD;
        list_ptr->size = 1;
        return list_ptr;
    }
    else if (list_ptr->size == 1)
    {
        Node *ptr = new Node;
        ptr->key = new_key;
        ptr->next = list_ptr->NIL;
        ptr->prev = list_ptr->HEAD;
        list_ptr->TAIL = ptr;
        list_ptr->HEAD->next = list_ptr->TAIL;
        list_ptr->size = 2;
        return list_ptr;
    }
    else
    {
        Node *ptr = new Node;
        ptr->key = new_key;
        ptr->next = list_ptr->NIL;
        ptr->prev = list_ptr->TAIL;
        list_ptr->TAIL->next = ptr;
        list_ptr->TAIL = ptr;
        list_ptr->size++;
        return list_ptr;
    }
}
void clear_list(List* list_ptr){
    if (list_ptr != nullptr){
        while (list_ptr->HEAD != list_ptr->TAIL){
            Node *current = list_ptr->HEAD;
            if (list_ptr->HEAD->next){
                list_ptr->HEAD->next->prev = nullptr;
                list_ptr->HEAD = list_ptr->HEAD->next;
            }
            else list_ptr->HEAD = nullptr;
            delete current;
            list_ptr->size--;
        }
    }
}

using std::cout;
using std::endl;


int main() {
  List* list = create_empty_list();
  list = push_back(list, 0);
  list = push_back(list, 1);
  list = push_back(list, 2);
  list = push_back(list, 3);
  clear_list(list);
  if ((list->HEAD == list->TAIL) and (list->NIL != nullptr)) {
    cout << "OK" << endl;
  }
  delete list->NIL;
  delete list;
  return 0;
}