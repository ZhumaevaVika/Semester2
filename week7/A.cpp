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

int main() {
  Node* HEAD = nullptr;
  HEAD = new Node;
  if ((HEAD->key == 0) and (HEAD->next == nullptr)) {
    cout << "OK" << endl;
  } else {
    cout << endl;
  }
  delete HEAD;
  return 0;
}